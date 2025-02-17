#include "addition-subtraction.h"

int** sum_matrices( int **matrix_a, int **matrix_b, int rows, int columns, int operation ) {

    int **result;

    result  =   allocate_matrix( rows );
    
    for( int row = 0; row < rows; row += 1 ) {

        result[ row ]   =   allocate_vector( columns );

        for( int column = 0; column < columns; column += 1 ) {

            if( operation == 0 ) {

                result[ row ][ column ] =   matrix_a[ row ][ column ]  + matrix_b[ row ][ column ] ;

            } else if ( operation == -1 ) {

                result[ row ][ column ] =   matrix_a[ row ][ column ] - matrix_b[ row ][ column ] ;

            }

        }

    }

    return result; 

}


int** add_matrices( int **matrix_a, int **matrix_b, int rows, int columns ) {

    return sum_matrices( matrix_a, matrix_b,  rows,  columns, 0 ); 

}

int** subtract_matrices( int **matrix_a, int **matrix_b, int rows, int columns ) {

    return sum_matrices( matrix_a, matrix_b,  rows,  columns, -1 ); 

}


void do_sum_matrices() {

    char    operation_type;
    int     **matrix_a, **matrix_b, **result;
    int     rows, columns;

    fflush( stdin );


    do {

        puts( "addition or subtraction [a/s]" );
        scanf( "%c", &operation_type );
        fflush( stdin );


    } while( operation_type != 'a' && operation_type != 's' && operation_type != 'A' && operation_type != 'S' );

    puts( "[ 1nd martix ]" );

    matrix_a   =   scan_matrix( &rows, &columns );

    printf( "\n" );

    puts( "[ 2nd martix ]" );

    matrix_b   =   create_matrix( rows, columns );

    switch ( operation_type ) {
            
        case 'a':
        case 'A':

            result  =   add_matrices( matrix_a, matrix_b, rows, columns );

            break;
        
        case 's':
        case 'S':

            result  =   subtract_matrices( matrix_a, matrix_b, rows, columns );

            break;
    
    }

    puts( "\n[ result ]" );
    print_matrix( result, rows, columns );

    free_matrix( result, rows );
    free_matrix( matrix_a, rows );
    free_matrix( matrix_b, rows );

}


