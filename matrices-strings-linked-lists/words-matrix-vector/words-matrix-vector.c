#include "./words-matrix-vector.h"


word_element** words_matrix_vector( char* text ) {

    int     words_count =   text_words_count( text );
    char    **matrix    =   words_matrix( text );

    word_element**  
            vector      =   ( word_element** )malloc( words_count * sizeof( word_element* ) );

    for ( int iterator = 0; iterator < words_count;  iterator += 1 ) {

        vector[ iterator ]   =   ( word_element* )malloc( sizeof( word_element ) );
        vector[ iterator ]->word     =   matrix[ iterator ]; 
        vector[ iterator ]->next  =   NULL; 

    }

    free( matrix );

    return vector;

}

void do_words_matrix_vector() {

    char* text              =   scan_text( 500 );;
    word_element **vector   =   words_matrix_vector( text );
    int     words_count     =   text_words_count( text );

    for( int iterator = 0; iterator < words_count; iterator += 1 ) {

        puts( vector[ iterator ]->word );
        free( vector[ iterator ]->word );
        free( vector[ iterator ] );

    }

    free( vector );

}
