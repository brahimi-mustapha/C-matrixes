

// words to matrix

#include "./words-matrix/words-matrix.c"

// matrix to vector

#include "./words-matrix-vector/words-matrix-vector.c"

// // alphabetic vector

#include "./words-organizer/words-organizer.c"


//

#include "./words-organizer-add-remove/words-organizer-add-remove.c"

void matrices_strings_linked_lists() {

    int operation_type;
    
    printf( "__________\n\n" );
    puts( "=> 1. create words matrix" );
    puts( "=> 2. create words vector" );
    puts( "=> 3. create words structre" );
    puts( "=> 4. add/remove word from the structure" );

    do {

        scanf( "%d", &operation_type );


    } while( operation_type  > 4 || operation_type < 0 );

    switch ( operation_type ) {

        case 1:
            do_words_matrix();
            break;

        case 2:

            do_words_matrix_vector();
            break;

        case 3:

            do_organize_words();
            break;


        case 4:
            do_add_remove_words_organizer();
            break;
        

    }

}