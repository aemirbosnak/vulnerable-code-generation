//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of lines in the ebook
#define MAX_LINES 1000

// Define the maximum length of a line in the ebook
#define MAX_LINE_LENGTH 1000

// Define the structure of an ebook
typedef struct {
    char* lines[MAX_LINES];
    int num_lines;
} Ebook;

// Function to read an ebook from a file
Ebook* read_ebook(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open ebook file.\n");
        exit(1);
    }

    Ebook* ebook = (Ebook*)malloc(sizeof(Ebook));
    ebook->num_lines = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        ebook->lines[ebook->num_lines++] = strdup(line);
    }

    fclose(file);
    return ebook;
}

// Function to display an ebook
void display_ebook(Ebook* ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        printf("%s", ebook->lines[i]);
    }
}

// Function to search for a word in an ebook
int search_ebook(Ebook* ebook, const char* word) {
    int count = 0;
    for (int i = 0; i < ebook->num_lines; i++) {
        char* line = ebook->lines[i];
        char* token = strtok(line, " ");
        while (token!= NULL) {
            if (strcmp(token, word) == 0) {
                count++;
            }
            token = strtok(NULL, " ");
        }
    }
    return count;
}

int main() {
    Ebook* ebook = read_ebook("ebook.txt");
    display_ebook(ebook);
    int word_count = search_ebook(ebook, "the");
    printf("The word 'the' appears %d times in the ebook.\n", word_count);
    return 0;
}