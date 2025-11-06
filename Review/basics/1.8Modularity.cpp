/*
    In our double_sqrt() function, we define separately three member functions
    
    1. Definition of the constructor 
    2. Definition of subscripting 
    3. Definition of size()
*/

double sqrt(double)

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