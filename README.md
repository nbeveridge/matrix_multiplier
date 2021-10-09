+# Brain Corp Take Home Test

## Prerequisites
1. Ubuntu.
2. Make
3. g++
## To Run Demo
1. Compile
    ```sh
    make
    ```
2. Run
    ```sh
    ./obj/main
    ```
## To Run Tests
1. Compile
    ```sh
    make test
    ```
2. Run
    ```sh
    ./obj/test
    ```


## The Design
My code is centered around a 2d array stored as a 1d array in column major format. This was chosen because, while it does involve more manipulation than an array of arrays, due to the data being stored in one continous memory block we can more quickly access or data. I have also chosen to use the Strassen Algorithm to multiply matricies because of it's surperior performance with large matrices(O(N^2.8) as opposed to O(N^3)).
