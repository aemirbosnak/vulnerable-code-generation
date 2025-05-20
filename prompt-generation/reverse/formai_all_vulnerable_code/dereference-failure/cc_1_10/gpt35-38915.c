//FormAI DATASET v1.0 Category: Ebook reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PAGES 1000
#define MAX_PAGESIZE 100000
#define MAX_FILENAMELEN 100

struct Book_t {
    char filename[MAX_FILENAMELEN];
    char author[MAX_FILENAMELEN];
    char title[MAX_FILENAMELEN];
    char publisher[MAX_FILENAMELEN];
    int total_pages;
    char **pages;
};

typedef struct Book_t Book;

Book *create_book(char *filename, char *author, char *title, char *publisher, int total_pages);

bool load_book(Book *book);

void show_page(Book *book, int page_number);

void destroy_book(Book *book);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./ebook <filename>\n");
        return 1;
    }

    Book *book = create_book(argv[1], "Unknown Author", "Unknown Title", "Unknown Publisher", 0);

    if (!load_book(book)) {
        printf("Error loading book %s\n", argv[1]);
        destroy_book(book);
        return 1;
    }

    printf("Loaded book %s, by %s (%s)\n", book->title, book->author, book->publisher);

    int current_page = 0;

    char command;

    do {
        show_page(book, current_page);
        command = getchar();
        getchar(); // consume newline

        switch (command) {
            case 'n':
                current_page = (current_page + 1) % book->total_pages;
                break;
            case 'p':
                current_page = (current_page - 1 + book->total_pages) % book->total_pages;
                break;
            case 'q':
                break;
            default:
                printf("Unknown command %c\n", command);
        }
    } while (command != 'q');

    destroy_book(book);

    return 0;
}

Book *create_book(char *filename, char *author, char *title, char *publisher, int total_pages) {
    Book *book = (Book *) malloc(sizeof(Book));
    book->total_pages = total_pages;

    for (int i = 0; i < MAX_FILENAMELEN; i++) {
        book->filename[i] = filename[i];
        book->author[i] = author[i];
        book->title[i] = title[i];
        book->publisher[i] = publisher[i];
    }

    book->pages = (char **) malloc(sizeof(char *) * MAX_PAGES);

    for (int i = 0; i < MAX_PAGES; i++) {
        book->pages[i] = (char *) malloc(sizeof(char) * MAX_PAGESIZE);
    }

    return book;
}

bool load_book(Book *book) {
    FILE *fp = fopen(book->filename, "r");

    if (!fp) {
        return false;
    }

    int current_page = 0;

    while (fgets(book->pages[current_page], MAX_PAGESIZE, fp) != NULL) {
        if (book->pages[current_page][0] == '\f') {
            current_page++;
        }
    }

    book->total_pages = current_page;

    fclose(fp);

    return true;
}

void show_page(Book *book, int page_number) {
    system("clear");

    if (page_number >= 0 && page_number < book->total_pages) {
        printf("%s, by %s (%s)\n\n", book->title, book->author, book->publisher);
        printf("Page %d/%d:\n\n%s\n\n(n)ext page, (p)revious page, (q)uit\n", page_number + 1, book->total_pages, book->pages[page_number]);
    } else {
        printf("Invalid page number %d\n", page_number);
    }
}

void destroy_book(Book *book) {
    for (int i = 0; i < MAX_PAGES; i++) {
        free(book->pages[i]);
    }

    free(book->pages);

    free(book);
}