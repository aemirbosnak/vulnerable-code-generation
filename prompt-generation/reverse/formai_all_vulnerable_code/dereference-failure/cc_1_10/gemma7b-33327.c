//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_ ebooks 10
#define MAX_BOOK_NAME_LENGTH 255

typedef struct Ebook {
    char name[MAX_BOOK_NAME_LENGTH];
    char author[MAX_BOOK_NAME_LENGTH];
    int pages;
    struct Ebook* next;
} Ebook;

Ebook* ebooks = NULL;

void add_ebook(char* name, char* author, int pages) {
    Ebook* new_ebook = malloc(sizeof(Ebook));
    strcpy(new_ebook->name, name);
    strcpy(new_ebook->author, author);
    new_ebook->pages = pages;
    new_ebook->next = ebooks;
    ebooks = new_ebook;
}

void read_ebook(char* name) {
    Ebook* current_ebook = ebooks;

    while (current_ebook) {
        if (strcmp(current_ebook->name, name) == 0) {
            printf("Name: %s\n", current_ebook->name);
            printf("Author: %s\n", current_ebook->author);
            printf("Pages: %d\n", current_ebook->pages);
            break;
        }
        current_ebook = current_ebook->next;
    }

    if (current_ebook == NULL) {
        printf("Error: Book not found.\n");
    }
}

int main() {
    add_ebook("The Lord of the Flies", "William Golding", 242);
    add_ebook("The Great Gatsby", "F. Scott Fitzgerald", 200);
    add_ebook("To Kill a Mockingbird", "Harper Lee", 281);

    read_ebook("The Lord of the Flies");

    return 0;
}