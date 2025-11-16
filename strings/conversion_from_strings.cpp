#include <charconv>     // to_chars, from_chars, errc
#include <string>       // std::string
#include <print>        // std::println  (C++23)
#include <iostream>     // (optional fallback if needed)

int main() {
    constexpr std::size_t BufferSize = 64;

    double value1 { 0.314 };
    std::string out(BufferSize, ' '); // A string of BufferSize space characters.

    // Convert value1 → chars (to_chars does NOT append '\0')
    auto [ptr1, error1] = std::to_chars(out.data(), out.data() + out.size(), value1);

    if (error1 == std::errc{}) {
        std::println("{}", out); // Conversion successful.
    }

    double value2;

    // Convert chars → double
    auto [ptr2, error2] = std::from_chars(out.data(), out.data() + out.size(), value2);

    if (error2 == std::errc{}) {
        if (value1 == value2) {
            std::println("Perfect roundtrip");
        } else {
            std::println("No perfect roundtrip?!?");
        }
    }

    return 0;
}
