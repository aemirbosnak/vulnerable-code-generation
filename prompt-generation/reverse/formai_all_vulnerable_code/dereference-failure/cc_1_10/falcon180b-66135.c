//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100

struct entry {
    char *date;
    char *activity;
    int duration;
};

int main() {
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char input[100];
    char *token;

    while (1) {
        printf("Enter a fitness activity (type 'quit' to exit): ");
        fgets(input, sizeof(input), stdin);

        token = strtok(input, " ");
        if (strcmp(token, "quit") == 0) {
            break;
        }

        struct entry *entry = &entries[num_entries];
        entry->date = strdup(token);
        num_entries++;

        token = strtok(NULL, " ");
        while (token!= NULL) {
            if (strcmp(token, "run") == 0 || strcmp(token, "walk") == 0 ||
                strcmp(token, "bike") == 0) {
                entry->activity = strdup(token);
            } else if (isdigit(token[0])) {
                entry->duration = atoi(token);
            }
            token = strtok(NULL, " ");
        }
    }

    printf("Fitness tracker report:\n");
    printf("Date\tActivity\tDuration\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\t%d\n", entries[i].date, entries[i].activity,
               entries[i].duration);
    }

    return 0;
}