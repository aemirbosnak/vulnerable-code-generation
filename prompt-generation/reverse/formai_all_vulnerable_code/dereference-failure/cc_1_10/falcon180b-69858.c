//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

struct entry {
    time_t timestamp;
    char text[500];
};

int main() {
    FILE *diary;
    time_t now;
    char filename[100];
    int num_entries = 0;
    struct entry *entries = malloc(MAX_ENTRIES * sizeof(struct entry));

    if (entries == NULL) {
        printf("Error: could not allocate memory for entries.\n");
        return 1;
    }

    time(&now);
    strftime(filename, sizeof(filename), "diary_%Y%m%d_%H%M%S.txt", localtime(&now));
    diary = fopen(filename, "a");

    if (diary == NULL) {
        printf("Error: could not open diary file.\n");
        free(entries);
        return 1;
    }

    while (num_entries < MAX_ENTRIES) {
        printf("Enter a diary entry (or 'q' to quit):\n");
        fgets(entries[num_entries].text, sizeof(entries[num_entries].text), stdin);

        if (strlen(entries[num_entries].text) == 0) { // empty entry
            num_entries--;
        } else if (strlen(entries[num_entries].text) > 0) {
            num_entries++;
        }
    }

    for (int i = 0; i < num_entries; i++) {
        fprintf(diary, "%s\n", entries[i].text);
    }

    fclose(diary);
    free(entries);

    return 0;
}