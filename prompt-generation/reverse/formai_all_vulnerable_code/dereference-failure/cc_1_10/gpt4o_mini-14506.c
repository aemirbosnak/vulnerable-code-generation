//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define PAGE_LINES 20

typedef struct {
    char **lines;
    int total_lines;
} Ebook;

Ebook* loadEbook(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return NULL;
    }

    Ebook *ebook = malloc(sizeof(Ebook));
    ebook->lines = malloc(sizeof(char*) * MAX_LINE_LENGTH);
    ebook->total_lines = 0;

    while (fgets(ebook->lines[ebook->total_lines], MAX_LINE_LENGTH, file)) {
        ebook->lines[ebook->total_lines] = strdup(ebook->lines[ebook->total_lines]);
        ebook->total_lines++;
    }

    fclose(file);
    return ebook;
}

void displayPage(Ebook *ebook, int start_line) {
    int end_line = start_line + PAGE_LINES < ebook->total_lines ? start_line + PAGE_LINES : ebook->total_lines;
    for (int i = start_line; i < end_line; i++) {
        printf("%s", ebook->lines[i]);
    }
    printf("\n");
}

void freeEbook(Ebook *ebook) {
    for (int i = 0; i < ebook->total_lines; i++) {
        free(ebook->lines[i]);
    }
    free(ebook->lines);
    free(ebook);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <ebook-file>\n", argv[0]);
        return 1;
    }

    Ebook *ebook = loadEbook(argv[1]);
    if (ebook == NULL) {
        return 1;
    }

    int current_page = 0;
    char command;

    while (1) {
        printf("\n--- Page %d of %d ---\n", current_page + 1, (ebook->total_lines + PAGE_LINES - 1) / PAGE_LINES);
        displayPage(ebook, current_page * PAGE_LINES);

        if (current_page * PAGE_LINES >= ebook->total_lines) {
            printf("End of the ebook. Press 'q' to quit.\n");
            command = getchar();
            if (command == 'q') {
                break;
            }
            continue;
        }

        printf("Commands: [n] Next Page, [p] Previous Page, [q] Quit: ");
        while ((command = getchar()) == '\n'); // Ignore newline characters

        switch (command) {
            case 'n':
                if (current_page * PAGE_LINES + PAGE_LINES < ebook->total_lines) {
                    current_page++;
                } else {
                    printf("Already on the last page.\n");
                }
                break;
            case 'p':
                if (current_page > 0) {
                    current_page--;
                } else {
                    printf("Already on the first page.\n");
                }
                break;
            case 'q':
                freeEbook(ebook);
                return 0;
            default:
                printf("Unknown command. Please use [n], [p], or [q].\n");
                break;
        }
        // Clear input buffer
        while ((command = getchar()) != '\n' && command != EOF);
    }

    freeEbook(ebook);
    return 0;
}