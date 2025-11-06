#include <iostream>

int count_x(char* p, char x)
{
    // Count the number of occurences of x in p[]
    // p is assumed to point to a zero - terminated array of char

    if (p == nullptr) return 0;
    int count = 0;
    for (; *p!=0; ++p)
        if(*p==x)
            ++count;
    return count;
}

int main() {
    char str1[] = "hello world";
    char str2[] = "xxx";
    char str3[] = "";
    char* str4 = nullptr;

    std::cout << "Occurrences of 'l' in \"" << str1 << "\": " << count_x(str1, 'l') << std::endl;
    std::cout << "Occurrrences of 'x' in \"" << str2 << "\": " << count_x(str2, 'x') << std::endl;
     
}