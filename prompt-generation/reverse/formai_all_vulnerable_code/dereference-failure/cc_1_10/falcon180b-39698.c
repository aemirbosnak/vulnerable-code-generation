//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256

typedef struct {
    char *filename;
    char *content;
    size_t length;
} Ebook;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <ebook_filename>\n", argv[0]);
        return 1;
    }

    Ebook ebook = {0};
    ebook.filename = argv[1];

    FILE *file = fopen(ebook.filename, "r");
    if (file == NULL) {
        printf("Error: Could not open ebook file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char *buffer = NULL;
    size_t buffer_length = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (buffer == NULL) {
            buffer = malloc(strlen(line));
            strcpy(buffer, line);
            buffer_length = strlen(buffer);
        } else {
            char *new_buffer = realloc(buffer, buffer_length + strlen(line) + 1);
            if (new_buffer == NULL) {
                printf("Error: Could not allocate memory.\n");
                free(buffer);
                fclose(file);
                return 1;
            }
            strcat(new_buffer, line);
            buffer = new_buffer;
            buffer_length += strlen(line);
        }
    }

    ebook.content = buffer;
    ebook.length = buffer_length;

    fclose(file);

    printf("Ebook content:\n%s\n", ebook.content);

    return 0;
}