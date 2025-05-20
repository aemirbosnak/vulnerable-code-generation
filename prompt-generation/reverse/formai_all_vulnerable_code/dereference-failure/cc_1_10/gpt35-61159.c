//FormAI DATASET v1.0 Category: Spell checking ; Style: light-weight
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define DICTIONARY_CAPACITY 10000

char *dictionary[DICTIONARY_CAPACITY]; // holds the words in the dictionary
int word_count = 0; // counter to keep track of how many words are in the dictionary

// function prototypes
int is_misspelled(char *word);
void add_to_dictionary(char *word);

// main program loop
int main() {

    // start by loading the dictionary from file
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, fp)) != -1) {
        // remove newline character from end of line
        line[strcspn(line, "\n")] = '\0';
        add_to_dictionary(line);
    }
    fclose(fp);
    if (line) {
        free(line);
    }

    // read user input from stdin and check for spelling errors
    printf("Type some text and press enter to check for spelling errors.\n");
    while (1) {
        char input[MAX_WORD_LENGTH+1];
        printf("> ");
        fgets(input, MAX_WORD_LENGTH+1, stdin);
        // remove newline character from end of input
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "exit") == 0) {
            // exit program if user types "exit"
            break;
        }
        char *word = strtok(input, " "); // tokenize input into words
        while (word != NULL) {
            if (is_misspelled(word)) {
                printf("%s is misspelled.\n", word);
            }
            word = strtok(NULL, " ");
        }
    }

    // free memory used for dictionary
    for (int i = 0; i < word_count; i++) {
        free(dictionary[i]);
    }

    return 0;
}

// function to check if a word is in the dictionary
int is_misspelled(char *word) {
    int start = 0;
    int end = word_count-1;
    while (start <= end) { // binary search
        int mid = (start + end) / 2;
        int cmp = strcmp(word, dictionary[mid]);
        if (cmp == 0) {
            return 0; // word was found in dictionary
        }
        else if (cmp < 0) {
            end = mid-1;
        }
        else {
            start = mid+1;
        }
    }
    return 1; // word was not found in dictionary
}

// function to add a word to the dictionary
void add_to_dictionary(char *word) {
    dictionary[word_count] = malloc(strlen(word)+1); // allocate memory for string
    strcpy(dictionary[word_count], word); // copy string to dictionary
    word_count++;
}