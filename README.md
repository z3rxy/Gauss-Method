# Gaussian Elimination

## Overview

This repository contains a C++ program that solves a system of linear equations using the Gaussian elimination method. The main idea behind this method is to select the first element in each row as the leading element and normalize it to 1 while simultaneously zeroing out the elements below it in the same column. This process continues until the matrix is in upper triangular form, after which you can easily solve for the unknowns.

## How it Works

1. **Input**: You will be prompted to input the number of rows and columns for your coefficient matrix and then provide the elements of the matrix.

2. **Gaussian Elimination**: It scales the leading element to 1 and subtracts multiples of it from the rows below to zero out the elements below it.

3. **Output**: After the elimination process, the program displays the row-echelon form of the matrix.

4. **Error Handling**: If a zero element is encountered on the main diagonal during the elimination process, the program will detect it and terminate, indicating that the system is either inconsistent or has infinitely many solutions.

## How to Use

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/z3rxy/Gauss-Method.git

2. **Navigate to the project directory**:
cd Gauss-Method

3. **Compile the C++ program**: Compile the program using the following command:
g++ Gauss_method.cpp -o Gauss_method

4. **Run the program**: Execute the program with the following command:
./Gauss_method

5. **Input your matrix**: Follow the on-screen prompts to input the coefficients of your matrix.

## Example

1. Suppose you have the following system of linear equations:  
2x + 3y - z = 1  
4x + y + 2z = 2  
3x + 2y + 3z = 3  
2. Enter these coefficients into the program as in the following example:  
2 3 -1  
4 1 2  
3 2 3  
3. Then enter the coefficients of the vector on the right side:  
1  
2  
3  
4. After executing the program, you will receive an answer to your system of equations in the form:  
x[1] = 0.08  
x[2] = 0.48  
x[3] = 0.6  
