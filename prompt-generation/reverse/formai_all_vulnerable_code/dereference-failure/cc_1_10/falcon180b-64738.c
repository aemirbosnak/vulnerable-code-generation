//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000

// Function to read a line from the book file
char* read_line(FILE* book_file) {
    char* line = malloc(MAX_LINE_LEN * sizeof(char));
    fgets(line, MAX_LINE_LEN, book_file);
    return line;
}

// Function to print a line with a chapter number prefix
void print_line(int chapter_num, char* line) {
    printf("%d: %s", chapter_num, line);
}

// Function to print a blank line for spacing
void print_blank_line() {
    printf("\n");
}

int main() {
    // Open the book file
    FILE* book_file = fopen("book.txt", "r");
    if (book_file == NULL) {
        printf("Error: could not open book file.\n");
        return 1;
    }

    // Read the book file chapter by chapter
    int chapter_num = 1;
    char* line = read_line(book_file);
    while (line!= NULL) {
        // Print a blank line for spacing
        print_blank_line();

        // Print the chapter number and a line from the book
        print_line(chapter_num, line);

        // Read the next line from the book file
        line = read_line(book_file);

        // Increment the chapter number for the next chapter
        chapter_num++;
    }

    // Close the book file
    fclose(book_file);
    return 0;
}