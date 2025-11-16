#include <string>
#include <print>
#include <system_error>

struct to_chars_result {
    char* ptr;
    std::errc ec;
};

int main() {
    const size_t BufferSize { 50 }; 
    
    std::string out(BufferSize, ' ');  // A string of BufferSize space chars
   
    auto result { std::to_chars(out.data(), out.data() + out.size(), 12345 ) }; 
    
    if (result.ec == std::errc{}) { std::println("{}", out); 
    /* Conversion succesful */ } 
} 

