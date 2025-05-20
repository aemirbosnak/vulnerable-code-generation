//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the ebook data
struct ebook {
    char title[100];
    char author[100];
    char content[100000];
};

// Function to read an ebook from a file
struct ebook read_ebook(const char *filename) {
    struct ebook ebook;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    // Read the title
    if (fscanf(file, "%s", ebook.title)!= 1) {
        fprintf(stderr, "Error: Could not read title from file '%s'\n", filename);
        exit(1);
    }

    // Read the author
    if (fscanf(file, "%s", ebook.author)!= 1) {
        fprintf(stderr, "Error: Could not read author from file '%s'\n", filename);
        exit(1);
    }

    // Read the content
    if (fscanf(file, "%s", ebook.content)!= 1) {
        fprintf(stderr, "Error: Could not read content from file '%s'\n", filename);
        exit(1);
    }

    fclose(file);
    return ebook;
}

// Function to display an ebook
void display_ebook(struct ebook ebook) {
    printf("Title: %s\n", ebook.title);
    printf("Author: %s\n", ebook.author);
    printf("Content:\n%s\n", ebook.content);
}

// Main function
int main() {
    // Read ebook from file
    struct ebook ebook = read_ebook("ebook.txt");

    // Display ebook
    display_ebook(ebook);

    // Free memory
    free(ebook.title);
    free(ebook.author);
    free(ebook.content);

    return 0;
}