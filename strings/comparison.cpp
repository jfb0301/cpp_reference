#include <print>
#include <string>

int main() {
    std::string a { "Hello" };
    std::string b { "World" };

    std::println("{}'' '{}' = {}", a, b, a < b);
    std::println("'{}' '{}' = {}", a, b, a < b); 
}
