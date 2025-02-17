

// addition-subtraction
#include "./addition-subtraction/addition-subtraction.c"

// multiply a matrix by a number
#include "./multiplication-number-matrix/multiplication-number-matrix.c"

// multiply a matrix by matrix
#include "./multiplication-matrix-matrix/multiplication-matrix-matrix.c"



// invert a matrix 
#include "./inverse-matrix/inverse-matrix.c"



int arithmetic( ) {

    int operation_type;
    
    printf( "__________\n\n" );
    puts( "=> 1. add/subtract 2 matrices" );
    puts( "=> 2. multiply matrix by a number" );
    puts( "=> 3. multiply matrix by a matrix" );
    puts( "=> 4. invert a matrix" );

    do {

        scanf( "%d", &operation_type );


    } while( operation_type  > 4 || operation_type < 0 );

    switch ( operation_type ) {

        case 1:
            do_sum_matrices();
            break;

        case 2:

            do_multiply_matrix_number();
            break;

        case 3:

            do_mutliply_matrix_matrix();
            break;


        case 4:
            do_invert_matrix();
            break;

    }


    return 0;

}