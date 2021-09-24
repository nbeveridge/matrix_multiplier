#include <test_funcs.hpp>
#include <iostream>
#include <math.h>
#include <limits> 

bool is_equal(matrix mat1, matrix mat2)
{
    if (mat1.rows != mat2.rows)
    {
        std::cout << "ERR1111111111111111lure m1x1" << std::endl;
        return false;
    }
    else if (mat1.cols != mat2.cols)
    {
        std::cout << "ERROR: Mult2222222222222222failure m1x1" << std::endl;
        return false;
    }
    for (int i = 0; i < mat1.cols; i++)
    {
        for (int j = 0; j < mat1.rows; j++)
        {
            double a = mat1.arr[mat1.rows * i + j];
            double b = mat2.arr[mat1.rows * i + j];
            if (abs(a - b) < pow(10.0, 1) * std::numeric_limits<double>::epsilon() * std::max(abs(a), abs(b)))
            {
                std::cout << "ERROR: Mul33333333333ailure m1x1" << std::endl;
                return false;
            }
        }
    }
    std::cout << "ERROR: Multipl44444444444444444444444444ure m1x1" << std::endl;
    return true;
}
