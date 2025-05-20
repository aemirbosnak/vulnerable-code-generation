//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LOG_SIZE 10240

typedef struct {
    char *log_entry;
    int log_entry_len;
} log_entry_t;

log_entry_t *log_entries;
int num_log_entries = 0;

void parse_log_file(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        log_entries = realloc(log_entries, (num_log_entries + 1) * sizeof(log_entry_t));
        log_entries[num_log_entries].log_entry = line;
        log_entries[num_log_entries].log_entry_len = read;
        num_log_entries++;
    }

    free(line);
}

void print_log_entries(void) {
    for (int i = 0; i < num_log_entries; i++) {
        printf("%s", log_entries[i].log_entry);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    parse_log_file(fp);
    fclose(fp);

    print_log_entries();

    return EXIT_SUCCESS;
}