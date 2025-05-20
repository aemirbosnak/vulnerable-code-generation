//FormAI DATASET v1.0 Category: Ebook reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM_EBOOKS 10
#define MAX_NUM_PAGES 100

typedef struct {
    char title[50];
    char author[50];
    int num_pages;
    char* pages[MAX_NUM_PAGES];
} Ebook;

typedef struct {
    Ebook* ebooks[MAX_NUM_EBOOKS];
    int num_ebooks;
} EbookCollection;

void add_ebook(EbookCollection* collection, Ebook* ebook) {
    collection->ebooks[collection->num_ebooks] = ebook;
    collection->num_ebooks++;
}

void print_ebook(Ebook* ebook) {
    printf("Title: %s\n", ebook->title);
    printf("Author: %s\n", ebook->author);
    printf("Num pages: %d\n", ebook->num_pages);
    for (int i = 0; i < ebook->num_pages; i++) {
        printf("%s\n", ebook->pages[i]);
    }
}

int main() {
    EbookCollection my_collection;
    my_collection.num_ebooks = 0;

    Ebook* ebook1 = malloc(sizeof(Ebook));
    strcpy(ebook1->title, "The C Programming Language");
    strcpy(ebook1->author, "Brian W. Kernighan, Dennis M. Ritchie");
    ebook1->num_pages = 3;
    ebook1->pages[0] = "Chapter 1: Introduction";
    ebook1->pages[1] = "Chapter 2: Types, Operators, and Expressions";
    ebook1->pages[2] = "Chapter 3: Control Flow";

    Ebook* ebook2 = malloc(sizeof(Ebook));
    strcpy(ebook2->title, "Programming Pearls");
    strcpy(ebook2->author, "Jon Bentley");
    ebook2->num_pages = 2;
    ebook2->pages[0] = "Chapter 1: Cracking the Oyster";
    ebook2->pages[1] = "Chapter 2: The Sultan's Dowry";

    add_ebook(&my_collection, ebook1);
    add_ebook(&my_collection, ebook2);

    for (int i = 0; i < my_collection.num_ebooks; i++) {
        print_ebook(my_collection.ebooks[i]);
        printf("\n");
    }
    
    return 0;
}