//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: random
// Welcome to the Eccentric E-Book Reader!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A dash of global flavor for our literary journey
char *book_title;
char *book_content;
int num_pages;
int current_page = 1;

// A sprinkle of functions to navigate our book
void load_book(char *filename);
void show_page(int page);
void turn_page(int direction);

// A dash of styling to spice up our reader
#define PAGE_WIDTH 80
#define PAGE_HEIGHT 25

// A generous helping of page layout
void format_page(int page) {
    printf("\n");
    printf("=======================================================\n");
    printf("                                                     %s\n", book_title);
    printf("-------------------------------------------------------\n");
    printf("                                              Page %d / %d\n", page, num_pages);
    printf("\n");

    char *page_start = book_content + (page - 1) * PAGE_WIDTH * PAGE_HEIGHT;
    for (int i = 0; i < PAGE_HEIGHT; i++) {
        for (int j = 0; j < PAGE_WIDTH; j++) {
            printf("%c", page_start[i * PAGE_WIDTH + j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {

    // Get ready for some book-reading action!
    if (argc != 2) {
        printf("Usage: ebook <filename>\n");
        return 1;
    }

    // Load the book into our virtual bookshelf
    load_book(argv[1]);

    // Now let's dive into the pages!
    while (1) {
        show_page(current_page);

        // Give the user a chance to navigate or exit
        int c = getchar();
        switch (c) {
            case 'n':
            case ' ':
                turn_page(1);
                break;
            case 'p':
                turn_page(-1);
                break;
            case 'x':
            case 'q':
                return 0;
        }
    }

    return 0;
}

// Read the book's content into memory
void load_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open book.\n");
        exit(1);
    }

    // Get the file size
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for the book content
    book_content = malloc(size);
    if (book_content == NULL) {
        printf("Error: Could not allocate memory for book content.\n");
        exit(1);
    }

    // Read the book content into memory
    fread(book_content, 1, size, fp);
    fclose(fp);

    // Get the book title
    char *title_end = strchr(book_content, '\n');
    *title_end = '\0';
    book_title = book_content;

    // Calculate the number of pages
    num_pages = (size + PAGE_WIDTH * PAGE_HEIGHT - 1) / (PAGE_WIDTH * PAGE_HEIGHT);
}

// Show the specified page of the book
void show_page(int page) {
    if (page < 1 || page > num_pages) {
        printf("Error: Invalid page number.\n");
        return;
    }

    current_page = page;
    format_page(page);
}

// Turn the page in the specified direction
void turn_page(int direction) {
    if (direction == 1 && current_page < num_pages) {
        current_page++;
    } else if (direction == -1 && current_page > 1) {
        current_page--;
    }
}