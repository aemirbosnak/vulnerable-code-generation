//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ ebooks 10
#define MAX_ ebooks_PER_FOLDER 5

typedef struct Ebook {
    char title[50];
    char author[50];
    char genre[50];
    char folder[50];
    int pages;
    struct Ebook* next;
} Ebook;

Ebook* insert_ebook(Ebook* head, char* title, char* author, char* genre, int pages) {
    Ebook* new_ebook = malloc(sizeof(Ebook));
    strcpy(new_ebook->title, title);
    strcpy(new_ebook->author, author);
    strcpy(new_ebook->genre, genre);
    strcpy(new_ebook->folder, "");
    new_ebook->pages = pages;
    new_ebook->next = NULL;

    if (head == NULL) {
        head = new_ebook;
    } else {
        head->next = new_ebook;
    }

    return head;
}

void print_ebook_list(Ebook* head) {
    while (head) {
        printf("%s by %s (%d pages)\n", head->title, head->author, head->pages);
        head = head->next;
    }
}

int main() {
    Ebook* head = NULL;

    insert_ebook(head, "The Lord of the Flies", "William Golding", "Classic", 200);
    insert_ebook(head, "The Great Gatsby", "F. Scott Fitzgerald", "Classic", 180);
    insert_ebook(head, "The Hobbit: An Unexpected Journey", "J.R.R. Tolkien", "Fantasy", 320);
    insert_ebook(head, "The Hunger Games", "Suzanne Collins", "Young Adult", 350);

    print_ebook_list(head);

    return 0;
}