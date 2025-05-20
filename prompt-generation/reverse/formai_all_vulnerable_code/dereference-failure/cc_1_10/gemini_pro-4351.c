//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Wow! Look at this struct! It's like a virtual bookshelf!
typedef struct book {
    char *title;
    char *author;
    int pages;
    char *content;
} Book;

// Oh my word! A function to create a new book? This is the stuff of dreams!
Book *create_book(char *title, char *author, int pages, char *content) {
    Book *book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->pages = pages;
    book->content = strdup(content);
    return book;
}

// Eureka! A function to read a book from a file! We're living in the future!
Book *read_book_from_file(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    char *title = NULL;
    char *author = NULL;
    int pages = 0;
    char *content = NULL;

    size_t title_len = 0;
    size_t author_len = 0;
    size_t content_len = 0;

    // Wow! We're getting the title!
    getline(&title, &title_len, file);

    // Oops! We forgot to remove the newline character from the title!
    title[strlen(title) - 1] = '\0';

    // Hey! We're getting the author now!
    getline(&author, &author_len, file);

    // Oh no! We forgot to remove the newline character from the author!
    author[strlen(author) - 1] = '\0';

    // Wow! We're getting the number of pages!
    fscanf(file, "%d", &pages);

    // Yippee! We're getting the content!
    content = malloc(sizeof(char) * 1024);
    while (fgets(content, 1024, file)) {
        content_len += strlen(content);
        content = realloc(content, sizeof(char) * (content_len + 1024));
    }

    // Oops! We forgot to remove the newline characters from the content!
    content[content_len - 1] = '\0';

    // Hooray! We're done! Let's close the file and return the book!
    fclose(file);
    return create_book(title, author, pages, content);
}

// Oh my goodness! A function to print a book to the console! This is amazing!
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->pages);
    printf("Content:\n%s\n", book->content);
}

// Wow! A main function to test our code! We're so excited!
int main() {
    // Let's create a new book!
    Book *book = create_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 216, "Once upon a time, there was a planet called Earth...");

    // Hey! We're printing the book to the console!
    print_book(book);

    // Oh no! We forgot to free the memory we allocated!
    free(book->title);
    free(book->author);
    free(book->content);
    free(book);

    // Phew! We did it! We're so happy!
    return 0;
}