//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024 // Max size of a line in the e-book
#define MAX_WORD_SIZE 64 // Max size of a word in the e-book
#define MAX_WORDS 10000 // Max number of words in the e-book

// Structure to hold e-book information
typedef struct {
    char title[MAX_LINE_SIZE];
    char author[MAX_LINE_SIZE];
    int num_words;
    char words[MAX_WORD_SIZE][MAX_LINE_SIZE];
} EBook;

// Function to read e-book from file
EBook* readEBook(FILE* file) {
    EBook* ebook = (EBook*) malloc(sizeof(EBook));

    // Read title and author
    fscanf(file, "Title: %[^\n]\n", ebook->title);
    fscanf(file, "Author: %[^\n]\n", ebook->author);

    // Read number of words
    fscanf(file, "Number of words: %d\n", &ebook->num_words);

    // Read words
    for (int i = 0; i < ebook->num_words; i++) {
        fscanf(file, "Word %d: %[^\n]\n", i+1, ebook->words[i]);
    }

    return ebook;
}

// Function to search for a word in the e-book
int searchWord(EBook* ebook, char* word) {
    int count = 0;

    // Search for word in each line
    for (int i = 0; i < ebook->num_words; i++) {
        if (strstr(ebook->words[i], word)) {
            count++;
        }
    }

    return count;
}

// Main function
int main() {
    // Open e-book file
    FILE* file = fopen("example.ebook", "r");
    if (file == NULL) {
        printf("Error opening e-book file.\n");
        exit(1);
    }

    // Read e-book from file
    EBook* ebook = readEBook(file);
    fclose(file);

    // Search for word in e-book
    char word[MAX_WORD_SIZE];
    printf("Enter word to search for: ");
    scanf("%s", word);
    int count = searchWord(ebook, word);

    if (count == 0) {
        printf("Word not found in e-book.\n");
    } else {
        printf("Word found %d times in e-book.\n", count);
    }

    return 0;
}