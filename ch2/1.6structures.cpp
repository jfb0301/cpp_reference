#include <iostream>

struct Vector {
    int sz;
    double* elem;

    // Destructor to free allocated memory
    ~Vector() {
        delete[] elem;
    }
};

// Initialize a Vector with size s
void vector_init(Vector& v, int s) {
    v.elem = new double[s];
    v.sz = s;
}

// Read s doubles from cin and return their sum; s is assumed positive
double read_and_sum(int s) {
    Vector v;
    vector_init(v, s);
    for (int i = 0; i != s; ++i)
        std::cin >> v.elem[i]; // Fixed: Added semicolon

    double sum = 0;
    for (int i = 0; i != s; ++i)
        sum += v.elem[i];
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