#include "./multiplication-number-matrix.h"

int** multiply_matrix_number( int** matrix, int rows, int columns, int multiplier ) {

    int** result;

    result  =   allocate_matrix( rows );
    
    for( int row = 0; row < rows; row += 1 ) {

        result[ row ]   =   allocate_vector( columns );

        for( int column = 0; column < columns; column += 1 ) {

            result[ row ][ column ] =   matrix[ row ][ column ] * multiplier;

        }

    }

    return result;

}


void do_multiply_matrix_number() {

    int     **matrix, **result;
    int     rows, columns, multiplier;

    matrix   =   scan_matrix( &rows, &columns );

    puts( "please enter the multiplier" );

    scanf( "%d", &multiplier );

    result  =   multiply_matrix_number( matrix, rows, columns, multiplier );

    puts( "\n[ result ]" );
    print_matrix( result, rows, columns );
    puts( "\n" );
    free_matrix( result, rows );
    free_matrix( matrix, rows );


}