#include <strassen.hpp>
#include <general_operations.hpp>

matrix sq_matrix_multiply(matrix mat1, matrix mat2)
{

    matrix Empty(matrix::EMPTY, 2, 2);
    double a, b, c, d, e, f, g, h;

    a = mat1.arr[0];
    b = mat1.arr[2];
    c = mat1.arr[1];
    d = mat1.arr[3];

    e = mat2.arr[0];
    f = mat2.arr[2];
    g = mat2.arr[1];
    h = mat2.arr[3];

    Empty.arr[0] = a * e + b * g;
    Empty.arr[2] = a * f + b * h;
    Empty.arr[1] = c * e + d * g;
    Empty.arr[3] = c * f + d * h;

    return Empty;
}

matrix multiply_recurse(matrix mat1, matrix mat2)
{

    if (mat1.rows == 2)
    {
        return sq_matrix_multiply(mat1, mat2);
    }

    matrix Empty(matrix::EMPTY, mat1.rows, mat2.cols);

    int divcols = mat1.cols / 2;
    int divrows = mat1.rows / 2;
    int newsize = divcols * divrows;
    int halfoldsize = newsize * 2;
    int origrows = mat1.rows;
    int origcols = mat1.cols;

    matrix mat1quad1(matrix::EMPTY, divrows, divcols);
    matrix mat1quad2(matrix::EMPTY, divrows, divcols);
    matrix mat1quad3(matrix::EMPTY, divrows, divcols);
    matrix mat1quad4(matrix::EMPTY, divrows, divcols);

    matrix mat2quad1(matrix::EMPTY, divrows, divcols);
    matrix mat2quad2(matrix::EMPTY, divrows, divcols);
    matrix mat2quad3(matrix::EMPTY, divrows, divcols);
    matrix mat2quad4(matrix::EMPTY, divrows, divcols);

    for (int i = 0; i < divcols; i++)
    {
        for (int j = 0; j < divrows; j++)
        {
            mat1quad1.arr[divrows * i + j] = mat1.arr[mat1.rows * i + j];
            mat1quad2.arr[divrows * i + j] = mat1.arr[mat1.rows * i + j + halfoldsize];
            mat1quad3.arr[divrows * i + j] = mat1.arr[mat1.rows * i + j + divrows];
            mat1quad4.arr[divrows * i + j] = mat1.arr[mat1.rows * i + j + divrows + halfoldsize];

            mat2quad1.arr[divrows * i + j] = mat2.arr[mat2.rows * i + j];
            mat2quad2.arr[divrows * i + j] = mat2.arr[mat2.rows * i + j + halfoldsize];
            mat2quad3.arr[divrows * i + j] = mat2.arr[mat2.rows * i + j + divrows];
            mat2quad4.arr[divrows * i + j] = mat2.arr[mat2.rows * i + j + divrows + halfoldsize];
        }
    }

    matrix sa0 = subtract(mat2quad2, mat2quad4);
    matrix sa1 = add(mat1quad1, mat1quad2);
    matrix sa2 = add(mat1quad3, mat1quad4);
    matrix sa3 = subtract(mat2quad3, mat2quad1);
    matrix sa4 = add(mat1quad1, mat1quad4);
    matrix sa5 = add(mat2quad1, mat2quad4);
    matrix sa6 = subtract(mat1quad2, mat1quad4);
    matrix sa7 = add(mat2quad3, mat2quad4);
    matrix sa8 = subtract(mat1quad1, mat1quad3);
    matrix sa9 = add(mat2quad1, mat2quad2);

    matrix P1 = multiply_recurse(mat1quad1, sa0);
    matrix P2 = multiply_recurse(sa1, mat2quad4);
    matrix P3 = multiply_recurse(sa2, mat2quad1);
    matrix P4 = multiply_recurse(mat1quad4, sa3);
    matrix P5 = multiply_recurse(sa4, sa5);
    matrix P6 = multiply_recurse(sa6, sa7);
    matrix P7 = multiply_recurse(sa8, sa9);

    matrix qas0 = add(P5, P4);
    matrix qas1 = add(qas0, P6);
    matrix qas2 = add(P5, P1);
    matrix qas3 = subtract(qas2, P3);
    matrix qas4 = subtract(qas1, P2);

    matrix q1 = subtract(qas1, P2);
    matrix q2 = add(P1, P2);
    matrix q3 = add(P3, P4);
    matrix q4 = subtract(qas3, P7);

    for (int i = 0; i < divcols; i++)
    {
        for (int j = 0; j < divrows; j++)
        {
            Empty.arr[origrows * i + j] = q1.arr[divrows * i + j];
            Empty.arr[origrows * i + j + halfoldsize] = q2.arr[divrows * i + j];
            Empty.arr[origrows * i + j + divrows] = q3.arr[divrows * i + j];
            Empty.arr[origrows * i + j + divrows + halfoldsize] = q4.arr[divrows * i + j];
        }
    }

    return Empty;
}

matrix pad_square_zeros(matrix mat, int power)
{
    int rows = mat.rows;
    int cols = mat.cols;

    matrix Zeros(matrix::ZEROS, power, power);

    for (int i = 0; i < mat.cols; i++)
    {
        for (int j = 0; j < mat.rows; j++)
        {
            Zeros.arr[Zeros.rows * i + j] = mat.arr[mat.rows * i + j];
        }
    }

    return Zeros;
}

matrix remove_pad(matrix mat, int rows, int cols)
{

    matrix Empty(matrix::EMPTY, rows, cols);

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            Empty.arr[rows * i + j] = mat.arr[mat.rows * i + j];
        }
    }
    return Empty;
}

matrix multiply(matrix mat1, matrix mat2)
{
    int max, max1, max2;

    max1 = std::max(mat1.rows, mat1.cols);
    max2 = std::max(mat2.rows, mat2.cols);
    max = std::max(max1, max2);

    int power = 1;
    while (power < max)
    {
        power *= 2;
    }

    matrix newmat1 = pad_square_zeros(mat1, power);
    matrix newmat2 = pad_square_zeros(mat2, power);

    matrix out = multiply_recurse(newmat1, newmat2);

    matrix outnopad = remove_pad(out, mat1.rows, mat2.cols);

    return outnopad;
}