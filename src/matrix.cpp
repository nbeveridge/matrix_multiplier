#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

#include <matrix.hpp>


matrix::matrix() {}

matrix::matrix(enum MATRIX_FILL fill, const int rowsin, const int colsin, std::string values){
    rows = rowsin;
    cols=colsin;
    arr = new double[rows * cols];
    switch (fill) {
    case RANDOM:
        for (int j = 0; j < cols; j++){
            for (int i = 0; i < rows; i++){
                int pos = j*rows+i;
                arr[pos] = 1*((double)rand())/RAND_MAX;
            }
        }
        break;
    case ZEROS:
        for (int j = 0; j < cols; j++){
            for (int i = 0; i < rows; i++){
                arr[j*rows+i] = 0.000;
            }
        }
        break;
    case EMPTY:
        break;
    case MANUAL:
            values.erase(std::remove(values.begin(), values.end(), ' '), values.end());
            values.erase(std::remove(values.begin(), values.end(), '['), values.end());
            std::string rowdelimiter = "]";
            std::string coldelimiter = ",";
            size_t rowcount = 0;
            size_t colcount = 0;
            size_t posrow = 0;
            size_t poscol = 0;
            std::string rowtoken;
            std::string coltoken;
            while ((posrow = values.find(rowdelimiter)) != std::string::npos) {
                rowtoken = values.substr(0, posrow);
                while ((poscol = rowtoken.find(coldelimiter)) != std::string::npos) {
                    coltoken = rowtoken.substr(0, poscol);
                    arr[colcount*rows+rowcount] = stod(coltoken);
                    ++colcount;
                    rowtoken.erase(0, poscol + coldelimiter.length());
                }
                ++rowcount;
                colcount = 0;
                values.erase(0, posrow + rowdelimiter.length());
            }
        break;
    }
}

matrix::~matrix()
{
    // delete[] arr;
}

void matrix::print(const char * name){
    printf("Matrix %s has %d rows and %d columns:\n", name, rows, cols);
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("%.3f ", arr[j*rows + i]);
        }
        printf("\n");
    } 
    printf("\n");
}



 

