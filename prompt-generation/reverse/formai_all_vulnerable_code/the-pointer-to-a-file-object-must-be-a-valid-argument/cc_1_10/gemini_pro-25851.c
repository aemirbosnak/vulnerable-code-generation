//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_LINE_LENGTH 1024
#define MAX_BOOK_SIZE 1000000

// Types
typedef struct {
    char *text;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
    int size;
} Book;

// Functions
Book *new_book() {
    Book *book = (Book *)malloc(sizeof(Book));
    book->lines = (Line *)malloc(sizeof(Line) * MAX_BOOK_SIZE);
    book->num_lines = 0;
    book->size = 0;
    return book;
}

void free_book(Book *book) {
    for (int i = 0; i < book->num_lines; i++) {
        free(book->lines[i].text);
    }
    free(book->lines);
    free(book);
}

Line new_line() {
    Line line;
    line.text = (char *)malloc(sizeof(char) * MAX_LINE_LENGTH);
    line.length = 0;
    return line;
}

void free_line(Line line) {
    free(line.text);
}

void add_line_to_book(Book *book, Line line) {
    book->lines[book->num_lines] = line;
    book->num_lines++;
    book->size += line.length;
}

void print_book(Book *book) {
    for (int i = 0; i < book->num_lines; i++) {
        printf("%s\n", book->lines[i].text);
    }
}

int main() {
    // Create a new book
    Book *book = new_book();

    // Read lines from the file
    FILE *file = fopen("book.txt", "r");
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        // Create a new line
        Line line_struct = new_line();

        // Set the text and length of the line
        line_struct.text = strdup(line);
        line_struct.length = strlen(line);

        // Add the line to the book
        add_line_to_book(book, line_struct);
    }
    fclose(file);

    // Print the book
    print_book(book);

    // Free the book
    free_book(book);

    return 0;
}