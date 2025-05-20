//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of an E-book
typedef struct Ebook {
    char *title;
    char *author;
    char *content;
    int num_pages;
} Ebook;

// Read an E-book from a file
Ebook *read_ebook(char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Allocate memory for the E-book
    Ebook *ebook = malloc(sizeof(Ebook));
    if (ebook == NULL) {
        fclose(fp);
        return NULL;
    }

    // Read the title
    char line[1024];
    if (fgets(line, sizeof(line), fp) == NULL) {
        fclose(fp);
        free(ebook);
        return NULL;
    }
    ebook->title = strdup(line);

    // Read the author
    if (fgets(line, sizeof(line), fp) == NULL) {
        fclose(fp);
        free(ebook->title);
        free(ebook);
        return NULL;
    }
    ebook->author = strdup(line);

    // Read the content
    ebook->content = malloc(1);
    ebook->content[0] = '\0';
    while (fgets(line, sizeof(line), fp) != NULL) {
        ebook->content = realloc(ebook->content, strlen(ebook->content) + strlen(line) + 1);
        strcat(ebook->content, line);
    }

    // Read the number of pages
    if (fscanf(fp, "%d", &ebook->num_pages) != 1) {
        fclose(fp);
        free(ebook->title);
        free(ebook->author);
        free(ebook->content);
        free(ebook);
        return NULL;
    }

    // Close the file
    fclose(fp);

    // Return the E-book
    return ebook;
}

// Free the memory allocated for an E-book
void free_ebook(Ebook *ebook) {
    free(ebook->title);
    free(ebook->author);
    free(ebook->content);
    free(ebook);
}

// Print the title, author, and content of an E-book
void print_ebook(Ebook *ebook) {
    printf("Title: %s\n", ebook->title);
    printf("Author: %s\n", ebook->author);
    printf("Content: %s\n", ebook->content);
}

// Main function
int main() {
    // Read an E-book from a file
    Ebook *ebook = read_ebook("ebook.txt");
    if (ebook == NULL) {
        printf("Error reading E-book.\n");
        return EXIT_FAILURE;
    }

    // Print the E-book
    print_ebook(ebook);

    // Free the memory allocated for the E-book
    free_ebook(ebook);

    return EXIT_SUCCESS;
}