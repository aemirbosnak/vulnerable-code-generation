//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char *line;
    int line_num;
    time_t timestamp;
} log_entry;

int compare_log_entries(const void *a, const void *b) {
    const log_entry *ea = (const log_entry *)a;
    const log_entry *eb = (const log_entry *)b;

    return ea->timestamp - eb->timestamp;
}

int main(int argc, char **argv) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int line_num = 0;
    log_entry *log_entries = NULL;
    int num_log_entries = 0;
    int i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        line_num++;

        log_entry *new_log_entry = (log_entry *)malloc(sizeof(log_entry));
        if (new_log_entry == NULL) {
            perror("malloc");
            return EXIT_FAILURE;
        }

        new_log_entry->line = (char *)malloc(read + 1);
        if (new_log_entry->line == NULL) {
            perror("malloc");
            return EXIT_FAILURE;
        }

        strcpy(new_log_entry->line, line);
        new_log_entry->line_num = line_num;
        new_log_entry->timestamp = time(NULL);

        log_entries = (log_entry *)realloc(log_entries, (num_log_entries + 1) * sizeof(log_entry));
        if (log_entries == NULL) {
            perror("realloc");
            return EXIT_FAILURE;
        }

        log_entries[num_log_entries] = *new_log_entry;
        num_log_entries++;

        free(new_log_entry);
    }

    fclose(fp);

    qsort(log_entries, num_log_entries, sizeof(log_entry), compare_log_entries);

    for (i = 0; i < num_log_entries; i++) {
        printf("%d %s\n", log_entries[i].line_num, log_entries[i].line);
        free(log_entries[i].line);
    }

    free(log_entries);

    return EXIT_SUCCESS;
}