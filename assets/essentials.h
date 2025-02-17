
// required libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
// structs 
#include "./struct.h"

// for allocations

int* allocate_vector( int length );
int** allocate_matrix( int rows );


// for creation
int* create_vector( int length );
int** create_matrix( int rows, int columns );

// for scaning

int** scan_matrix( int* rows, int* columns );
char* scan_text( int text_length );

// text utilites

int text_words_count( char *text );
char* text_to_lower_case( char *text );

// for clearing memory

void free_matrix( int** matrix, int rows );
void free_float_matrix( float** matrix, int rows );

// for printing 

char* counter( int a );
void print_matrix( int** matrix, int rows, int columns );
void print_float_matrix( float** matrix, int rows, int columns );
void print_vector( int* matrix, int length );