#include <test_funcs.hpp>
#include <iostream>
#include <math.h>
#include <limits>

bool is_equal(matrix mat1, matrix mat2)
{
    if (mat1.rows != mat2.rows)
    {
        return false;
    }
    else if (mat1.cols != mat2.cols)
    {
        return false;
    }
    for (int i = 0; i < mat1.cols; i++)
    {
        for (int j = 0; j < mat1.rows; j++)
        {
            double a = mat1.arr[mat1.rows * i + j];
            double b = mat2.arr[mat1.rows * i + j];
            if (abs(a - b) > pow(10.0, 13) * std::numeric_limits<double>::epsilon() * std::max(abs(a), abs(b)))
            {
                return false;
            }
        }
    }
    return true;
}
