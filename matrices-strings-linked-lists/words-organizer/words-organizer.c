#include "./words-organizer.h"

words_vector_element* init_words_vector() {

    char letter   =   'a';

    words_vector_element *vector    =   ( words_vector_element* )malloc( 26 * sizeof( words_vector_element ) );


    for( int iterator = 0; iterator < 26; iterator += 1 ) {

        vector[ iterator ].letter   =   letter + iterator;
        vector[ iterator ].next     =   NULL;

    }

    return vector;


}

int element_exist( word_element *head, char *word  ) {

    word_element *walkthrough   =   head;

    while ( walkthrough != NULL ) {

        if( strcmp( walkthrough->word, word ) == 0 ) {

            return  1;

        }

        walkthrough =   walkthrough->next;

    }
    
    return 0;

}

void insert_word_to_vector( words_vector_element *orginazed_vector, word_element *word ) {

    for( int iterator = 0; iterator < 26; iterator += 1 ) {

        if( orginazed_vector[ iterator ].letter == word->word[ 0 ] ) {

            if( orginazed_vector[ iterator ].next == NULL ) {

                orginazed_vector[ iterator ].next   =   word;

            } else if( element_exist( orginazed_vector[ iterator ].next, word->word ) == 0 ) {

                word->next  =   orginazed_vector[ iterator ].next;
                orginazed_vector[ iterator ].next   =   word;

            }

        }

    }

}

words_vector_element* orginize_words( char* text ) {


    char
        *lowercase_text     =   text_to_lower_case( text );

    word_element            
        **vector            =   words_matrix_vector( lowercase_text ), *holder;
    
    words_vector_element    
        *orginazed_vector   =   init_words_vector();

    int                     
        words_count         =   text_words_count( lowercase_text );


    for( int iterator = 0; iterator < words_count; iterator += 1 ) {

        insert_word_to_vector( orginazed_vector, vector[ iterator ] );
        
    }
    
    return orginazed_vector;    

}

void print_originzed_words_vector( words_vector_element * orginazed_words_vector ) {

    word_element    *walkthrough;

    for ( int  iterator = 0; iterator < 26; iterator += 1 )  {

        if( orginazed_words_vector[ iterator ].next == NULL ) {
            continue;
        }

        walkthrough     =   orginazed_words_vector[ iterator ].next;

        printf( "%c \n", toupper( orginazed_words_vector[ iterator ].letter ) );

        while( walkthrough != NULL ) {

            printf( "\t%s\n", walkthrough->word );

            walkthrough =   walkthrough->next;

        }

    }

}

void free_originzed_words_vector( words_vector_element * orginazed_words_vector ) {

    word_element    *walkthrough, *next;

    for ( int  iterator = 0; iterator < 26; iterator += 1 )  {

        walkthrough     =   orginazed_words_vector[ iterator ].next;

        while( walkthrough != NULL ) {

            next        =   walkthrough->next;
            free( walkthrough );
            walkthrough =   next;

        }

    }

    free( orginazed_words_vector );

}

void do_organize_words() {

    char *text      =   scan_text( 500 );

    int words_count =   text_words_count( text );

    words_vector_element *orginazed   =  orginize_words( text );
    
    print_originzed_words_vector( orginazed );

    free_originzed_words_vector( orginazed );


}