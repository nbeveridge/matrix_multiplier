#include <matrix.hpp>
#include <general_operations.hpp>
#include <transpose.hpp>

#include <test_matrices.hpp>

#include <time.h>
#include <stdlib.h>
#include <cblas.h>
#include <string>
#include <iostream>
#include <algorithm>

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

int main(void)
{
    // int rowsA, colsB, common;
    // int i,j,k;

    // rowsA = 2;
    // colsB = 2;
    // common = 2;

    // matrix::MATRIX_FILL fillrand = matrix::RANDOM;
    // matrix::MATRIX_FILL fillempty = matrix::EMPTY;

    // std::string s1 = "[1,2,3,4,] \
    //                     [5,6,7,8,]";

    // matrix Z1(matrix::MANUAL, 2,4,s1);

    // // //    Z.rows = 2;

    // std::cout << std::to_string(Z1.cols) << std::endl;

    // Z.print("Z ");//, Z.arr, 2, 4);

    // matrix A(fillrand, rowsA, common);
    // matrix B(fillrand, common , colsB);
    // matrix C(fillempty, rowsA , colsB);
    // C.print("C EMPTY ");//, C.arr, rowsA, colsB);

    // // // CblasColMajor means that first are stored the nrow values of the first column of matrix A, then the nrow values of second column of A and so on.
    // CBLAS_ORDER order = CblasColMajor;
    // // // This indicates the transpose operation for a matrix can use CblasTrans,CblasNoTrans,CblasConjTrans,AtlasConj
    // CBLAS_TRANSPOSE transA = CblasNoTrans;
    // CBLAS_TRANSPOSE transB = CblasNoTrans;

    // // // alpha = Scaling factor for the product of matrices A and B.
    // // // beta = Scaling factor for matrix C.
    // double alpha = 1.0, beta = 0.0;

    // // this is needed to set the time as a seed for rand() this way rand is different on every run through
    // //    srand(time(NULL));

    // // multiply matrix A and B
    // cblas_dgemm(order,transA,transB, rowsA, colsB, common ,alpha,A.arr,
    //             rowsA ,B.arr, common ,beta,C.arr, rowsA);

    // A.print("A");//, A.arr, rowsA, common);
    // B.print("B");//, B.arr, common, colsB);
    // C.print("C");//, C.arr, rowsA, colsB);

    // // multiply(A, B);
    // transpose(Z,2,4);

    // std::string s = "[1,2,3,4,] \
    //                  [5,6,7,8,] \
    //                  [9,10,11,12,] \
    //                  [13,14,15,16,] \
    //                 ";

    // std::string s = "[1,2,3,4,5,6,1,1,] \
    //                  [7,8,9,10,11,12,1,1,] \
    //                  [13,14,15,16,17,18,1,1,] \
    //                  [19,20,21,22,23,24,1,1,] \
    //                  [25,26,27,28,29,30,1,1,] \
    //                  [25,26,27,28,29,30,1,1,] \
    //                  [25,26,27,28,29,30,1,1,] \
    //                  [31,32,33,34,35,36,1,1,]";

    // matrix Z(matrix::RANDOM, 256,256,s);
    // // matrix Z(matrix::MANUAL, 4,4,s);

    // // Z.print("Z");

    // matrix Z1(matrix::RANDOM, 8,8);
    // matrix Z2(matrix::RANDOM, 8,8);
    // matrix C(matrix::EMPTY, 8,8);

    // Z1.print("Z1");
    // Z2.print("Z2");

    // cblas_dgemm(order,transA,transB, 8, 8, 8 ,alpha,Z1.arr,
    //     8 ,Z2.arr, 8 ,beta,C.arr, 8);

    // C.print("C");

    // // matrix aasjkdn = multiply_recurse(Z1,Z2);
    // matrix out(matrix::EMPTY, 4,4);

    // // out = multiply_recurse(Z,Z);

    // out.print("output");

    // matrix P(matrix::RANDOM, 5,6);
    // pad_square_zeros(P).print("padded");

    // Z.print("Z at end");

    // Now add zero padding and deleting
    // should I use matrix mat1 or matrix& mat1
    // Do I have mem leak from no destructor
    // Equality check

    // matrix X(matrix::RANDOM, 36,85);
    // matrix Y(matrix::RANDOM, 85,36);

    // matrix X(matrix::RANDOM, 2,5);
    // matrix Y(matrix::RANDOM, 5,3);

    // matrix C(matrix::EMPTY,2,3);

    // matrix a = multiply(X,Y);

    // cblas_dgemm(order,transA,transB, X.rows, Y.cols, X.cols ,alpha,X.arr,
    //             X.rows ,Y.arr, X.cols ,beta,C.arr, X.rows);

    // X.print("X");
    // Y.print("Y");
    // a.print("a");
    // C.print("c");

    // // if (!is_equal(X,Y)) {
    // //     std::cout << "X and Y not equal" << std::endl;
    // }

    // if (is_equal(a,C)) {
    //     std::cout << "a and C are equal" << std::endl;
    // }

    // matrix test(matrix::RANDOM,2,3);

    // matrix test(matrix::MANUAL, 8,8,tm1);

    test2.print("tedscsdcjscnskjcndskjcnkjst");

    // std::string s1 = "  [8.402, 7.831, 9.116, 3.352, 2.778, 0.000, 0.000, 0.000,] \
    //                     [3.944 7.984 1.976 7.682 5.540 0.000, 0.000, 0.000,] \
    //                     [0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000,] \
    //                     [0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000,] \
    //                     [0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000,] \
    //                     [0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000,] \
    //                     [0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000,] \
    //                     [0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000,] \
    //                 ";

    // matrix T1(matrix::MANUAL, 8,8,s1);

    // std::string s2 = "  [4.774, 9.162, 0.163, 0.000, 0.000, 0.000, 0.000, 0.000, ]\
    //                     [6.289, 6.357, 2.429, 0.000, 0.000, 0.000, 0.000, 0.000, ]\
    //                     [3.648, 7.173, 1.372, 0.000, 0.000, 0.000, 0.000, 0.000, ]\
    //                     [5.134, 1.416, 8.042, 0.000, 0.000, 0.000, 0.000, 0.000, ]\
    //                     [9.522, 6.070, 1.567, 0.000, 0.000, 0.000, 0.000, 0.000, ]\
    //                     [0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, ]\
    //                     [0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, ]\
    //                     [0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, ]\
    //                 ";

    // matrix T2(matrix::MANUAL, 8,8,s2);

    // multiply_recurse(T1,T2).print("T1 T2");

    // matrix X(matrix::RANDOM, 8,8);
    // matrix Y(matrix::RANDOM, 8,8);

    // matrix C(matrix::EMPTY,8,8);

    // matrix a = multiply(X,Y);

    // cblas_dgemm(order,transA,transB, X.rows, Y.cols, X.cols ,alpha,X.arr,
    //             X.rows ,Y.arr, X.cols ,beta,C.arr, X.rows);

    // X.print("X");
    // Y.print("Y");
    // a.print("a");
    // C.print("C");
    // multiply_recurse(X,Y).print("x y recurse");
    // multiply(X,Y).print(".print mult");

    return 0;
}
