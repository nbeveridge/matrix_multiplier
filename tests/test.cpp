#include <test_transpose.hpp>
#include <test_strassen.hpp>

int main(void)
{
    test_transpositions();
    test_strassen();
    return 0;
}
