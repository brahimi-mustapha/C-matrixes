// transpose 

#include "./transposition-matrix/transposition-matrix.c"

// sort matrix 
#include "./sort-matrix/sort-matrix.c"


// max ligne vector
#include "./max-row/max-row.c"


// max column vector
#include "./max-column/max-column.c"


// extract sub matrices
#include "./extraction-sub-matrices/extraction-sub-matrices.c"


void other_matrix_operations() {

    int operation_type;
    
    printf( "__________\n\n" );
    puts( "=> 1. transpose matrix" );
    puts( "=> 2. sort a matrix" );
    puts( "=> 3. calculate the vector MAXROW" );
    puts( "=> 4. calculate the vector MAXCOLUMN" );
    puts( "=> 5. exctract sub matrices" );

    do {

        scanf( "%d", &operation_type );


    } while( operation_type  > 5 || operation_type < 0 );

    switch ( operation_type ) {

        case 1:
            do_transpose_matrix();
            break;

        case 2:

            do_sort_matrix();
            break;

        case 3:

            do_exctract_max_row_vector();
            break;


        case 4:
            do_exctract_max_column_vector();
            break;
        
        case 5:
            do_extract_sub_matrices();
            break;

    }


    return;

}