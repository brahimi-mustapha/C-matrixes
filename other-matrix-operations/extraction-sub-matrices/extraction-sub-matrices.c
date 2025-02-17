#include "./extraction-sub-matrices.h"

int** extract_sub_matrix( int** matrix, int offset_row, int offset_column, int rows_length, int columns_length ) {

    // forbidden cases

    if( rows_length < 1 || columns_length < 1 ) {

        return NULL;

    }

    int **extracted;

    extracted   =   allocate_matrix( rows_length );

    for( int row =  0; row < rows_length; row += 1 ) {

        extracted[ row ]    =   allocate_vector( columns_length );

        for( int column = 0; column < columns_length; column += 1 ) {

            extracted[ row ][ column ]  =   matrix[ offset_row + row ][ offset_column + column ];

        }

    }

    return extracted;

}

int*** extract_sub_matrices( int** matrix, int rows, int columns, int sub_rows, int sub_columns ) {



    // forbidden cases

    if( sub_rows > rows || sub_columns > columns ) {

        return NULL;

    }

    int ***matrices, sub_matrices_columns_count, sub_matrices_rows_count, iterator;
    
    sub_matrices_columns_count  =   columns - ( sub_columns - 1 );
    sub_matrices_rows_count     =   rows - ( sub_rows - 1 );
    iterator                    =   0;

    matrices    =   (int***)malloc( sub_matrices_columns_count * sub_matrices_rows_count * sizeof( int** ) );
    


    for( int row = 0; row <= ( rows - sub_rows ); row += 1 ) {

        for( int column = 0; column <= ( columns - sub_columns ); column += 1 ) {

            matrices[ iterator ] = extract_sub_matrix( matrix, row, column, sub_rows, sub_columns );
            iterator    +=  1;
        }

    }
 
    return matrices; 

}

void do_extract_sub_matrices(){

    int ***matrices, **matrix, rows, columns, sub_columns, sub_rows;

    matrix  =   scan_matrix( &rows, &columns );

    fflush( stdin );


    do {

        puts( "enter the rows of the sub matrix that you would extract" );
        scanf( "%d", &sub_rows );


        fflush( stdin );

        puts( "enter the columns of the sub matrix that you would extract" );
        scanf( "%d", &sub_columns );

        fflush( stdin );

        if( sub_columns > columns || sub_rows > rows ) {

            printf( "\033[0;31m" );
            puts( "[ WARNING ] : obviously you can't extract a sub matrix bigger than the original matrix ( *3* ), please renter the values ");
            printf( "\033[0m" ); 

        } else if( sub_columns < 1 || sub_rows < 1 ) {

            printf( "\033[0;31m" );
            puts( "[ WARNING ] : you can't extract a matrix with ( 0x0 ) dimensions ( *3* ), please renter the values ");
            printf( "\033[0m" ); 

        }
    
    
    } while( sub_columns > columns || sub_columns < 1 || sub_rows > rows || sub_rows < 1 );

    matrices    =   extract_sub_matrices( matrix, rows, columns, sub_columns, sub_rows );

    for( int iterator = 0; iterator < ( columns - ( sub_columns - 1 ) ) * ( rows - ( sub_rows - 1 ) ); iterator += 1 ) {

        print_matrix( matrices[ iterator ], sub_rows, sub_columns );
        puts( "============" );
        free_matrix( matrices[ iterator ], sub_rows );

    }

    free_matrix( matrix, rows );


}