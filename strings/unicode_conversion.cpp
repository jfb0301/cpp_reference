#include <string_view>
#include <format>
#include <print>

enum class Language { English, Dutch };

std::string_view GetLocalizedFormat(Language language)
{
    switch (language) {
        case Language::English:
            return "Numbers: {0} and {1}.";
        case Language::Dutch:
            return "Getallen: {0} en {1}.";
    }

}

int main()
{
    Language language { Language::English };

    vprint_unicode(GetLocalizedFormat(language), make_format_args(1, 2));
    std::println("");

    language = Language::Dutch;

    vprint_unicode(GetLocalizedFormat(language), make_format_args(1, 2));
}
