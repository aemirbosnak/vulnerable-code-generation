//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 80
#define MAX_WORD_LENGTH 20
#define MAX_WORDS_PER_LINE 10

// Function to read a line from the file
char* read_line(FILE* file) {
    char* line = (char*) malloc(MAX_LINE_LENGTH * sizeof(char));
    fgets(line, MAX_LINE_LENGTH, file);
    line[strcspn(line, "\n")] = '\0';
    return line;
}

// Function to split a line into words
char** split_line(char* line) {
    int num_words = 0;
    char* word = strtok(line, " ");
    char** words = (char**) malloc(MAX_WORDS_PER_LINE * sizeof(char*));

    while (word!= NULL) {
        if (num_words >= MAX_WORDS_PER_LINE) {
            break;
        }
        words[num_words] = (char*) malloc(MAX_WORD_LENGTH * sizeof(char));
        strcpy(words[num_words], word);
        num_words++;
        word = strtok(NULL, " ");
    }

    return words;
}

// Function to display a line of words
void display_line(char** words) {
    int i;

    for (i = 0; i < MAX_WORDS_PER_LINE && words[i]!= NULL; i++) {
        printf("%s ", words[i]);
    }
}

// Function to read and display a file
void read_file(char* filename) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    char* line;
    while ((line = read_line(file))!= NULL) {
        char** words = split_line(line);
        display_line(words);
        free(line);
        int i;
        for (i = 0; i < MAX_WORDS_PER_LINE && words[i]!= NULL; i++) {
            free(words[i]);
        }
        free(words);
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    read_file(argv[1]);

    return 0;
}