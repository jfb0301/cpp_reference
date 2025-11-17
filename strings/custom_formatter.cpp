#include <string>
#include <string_view>
#include <format>
#include <print>
#include <iostream>

using std::string;
using std::string_view;
using std::format_error;
using std::formatter;
using std::format_parse_context;
using std::vformat;
using std::make_format_args;

// -------------------------------------------------------------
// KeyValue class
// -------------------------------------------------------------
class KeyValue {
public:
    KeyValue(string_view key, int value)
        : m_key{key}, m_value{value} {}

    const string& getKey() const { return m_key; }
    int getValue() const { return m_value; }

private:
    string m_key;
    int m_value{0};
};

// -------------------------------------------------------------
// Custom formatter for KeyValue
// Format syntax:
//
//   {:b:KeyFmt:ValueFmt}
//   {:k}       → key only
//   {:v}       → value only
//   {:b}       → key + " - " + value
// -------------------------------------------------------------
template <>
class std::formatter<KeyValue> {
public:
    enum class OutputType { KeyOnly, ValueOnly, KeyAndValue };

    // ---------------------------------------------------------
    // parse()
    // ---------------------------------------------------------
    constexpr auto parse(auto& ctx) {
        string keyFormat, valueFormat;
        size_t colonCount = 0;

        auto it = ctx.begin();
        for (; it != ctx.end(); ++it) {

            if (*it == '}')
                break;

            if (colonCount == 0) {
                // Parsing output type
                switch (*it) {
                case 'k': case 'K':
                    m_outputType = OutputType::KeyOnly;
                    break;
                case 'v': case 'V':
                    m_outputType = OutputType::ValueOnly;
                    break;
                case 'b': case 'B':
                    m_outputType = OutputType::KeyAndValue;
                    break;
                case ':':
                    ++colonCount;
                    break;
                default:
                    throw format_error{"Invalid KeyValue format."};
                }
            }
            else if (colonCount == 1) {
                // Parsing key format
                if (*it == ':')
                    ++colonCount;
                else
                    keyFormat += *it;
            }
            else if (colonCount == 2) {
                // Parsing value format
                valueFormat += *it;
            }
        }

        // Validate key format specifier
        if (!keyFormat.empty()) {
            format_parse_context keyCtx{keyFormat};
            m_keyFormatter.parse(keyCtx);
        }

        // Validate value format specifier
        if (!valueFormat.empty()) {
            format_parse_context valueCtx{valueFormat};
            m_valueFormatter.parse(valueCtx);
        }

        if (it != ctx.end() && *it != '}')
            throw format_error{"Invalid KeyValue format."};

        return it;
    }

    // ---------------------------------------------------------
    // format()
    // ---------------------------------------------------------
    auto format(const KeyValue& kv, auto& ctx) const {
        using enum OutputType;

        switch (m_outputType) {
        case KeyOnly:
            ctx.advance_to(m_keyFormatter.format(kv.getKey(), ctx));
            break;

        case ValueOnly:
            ctx.advance_to(m_valueFormatter.format(kv.getValue(), ctx));
            break;

        case KeyAndValue:
            ctx.advance_to(m_keyFormatter.format(kv.getKey(), ctx));
            ctx.advance_to(std::format_to(ctx.out(), " - "));
            ctx.advance_to(m_valueFormatter.format(kv.getValue(), ctx));
            break;
        }

        return ctx.out();
    }

private:
    OutputType m_outputType{OutputType::KeyAndValue};
    formatter<string> m_keyFormatter;
    formatter<int>    m_valueFormatter;
};

// -------------------------------------------------------------
// Test main()
// -------------------------------------------------------------
int main() {
    const size_t len{34};
    KeyValue kv{"Key 1", 255};

    std::println("{:>{}} {}", "Default:",               len, kv);
    std::println("{:>{}} {:k}", "Key only:",            len, kv);
    std::println("{:>{}} {:v}", "Value only:",          len, kv);
    std::println("{:>{}} {:b}", "Key & value default:", len, kv);

    std::println("{:>{}} {:k:*^11}", 
                 "Key only special:", len, kv);

    std::println("{:>{}} {:v::#06X}", 
                 "Value special:", len, kv);

    std::println("{:>{}} {::*^11:#06X}", 
                 "Key + value special:", len, kv);

    // Error test
    try {
        auto formatted = vformat("{:cd}", make_format_args(kv));
        std::println("{}", formatted);
    } 
    catch (const format_error& ex) {
        std::println("Caught exception: {}", ex.what());
    }
}
