//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE 20
#define MAX_FILENAME_LENGTH 100

void display_page(char **content, int start_line) {
    for (int i = 0; i < PAGE_SIZE; i++) {
        if (content[start_line + i] != NULL) {
            printf("%s", content[start_line + i]);
        }
    }
}

void load_book(const char *filename, char ***content, int *total_lines) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    char **lines = malloc(sizeof(char*) * 1000); // Allocate memory for 1000 lines
    char buffer[256];
    int count = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        lines[count] = malloc(strlen(buffer) + 1);
        strcpy(lines[count], buffer);
        count++;
    }

    fclose(file);
    *content = lines;
    *total_lines = count;
}

void free_book_content(char **content, int total_lines) {
    for (int i = 0; i < total_lines; i++) {
        free(content[i]);
    }
    free(content);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char **book_content;
    int total_lines = 0;
    int current_page = 0;

    // Get the filename from the user
    printf("Enter the eBook filename (with .txt extension): ");
    fgets(filename, sizeof(filename), stdin);
    // Remove newline from filename
    filename[strcspn(filename, "\n")] = 0;

    // Load the book content
    load_book(filename, &book_content, &total_lines);

    // Main loop for reading the book
    while (1) {
        system("clear"); // Clear the terminal screen
        display_page(book_content, current_page * PAGE_SIZE);

        printf("\n[Page %d/%d] (Press 'n' for next page, 'p' for previous page, 'q' to quit)\n", 
               current_page + 1, (total_lines + PAGE_SIZE - 1) / PAGE_SIZE);

        char command;
        command = getchar(); // Get user command
        getchar(); // Clean the newline character from the buffer
        if (command == 'n') {
            if ((current_page + 1) * PAGE_SIZE < total_lines) {
                current_page++;
            } else {
                printf("You are already on the last page.\n");
            }
        } else if (command == 'p') {
            if (current_page > 0) {
                current_page--;
            } else {
                printf("You are already on the first page.\n");
            }
        } else if (command == 'q') {
            break; // Exit the loop
        }
    }

    // Clean up
    free_book_content(book_content, total_lines);
    printf("Thank you for using the eBook reader. Goodbye!\n");

    return 0;
}