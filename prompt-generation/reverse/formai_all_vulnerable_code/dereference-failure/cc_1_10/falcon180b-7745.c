//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024 // Maximum length of a line in the eBook

// eBook data structure
typedef struct {
    char* title;
    char* author;
    char* content;
    int num_pages;
} eBook;

// Function to read the eBook data from a file
eBook* read_eBook(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return NULL;
    }

    eBook* ebook = malloc(sizeof(eBook));
    ebook->title = NULL;
    ebook->author = NULL;
    ebook->content = NULL;
    ebook->num_pages = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char* token = strtok(line, ":");
        if (token == NULL) {
            printf("Error: Invalid eBook data format\n");
            free(ebook);
            return NULL;
        }

        if (strcmp(token, "title") == 0) {
            ebook->title = strdup(strtok(NULL, ":"));
        } else if (strcmp(token, "author") == 0) {
            ebook->author = strdup(strtok(NULL, ":"));
        } else if (strcmp(token, "content") == 0) {
            ebook->content = strdup(strtok(NULL, ":"));
        } else if (strcmp(token, "num_pages") == 0) {
            ebook->num_pages = atoi(strtok(NULL, ":"));
        }
    }

    fclose(file);
    return ebook;
}

// Function to display the eBook content
void display_eBook(eBook* ebook) {
    printf("Title: %s\n", ebook->title);
    printf("Author: %s\n", ebook->author);
    printf("Number of pages: %d\n", ebook->num_pages);

    printf("\nContent:\n");
    for (int i = 0; i < ebook->num_pages; i++) {
        printf("%s\n", ebook->content);
    }
}

// Function to free the eBook data
void free_eBook(eBook* ebook) {
    free(ebook->title);
    free(ebook->author);
    free(ebook->content);
    free(ebook);
}

int main() {
    eBook* ebook = read_eBook("example.ebook");
    if (ebook == NULL) {
        return 1;
    }

    display_eBook(ebook);

    free_eBook(ebook);
    return 0;
}