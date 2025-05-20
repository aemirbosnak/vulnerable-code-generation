//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define LINES_PER_PAGE 10

void display_page(char **lines, int start_line, int num_lines) {
    printf("\n--- Page %d ---\n", start_line / LINES_PER_PAGE + 1);
    for (int i = 0; i < num_lines; i++) {
        if (lines[start_line + i] != NULL) {
            printf("%s", lines[start_line + i]);
        }
    }
    printf("\n------------------\n");
    printf("Press 'n' for next page, 'p' for previous page, 'q' to quit.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Surprise! You need to provide an ebook filename!\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Whoa! Can't open the file: %s\n", argv[1]);
        return 1;
    }

    char **lines = malloc(MAX_LINE_LENGTH * sizeof(char *));
    if (!lines) {
        printf("Oops! Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    int line_count = 0;
    while (fgets(lines[line_count], MAX_LINE_LENGTH, file) != NULL) {
        lines[line_count] = malloc(strlen(lines[line_count]) + 1);
        if (lines[line_count] == NULL) {
            printf("Surprise! Memory allocation for lines failed.\n");
            break;
        }
        strcpy(lines[line_count], lines[line_count]);
        line_count++;
    }
    fclose(file);

    int current_line = 0;
    
    char command;
    while (1) {
        if (current_line >= line_count) {
            printf("Hmm... You've reached the end of the ebook!\n");
            break;
        }
        int lines_to_display = (line_count - current_line < LINES_PER_PAGE) ? (line_count - current_line) : LINES_PER_PAGE;
        display_page(lines, current_line, lines_to_display);

        command = getchar();
        while ((getchar()) != '\n'); // Clear the buffer

        if (command == 'n') {
            current_line += LINES_PER_PAGE;
        } else if (command == 'p') {
            current_line -= LINES_PER_PAGE;
            if (current_line < 0) {
                current_line = 0;
            }
        } else if (command == 'q') {
            printf("You've decided to leave the adventure. Bye!\n");
            break;
        } else {
            printf("Surprise! Unknown command! Use 'n', 'p', or 'q'.\n");
        }
    }

    for (int i = 0; i < line_count; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}