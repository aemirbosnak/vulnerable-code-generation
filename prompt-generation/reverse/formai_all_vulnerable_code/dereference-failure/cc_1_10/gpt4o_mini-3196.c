//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

typedef struct {
    char *words[MAX_WORDS];
    int count;
} WordList;

// Function to trim whitespace from the start and end of a string
char* trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while(isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    // Null terminate after trailing space
    *(end+1) = '\0';

    return str;
}

// Function to split a line into words
WordList split_into_words(const char *line) {
    WordList wordList;
    wordList.count = 0;
    char copy[MAX_LINE_LENGTH];
    strcpy(copy, line);

    char *token = strtok(copy, " \t\n");
    while(token != NULL && wordList.count < MAX_WORDS) {
        char *word = malloc((strlen(token) + 1) * sizeof(char));
        if (word != NULL) {
            strcpy(word, token);
            wordList.words[wordList.count++] = word;
        } else {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        token = strtok(NULL, " \t\n");
    }
    
    return wordList;
}

// Function to free memory allocated for words
void free_word_list(WordList *wordList) {
    for(int i = 0; i < wordList->count; i++) {
        free(wordList->words[i]);
    }
}

// Function to count the frequency of each word
void count_word_frequency(WordList *wordList) {
    int frequencies[MAX_WORDS] = {0};
    char *uniqueWords[MAX_WORDS];
    int uniqueCount = 0;
    
    for(int i = 0; i < wordList->count; i++) {
        int found = 0;
        for(int j = 0; j < uniqueCount; j++) {
            if(strcmp(uniqueWords[j], wordList->words[i]) == 0) {
                frequencies[j]++;
                found = 1;
                break;
            }
        }
        if(!found) {
            uniqueWords[uniqueCount] = wordList->words[i];
            frequencies[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    printf("Word Frequency Count:\n");
    for(int i = 0; i < uniqueCount; i++) {
        printf("%s: %d\n", uniqueWords[i], frequencies[i]);
    }
}

// Function to read the contents of a file and process the text
void process_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s for reading\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    WordList wordList;
    wordList.count = 0;

    while (fgets(line, sizeof(line), file)) {
        char *trimmed_line = trim_whitespace(line);
        WordList lineWords = split_into_words(trimmed_line);

        for (int i = 0; i < lineWords.count; i++) {
            wordList.words[wordList.count++] = lineWords.words[i];
        }
        free_word_list(&lineWords);
    }

    fclose(file);
    count_word_frequency(&wordList);
    free_word_list(&wordList);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    process_file(argv[1]);
    return EXIT_SUCCESS;
}