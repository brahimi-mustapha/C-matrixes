#include "./words-organizer-add-remove.h"


void add_word_to_words_organizer( words_vector_element* organized, char *word ) {

    word_element *element;
    
    element         =   ( word_element* )malloc( sizeof( word_element ) );
    element->word   =   word;
    element->next   =   NULL;

    insert_word_to_vector( organized, element );

}

void remove_word_from_words_organizer( words_vector_element* organized, char *word ) {

    char    a   =   'a';
    int     row =   word[ 0 ] - a;
    word_element 
            *previous,
            *walkthrough;

    if( row > 26 || row < 0 ) {
        return;
    }

    if( element_exist( organized[ row ].next, word ) == 0 ) {

        return;

    }

    if( strcmp( organized[ row ].next->word, word ) == 0 ) {

        organized[ row ].next  =   organized[ row ].next->next;

    } else {

         
        previous       =   organized[ row ].next,
        walkthrough    =   organized[ row ].next->next;

        while( walkthrough != NULL ) {

            if( strcmp( walkthrough->word, word ) == 0 ) {

                previous->next  =   ( walkthrough->next != NULL ? walkthrough->next : NULL );

            } 

            previous    =   previous->next;
            walkthrough =   walkthrough->next;

        }

    }

}

// void remove_word_to_words_organizer( words_vector_element* organized, char *word );


void do_add_remove_words_organizer() {

    char    operation_type,
            *text    =   scan_text( 500 ),
            word[500];


    fflush( stdin );

    do {

        puts( "add or remove [a/r]" );
        scanf( "%c", &operation_type );
        fflush( stdin );


    } while( operation_type != 'a' && operation_type != 'r' && operation_type != 'A' && operation_type != 'R' );


    printf( "enter the word that you want to %s: ", ( operation_type == 'a' || operation_type == 'A' ? "add" : "remove" ) );
    
    scanf( "%s", word );

    words_vector_element *organized;
    
    organized   =  orginize_words( text );
    
    switch ( operation_type ) {

        case 'a':
        case 'A':

            add_word_to_words_organizer( organized, word );
            break;

        
        case 'r':
        case 'R':

            remove_word_from_words_organizer( organized, word );
            break;



    }


    print_originzed_words_vector( organized );

    free_originzed_words_vector( organized );


}