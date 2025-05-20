//FormAI DATASET v1.0 Category: Ebook reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define structure to hold book data
struct book {
    char title[50];
    char author[50];
    char format[10];
    int pages;
    char filepath[100];
};

// define function to read book data from file and return as array of book structs
struct book* read_books(char* filename, int* num_books) {
    FILE* fp = fopen(filename, "r"); // open file for reading
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return NULL;
    }

    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int line_count = 0;

    // count number of lines in file (each line represents a book)
    while ((read = getline(&line, &len, fp)) != -1) {
        line_count++;
    }

    // allocate memory for array of book structs
    struct book* books = (struct book*)malloc(line_count * sizeof(struct book));
    if (books == NULL) {
        printf("Error: could not allocate memory for books array\n");
        return NULL;
    }

    // reset file pointer to beginning of file
    fseek(fp, 0, SEEK_SET);

    // read book data from file and store in array of book structs
    for (int i = 0; i < line_count; i++) {
        read = fscanf(fp, "%[^,],%[^,],%[^,],%d,%s\n", books[i].title, books[i].author, books[i].format, &books[i].pages, books[i].filepath);
        if (read != 5) {
            printf("Error: could not read book data from file %s\n", filename);
            free(books);
            return NULL;
        }
    }

    fclose(fp); // close file
    *num_books = line_count; // set num_books pointer to line_count
    return books; // return array of book structs
}

// define function to display book data
void display_book(struct book b) {
    printf("Title: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Format: %s\n", b.format);
    printf("Pages: %d\n", b.pages);
    printf("Filepath: %s\n", b.filepath);
    printf("\n");
}

// define function to display all books in array of book structs
void display_all_books(struct book* books, int num_books) {
    for (int i = 0; i < num_books; i++) {
        display_book(books[i]);
    }
}

// main function
int main(int argc, char** argv) {
    int num_books = 0;
    struct book* books = read_books("books.txt", &num_books);
    if (books == NULL) {
        return 1;
    }

    display_all_books(books, num_books); // display all books in array of book structs

    free(books); // free allocated memory
    return 0;
}