#include <matrix.hpp>
#include <strassen.hpp>

#include <test_matrices.hpp>
#include <test_strassen.hpp>
#include <test_funcs.hpp>

#include <stdlib.h>
#include <string>
#include <iostream>

void test_strassen(void) {

    // One by one multiplication
    matrix mult_m1x1 = multiply(m1x1,m1x1);
    m1x1.print("m1x1");
    mult_m1x1.print("mult");
    m1x1squared.print("m1x1squared");
    if (!is_equal(m1x1squared,mult_m1x1)) {
        std::cout << "ERROR: Multiplication failure m1x1" << std::endl;
    }
    else {
        std::cout << "Multiplication passed m1x1" << std::endl;
    }

        std::cout << std::to_string(mult_m1x1.arr[0])<< std::endl;
        std::cout << std::to_string(m1x1squared.arr[0])<< std::endl;

//     // Two by two multiplication
//     matrix mult_m3 = multiply(m3);

//     if (!is_equal(m4,mult_m3)) {
//         std::cout << "ERROR: Multiplication failure m3" << std::endl;
//     }
//     else {
//         std::cout << "Multiplication passed m3" << std::endl;
//     }

//     matrix mult_m5 = multiply(m5);

//     if (!is_equal(m6,mult_m5)) {
//         std::cout << "ERROR: Multiplication failure m5" << std::endl;
//     }
//     else {
//         std::cout << "Multiplication passed m5" << std::endl;
//     }

//     // Large squares

//     matrix mult_m10 = multiply(m10);

//     if (!is_equal(m7,mult_m10)) {
//         std::cout << "ERROR: Multiplication failure m10" << std::endl;
//     }
//     else {
//         std::cout << "Multiplication passed m10" << std::endl;
//     }

//     // Rectangular

//     matrix mult_m11 = multiply(m11);

//     if (!is_equal(m14,mult_m11)) {
//         std::cout << "ERROR: Multiplication failure m11" << std::endl;
//     }
//     else {
//         std::cout << "Multiplication passed m11" << std::endl;
//     }
//     matrix single_mult_m13 = multiply(m13);
//     matrix mult_m13 = multiply(single_mult_m13);

//     if (!is_equal(m13,mult_m13)) {
//         std::cout << "ERROR: Multiplication failure m13" << std::endl;
//     }
//     else {
//         std::cout << "Multiplication passed m13" << std::endl;
//     }


}
