//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of an ebook
typedef struct {
    char title[100];
    char author[100];
    char pages[100];
    char publisher[100];
} ebook_t;

// Function to read an ebook file
ebook_t* read_ebook(char* filename) {
    ebook_t* ebook = (ebook_t*) malloc(sizeof(ebook_t));
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[100];
    while (fgets(line, sizeof(line), file)!= NULL) {
        // Skip the first line, which is the title
        if (strncmp(line, "Title:", 6) == 0) {
            fgets(line, sizeof(line), file);
            fgets(ebook->title, sizeof(ebook->title), file);
        } else if (strncmp(line, "Author:", 6) == 0) {
            fgets(line, sizeof(line), file);
            fgets(ebook->author, sizeof(ebook->author), file);
        } else if (strncmp(line, "Pages:", 6) == 0) {
            fgets(line, sizeof(line), file);
            fgets(ebook->pages, sizeof(ebook->pages), file);
        } else if (strncmp(line, "Publisher:", 10) == 0) {
            fgets(line, sizeof(line), file);
            fgets(ebook->publisher, sizeof(ebook->publisher), file);
        }
    }
    fclose(file);
    return ebook;
}

// Function to print an ebook
void print_ebook(ebook_t* ebook) {
    printf("Title: %s\n", ebook->title);
    printf("Author: %s\n", ebook->author);
    printf("Pages: %s\n", ebook->pages);
    printf("Publisher: %s\n", ebook->publisher);
}

// Function to search for a word in an ebook
int search_word(ebook_t* ebook, char* word) {
    int count = 0;
    char buffer[100];
    int len = strlen(word);
    for (int i = 0; i < strlen(ebook->title); i++) {
        if (strcmp(word, ebook->title + i) == 0) {
            count++;
        }
    }
    for (int i = 0; i < strlen(ebook->author); i++) {
        if (strcmp(word, ebook->author + i) == 0) {
            count++;
        }
    }
    for (int i = 0; i < strlen(ebook->pages); i++) {
        if (strcmp(word, ebook->pages + i) == 0) {
            count++;
        }
    }
    for (int i = 0; i < strlen(ebook->publisher); i++) {
        if (strcmp(word, ebook->publisher + i) == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    ebook_t* ebook = read_ebook("example.txt");
    if (ebook == NULL) {
        printf("Error reading file\n");
        exit(EXIT_FAILURE);
    }
    print_ebook(ebook);
    printf("Number of occurrences of word 'apple': %d\n", search_word(ebook, "apple"));
    printf("Number of occurrences of word 'banana': %d\n", search_word(ebook, "banana"));
    return 0;
}