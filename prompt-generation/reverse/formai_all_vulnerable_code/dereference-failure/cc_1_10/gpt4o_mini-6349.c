//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 256
#define MAX_FILENAME_LENGTH 100

void display_file(const char *filename, int font_size);
void print_line(const char *line, int font_size);
void print_usage();

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
        return 1;
    }

    char *filename = argv[1];
    int font_size = 1; // Default font size scale

    if (argc == 3) {
        font_size = atoi(argv[2]);
        if (font_size <= 0) {
            printf("Font size must be a positive integer. Using default size.\n");
            font_size = 1;
        }
    }

    display_file(filename, font_size);
    return 0;
}

void display_file(const char *filename, int font_size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int line_count = 0;

    while (fgets(line, sizeof(line), file)) {
        print_line(line, font_size);
        line_count++;

        if (line_count % MAX_LINES == 0) {
            printf("\n--- Press Enter to continue or 'q' to quit ---\n");
            int ch = getchar();
            if (ch == 'q') {
                break;
            }
            while (getchar() != '\n'); // Clear the input buffer
        }
    }

    fclose(file);
}

void print_line(const char *line, int font_size) {
    for (int i = 0; i < font_size; i++) {
        printf("%s", line);
    }
}

void print_usage() {
    printf("Usage: ebook_reader <filename> [font_size]\n");
    printf("  <filename>: Path to the text file to read.\n");
    printf("  [font_size]: Optional. Integer to change font size (number of times each line is printed). Default is 1.\n");
}