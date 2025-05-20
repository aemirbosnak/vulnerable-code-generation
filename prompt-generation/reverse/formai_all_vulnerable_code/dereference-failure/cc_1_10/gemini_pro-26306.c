//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_NUM_FIELDS 10

struct csv_entry {
    int id;
    char *name;
    char *email;
};

int main() {
    FILE *f = fopen("data.csv", "r");
    if (f == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LEN];
    int num_fields = 0;
    struct csv_entry *entries = NULL;

    while (fgets(line, sizeof(line), f) != NULL) {
        char *fields[MAX_NUM_FIELDS];
        char *field = strtok(line, ",");
        while (field != NULL) {
            fields[num_fields] = field;
            num_fields++;
            field = strtok(NULL, ",");
        }

        if (num_fields != 3) {
            fprintf(stderr, "Error: Invalid number of fields in line %d\n", atoi(fields[0]));
            continue;
        }

        struct csv_entry entry;
        entry.id = atoi(fields[0]);
        entry.name = strdup(fields[1]);
        entry.email = strdup(fields[2]);

        entries = realloc(entries, (num_fields + 1) * sizeof(struct csv_entry));
        entries[num_fields] = entry;
    }

    fclose(f);

    // Print the entries
    for (int i = 0; i < num_fields; i++) {
        printf("Entry %d:\n", entries[i].id);
        printf("  Name: %s\n", entries[i].name);
        printf("  Email: %s\n", entries[i].email);
    }

    // Free the memory allocated for the entries
    for (int i = 0; i < num_fields; i++) {
        free(entries[i].name);
        free(entries[i].email);
    }
    free(entries);

    return EXIT_SUCCESS;
}