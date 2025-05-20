//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a structure to hold information about each page in the ebook
typedef struct {
    char* title;
    char* content;
} Page;

// Define a structure to hold information about the entire ebook
typedef struct {
    char* title;
    int num_pages;
    Page* pages;
} Ebook;

// Function to add a new page to the ebook
void add_page(Ebook* ebook, char* title, char* content) {
    ebook->num_pages++;
    Page* new_page = malloc(sizeof(Page));
    new_page->title = strdup(title);
    new_page->content = strdup(content);
    ebook->pages = realloc(ebook->pages, sizeof(Page) * ebook->num_pages);
    ebook->pages[ebook->num_pages - 1] = *new_page;
}

// Function to print the title and content of a specific page in the ebook
void print_page(Ebook* ebook, int page_num) {
    printf("Page %d:\n", page_num + 1);
    printf("Title: %s\n", ebook->pages[page_num].title);
    printf("Content:\n%s\n", ebook->pages[page_num].content);
}

// Function to print the title and number of pages in the ebook
void print_ebook(Ebook* ebook) {
    printf("Ebook Title: %s\n", ebook->title);
    printf("Number of Pages: %d\n", ebook->num_pages);
}

// Function to search for a specific word in the ebook
bool search_word(Ebook* ebook, char* word) {
    for (int i = 0; i < ebook->num_pages; i++) {
        if (strstr(ebook->pages[i].content, word)!= NULL) {
            return true;
        }
    }
    return false;
}

int main() {
    // Create a new ebook
    Ebook* ebook = malloc(sizeof(Ebook));
    strcpy(ebook->title, "The Great Gatsby");
    ebook->num_pages = 0;
    ebook->pages = NULL;

    // Add some pages to the ebook
    add_page(ebook, "Chapter 1", "It was a bright cold day in April and the clocks were striking thirteen.");
    add_page(ebook, "Chapter 2", "There was a queer smell of musks in the air. It made me think of Daisy and Gatsby");
    add_page(ebook, "Chapter 3", "I had a date to play golf in the morning with Tom Buchanan");

    // Print the ebook
    printf("Ebook:\n");
    print_ebook(ebook);

    // Search for a word in the ebook
    if (search_word(ebook, "Gatsby")) {
        printf("Word found!\n");
    } else {
        printf("Word not found.\n");
    }

    // Print a specific page in the ebook
    printf("Page 1:\n");
    print_page(ebook, 0);

    return 0;
}