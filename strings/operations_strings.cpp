#include <print>
#include <string>

int main() {
    std::string strHello { " Hello!! " };
    std::string strWorld { " World " }; 
    auto position { strHello.find("!!") };
        if (position != std::string::npos) {
            strHello.replace(position, 2, strWorld.substr(3,6)); 
        }
    std::println("{}", strHello); 
    // Test contains()
    std::string toFind { "World" }; 
    std::println("{}", strWorld.contains(toFind)); 
    std::println("{}", strWorld.contains('.')); 
    std::println("{}", strWorld.contains("Hello"));
}