#include "./words-matrix.h"

char** words_matrix( char* text ) {

    // [ ALERT ] This Fonction might be a litte bit complicated but this is the best way to conserve memory

    int     iterator            =   1,
            matrix_iterator     =   0,
            word_length         =   0,
            text_length         =   strlen( text );


    // the text could be one single word
    char    **matrix    =   ( char** )malloc( sizeof( char * ) * text_words_count( text ) ),
            *holder     =   ( char* )malloc( sizeof( char ) * text_length ),
            space       =   ' ',
            *word;

    if( text[0] != space ) {

        holder[0]   =   text[0];
        word_length =   1;

    }

    while( iterator < text_length ) {

        if( ( text[ iterator - 1 ] != space && text[ iterator ] == space ) || ( iterator == ( text_length - 1 ) && text[ iterator ] != space  ) /* for the last word */ ) {

            // add the last char of the text to the word holder
            if( iterator == ( text_length - 1 ) ) {
                holder[ word_length ]   =   text[ iterator ];
            }

            // add the new word to the matrix 
            word                        =   ( char* )malloc( sizeof( char ) * strlen( holder ) );
            strcpy( word, holder );
            matrix[ matrix_iterator ]   =   word;
            matrix_iterator             +=  1;

            // reset variables for the next word
            free( holder );
            word_length     =   0;
            holder          =   ( char* )malloc( sizeof( char ) * /* if the rest of the text is a single word */ ( text_length - iterator ) ); 


        } else {

            // crafting the new word
            if( text[ iterator ] != space ) {

                holder[ word_length ]   =   text[ iterator ];
                word_length             +=  1;

            }

        }

        iterator += 1;

    }


    free( holder );

    return matrix;

}

void do_words_matrix() {

    char *text, **matrix;
    int words_count;

    text        =   scan_text( 500 );
    matrix      =   words_matrix( text );
    words_count =   text_words_count( text );

    puts( "[ your text words ]" );

    for( int iterator = 0; iterator < words_count; iterator += 1 ) {

        puts( matrix[iterator] );
        free( matrix[iterator] );

    }

    free( matrix );

}