//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char* title;
    char* author;
    char* language;
    char* publisher;
    int page_count;
    int font_size;
} Ebook;

Ebook* create_ebook(char* title, char* author, char* language, char* publisher, int page_count, int font_size) {
    Ebook* ebook = malloc(sizeof(Ebook));
    if (ebook == NULL) {
        fprintf(stderr, "Out of memory!\n");
        exit(EXIT_FAILURE);
    }
    ebook->title = strdup(title);
    ebook->author = strdup(author);
    ebook->language = strdup(language);
    ebook->publisher = strdup(publisher);
    ebook->page_count = page_count;
    ebook->font_size = font_size;
    return ebook;
}

void destroy_ebook(Ebook* ebook) {
    if (ebook!= NULL) {
        free(ebook->title);
        free(ebook->author);
        free(ebook->language);
        free(ebook->publisher);
        free(ebook);
    }
}

void display_ebook(Ebook* ebook) {
    printf("Title: %s\n", ebook->title);
    printf("Author: %s\n", ebook->author);
    printf("Language: %s\n", ebook->language);
    printf("Publisher: %s\n", ebook->publisher);
    printf("Page count: %d\n", ebook->page_count);
    printf("Font size: %d\n", ebook->font_size);
}

int main(int argc, char* argv[]) {
    if (argc!= 5) {
        fprintf(stderr, "Usage: %s <title> <author> <language> <publisher> <font_size>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    Ebook* ebook = create_ebook(argv[1], argv[2], argv[3], argv[4], atoi(argv[5]), atoi(argv[6]));
    if (ebook == NULL) {
        exit(EXIT_FAILURE);
    }
    display_ebook(ebook);
    destroy_ebook(ebook);
    return 0;
}