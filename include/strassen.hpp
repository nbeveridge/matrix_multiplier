#pragma once

#include <matrix.hpp>

matrix sq_matrix_multiply(matrix mat1, matrix mat2);

matrix multiply_recurse(matrix mat1, matrix mat2);

matrix pad_square_zeros(matrix mat, int power);

matrix remove_pad(matrix mat, int rows, int cols);

matrix multiply(matrix mat1, matrix mat2);