#include <matrix.hpp>
#include <transpose.hpp>
#include <strassen.hpp>

#include <test_matrices.hpp>

#include <time.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>


int main(void)
{
    std::string intro = "The main function serves to display some of the"
                        "functionality of the project I have made. See the"
                        " README for background and info on how to run tests."
                        " Below are some example transpose and multiply operations.";

    std::cout << intro << "\n\n\n\n\n" << std::endl;

    // Multiply 2 random matrices
    std::string multiplystr = "Below we can use the multiply function to multiply matrix"
                              "X with Y to make Z.";

    std::cout << multiplystr << "\n\n" << std::endl;

    matrix X(matrix::RANDOM, 8, 3);
    matrix Y(matrix::RANDOM, 3, 5);

    matrix Z = multiply(X, Y);

    X.print("X");
    Y.print("Y");
    Z.print("Z");


    // Transpose a random matrix
    std::string transposestr = "Below we can use the transpose function to transpose a matrix"
                              "A to make B.";

    std::cout << "\n\n" << transposestr << "\n\n" << std::endl;

    matrix A(matrix::RANDOM, 12, 5);

    matrix B = transpose(A);
    
    A.print("A");
    B.print("B");


    // Multiply 2 large matricies
    std::string largemult = "Below we can use the multiply function to multiply a "
                            "very large matrix. This is where the strassen algorithm "
                            "becomes very advantageous as it is O(n^2.3ish) as opposed "
                            "to O(n^3). \n\n"
                            "This may take a minute or so. Also you might want to zoom out.";

    std::cout << largemult << "\n\n" << std::endl;

    matrix L1(matrix::RANDOM, 233, 76);
    matrix L2(matrix::RANDOM, 76, 100);

    matrix L3 = multiply(L1, L2);

    L1.print("L1");
    L2.print("L2");
    L3.print("L3");

    return 0;
}
