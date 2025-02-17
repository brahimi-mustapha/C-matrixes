#include "./inverse-matrix.h"

int** ignore_matrix_ligne_column( int **matrix, int rows, int columns, int ignored_row, int ignored_column  ) {

    int **new_matrix, new_row, new_column;

    new_matrix  =   allocate_matrix( rows  - 1  );

    new_row     =   0;

    for( int row = 0; row < rows ; row += 1 ) {

        if( row == ignored_row ) { continue; }

        new_column     =   0;

        new_matrix[ new_row ]   =   allocate_vector( columns - 1 );

        for( int column = 0; column < columns; column += 1 ) {

            if( column == ignored_column ) { continue; }

            new_matrix[ new_row ][ new_column ] =   matrix[ row ][ column ];

            new_column  +=  1;

        }

        new_row     +=  1;

    }

    return new_matrix;

}

int matrix_determinant( int **matrix, int width ){

    int determinant     =   0;

    switch ( width ) {

    case 1:

        return matrix[0][0];
        break;
    
    // ===========

    case 2:
    
        return( ( matrix[0][0] * matrix[1][1] ) - ( matrix[0][1] * matrix[1][0] ));
        break;
    
    // ==========

    default:

        for( int column = 0; column < width; column += 1 ) {

            determinant
            
            +=  pow( -1, column ) * 
            
            ( matrix_determinant( 
                
                ignore_matrix_ligne_column( matrix, width, width, 0, column ),
                
                ( width - 1 )
                
            ) * matrix[ 0 ][ column ] );  

        }

        return determinant;

        break;

    }

}

int** matrix_cofactors( int **matrix, int width ) {

    int **result;

    result  =   allocate_matrix( width );


    if( width == 1 ) {

        result[0]       =   allocate_vector( width );
        result[0][0]    =   1;

        return result;
    
    }

    for( int row = 0; row < width; row += 1 ) {

        result[ row ]   =   allocate_vector( width );

        for( int column = 0; column < width; column += 1 ) {

            result[ row ][ column ] =

            pow( -1, column + row ) *

            matrix_determinant(

                ignore_matrix_ligne_column( matrix, width, width, row, column ),
               
                width - 1

            );

        }

    }

    return result;


}

int** matrix_switch_row_column( int **matrix, int width ) {

    int **result;

    result  =   allocate_matrix( width );

    for( int row = 0; row < width; row += 1 ) {

        result[ row ]   =   allocate_vector( width );

        for( int column = 0; column < width; column += 1 ) {

            result[ row ][ column ]     =   matrix[ column ][ row ];

        }

    }

    return result;
}

float** invert_matrix( int **matrix, int width ) {

    int **cofactors, **adj, determinant;

    float **inverted;

    determinant =   matrix_determinant( matrix, width );

    if( determinant == 0 ) {

    
        return NULL;
    
    }

    cofactors   =   matrix_cofactors( matrix, width );

    adj         =   matrix_switch_row_column( cofactors, width );

    inverted    =   (float**)malloc( width * sizeof( float* ) );

    for( int row = 0; row < width; row += 1 ) {

        inverted[ row ] =   (float*)malloc( width * sizeof( float ) );

        for( int column = 0; column < width; column += 1 ) {

            inverted[ row ][ column ]   =   (float)( adj[ row ][ column ] ) / ( float )( determinant );

        }


    }

    free_matrix( cofactors, width );
    free_matrix( adj, width );

    return inverted;

} 

void do_invert_matrix() {

    int **matrix, **switched, **matrix_cofac, width;

    float **inverted;

    puts( "enter the width of your square matrix" );
    scanf( "%d", &width );

    matrix      =   create_matrix( width, width );
    inverted    =   invert_matrix( matrix, width );

    if( inverted == NULL ) {

        puts( "the detrmeninat of your matrix is 0" );

    } else {

        puts( "\n[ RESULT ]" );
        print_float_matrix( inverted, width, width );
        free_float_matrix( inverted, width );

    }

    free_matrix( matrix, width );


}