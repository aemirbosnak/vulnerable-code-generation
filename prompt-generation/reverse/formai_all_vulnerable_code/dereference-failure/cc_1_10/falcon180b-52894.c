//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Define the maximum length of a line in the ebook
#define MAX_LINE_LENGTH 100

typedef struct {
    char *title;
    char *author;
    char *content;
} Ebook;

// Function to read the ebook from a file and store it in memory
Ebook read_ebook(FILE *file) {
    Ebook ebook = {NULL, NULL, NULL};
    char line[MAX_LINE_LENGTH];

    // Read the title
    fgets(line, MAX_LINE_LENGTH, file);
    ebook.title = strdup(line);

    // Read the author
    fgets(line, MAX_LINE_LENGTH, file);
    ebook.author = strdup(line);

    // Read the content
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    ebook.content = malloc(file_size + 1);
    fread(ebook.content, file_size, 1, file);
    ebook.content[file_size] = '\0';

    return ebook;
}

// Function to print the ebook information
void print_ebook(Ebook ebook) {
    printf("Title: %s\n", ebook.title);
    printf("Author: %s\n", ebook.author);
    printf("Content:\n%s", ebook.content);
}

// Main function to run the program
int main() {
    // Open the ebook file
    FILE *file = fopen("ebook.txt", "r");
    if (file == NULL) {
        printf("Error opening ebook file.\n");
        return 1;
    }

    // Read the ebook from the file
    Ebook ebook = read_ebook(file);

    // Print the ebook information
    print_ebook(ebook);

    // Close the ebook file
    fclose(file);

    return 0;
}