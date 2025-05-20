//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to represent a book
typedef struct Book {
    char *title;
    char *author;
    int num_pages;
    char *text;
} Book;

// Function to create a new book
Book *create_book(char *title, char *author, int num_pages, char *text) {
    Book *book = malloc(sizeof(Book));
    book->title = malloc(strlen(title) + 1);
    strcpy(book->title, title);
    book->author = malloc(strlen(author) + 1);
    strcpy(book->author, author);
    book->num_pages = num_pages;
    book->text = malloc(strlen(text) + 1);
    strcpy(book->text, text);
    return book;
}

// Function to free the memory allocated for a book
void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book->text);
    free(book);
}

// Function to print the details of a book
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Text:\n%s\n", book->text);
}

// Function to read a book from a file
Book *read_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Read the title of the book
    char title[100];
    if (fgets(title, 100, fp) == NULL) {
        printf("Error reading title from file %s\n", filename);
        fclose(fp);
        return NULL;
    }

    // Read the author of the book
    char author[100];
    if (fgets(author, 100, fp) == NULL) {
        printf("Error reading author from file %s\n", filename);
        fclose(fp);
        return NULL;
    }

    // Read the number of pages in the book
    int num_pages;
    if (fscanf(fp, "%d", &num_pages) != 1) {
        printf("Error reading number of pages from file %s\n", filename);
        fclose(fp);
        return NULL;
    }

    // Read the text of the book
    char *text = malloc(100000);
    if (fgets(text, 100000, fp) == NULL) {
        printf("Error reading text from file %s\n", filename);
        fclose(fp);
        return NULL;
    }

    fclose(fp);

    // Create a new book and populate it with the data read from the file
    Book *book = create_book(title, author, num_pages, text);

    return book;
}

// Function to write a book to a file
void write_book(char *filename, Book *book) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Write the title of the book
    fprintf(fp, "%s\n", book->title);

    // Write the author of the book
    fprintf(fp, "%s\n", book->author);

    // Write the number of pages in the book
    fprintf(fp, "%d\n", book->num_pages);

    // Write the text of the book
    fprintf(fp, "%s\n", book->text);

    fclose(fp);
}

// Function to search for a word in a book
int search_book(Book *book, char *word) {
    char *text = book->text;
    int i = 0;
    int found = 0;

    while (text[i] != '\0') {
        if (strncmp(&text[i], word, strlen(word)) == 0) {
            found = 1;
            break;
        }
        i++;
    }

    return found;
}

// Function to get the number of words in a book
int get_num_words(Book *book) {
    char *text = book->text;
    int num_words = 0;
    int i = 0;

    while (text[i] != '\0') {
        if (isspace(text[i])) {
            num_words++;
        }
        i++;
    }

    return num_words;
}

// Function to get the frequency of a word in a book
int get_word_frequency(Book *book, char *word) {
    char *text = book->text;
    int frequency = 0;
    int i = 0;

    while (text[i] != '\0') {
        if (strncmp(&text[i], word, strlen(word)) == 0) {
            frequency++;
        }
        i++;
    }

    return frequency;
}

int main() {
    // Create a new book
    Book *book = create_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 183, "Far out in the uncharted backwaters of the unfashionable end of the western spiral arm of the Galaxy lies a small, unassuming planet called Earth...");

    // Print the details of the book
    print_book(book);

    // Search for a word in the book
    char *word = "Arthur";
    int found = search_book(book, word);
    if (found) {
        printf("The word '%s' was found in the book.\n", word);
    } else {
        printf("The word '%s' was not found in the book.\n", word);
    }

    // Get the number of words in the book
    int num_words = get_num_words(book);
    printf("The book contains %d words.\n", num_words);

    // Get the frequency of a word in the book
    char *word2 = "the";
    int frequency = get_word_frequency(book, word2);
    printf("The word '%s' appears %d times in the book.\n", word2, frequency);

    // Write the book to a file
    write_book("book.txt", book);

    // Free the memory allocated for the book
    free_book(book);

    return 0;
}