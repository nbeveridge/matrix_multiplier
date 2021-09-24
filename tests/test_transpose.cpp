#include <matrix.hpp>
#include <transpose.hpp>

#include <test_matrices.hpp>
#include <test_transpose.hpp>
#include <test_funcs.hpp>

#include <stdlib.h>
#include <string>
#include <iostream>

void test_transpositions(void)
{

    // One by one transposition
    matrix trans_m1x1 = transpose(m1x1);

    if (!is_equal(m1x1, trans_m1x1))
    {
        std::cout << "ERROR: Transposition failure m1x1" << std::endl;
    }
    else
    {
        std::cout << "Transposition passed m1x1" << std::endl;
    }

    // Two by two transposition
    matrix trans_m3 = transpose(m3);

    if (!is_equal(m4, trans_m3))
    {
        std::cout << "ERROR: Transposition failure m3" << std::endl;
    }
    else
    {
        std::cout << "Transposition passed m3" << std::endl;
    }

    matrix trans_m5 = transpose(m5);

    if (!is_equal(m6, trans_m5))
    {
        std::cout << "ERROR: Transposition failure m5" << std::endl;
    }
    else
    {
        std::cout << "Transposition passed m5" << std::endl;
    }

    // Large squares

    matrix trans_m10 = transpose(m10);

    if (!is_equal(m7, trans_m10))
    {
        std::cout << "ERROR: Transposition failure m10" << std::endl;
    }
    else
    {
        std::cout << "Transposition passed m10" << std::endl;
    }

    // Rectangular

    matrix trans_m11 = transpose(m11);

    if (!is_equal(m14, trans_m11))
    {
        std::cout << "ERROR: Transposition failure m11" << std::endl;
    }
    else
    {
        std::cout << "Transposition passed m11" << std::endl;
    }
    matrix single_trans_m13 = transpose(m13);
    matrix trans_m13 = transpose(single_trans_m13);

    if (!is_equal(m13, trans_m13))
    {
        std::cout << "ERROR: Transposition failure m13" << std::endl;
    }
    else
    {
        std::cout << "Transposition passed m13" << std::endl;
    }
}
