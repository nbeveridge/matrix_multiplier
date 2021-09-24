#include <transpose.hpp>

matrix transpose(matrix &mat)
{
    int rows = mat.rows;
    int cols = mat.cols;

    matrix Empty(matrix::EMPTY, cols, rows);

    size_t rowcount = 0;
    size_t colcount = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            Empty.arr[i * cols + j] = mat.arr[colcount * rows + rowcount];
            ++colcount;
        }
        colcount = 0;
        ++rowcount;
    }

    return Empty;
}
