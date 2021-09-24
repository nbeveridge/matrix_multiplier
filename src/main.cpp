#include <matrix.hpp>
#include <transpose.hpp>
#include <strassen.hpp>

#include <test_matrices.hpp>

#include <time.h>
#include <stdlib.h>
#include <cblas.h>
#include <string>
#include <iostream>
#include <algorithm>


int main(void)
{
    std::string intro = "The main function serves to display some of the"
                        "functionality of the project I have made. See the"
                        " README for background and info on how to run tests.";

    std::cout << intro << std::endl;

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

    // // CblasColMajor means that first are stored the nrow values of the first column of matrix A, then the nrow values of second column of A and so on.
    CBLAS_ORDER order = CblasColMajor;
    // // This indicates the transpose operation for a matrix can use CblasTrans,CblasNoTrans,CblasConjTrans,AtlasConj
    CBLAS_TRANSPOSE transA = CblasNoTrans;
    CBLAS_TRANSPOSE transB = CblasNoTrans;

    // // alpha = Scaling factor for the product of matrices A and B.
    // // beta = Scaling factor for matrix C.
    double alpha = 1.0, beta = 0.0;

    // // this is needed to set the time as a seed for rand() this way rand is different on every run through
    // //    srand(time(NULL));

    // // multiply matrix A and B
    // cblas_dgemm(order,transA,transB, rowsA, colsB, common ,alpha,A.arr,
    //             rowsA ,B.arr, common ,beta,C.arr, rowsA);

    // A.print("A");//, A.arr, rowsA, common);
    // B.print("B");//, B.arr, common, colsB);
    // C.print("C");//, C.arr, rowsA, colsB);

    // // multiply(A, B);
    // matrix Z10(matrix::RANDOM, 2, 4);
    // transpose(Z10);

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

    matrix X(matrix::RANDOM, 8, 3);
    matrix Y(matrix::RANDOM, 3, 5);

    matrix C(matrix::EMPTY, 8, 5);

    matrix a = multiply(X, Y);

    cblas_dgemm(order, transA, transB, X.rows, Y.cols, X.cols, alpha, X.arr,
                X.rows, Y.arr, X.cols, beta, C.arr, X.rows);

    X.print("X");
    Y.print("Y");
    a.print("a");
    C.print("c");

    transpose(X).print("X trans");



    // if (!is_equal(X,Y)) {
    //     std::cout << "X and Y not equal" << std::endl;
    // }

    // if (is_equal(a,C)) {
    //     std::cout << "a and C are equal" << std::endl;
    // }

    // matrix test(matrix::RANDOM,2,3);

    // matrix test(matrix::MANUAL, 8,8,tm1);

    // test2.print("test");

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
