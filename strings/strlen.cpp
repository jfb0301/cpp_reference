#include <cstring>
#include <print>

char* copyString(const char* str) 
{
	char* result =  new char[strlen(str) ];   //Bug of by one
		strcpy(result, str); 
		return result; 
}

int main()
{
	const char* original = "Hello, this is a longer string now"; 
	char* copy = copyString(original); 

	std::println("{}", original); 
	std::println("{}", copy);
	
	delete[] copy; 
	return 0; 
}