#include "essentials.h"

// for allocation

int* allocate_vector( int length ) {

    if( length == 0 ) {
        return NULL;
    }

    return (int*) malloc( length * sizeof(int) );
}

int** allocate_matrix( int rows ) {

    if( rows == 0 ) {
        return NULL;
    }

    return ( int** )malloc( rows * sizeof( int* ) );

}

// for creation

int* create_vector( int length ) {

    if( length == 0 ) {
        return NULL;
    }

    int *vector;

    vector   =   allocate_vector( length );

    for( int iteration = 0; iteration < length ; iteration += 1 ) {

        printf( "  enter the %d%s value: ", ( iteration + 1 ), counter( iteration + 1 ) );
        scanf( "%d", &vector[ iteration ] );

    }

    return vector;
}

int** create_matrix( int rows, int columns ) { 

    if( rows == 0 || columns == 0 ) {
        return NULL;
    }

    int **matrix;

    matrix  =   allocate_matrix( rows );

    for( int iteration = 0; iteration < rows; iteration += 1 ) {

        printf( "\n[ %d%s row ]\n", ( iteration + 1 ), counter( iteration + 1 ) );

        matrix[iteration]   =   create_vector( columns );

    }

    return matrix;

}

// for scanning

int** scan_matrix( int* rows, int* columns ) {

    puts( "please enter your matrix rows count" );
    scanf( "%d", rows );
    
    puts( "please enter your matrix columns count" );
    scanf( "%d", columns );


    if( rows == 0 || columns == 0 ) {
        return NULL;
    }

    return create_matrix( *rows, *columns );

}

char* scan_text( int text_length ) {

    char *text;

    text    =   ( char* )malloc( sizeof( char ) * text_length );

    puts( "Enter Your Text : " );
    fflush( stdin );

    // i found that [^\n] online  https://www.includehelp.com/c/c-program-to-read-string-with-spaces-using-scanf-function.aspx
    scanf( "%[^\n]", text );
    
    fflush( stdin );

    return text;

}

// text utilities

int text_words_count( char *text ) {

    char    space       =   ' ';
    int     counter     =   ( text[ 0 ] == space ? 0 : 1 );

    if( strlen( text ) == 0 ) {

        return 0;

    }

    for( int iterator = 1; iterator < strlen( text ); iterator += 1 ) {

        if( text[ iterator ] != space && text[ iterator - 1 ] == space ){

            counter +=  1;

        }
    
    }

    return counter;

}

char* text_to_lower_case( char *text ) {

    char* lowercase_text;
    int text_length =   strlen( text );

    lowercase_text  =   ( char* )malloc( text_length * sizeof( char ) );

    for( int iterator = 0; iterator < text_length; iterator += 1 ) {

        lowercase_text[ iterator ]  =   tolower( text[ iterator ] );

    }

    return lowercase_text;

}

// for clear memory

void free_matrix( int** matrix, int rows ) {

    for( int row = 0; row < rows; row += 1 ) {

        free( matrix[ row ] );

    }

    free( matrix );

}

void free_float_matrix( float** matrix, int rows ) {

    for( int row = 0; row < rows; row += 1 ) {

        free( matrix[ row ] );

    }

    free( matrix );

}

// for printing

char* counter( int a ) {

    if( ( a / 10 ) % 10 == 1 ) {

        return "th";

    } else if ( ( a % 10 ) == 1 ) {

        return "st";

    }
    else if ( ( a % 10 ) == 2 ) {

        return "nd";

    }
    else if ( ( a % 10 ) == 3 ) {

        return "rd";

    } else {

        return "th";

    }

}

void print_matrix( int** matrix, int rows, int columns ) {

    for( int row = 0; row < rows; row += 1 ) {

        for( int column = 0; column < columns; column += 1 ) {

            printf( "%d \t", matrix[ row ][ column ] );

        }

        printf( "\n" );

    }

}

void print_float_matrix( float** matrix, int rows, int columns ) {

    for( int row = 0; row < rows; row += 1 ) {

        for( int column = 0; column < rows; column += 1 ) {

            printf( "%.2f \t", matrix[ row ][ column ] );

        }

        printf( "\n" );

    }

}

void print_vector( int* matrix, int length ) {

    for( int iterator = 0; iterator < length; iterator += 1 ) {

        printf( "%d \t", matrix[ iterator ] );

    }

    printf( "\n" );

} 

