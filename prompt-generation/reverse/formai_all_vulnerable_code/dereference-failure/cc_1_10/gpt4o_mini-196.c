//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE 20
#define MAX_FILENAME 256

void display_page(const char *text[], int start_line, int line_count) {
    for (int i = 0; i < line_count; i++) {
        if (text[start_line + i] != NULL) {
            printf("%s\n", text[start_line + i]);
        }
    }
    printf("\nPress 'n' for next page or 'q' to quit.\n");
}

void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return;
    }

    // Array to hold lines of the ebook
    char **text = malloc(PAGE_SIZE * sizeof(char *));
    char line[256];
    int line_count = 0;

    // Read file line by line
    while (fgets(line, sizeof(line), file)) {
        if (line_count >= PAGE_SIZE) {
            break;
        }
        line[strcspn(line, "\n")] = 0; // Remove newline
        text[line_count] = strdup(line);
        line_count++;
    }
    fclose(file);

    // Page display logic
    int start_line = 0;
    char command;
    while (start_line < line_count) {
        display_page(text, start_line, PAGE_SIZE);
        command = getchar();
        getchar(); // To consume the newline character
        if (command == 'n') {
            start_line += PAGE_SIZE;
            if (start_line >= line_count) {
                start_line = line_count; // Last page
            }
        } else if (command == 'q') {
            break;
        }
    }

    // Free allocated memory
    for (int i = 0; i < line_count; i++) {
        free(text[i]);
    }
    free(text);
}

int main() {
    char filename[MAX_FILENAME];
    
    printf("Welcome to the C Ebook Reader\n");
    printf("Please enter the filename of the ebook: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove newline

    read_file(filename);

    printf("Thank you for using the C Ebook Reader. Goodbye!\n");
    return 0;
}