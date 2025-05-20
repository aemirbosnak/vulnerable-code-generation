//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define a struct to hold each word and its frequency
typedef struct word_t {
    char* word;
    int freq;
} word_t;

// Function to convert a string to lowercase
void str_to_lowercase(char* str) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

// Function to check if a character is a word character
int is_word_char(char c) {
    return isalpha(c) || isdigit(c) || c == '\'' || c == '-';
}

// Function to read input text from a file into a buffer
char* read_input_text(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return NULL;
    }

    // Get the file size
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for the buffer
    char* buffer = calloc(size + 1, sizeof(char));
    if (buffer == NULL) {
        printf("Error: Memory allocation failed\n");
        fclose(fp);
        return NULL;
    }

    // Read the file into the buffer
    long bytes_read = 0;
    while (!feof(fp)) {
        bytes_read += fread(buffer + bytes_read, 1, size - bytes_read, fp);
    }

    // Close the file and return the buffer
    fclose(fp);
    return buffer;
}

// Function to split a text string into words and count their frequency
word_t* count_word_frequency(const char* text, int* num_words) {
    // Allocate memory for an array of word_t structs
    word_t* word_list = calloc(1, sizeof(word_t));
    if (word_list == NULL) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    
    // Loop through the text string, counting the frequency of each word
    int text_len = strlen(text);
    int word_start = 0;
    int i;
    for (i = 0; i < text_len; i++) {
        if (is_word_char(text[i])) {
            // The current character is part of a word
            if (word_start == -1) {
                // This is the start of a new word - record its position
                word_start = i;
            }
        } else {
            // The current character is not part of a word
            if (word_start != -1) {
                // We have found the end of a word - add it to the word list
                int word_len = i - word_start;
                char* word = calloc(word_len + 1, sizeof(char));
                if (word == NULL) {
                    printf("Error: Memory allocation failed\n");
                    free(word_list);
                    return NULL;
                }

                strncpy(word, &text[word_start], word_len);
                str_to_lowercase(word);

                int word_index = -1;
                int j;
                for (j = 0; j < *num_words; j++) {
                    if (strcmp(word_list[j].word, word) == 0) {
                        word_index = j;
                        break;
                    }
                }

                if (word_index == -1) {
                    // This is a new word - add it to the word list
                    word_list = realloc(word_list, (*num_words + 1) * sizeof(word_t));
                    if (word_list == NULL) {
                        printf("Error: Memory allocation failed\n");
                        free(word);
                        free(word_list);
                        return NULL;
                    }

                    word_list[*num_words].word = word;
                    word_list[*num_words].freq = 1;
                    (*num_words)++;
                } else {
                    // This is an existing word - increment its frequency
                    word_list[word_index].freq++;
                    free(word);
                }

                // Reset the word start position
                word_start = -1;
            }
        }
    }

    // If the text ends with a word, we need to add it to the word list now
    if (word_start != -1) {
        int word_len = i - word_start;
        char* word = calloc(word_len + 1, sizeof(char));
        if (word == NULL) {
            printf("Error: Memory allocation failed\n");
            free(word_list);
            return NULL;
        }

        strncpy(word, &text[word_start], word_len);
        str_to_lowercase(word);

        int word_index = -1;
        int j;
        for (j = 0; j < *num_words; j++) {
            if (strcmp(word_list[j].word, word) == 0) {
                word_index = j;
                break;
            }
        }

        if (word_index == -1) {
            // This is a new word - add it to the word list
            word_list = realloc(word_list, (*num_words + 1) * sizeof(word_t));
            if (word_list == NULL) {
                printf("Error: Memory allocation failed\n");
                free(word);
                free(word_list);
                return NULL;
            }

            word_list[*num_words].word = word;
            word_list[*num_words].freq = 1;
            (*num_words)++;
        } else {
            // This is an existing word - increment its frequency
            word_list[word_index].freq++;
            free(word);
        }
    }

    return word_list;
}

// Function to print out the word frequency list
void print_word_frequency(const word_t* word_list, int num_words) {
    printf("%-20s %s\n", "Word", "Frequency");
    printf("--------------------------------------------\n");
    
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%-20s %d\n", word_list[i].word, word_list[i].freq);
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Error: Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    char* text = read_input_text(argv[1]);
    if (text == NULL) {
        return 1;
    }

    int num_words = 0;
    word_t* word_list = count_word_frequency(text, &num_words);
    if (word_list == NULL) {
        free(text);
        return 1;
    }

    print_word_frequency(word_list, num_words);

    // Free memory and exit
    int i;
    for (i = 0; i < num_words; i++) {
        free(word_list[i].word);
    }

    free(word_list);
    free(text);
    return 0;
}