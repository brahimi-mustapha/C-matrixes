
#include "./transposition-matrix.h"

int** transpose_matrix( int** matrix, int rows, int columns ) {

    int **transposed;

    transposed  =   allocate_matrix( columns );


    for( int column = 0; column < columns; column += 1 ) {

        transposed[ column ]   =   allocate_vector( rows );


        for( int row = 0; row < rows; row += 1 ) {

            transposed[ column ][ row ] =   matrix[ row ][ column ];

        }

    }

    return( transposed );


}

void do_transpose_matrix() {

    int **matrix, **transposed;
    int rows, columns;

    matrix      =   scan_matrix( &rows, &columns );
    transposed  =   transpose_matrix( matrix, rows, columns );    

    print_matrix( transposed, columns, rows );

    free_matrix( transposed, columns );
    free_matrix( matrix, rows );

}