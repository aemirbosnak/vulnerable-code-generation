//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define BUFFER_SIZE 10

typedef struct {
    char **lines;
    size_t line_count;
    size_t capacity;
} eBook;

void init_eBook(eBook *book) {
    book->line_count = 0;
    book->capacity = BUFFER_SIZE;
    book->lines = malloc(book->capacity * sizeof(char *));
    if (book->lines == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void free_eBook(eBook *book) {
    for (size_t i = 0; i < book->line_count; i++) {
        free(book->lines[i]);
    }
    free(book->lines);
}

void add_line(eBook *book, const char *line) {
    if (book->line_count >= book->capacity) {
        book->capacity *= 2;
        book->lines = realloc(book->lines, book->capacity * sizeof(char *));
        if (book->lines == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    book->lines[book->line_count] = strdup(line);
    if (book->lines[book->line_count] == NULL) {
        fprintf(stderr, "String duplication failed\n");
        exit(EXIT_FAILURE);
    }
    book->line_count++;
}

void load_eBook(eBook *book, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Unable to open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        add_line(book, line);
    }

    fclose(file);
}

void display_page(eBook *book, size_t start_line, size_t lines_per_page) {
    size_t end_line = start_line + lines_per_page;
    if (end_line > book->line_count) {
        end_line = book->line_count;
    }

    for (size_t i = start_line; i < end_line; i++) {
        printf("%s", book->lines[i]);
    }
}

void navigate_book(eBook *book) {
    size_t current_line = 0;
    size_t lines_per_page = 10;
    char command;

    while (1) {
        display_page(book, current_line, lines_per_page);
        if (current_line + lines_per_page < book->line_count) {
            printf("\n-- Press 'n' for next page, 'p' for previous page, 'q' to quit --\n");
            command = getchar();
            // Clear the buffer
            while (getchar() != '\n');
        } else {
            printf("\n-- Press 'p' for previous page, 'q' to quit --\n");
            command = getchar();
            while (getchar() != '\n');
        }

        if (command == 'n') {
            current_line += lines_per_page;
            if (current_line >= book->line_count) {
                current_line = book->line_count - 1;
            }
        } else if (command == 'p') {
            if (current_line >= lines_per_page) {
                current_line -= lines_per_page;
            } else {
                current_line = 0;
            }
        } else if (command == 'q') {
            printf("Exiting the eBook reader.\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ebook.txt>\n", argv[0]);
        return EXIT_FAILURE;
    }

    eBook myBook;
    init_eBook(&myBook);
    load_eBook(&myBook, argv[1]);
    navigate_book(&myBook);
    free_eBook(&myBook);

    return EXIT_SUCCESS;
}