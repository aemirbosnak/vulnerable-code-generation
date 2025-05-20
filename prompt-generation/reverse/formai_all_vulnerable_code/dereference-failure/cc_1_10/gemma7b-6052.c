//Gemma-7B DATASET v1.0 Category: Database querying ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY_LENGTH 255

typedef struct Book {
    char title[255];
    char author[255];
    int pages;
} Book;

Book books[] = {
    {"The Lord of the Flies", "William Golding", 320},
    {"The Great Gatsby", "F. Scott Fitzgerald", 180},
    {"To Kill a Mockingbird", "Harper Lee", 320},
    {"The Catcher in the Rye", "J.D. Salinger", 160},
    {"The Joy of Living", "William Shakespeare", 320}
};

int main() {
    char query[MAX_QUERY_LENGTH];
    char *token;
    int i, result = 0;

    printf("Enter a book query: ");
    fgets(query, MAX_QUERY_LENGTH, stdin);

    // Tokenize the query
    token = strtok(query, " ");

    // Search for books
    for (i = 0; i < 5; i++) {
        int match = 0;

        // Check book title
        if (strcmp(books[i].title, token) == 0) {
            match = 1;
        }

        // Check book author
        if (strcmp(books[i].author, token) == 0) {
            match = 1;
        }

        // If book matches, increment result
        if (match) {
            result++;
        }
    }

    // Print the results
    if (result > 0) {
        printf("Found %d books matching your query.\n", result);
    } else {
        printf("No books found matching your query.\n");
    }

    return 0;
}