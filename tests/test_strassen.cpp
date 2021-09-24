#include <matrix.hpp>
#include <strassen.hpp>

#include <test_matrices.hpp>
#include <test_strassen.hpp>
#include <test_funcs.hpp>

#include <stdlib.h>
#include <string>
#include <iostream>

void test_strassen(void)
{

    // One by one multiplication
    matrix mult_m1x1 = multiply(m1x1, m1x1);

    if (!is_equal(m1x1squared, mult_m1x1))
    {
        std::cout << "ERROR: Multiplication failure m1x1" << std::endl;
    }
    else
    {
        std::cout << "Multiplication passed m1x1" << std::endl;
    }

    // Two by two multiplication
    matrix m2_m3 = multiply(m2, m3);

    if (!is_equal(m5, m2_m3))
    {
        std::cout << "ERROR: Multiplication failure m2 m3" << std::endl;
    }
    else
    {
        std::cout << "Multiplication passed m2 m3" << std::endl;
    }

    // Large squares
    matrix m7_m8 = multiply(m7, m8);

    if (!is_equal(m9, m7_m8))
    {
        std::cout << "ERROR: Multiplication failure m7_m8" << std::endl;
    }
    else
    {
        std::cout << "Multiplication passed m7_m8" << std::endl;
    }

    // Rectangular
    matrix m11_m12 = multiply(m11, m12);

    if (!is_equal(m13, m11_m12))
    {
        std::cout << "ERROR: Multiplication failure m11_m12" << std::endl;
    }
    else
    {
        std::cout << "Multiplication passed m11_m12" << std::endl;
    }
}
