#include "./max-column.h"

int* exctract_max_column_vector( int** matrix, int rows, int columns ) {

    int *vector, max;

    vector  =   allocate_vector( columns );

    for( int column = 0; column < columns; column += 1 ) {

        max     =   matrix[ 0 ][ column ];
        
        for( int row = 1; row < rows; row += 1 ) {

            max     =   ( matrix[ row ][ column ] > max ? matrix[ row ][ column ] : max );
        
        }

        vector[ column ]   =   max;   

    }

    return vector;

}


void do_exctract_max_column_vector( ) {

    int **matrix, *vector, rows, columns;

    matrix  =   scan_matrix( &rows, &columns );
    vector  =   exctract_max_column_vector( matrix, rows, columns );

    print_vector( vector, columns );

    free( vector );
    

}
