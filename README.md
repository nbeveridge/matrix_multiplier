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

## Background
Coincidentally I have had a decent ammount of practice with linear algebra opperations in c++ due to my work with 23andMe. Most of this work involves heavy use of BLAS, LAPACK, and MKL so I am fairly familiar with some of the underlying algorithms at play with these libraries. Because of this, instead of just building the simple O(N^3) algorithm I decided to opt for the slightly more complex Strassen Algorithm. This meant I spent a little more time on algorithm stuff and less on memory management and optimization than I would have hoped.

## What I Would Change Given More Time
There are so many ways I can optimize my implementation given more time. The ones that I would first tackle(assuming I'm not writing assembly) are as follows.

1. Currently I need a matrix with a square number to divide the matrix into parts I acheive this by zero padding but this comes at a performance loss. I think I could fix this without too much trouble given a little more time.

2. When I calculate the nearest power to create my matrix above I use a loop instead of bit manipulation which is a much better solution. This results in a fraction of a percent in performance loss but it still bothers me.
   
3. The code I wrote does not address memory safety as I'm not too worried about safety for this application but given more time I would want to focus on how I'm allocating and deallocating my memory. 
