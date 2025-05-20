//FormAI DATASET v1.0 Category: Ebook reader ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EBOOKS 100

typedef struct {
    char* title;
    char* author;
    int pages;
    double size;
    char* format;
    char* file_name;
} Ebook;

typedef struct {
    Ebook* ebooks[MAX_EBOOKS];
    int count;
} EbookCollection;

EbookCollection* create_ebook_collection() {
    EbookCollection* collection = malloc(sizeof(EbookCollection));
    collection->count = 0;
    return collection;
}

void add_ebook(EbookCollection* collection, Ebook* ebook) {
    if (collection->count < MAX_EBOOKS) {
        collection->ebooks[collection->count] = ebook;
        collection->count++;
    } else {
        printf("Collection is full. Cannot add ebook.\n");
    }
}

Ebook* create_ebook(char* title, char* author, int pages, double size, char* format, char* file_name) {
    Ebook* ebook = malloc(sizeof(Ebook));
    ebook->title = malloc(strlen(title) + 1);
    strcpy(ebook->title, title);
    ebook->author = malloc(strlen(author) + 1);
    strcpy(ebook->author, author);
    ebook->pages = pages;
    ebook->size = size;
    ebook->format = malloc(strlen(format) + 1);
    strcpy(ebook->format, format);
    ebook->file_name = malloc(strlen(file_name) + 1);
    strcpy(ebook->file_name, file_name);
    return ebook;
}

void destroy_ebook(Ebook* ebook) {
    free(ebook->title);
    free(ebook->author);
    free(ebook->format);
    free(ebook->file_name);
    free(ebook);
}

void display_ebook(Ebook* ebook) {
    printf("Title: %s\n", ebook->title);
    printf("Author: %s\n", ebook->author);
    printf("Pages: %d\n", ebook->pages);
    printf("Size: %.2fMB\n", ebook->size);
    printf("Format: %s\n", ebook->format);
    printf("File name: %s\n", ebook->file_name);
    printf("\n");
}

void display_ebook_collection(EbookCollection* collection) {
    printf("Ebook collection (%d):\n", collection->count);
    for (int i = 0; i < collection->count; i++) {
        display_ebook(collection->ebooks[i]);
    }
}

int main() {
    EbookCollection* collection = create_ebook_collection();

    Ebook* ebook1 = create_ebook("The Art of Computer Programming", "Donald Knuth", 784, 4.56, "PDF", "knuth.pdf");
    Ebook* ebook2 = create_ebook("Clean Code", "Robert Martin", 464, 2.84, "EPUB", "martin.epub");
    Ebook* ebook3 = create_ebook("Design Patterns", "Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides", 395, 3.19, "MOBI", "gang_of_four.mobi");

    add_ebook(collection, ebook1);
    add_ebook(collection, ebook2);
    add_ebook(collection, ebook3);

    display_ebook_collection(collection);

    destroy_ebook(ebook1);
    destroy_ebook(ebook2);
    destroy_ebook(ebook3);
    free(collection);

    return 0;
}