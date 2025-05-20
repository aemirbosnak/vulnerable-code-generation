//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_BUFFER_SIZE 100

typedef struct {
    char **lines;
    int line_count;
    int current_line;
} EbookReader;

EbookReader* create_reader() {
    EbookReader *reader = (EbookReader *)malloc(sizeof(EbookReader));
    reader->lines = (char **)malloc(sizeof(char *) * MAX_BUFFER_SIZE);
    for (int i = 0; i < MAX_BUFFER_SIZE; i++) {
        reader->lines[i] = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
    }
    reader->line_count = 0;
    reader->current_line = 0;
    return reader;
}

void destroy_reader(EbookReader *reader) {
    for (int i = 0; i < MAX_BUFFER_SIZE; i++) {
        free(reader->lines[i]);
    }
    free(reader->lines);
    free(reader);
}

void load_ebook(EbookReader *reader, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(reader->lines[reader->line_count], MAX_LINE_LENGTH, file) != NULL && 
           reader->line_count < MAX_BUFFER_SIZE) {
        reader->line_count++;
    }
    fclose(file);
}

void display_current_line(EbookReader *reader) {
    if (reader->current_line < reader->line_count) {
        printf("%s", reader->lines[reader->current_line]);
    } else {
        printf("End of book reached.\n");
    }
}

void navigate_ebook(EbookReader *reader) {
    char command;
    while (1) {
        display_current_line(reader);
        printf("\nCommand (n: next, p: previous, q: quit): ");
        command = getchar();
        getchar(); // Consume newline
        
        if (command == 'n') {
            if (reader->current_line < reader->line_count - 1) {
                reader->current_line++;
            } else {
                printf("You are at the last line.\n");
            }
        } else if (command == 'p') {
            if (reader->current_line > 0) {
                reader->current_line--;
            } else {
                printf("You are at the first line.\n");
            }
        } else if (command == 'q') {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <ebook_file.txt>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    EbookReader *reader = create_reader();
    load_ebook(reader, argv[1]);
    navigate_ebook(reader);
    destroy_reader(reader);
    
    return EXIT_SUCCESS;
}