//FormAI DATASET v1.0 Category: Ebook reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EBOOKS 100
#define MAX_TITLE_LENGTH 50

typedef struct ebook {
    char title[MAX_TITLE_LENGTH];
    int pages;
    float price;
} Ebook;

Ebook* ebooks[MAX_EBOOKS];
int num_ebooks = 0;

int add_ebook(char* title, int pages, float price) {
    if (num_ebooks < MAX_EBOOKS) {
        Ebook* new_ebook = (Ebook*) malloc(sizeof(Ebook));
        strncpy(new_ebook->title, title, MAX_TITLE_LENGTH);
        new_ebook->pages = pages;
        new_ebook->price = price;
        ebooks[num_ebooks++] = new_ebook;
        return 1;  // success
    }
    return 0;  // failure (too many ebooks)
}

void display_ebooks() {
    printf("Ebook library:\n");
    for (int i = 0; i < num_ebooks; i++) {
        Ebook* ebook = ebooks[i];
        printf("%d: %s (%d pages, $%.2f)\n", i+1, ebook->title, ebook->pages, ebook->price);
    }
    printf("\n");
}

void free_ebooks() {
    for (int i = 0; i < num_ebooks; i++) {
        free(ebooks[i]);
    }
}

int main() {
    add_ebook("The C Programming Language", 288, 38.99);
    add_ebook("Data Structures and Algorithm Analysis in C", 616, 58.45);
    add_ebook("C Programming Absolute Beginner's Guide", 352, 29.99);
    display_ebooks();
    free_ebooks();
    return 0;
}