//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE 30
#define MAX_LINES 1000

typedef struct {
    char **lines;
    int total_lines;
} Ebook;

Ebook* load_ebook(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }
    
    Ebook *ebook = (Ebook *)malloc(sizeof(Ebook));
    ebook->lines = (char **)malloc(MAX_LINES * sizeof(char *));
    ebook->total_lines = 0;
    
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) && ebook->total_lines < MAX_LINES) {
        ebook->lines[ebook->total_lines] = strdup(buffer);
        ebook->total_lines++;
    }
    
    fclose(file);
    return ebook;
}

void display_page(Ebook *ebook, int page_number) {
    int start = page_number * PAGE_SIZE;
    if (start >= ebook->total_lines) {
        printf("End of the book.\n");
        return;
    }

    for (int i = 0; i < PAGE_SIZE && (start + i) < ebook->total_lines; i++) {
        printf("%s", ebook->lines[start + i]);
    }
}

void free_ebook(Ebook *ebook) {
    for (int i = 0; i < ebook->total_lines; i++) {
        free(ebook->lines[i]);
    }
    free(ebook->lines);
    free(ebook);
}

int main() {
    char filename[100];
    printf("Welcome to the Curious Ebook Reader!\n");
    printf("Please enter the filename of the ebook: ");
    scanf("%99s", filename);

    Ebook *ebook = load_ebook(filename);
    if (ebook == NULL) {
        return 1; // Error loading the book
    }

    int current_page = 0;
    char command;

    while (1) {
        printf("\n--- Page %d ---\n", current_page + 1);
        display_page(ebook, current_page);

        printf("\nCommands: (n)ext, (p)revious, (q)uit: ");
        scanf(" %c", &command);

        if (command == 'n') {
            current_page++;
            if (current_page * PAGE_SIZE >= ebook->total_lines) {
                current_page = ebook->total_lines / PAGE_SIZE; // stay at the last page
            }
        } else if (command == 'p') {
            current_page--;
            if (current_page < 0) {
                current_page = 0; // stay at the first page
            }
        } else if (command == 'q') {
            printf("Exiting the Curious Ebook Reader. Happy reading!\n");
            break;
        } else {
            printf("Invalid command. Try again.\n");
        }
    }

    free_ebook(ebook);
    return 0;
}