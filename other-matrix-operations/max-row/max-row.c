#include "./max-row.h"

int* exctract_max_row_vector( int** matrix, int rows, int columns ) {

    int *vector, max;

    vector  =   allocate_vector( rows );

    for( int row = 0; row < rows; row += 1 ) {

        max     =   matrix[ row ][ 0 ];

        for( int column = 1; column < columns; column += 1 ) {

            max     =   ( matrix[ row ][ column ] > max ? matrix[ row ][ column ] : max );
        
        }

        vector[ row ]   =   max;   

    }

    return vector;

}


void do_exctract_max_row_vector( ) {

    int **matrix, *vector, rows, columns;

    matrix  =   scan_matrix( &rows, &columns );
    vector  =   exctract_max_row_vector( matrix, rows, columns );

    print_vector( vector, rows );
    

}
