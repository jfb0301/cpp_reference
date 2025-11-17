#include <print>
#include <format>
#include <iostream>
#include <locale>

int main()
{
    int i { 42 };

    // Width

    std::println("|{:5}|", i);

    std::println("|{:{}}|", i, 7);

    std::println("|{1:{0}}|", 7, i);

    // Aligthment 

    std::println("|{:7}|", i);

    std::println("|{:<7}|", i);

    std::println("|{:_>7}|", i);

    std::println("|{:_^7}|", i);

    // sign 

    std::println("|{:<5}", i); 

    std::println("|{:<+5}", i);

    std::println("|{:< 5}", i); 

    std::println("|{:< 5}", -i);

    // type

    std::println("|{:10d}|", i);
    std::println("|{:10b}|", i);
    std::println("|{:#10b}|", i);
    std::println("|{:10X}|", i);
    std::println("|{:#10X}|", i);


    // precision 

    double d { 3.1415 / 2.3 }; 

    std::println("|{:12g}|", d); 
    std::println("|{:12.2}|", d); 
    std::println("|{:12e}|", d); 

    int width { 12 }; 

    int precision { 3 }; 

    std::println("|{2:{0}.{1}f}|", width, precision, d); 
    
    std::println("|{2:{0}.{1}}|", width, precision, d); 
    
    // 0 

    std::println("|{:06d}|", i); 
    std::println("|{:+06d}|", i); 
    std::println("|{:06X}|", i); 
    std::println("|{:#06X}|", i); 

    // L 

    float f { 1.2f }; 
    std::cout << std::format(std::locale{ "POSIX" }, "|{:Lg}|\n", f);  

    // Formatting scape characters

    std::println("|{:?}|", "Hello\tworld!\n");
    std::println("|{:?}|", "\"");

    return 0;
}
