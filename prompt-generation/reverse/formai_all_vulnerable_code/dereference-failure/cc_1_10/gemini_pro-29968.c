//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: surrealist
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 512

typedef struct {
    char *date;
    char *time;
    char *entry;
} DiaryEntry;

int main()
{
    char line[MAX_LINE];
    char *ptr = NULL;
    DiaryEntry *entry = NULL;
    int num_entries = 0;

    while (fgets(line, MAX_LINE, stdin)) {
        if (line[0] == '#') {
            // Comment line
            continue;
        }

        ptr = strtok(line, "|");
        if (!ptr) {
            fprintf(stderr, "Invalid line format: %s", line);
            exit(1);
        }
        entry = realloc(entry, (num_entries + 1) * sizeof(DiaryEntry));
        entry[num_entries].date = strdup(ptr);
        ptr = strtok(NULL, "|");
        entry[num_entries].time = strdup(ptr);
        ptr = strtok(NULL, "\n");
        entry[num_entries].entry = strdup(ptr);
        num_entries++;
    }

    // Print the entries in reverse chronological order
    for (int i = num_entries - 1; i >= 0; i--) {
        printf("[%s] [%s] %s\n", entry[i].date, entry[i].time, entry[i].entry);
    }

    // Free the memory allocated for the entries
    for (int i = 0; i < num_entries; i++) {
        free(entry[i].date);
        free(entry[i].time);
        free(entry[i].entry);
    }
    free(entry);

    return 0;
}