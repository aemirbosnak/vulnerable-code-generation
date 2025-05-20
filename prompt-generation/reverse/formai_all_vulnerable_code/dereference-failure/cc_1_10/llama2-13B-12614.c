//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define EBOOK_MAX_PAGES 1000
#define EBOOK_MAX_WORD_LENGTH 50

typedef struct {
    char *title;
    char *author;
    char *content;
    int page_count;
} ebook_t;

ebook_t *load_ebook(const char *filename) {
    ebook_t *eb = malloc(sizeof(ebook_t));
    char buffer[4096];
    int pages = 0;
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return NULL;
    }

    while (fgets(buffer, sizeof(buffer), file)) {
        if (strstr(buffer, "--- page break ---")) {
            pages++;
        }
        if (pages == eb->page_count) {
            break;
        }
    }

    eb->title = strdup(buffer);
    eb->author = strdup(buffer);
    eb->content = malloc(pages * sizeof(char *));
    pages = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        if (strstr(buffer, "--- page break ---")) {
            pages++;
            eb->content[pages - 1] = strdup(buffer);
        } else {
            eb->content[pages] = strdup(buffer);
            pages++;
        }
    }

    fclose(file);
    return eb;
}

void print_ebook(ebook_t *eb) {
    int i = 0;
    for (i = 0; i < eb->page_count; i++) {
        printf("%s\n", eb->content[i]);
    }
}

int main() {
    ebook_t *eb = load_ebook("example.txt");
    print_ebook(eb);
    return 0;
}