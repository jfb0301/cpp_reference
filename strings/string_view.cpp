// Extract extension function extracts and returns from a given filename
// the extension including the dot character


#include <string>
#include <string_view>
#include <print>
#include <filesystem>

// Extract extension (including the dot) from a filename
std::string extractExtension(std::string_view filename) {
    // Find the last dot
    std::size_t pos = filename.rfind('.');
    
    if (pos == std::string_view::npos) {
        return {};  // No extension found → return empty string
    }

    // Return a copy of the substring starting at the dot
    return std::string{ filename.substr(pos) };
}

int main() {
    std::string filename{
        R"(/home/jose/Desktop/programming/cpp/filename.txt)"
    };
    std::println("C++ string: {}", extractExtension(filename));

    std::string cString{
        R"(/home/jose/Desktop/programming/cpp/file.txt)"
    };
    std::println("C string: {}", extractExtension(cString));

    std::println("Literal: {}",
        extractExtension(R"(/home/jose/Desktop/programming/cpp/filename2.txt)")
    );

    return 0;
}
