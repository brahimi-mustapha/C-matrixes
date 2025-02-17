words_vector_element* init_words_vector();

int element_exist( word_element *head, char *word  );

void insert_word_to_vector( words_vector_element *orginized_vector, word_element *word );

words_vector_element* orginize_words( char* text );

void print_originzed_words_vector( words_vector_element * orginized_words_vector );

void do_organize_words();