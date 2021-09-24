#include <general_operations.hpp>

matrix add(matrix mat1, matrix mat2)
{

    matrix Empty(matrix::EMPTY, mat1.rows, mat1.cols);

    for (int i = 0; i < Empty.cols; i++)
    {
        for (int j = 0; j < Empty.rows; j++)
        {
            Empty.arr[Empty.rows * i + j] = mat1.arr[Empty.rows * i + j] + mat2.arr[Empty.rows * i + j];
        }
    }
    return Empty;
}

matrix subtract(matrix mat1, matrix mat2)
{

    matrix Empty(matrix::EMPTY, mat1.rows, mat1.cols);

    for (int i = 0; i < Empty.cols; i++)
    {
        for (int j = 0; j < Empty.rows; j++)
        {
            Empty.arr[Empty.rows * i + j] = mat1.arr[Empty.rows * i + j] - mat2.arr[Empty.rows * i + j];
        }
    }
    return Empty;
}
