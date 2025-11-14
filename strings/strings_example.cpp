#include <string>
#include <print>

int main() {
    std::string dynamicStr = "Hello"; 
    dynamicStr += " World"; 
    std::println("Message: {}", dynamicStr);
}
