//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
typedef struct Book {
    char *title;
    char *author;
    int num_pages;
    char *content;
} Book;

// Function to create a new book
Book *create_book(char *title, char *author, int num_pages, char *content) {
    Book *book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->content = strdup(content);
    return book;
}

// Function to free the memory allocated for a book
void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book->content);
    free(book);
}

// Function to print the details of a book
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Content:\n%s\n", book->content);
}

// Function to read a book from a file
Book *read_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the title of the book
    char title[256];
    if (fgets(title, sizeof(title), fp) == NULL) {
        perror("Error reading title");
        fclose(fp);
        return NULL;
    }

    // Read the author of the book
    char author[256];
    if (fgets(author, sizeof(author), fp) == NULL) {
        perror("Error reading author");
        fclose(fp);
        return NULL;
    }

    // Read the number of pages in the book
    int num_pages;
    if (fscanf(fp, "%d", &num_pages) != 1) {
        perror("Error reading number of pages");
        fclose(fp);
        return NULL;
    }

    // Allocate memory for the content of the book
    char *content = malloc(num_pages * sizeof(char));
    if (content == NULL) {
        perror("Error allocating memory for content");
        fclose(fp);
        return NULL;
    }

    // Read the content of the book
    if (fread(content, sizeof(char), num_pages, fp) != num_pages) {
        perror("Error reading content");
        fclose(fp);
        free(content);
        return NULL;
    }

    // Close the file
    fclose(fp);

    // Create a new book with the data read from the file
    Book *book = create_book(title, author, num_pages, content);

    // Return the book
    return book;
}

// Function to write a book to a file
int write_book(Book *book, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Write the title of the book
    if (fputs(book->title, fp) == EOF) {
        perror("Error writing title");
        fclose(fp);
        return -1;
    }

    // Write the author of the book
    if (fputs(book->author, fp) == EOF) {
        perror("Error writing author");
        fclose(fp);
        return -1;
    }

    // Write the number of pages in the book
    if (fprintf(fp, "%d\n", book->num_pages) != 1) {
        perror("Error writing number of pages");
        fclose(fp);
        return -1;
    }

    // Write the content of the book
    if (fwrite(book->content, sizeof(char), book->num_pages, fp) != book->num_pages) {
        perror("Error writing content");
        fclose(fp);
        return -1;
    }

    // Close the file
    fclose(fp);

    // Return 0 if successful
    return 0;
}

// Main function
int main() {
    // Create a new book
    Book *book = create_book("The Catcher in the Rye", "J.D. Salinger", 277, "The Catcher in the Rye is a novel by J.D. Salinger that was first published in 1951. The novel's protagonist, Holden Caulfield, is a teenage boy who has just been expelled from Pencey Prep, an elite boarding school. Holden is intelligent and perceptive, but he is also deeply cynical and alienated from society. Over the course of the novel, Holden wanders around New York City, encountering a variety of people and experiences. Through these encounters, Holden comes to a greater understanding of himself and the world around him.");

    // Print the details of the book
    print_book(book);

    // Write the book to a file
    if (write_book(book, "catcher_in_the_rye.txt") != 0) {
        perror("Error writing book to file");
        return -1;
    }

    // Read the book from the file
    Book *book2 = read_book("catcher_in_the_rye.txt");
    if (book2 == NULL) {
        perror("Error reading book from file");
        return -1;
    }

    // Print the details of the book
    print_book(book2);

    // Free the memory allocated for the books
    free_book(book);
    free_book(book2);

    return 0;
}