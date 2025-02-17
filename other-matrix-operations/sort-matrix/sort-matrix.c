#include "./sort-matrix.h"

int** sort_matrix( int **matrix, int rows, int columns, int sort_type ) {

    int **sorted, *flat, holder, modified = 1;
    
    flat        =   allocate_vector( rows * columns );

    // transform the matrix into a flat array

    for( int row = 0; row < rows; row += 1 ) {

        for( int column = 0; column < columns; column += 1 ) {
            
            flat[ row * columns + column ]    =   matrix[ row ][ column ];

        }

    }

    // sort the flat array

    while( modified == 1 ) {

        modified = 0;

        for( int iterator = 0; iterator < ( rows * columns - 1 ); iterator += 1 ) { 

            if( sort_type == 0 ) {
            
                if( flat[ iterator ] > flat[ iterator + 1 ] ) {

                    holder              =   flat[ iterator ];
                    flat[ iterator ]    =   flat[ iterator + 1 ];
                    flat[ iterator + 1 ]=   holder;
                    modified            =   1;
                    
                }
            
            } else if( sort_type == -1 ) {

                if( flat[ iterator ] < flat[ iterator + 1 ] ) {

                    holder              =   flat[ iterator ];
                    flat[ iterator ]    =   flat[ iterator + 1 ];
                    flat[ iterator + 1 ]=   holder;
                    modified            =   1;
                    
                }

            }

        }

    }

    // transform the flat array into a matrix

    sorted  =   allocate_matrix( rows );

    for( int row = 0; row < rows; row += 1 ) {

        sorted[ row ]   =   allocate_vector( columns );

        for( int column = 0; column < columns; column += 1 ) {
            
            sorted[ row ][ column ] =   flat[ row * columns + column ] ;

        }

    }

    free( flat );

    return sorted;

}

int** sort_matrix_ascending( int **matrix, int rows, int columns ) {

    return sort_matrix( matrix, rows, columns, 0 );

}

int** sort_matrix_descending( int **matrix, int rows, int columns ) {

    return sort_matrix( matrix, rows, columns, -1 );

}

void do_sort_matrix() {

    int **matrix, **sorted, rows, columns;
    char    operation_type;

    fflush( stdin );

    do {

        puts( "ascending or descending [a/d]" );
        scanf( "%c", &operation_type );
        fflush( stdin );


    } while( operation_type != 'a' && operation_type != 'd' && operation_type != 'A' && operation_type != 'D' );
    
    matrix  =   scan_matrix( &rows, &columns );

    switch ( operation_type ) {
            
        case 'a':
        case 'A':

            sorted  =   sort_matrix_ascending( matrix, rows, columns );

            break;
        
        case 'd':
        case 'D':

            sorted  =   sort_matrix_descending( matrix, rows, columns );

            break;
    
    }

    print_matrix( sorted, rows, columns );

    free_matrix( sorted, rows );
    free_matrix( matrix, rows );

    return;

}