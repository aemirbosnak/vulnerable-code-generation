//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct csv_entry {
    char *key;
    char *value;
};

struct csv_reader {
    FILE *file;
    char *line;
    size_t line_len;
    size_t line_size;
};

void csv_reader_init(struct csv_reader *reader, FILE *file) {
    reader->file = file;
    reader->line = NULL;
    reader->line_len = 0;
    reader->line_size = 0;
}

void csv_reader_destroy(struct csv_reader *reader) {
    if (reader->line != NULL) {
        free(reader->line);
    }
}

int csv_reader_get_line(struct csv_reader *reader) {
    ssize_t len;

    if (getline(&reader->line, &reader->line_size, reader->file) == -1) {
        return -1;
    }

    len = strlen(reader->line);
    if (len > 0 && reader->line[len - 1] == '\n') {
        reader->line[len - 1] = '\0';
    }

    return 0;
}

int csv_reader_parse_line(struct csv_reader *reader, struct csv_entry *entry) {
    char *key, *value;

    key = reader->line;
    value = strchr(reader->line, ',');

    if (value == NULL) {
        return -1;
    }

    *value = '\0';
    value++;

    entry->key = strdup(key);
    entry->value = strdup(value);

    return 0;
}

int main(int argc, char **argv) {
    struct csv_reader reader;
    struct csv_entry entry;
    FILE *file;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    csv_reader_init(&reader, file);

    while (csv_reader_get_line(&reader) == 0) {
        if (csv_reader_parse_line(&reader, &entry) == 0) {
            printf("%s: %s\n", entry.key, entry.value);
        }
    }

    csv_reader_destroy(&reader);
    fclose(file);

    return EXIT_SUCCESS;
}