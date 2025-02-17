# 🧮 C Matrixes  

## 📌 Overview  
This project focuses on matrix operations and modular programming. It covers various functionalities such as matrix addition, subtraction, multiplication, inversion, and more, structured in a modular format.  

## 📂 Table of Contents  
- [📁 Directory Structure](#-directory-structure)  
- [🔑 Key Components](#-key-components)  
- [📌 Project Parts](#-project-parts)  
- [🛠️ Operations](#-operations)  
  - [➕ Matrix Operations](#-matrix-operations)  
  - [🔡 Matrix String Linked Lists](#-matrix-string-linked-lists)  
- [📌 Example Usage](#-example-usage)  
- [📌 Conclusion](#-conclusion)  

## 📁 Directory Structure  
```plaintext
├── assets
│   ├── essentials.c
│   └── struct.h
├── arithmetic
│   ├── matrices-strings-linked-lists
│   ├── other-matrix-operations
│   ├── main.c
│   └── main.exe
├── multiplication-number-matrix
│   ├── multiplication-number-matrix.c
│   ├── multiplication-number-matrix.h
│   └── essentials.h
```

### 🔑 Key Files  
- **essentials.c**: Contains core utility functions for memory allocation and matrix/vector management.  
- **struct.h**: Defines structs used across the project.  
- **arithmetic.c**: Handles arithmetic operations like matrix addition, subtraction, and multiplication.  

## 🔑 Key Components  

### 📂 assets  
- **struct.h**: Contains all the structs used across the project for easy access and clean structure.  
- **essential.h & essentials.c**: Includes standard libraries and essential functions like memory allocation and matrix creation.  

## 📌 Project Parts  

### ➕ Arithmetic Operations  
- **Matrix Addition/Subtraction**: Functions for adding or subtracting matrices by splitting the tasks into reusable sub-functions.  
- **Matrix Multiplication**: Includes functions for multiplying a matrix by a number or another matrix.  
- **Matrix Inversion**: More complex operation based on the cofactor matrix and determinant calculations.  

### 🛠️ Example Functions  
- `matrices_sum`: Adds or subtracts two matrices depending on the operation type.  
- `multiply_matrix_number`: Multiplies a matrix by a scalar.  
- `invert_matrix`: Inverts a matrix using the cofactor method and determinant.  

## 🛠️ Operations  

### ➕ Matrix Operations  
- **Transpose a Matrix**: Flips a matrix by switching its rows and columns.  
- **Sort a Matrix**: Sorts a matrix either in ascending or descending order.  
- **Extract Maximum Row/Column**: Finds the maximum values in rows or columns of a matrix.  

### 🔡 Matrix String Linked Lists  
- **Words to Matrix**: Splits text into words and stores them in a matrix.  
- **Organize Words into Structure**: Uses a linked list to organize the words from the text.  

## 📌 Example Usage  
Here’s an example of how you might use the matrix addition functionality:  

```c
int matrix_a[2][2] = {{1, 2}, {3, 4}};
int matrix_b[2][2] = {{5, 6}, {7, 8}};
int rows = 2, columns = 2;

int** result = matrices_sum(matrix_a, matrix_b, rows, columns, 0); // 0 for addition
```

## 📌 Conclusion  
- ✅ Teamwork is essential in development.  
- 🔄 Different compilers may behave differently; always test on your target platform.  
- 🏗️ Modular programming helps break complex problems into manageable chunks.  

## 🔗 References  
- [Matrix Multiplication in Java](https://www.baeldung.com/java-matrix-multiplication)  
- [Matrix Operations Video Tutorial 1](https://www.youtube.com/watch?v=S4n-tQZnU6o)  
- [Matrix Operations Video Tutorial 2](https://www.youtube.com/watch?v=uUqXLixmM9E&t=12s)  


[Read The Full Document](rapport.pdf)
