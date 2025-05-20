//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024
#define PAGE_SIZE 10

typedef struct {
    char **pages;
    int total_pages;
    int current_page;
} EbookReader;

void print_menu() {
    printf("\nEbook Reader Menu:\n");
    printf("1. Next Page\n");
    printf("2. Previous Page\n");
    printf("3. Go to Page\n");
    printf("4. Exit\n");
}

EbookReader* create_ebook(const char *filename) {
    EbookReader *reader = malloc(sizeof(EbookReader));
    reader->pages = malloc(MAX_LENGTH * sizeof(char*));
    for (int i = 0; i < MAX_LENGTH; i++) {
        reader->pages[i] = malloc(MAX_LENGTH * sizeof(char));
    }
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        free(reader);
        return NULL;
    }

    char line[MAX_LENGTH];
    int page_count = 0, line_count = 0;

    while (fgets(line, sizeof(line), file) && page_count < MAX_LENGTH) {
        strcpy(reader->pages[page_count * PAGE_SIZE + line_count], line);
        line_count++;
        if (line_count >= PAGE_SIZE) {
            line_count = 0;
            page_count++;
        }
    }
    reader->total_pages = page_count + (line_count > 0 ? 1 : 0);
    reader->current_page = 0;

    fclose(file);
    return reader;
}

void display_page(EbookReader *reader) {
    printf("\nPage %d/%d:\n", reader->current_page + 1, reader->total_pages);
    for (int i = 0; i < PAGE_SIZE; i++) {
        int line_index = reader->current_page * PAGE_SIZE + i;
        if (line_index < MAX_LENGTH && line_index < reader->total_pages * PAGE_SIZE && strlen(reader->pages[line_index]) > 0) {
            printf("%s", reader->pages[line_index]);
        }
    }
}

void next_page(EbookReader *reader) {
    if (reader->current_page < reader->total_pages - 1) {
        reader->current_page++;
    } else {
        printf("You are already on the last page.\n");
    }
}

void previous_page(EbookReader *reader) {
    if (reader->current_page > 0) {
        reader->current_page--;
    } else {
        printf("You are already on the first page.\n");
    }
}

void go_to_page(EbookReader *reader) {
    int page;
    printf("Enter page number (1 to %d): ", reader->total_pages);
    scanf("%d", &page);
    if (page >= 1 && page <= reader->total_pages) {
        reader->current_page = page - 1;
    } else {
        printf("Invalid page number.\n");
    }
}

void free_ebook(EbookReader *reader) {
    for (int i = 0; i < MAX_LENGTH; i++) {
        free(reader->pages[i]);
    }
    free(reader->pages);
    free(reader);
}

int main() {
    const char *filename = "sample_ebook.txt";
    EbookReader *reader = create_ebook(filename);
    if (reader == NULL) {
        return 1; // Failed to create ebook
    }

    int choice;
    do {
        display_page(reader);
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                next_page(reader);
                break;
            case 2:
                previous_page(reader);
                break;
            case 3:
                go_to_page(reader);
                break;
            case 4:
                printf("Exiting the reader. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    free_ebook(reader);
    return 0;
}