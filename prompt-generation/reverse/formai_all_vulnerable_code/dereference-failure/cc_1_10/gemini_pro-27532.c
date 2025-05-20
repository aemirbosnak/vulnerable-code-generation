//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: realistic
// ebook.c: A simple ebook reader in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// A simple linked list to represent a line of text
typedef struct line_node {
    char *text;
    struct line_node *next;
} line_node;

// A simple linked list to represent a page of text
typedef struct page_node {
    line_node *head;
    struct page_node *next;
} page_node;

// A simple linked list to represent a book
typedef struct book {
    page_node *head;
} book;

// Create a new book
book *new_book() {
    book *b = malloc(sizeof(book));
    b->head = NULL;
    return b;
}

// Add a new page to a book
void add_page(book *b, page_node *p) {
    p->next = b->head;
    b->head = p;
}

// Add a new line to a page
void add_line(page_node *p, line_node *l) {
    l->next = p->head;
    p->head = l;
}

// Create a new line of text
line_node *new_line(char *text) {
    line_node *l = malloc(sizeof(line_node));
    l->text = strdup(text);
    l->next = NULL;
    return l;
}

// Create a new page of text
page_node *new_page() {
    page_node *p = malloc(sizeof(page_node));
    p->head = NULL;
    return p;
}

// Read a book from a file
book *read_book(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    book *b = new_book();

    char line[BUFSIZ];
    while (fgets(line, sizeof(line), fp) != NULL) {
        line_node *l = new_line(line);
        page_node *p = new_page();
        add_line(p, l);
        add_page(b, p);
    }

    fclose(fp);

    return b;
}

// Print a book to the console
void print_book(book *b) {
    page_node *p = b->head;
    while (p != NULL) {
        line_node *l = p->head;
        while (l != NULL) {
            printf("%s", l->text);
            l = l->next;
        }
        printf("\n");
        p = p->next;
    }
}

// Free a book
void free_book(book *b) {
    page_node *p = b->head;
    while (p != NULL) {
        line_node *l = p->head;
        while (l != NULL) {
            free(l->text);
            line_node *next = l->next;
            free(l);
            l = next;
        }
        page_node *next = p->next;
        free(p);
        p = next;
    }
    free(b);
}

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    book *b = read_book(argv[1]);
    if (b == NULL) {
        return 1;
    }

    print_book(b);

    free_book(b);

    return 0;
}