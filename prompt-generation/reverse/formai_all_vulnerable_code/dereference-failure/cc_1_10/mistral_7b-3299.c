//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PAGES 10
#define LINE_WIDTH 80

typedef struct {
    char content[MAX_PAGES][LINE_WIDTH];
    int current_page;
} Ebook;

void load_ebook(Ebook* ebook, const char* filename);
void print_page(const Ebook* ebook);
void next_page(Ebook* ebook);
void prev_page(Ebook* ebook);

int main() {
    Ebook ebook;
    load_ebook(&ebook, "example.txt");

    while (true) {
        print_page(&ebook);
        next_page(&ebook);

        if (ebook.current_page >= MAX_PAGES) {
            printf("End of book.\n");
            break;
        }
    }

    return 0;
}

void load_ebook(Ebook* ebook, const char* filename) {
    FILE* file = fopen(filename, "r");

    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[LINE_WIDTH];
    int page = 0;

    while (fgets(line, LINE_WIDTH, file)) {
        strcpy(ebook->content[page], line);
        page++;
    }

    ebook->current_page = 0;
    fclose(file);
}

void print_page(const Ebook* ebook) {
    puts(ebook->content[ebook->current_page]);
}

void next_page(Ebook* ebook) {
    ebook->current_page++;
}

void prev_page(Ebook* ebook) {
    if (ebook->current_page > 0) {
        ebook->current_page--;
    }
}