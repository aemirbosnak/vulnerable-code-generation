//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE 5

void display_page(char **lines, int start_line, int total_lines) {
    int end_line = start_line + PAGE_SIZE < total_lines ? start_line + PAGE_SIZE : total_lines;
    for (int i = start_line; i < end_line; i++) {
        printf("%s\n", lines[i]);
    }
}

int read_ebook(const char *filename, char ***lines) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    // Read the lines from file
    char **temp_lines = malloc(100 * sizeof(char *));  
    if (!temp_lines) {
        perror("Memory allocation error");
        fclose(file);
        return -1;
    }

    int line_count = 0;

    while (1) {
        temp_lines[line_count] = malloc(256 * sizeof(char)); // allocate memory for each line
        if (!fgets(temp_lines[line_count], 256, file)) {
            break; // end of file or error
        }
        line_count++;
    }

    fclose(file);
    *lines = temp_lines;
    return line_count;
}

void free_lines(char **lines, int total_lines) {
    for (int i = 0; i < total_lines; i++) {
        free(lines[i]);
    }
    free(lines);
}

int main() {
    const char *filename = "ebook.txt"; // Change this to your ebook file path
    char **lines;
    int total_lines = read_ebook(filename, &lines);
    if (total_lines < 0) {
        return 1; // Error was encountered
    }

    int current_page = 0;

    while (1) {
        // Display the current page
        display_page(lines, current_page, total_lines);
        
        // Check if more lines are available
        if (current_page + PAGE_SIZE >= total_lines) {
            printf("\nEnd of the book! Press 'q' to quit.\n");
            char choice = getchar();
            if (choice == 'q') break;
        } else {
            printf("\nPress 'n' for next page, 'p' for previous page, or 'q' to quit: ");
            char choice = getchar();
            getchar(); // Consume the newline character

            if (choice == 'n') {
                current_page += PAGE_SIZE;
                if (current_page >= total_lines) {
                    current_page = total_lines - PAGE_SIZE; // If over page count, reset to last
                }
            } else if (choice == 'p') {
                current_page -= PAGE_SIZE;
                if (current_page < 0) {
                    current_page = 0; // Do not go before the first page
                }
            } else if (choice == 'q') {
                break; // Exit program
            }
        }
    }

    free_lines(lines, total_lines);
    return 0;
}