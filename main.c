// essentials 
#include "./assets/essentials.c"


// Opérations arithmétiques sur les matrices
#include "./arithmetic/arithmetic.c"


// Other Matrices Operations
#include "./other-matrix-operations/other-matrix-operations.c"


// Matrices Strings And Linked Lists

#include "./matrices-strings-linked-lists/matrices-strings-linked-lists.c"

int main() {

    int operation_type;

    puts( "[ CREATORS ]" );
    puts( "=================================================================" );

    puts(" __  __  ___  _   _ ____ _____  _    _____ _" );
    puts("|  \\/  |/ _ \\| | | / ___|_   _|/ \\  |  ___/ \\   " );
    puts("| |\\/| | | | | | | \\___ \\ | | / _ \\ | |_ / _ \\  " );
    puts("| |  | | |_| | |_| |___) || |/ ___ \\|  _/ ___ \\ " );
    puts("|_|__|_|\\___/ \\___/|____/ |_/_/ __\\_\\_|/_/   \\_\\" );
    puts("| __ )|  _ \\    / \\  | | | |_ _|  \\/  |_ _|     " );
    puts("|  _ \\| |_) |  / _ \\ | |_| || || |\\/| || |      " );
    puts("| |_) |  _ <  / ___ \\|  _  || || |  | || |      " );
    puts("|____/|_| \\_\\/_/   \\_\\_| |_|___|_|  |_|___|     " );


    puts( "=================================================================" );




    printf( "\n\n\n\n" );

    puts( "1. arithmetic operations on matrices" );
    puts( "2. other operations on matrices" );
    puts( "3. string and linked lists" );
    puts( "4. quit" );

    do {

        scanf( "%d", &operation_type );


    } while( operation_type  > 4 || operation_type < 0 );

    switch ( operation_type ) {

        case 1:

            arithmetic();

            break;

        case 2:

            other_matrix_operations();

            break;

        case 3:

            matrices_strings_linked_lists();
            break;


        case 4:
            break;

    }

    puts( "\n" );

    return 0;

}