#include <test_funcs.hpp>

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
            if (mat1.arr[mat1.rows * i + j] != mat2.arr[mat1.rows * i + j])
            {
                return false;
            }
        }
    }
    return true;
}
