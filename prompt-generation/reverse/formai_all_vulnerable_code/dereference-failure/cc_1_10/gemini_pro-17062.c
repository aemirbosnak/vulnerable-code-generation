//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAGE_LINES 10

typedef struct Page {
    char *lines[MAX_PAGE_LINES];
    int num_lines;
} Page;

typedef struct Book {
    char *title;
    char *author;
    int num_pages;
    Page *pages;
} Book;

Book *create_book(char *title, char *author, int num_pages) {
    Book *book = malloc(sizeof(Book));
    book->title = strdup(title);
    book->author = strdup(author);
    book->num_pages = num_pages;
    book->pages = malloc(sizeof(Page) * num_pages);
    
    printf("Loading pages for %s by %s...", book->title, book->author);
    for (int i = 0; i < num_pages; i++) { 
        book->pages[i].num_lines = 0;
        for (int j = 0; j < MAX_PAGE_LINES; j++) {
                char line[100];
                if(scanf("%s", line) != 1) {
                    printf("End of pages for this book.");
                    break;
                }
            book->pages[i].lines[j] = strdup(line);
            book->pages[i].num_lines++;
        }
    }
    return book;
}

void print_book(Book *book) {
    printf("\n%s by %s\n", book->title, book->author);
    for (int i = 0; i < book->num_pages; i++) {
        printf("\nPage %d:\n", i + 1);
        for (int j = 0; j < book->pages[i].num_lines; j++) {
            printf("%s\n", book->pages[i].lines[j]);
        }
    }
}

int main() {
    Book *book = create_book(
        "The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 10
    );
    print_book(book);
    
    free(book->title);
    free(book->author);
    for (int i = 0; i < book->num_pages; i++) {
        for (int j = 0; j < book->pages[i].num_lines; j++) {
            free(book->pages[i].lines[j]);
        }
    }
    free(book->pages);
    free(book);
    
    return 0;
}