//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure to represent an e-book
typedef struct {
    char *title;
    char *author;
    int num_pages;
    char **pages;
} EBook;

// Function to create a new e-book
EBook *create_ebook(char *title, char *author, int num_pages) {
    EBook *ebook = malloc(sizeof(EBook));
    ebook->title = strdup(title);
    ebook->author = strdup(author);
    ebook->num_pages = num_pages;
    ebook->pages = malloc(sizeof(char *) * num_pages);
    for (int i = 0; i < num_pages; i++) {
        ebook->pages[i] = NULL;
    }
    return ebook;
}

// Function to free the memory allocated for an e-book
void free_ebook(EBook *ebook) {
    free(ebook->title);
    free(ebook->author);
    for (int i = 0; i < ebook->num_pages; i++) {
        free(ebook->pages[i]);
    }
    free(ebook->pages);
    free(ebook);
}

// Function to read an e-book from a file
EBook *read_ebook(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    char line[1024];
    fgets(line, sizeof(line), file); // Read the first line of the file

    char *title = strdup(strtok(line, "\n"));
    char *author = strdup(strtok(NULL, "\n"));
    int num_pages = atoi(strtok(NULL, "\n"));

    EBook *ebook = create_ebook(title, author, num_pages);

    for (int i = 0; i < num_pages; i++) {
        fgets(line, sizeof(line), file); // Read the next line of the file
        ebook->pages[i] = strdup(line);
    }

    fclose(file);

    return ebook;
}

// Function to write an e-book to a file
void write_ebook(char *filename, EBook *ebook) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return;
    }

    fprintf(file, "%s\n", ebook->title);
    fprintf(file, "%s\n", ebook->author);
    fprintf(file, "%d\n", ebook->num_pages);

    for (int i = 0; i < ebook->num_pages; i++) {
        fprintf(file, "%s", ebook->pages[i]);
    }

    fclose(file);
}

// Function to print an e-book to the console
void print_ebook(EBook *ebook) {
    printf("Title: %s\n", ebook->title);
    printf("Author: %s\n", ebook->author);
    printf("Number of pages: %d\n", ebook->num_pages);

    for (int i = 0; i < ebook->num_pages; i++) {
        printf("Page %d:\n%s", i + 1, ebook->pages[i]);
    }
}

// Main function
int main() {
    // Create an e-book
    EBook *ebook = create_ebook("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 249);

    // Write the e-book to a file
    write_ebook("hitchhikers_guide.txt", ebook);

    // Read the e-book from the file
    ebook = read_ebook("hitchhikers_guide.txt");

    // Print the e-book to the console
    print_ebook(ebook);

    // Free the memory allocated for the e-book
    free_ebook(ebook);

    return 0;
}