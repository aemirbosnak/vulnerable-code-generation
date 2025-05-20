//FormAI DATASET v1.0 Category: Ebook reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 100

typedef struct {
    char* author;
    char* title;
    int year;
    char* filename;
} Book;

typedef struct {
    Book* books;
    int num_books;
} Library;

int load_library(Library* library, char* filename) {
    FILE* file;
    char buffer[MAX_FILENAME_LEN];
    char* temp;
    int num_books = 0;

    file = fopen(filename, "r");

    if (file == NULL) {
        return -1;
    }

    while (fgets(buffer, MAX_FILENAME_LEN, file)) {
        num_books++;
    }

    library->books = malloc(num_books * sizeof(Book));
    library->num_books = num_books;

    rewind(file);
    num_books = 0;

    while (fgets(buffer, MAX_FILENAME_LEN, file)) {
        library->books[num_books].title = strdup(strtok(buffer, ",\n"));
        library->books[num_books].author = strdup(strtok(NULL, ",\n"));
        library->books[num_books].year = atoi(strtok(NULL, ",\n"));
        temp = strtok(NULL, ",\n");
        library->books[num_books].filename = malloc(strlen(temp) + 1);
        strncpy(library->books[num_books].filename, temp, strlen(temp) + 1);

        num_books++;
    }

    fclose(file);

    return 0;
}

void print_book(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Year: %d\n", book.year);
    printf("Filename: %s\n", book.filename);
}

void print_library(Library library) {
    int i;

    for (i = 0; i < library.num_books; i++) {
        print_book(library.books[i]);
        printf("\n");
    }
}

void read_book(Book book) {
    char command[MAX_FILENAME_LEN + 10];
    snprintf(command, MAX_FILENAME_LEN + 10, "cat %s", book.filename);
    system(command);
}

int main(int argc, char** argv) {
    Library library;
    char filename[MAX_FILENAME_LEN];

    if (argc < 2) {
        printf("Usage: %s <library-file>\n", argv[0]);
        exit(-1);
    }

    strncpy(filename, argv[1], MAX_FILENAME_LEN);
    if (load_library(&library, filename)) {
        printf("Error loading library from file %s\n", filename);
        exit(-1);
    }

    print_library(library);

    int selection = -1;

    while (selection != 0) {
        printf("Enter the number of the book you want to read (0 to exit): ");
        scanf("%d", &selection);

        if (selection < 0 || selection > library.num_books) {
            printf("Invalid selection. Please try again.\n");
            continue;
        }

        if (selection == 0) {
            break;
        }

        read_book(library.books[selection - 1]);
    }

    return 0;
}