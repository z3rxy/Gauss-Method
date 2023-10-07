# Gaussian Elimination with Row Pivoting

## Overview

This repository contains a C++ program that solves a system of linear equations using the Gaussian elimination method with row pivoting. The main idea behind this method is to select the first element in each row as the leading element and normalize it to 1 while simultaneously zeroing out the elements below it in the same column. This process continues until the matrix is in upper triangular form, after which you can easily solve for the unknowns.

## How it Works

1. **Input**: You will be prompted to input the number of rows and columns for your coefficient matrix and then provide the elements of the matrix.

2. **Gaussian Elimination**: The program performs Gaussian elimination with row pivoting. It identifies the maximum element in each column below the leading element and swaps rows to ensure the leading element is the largest in its column. Then, it scales the leading element to 1 and subtracts multiples of it from the rows below to zero out the elements below it.

3. **Output**: After the elimination process, the program displays the row-echelon form of the matrix.

4. **Error Handling**: If a zero element is encountered on the main diagonal during the elimination process, the program will detect it and terminate, indicating that the system is either inconsistent or has infinitely many solutions.

## How to Use

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/your-username/gaussian-elimination.git
