
#   ____                           _        _               
#  / ___|          _ __ ___   __ _| |_ _ __(_)_  _____  ___ 
# | |      _____  | '_ ` _ \ / _` | __| '__| \ \/ / _ \/ __|
# | |___  |_____| | | | | | | (_| | |_| |  | |>  <  __/\__ \
#  \____|         |_| |_| |_|\__,_|\__|_|  |_/_/\_\___||___/

This project implements various matrix operations in C, including addition, subtraction, multiplication, inversion, sorting, and transformations. It follows a modular approach to ensure code reusability and clarity.  

## 📁 Project Structure  

```
📦 Project Folder  
 ┣ 📂 assets  
 ┃ ┣ 📜 essentials.c  
 ┃ ┣ 📜 struct.h  
 ┣ 📂 arithmetic  
 ┃ ┣ 📂 matrices-strings-linked-lists  
 ┃ ┣ 📂 other-matrix-operations  
 ┃ ┣ 📜 main.c  
 ┃ ┣ 📜 main.exe  
 ┃ ┣ 📜 arithmetic.c  
 ┃ ┣ 📂 addition-subtraction  
 ┃ ┣ 📂 inverse-matrix  
 ┃ ┣ 📂 multiplication-matrix-matrix  
 ┃ ┣ 📂 multiplication-number-matrix  
 ┃ ┃ ┣ 📜 multiplication-number-matrix.c  
 ┃ ┃ ┣ 📜 multiplication-number-matrix.h  
 ┃ ┗ 📜 essentials.h  
```

### 🔹 `assets/`
Contains essential functions (allocation, creation, and memory management).  
- `struct.h` → Defines all the structures used in the project.  
- `essentials.h` → Includes standard libraries and function prototypes.  

### 🔹 `arithmetic/`
Handles arithmetic operations on matrices.  

### 🔹 `multiplication-number-matrix/`
Contains functions for multiplying a matrix by a scalar.  

---

## 🚀 Features  

### 1️⃣ **Basic Arithmetic Operations**  
- Addition & Subtraction of matrices (`add_matrices`, `substract_matrices`)  
- Multiplication of matrices (`multiply_matrix_matrix`, `multiply_matrix_number`)  
- Matrix inversion (`invert_matrix`)  

### 2️⃣ **Other Matrix Operations**  
- Transpose (`transpose_matrix`)  
- Sorting (`sort_matrix`)  
- Extracting maximum values (`extract_max_row_vector`)  
- Sub-matrix extraction (`extract_sub_matrix`)  

### 3️⃣ **String & Linked List Processing**  
- Convert words to matrix (`words_matrix`)  
- Organize words into structures (`organize_words`)  
- Linked list operations  

---

## 📌 Installation & Compilation  

1. Clone the repository:  
   ```sh
   git clone https://github.com/your-username/matrix-operations.git  
   cd matrix-operations  
   ```  
2. Compile using `gcc`:  
   ```sh
   gcc -o main arithmetic/*.c assets/*.c -lm  
   ```  
3. Run the executable:  
   ```sh
   ./main  
   ```

---

## 📖 Usage  

Run the program and follow the on-screen instructions to perform matrix operations.  

---

## 🔗 Resources  

- [Matrix Multiplication Theory](https://www.baeldung.com/java-matrix-multiplication)  
- [Matrix Operations Explained (YouTube)](https://www.youtube.com/watch?v=S4n-tQZnU6o)  
- [Matrix Inversion (YouTube)](https://www.youtube.com/watch?v=uUqXLixmM9E&t=12s)  

[Read The Full Document](rapport.pdf)
