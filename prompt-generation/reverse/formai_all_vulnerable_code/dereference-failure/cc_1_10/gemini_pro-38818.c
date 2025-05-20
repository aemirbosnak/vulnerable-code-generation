//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <stdint.h>

#define MAX_LINE_LENGTH 1024

struct log_entry {
    time_t timestamp;
    char *message;
};

struct log_file {
    FILE *file;
    char *filename;
    size_t num_entries;
    struct log_entry *entries;
};

struct log_file *open_log_file(const char *filename) {
    struct log_file *lf = malloc(sizeof(struct log_file));
    if (lf == NULL) {
        return NULL;
    }

    lf->file = fopen(filename, "r");
    if (lf->file == NULL) {
        free(lf);
        return NULL;
    }

    lf->filename = strdup(filename);
    if (lf->filename == NULL) {
        fclose(lf->file);
        free(lf);
        return NULL;
    }

    lf->num_entries = 0;
    lf->entries = NULL;

    return lf;
}

void close_log_file(struct log_file *lf) {
    if (lf == NULL) {
        return;
    }

    if (lf->file != NULL) {
        fclose(lf->file);
    }

    if (lf->filename != NULL) {
        free(lf->filename);
    }

    if (lf->entries != NULL) {
        for (size_t i = 0; i < lf->num_entries; i++) {
            free(lf->entries[i].message);
        }
        free(lf->entries);
    }

    free(lf);
}

int parse_log_file(struct log_file *lf) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, lf->file) != NULL) {
        char *timestamp = strtok(line, " ");
        char *message = strtok(NULL, "\n");

        if (timestamp == NULL || message == NULL) {
            return -1;
        }

        struct log_entry entry;
        entry.timestamp = strtol(timestamp, NULL, 10);
        entry.message = strdup(message);

        if (entry.message == NULL) {
            return -1;
        }

        lf->entries = realloc(lf->entries, (lf->num_entries + 1) * sizeof(struct log_entry));
        if (lf->entries == NULL) {
            free(entry.message);
            return -1;
        }

        lf->entries[lf->num_entries++] = entry;
    }

    return 0;
}

void print_log_file(struct log_file *lf) {
    for (size_t i = 0; i < lf->num_entries; i++) {
        printf("%s %s\n", ctime(&lf->entries[i].timestamp), lf->entries[i].message);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct log_file *lf = open_log_file(argv[1]);
    if (lf == NULL) {
        fprintf(stderr, "Error opening log file: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    if (parse_log_file(lf) != 0) {
        fprintf(stderr, "Error parsing log file: %s\n", strerror(errno));
        close_log_file(lf);
        return EXIT_FAILURE;
    }

    print_log_file(lf);
    close_log_file(lf);
    return EXIT_SUCCESS;
}