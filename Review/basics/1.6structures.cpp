#include <iostream>

class Vector{
    public:
        Vector(int s) : elem{new double[s]} {}                //construct a vector
        ~Vector() { delete[] elem; }                    // Destructor - free memory 
        double& operator[](int i) {return elem[i]; }
        int size() { return sz; }
    private:
        double* elem;
        int sz;
};


// Read s doubles from cin and return their sum; s is assumed positive
double read_and_sum(int s) {
    Vector v(s);
    for (int i = 0; i != s; ++i)
        std::cin >> v[i]; // Fixed: Added semicolon

    double sum = 0;
    for (int i = 0; i != s; ++i)
        sum += v[i];
    return sum;
}

int main() {
    // Test read_and_sum with a specific size
    int size = 3;
    std::cout << "Enter " << size << " numbers to sum: ";
    double result = read_and_sum(size);
    std::cout << "Sum of the " << size << " numbers is: " << result << std::endl;

    return 0;
}