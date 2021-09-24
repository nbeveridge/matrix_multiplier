#pragma once
#include <string>

class matrix {
    private:
        matrix();
    public:
        std::string name;
        int rows;   
        int cols;
        double* arr;

        enum MATRIX_FILL {EMPTY, RANDOM, MANUAL, ZEROS};
        
        matrix(enum MATRIX_FILL fill, const int rowsin=0, const int colsin=0, std::string values="");

        ~matrix();

        // Prints out our array as a matrix
        // Everything is in column major order
        void print(const char * name);
};
