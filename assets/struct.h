


typedef struct word_element {

    char * word;
    struct word_element* next;

} word_element ;

typedef struct {

    char letter;
    struct word_element* next;

} words_vector_element;