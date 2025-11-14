#include <string>
#include <print>

int main() {
    std::string myString { "hello" }; 
    myString += ", there"; 
    std::string MyOtherString { myString }; 
    if (myString == MyOtherString) {
        MyOtherString[0] = 'H'; 
    } 

    println("{}", myString);
    println("{}", MyOtherString);
    return 0;
}
    
