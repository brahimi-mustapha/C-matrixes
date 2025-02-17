
#include "./multiplication-matrix-matrix.h"

int** mutliply_matrix_matrix( int** matrix_a, int rows_a, int columns_a ,int** matrix_b, int rows_b, int columns_b ) {

    int **result, sum;

    result  =   allocate_matrix( rows_a );

    for( int row = 0; row < rows_a; row += 1 ) {

        result[ row ]   =   allocate_vector( columns_b );

        for( int column = 0; column < columns_b; column += 1 ) {

            sum     =   0;

            for( int sub_column = 0; sub_column < columns_a; sub_column += 1 ) {

                sum     +=  matrix_a[row][sub_column] * matrix_b[sub_column][column];

            }

            result[ row ][ column ] = sum;

        
        }

    }

    return result; 


}

void do_mutliply_matrix_matrix() {

    int **matrix_a, **matrix_b, **result, rows_a, rows_b, columns_a, columns_b;

    puts( "enter the first matrix info" );
    matrix_a    =   scan_matrix( &rows_a, &columns_a );

    puts( "enter the second matrix info" );
    matrix_b    =   scan_matrix( &rows_b, &columns_b );

    result      =   mutliply_matrix_matrix( matrix_a, rows_a, columns_a, matrix_b, rows_b, columns_b );

    puts( "\n[ Result ]" );
    print_matrix( result, rows_a, columns_b );

    free_matrix( result, rows_a );
    free_matrix( matrix_a, rows_a );
    free_matrix( matrix_b, rows_b );

}