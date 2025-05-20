//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BOOK_LENGTH 100000
#define MAX_CHAPTERS 10

// Structure to store book information
struct book {
    char title[50];
    char author[50];
    int chapterCount;
    char *text;
};

// Function to read a book from a file
struct book readBook(char *filename) {
    struct book b;
    int i = 0;
    char line[100];

    // Read book title
    fgets(line, 100, filename);
    sscanf(line, "%s", b.title);

    // Read book author
    fgets(line, 100, filename);
    sscanf(line, "%s", b.author);

    // Read chapter count
    fgets(line, 100, filename);
    sscanf(line, "%d", &b.chapterCount);

    // Allocate memory for book text
    b.text = malloc(sizeof(char) * MAX_BOOK_LENGTH);

    // Read book text
    for (i = 0; i < b.chapterCount; i++) {
        fgets(line, 100, filename);
        strcat(b.text, line);
    }

    return b;
}

// Function to display book text
void displayBook(struct book b) {
    int i = 0;
    char *text = b.text;

    printf("Book Title: %s\n", b.title);
    printf("Book Author: %s\n", b.author);

    for (i = 0; i < b.chapterCount; i++) {
        printf("%d. Chapter: %s\n", i + 1, text);
        text += strlen(text) + 1;
    }
}

int main() {
    struct book b = readBook("mybook.txt");
    displayBook(b);

    return 0;
}