#include <matrix.hpp>
#include <general_operations.hpp>

#include <test_matrices.hpp>
#include <test_transpose.hpp>
#include <test_strassen.hpp>

#include <time.h>
#include <stdlib.h>
#include <cblas.h>
#include <string>
#include <iostream>
#include <algorithm>



int main(void)
{
    test_transpositions();
    test_strassen();
    return 0;
}
