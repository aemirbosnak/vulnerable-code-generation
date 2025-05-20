//FormAI DATASET v1.0 Category: Digital Diary ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ENTRY_SIZE 200
#define DATE_SIZE 20

struct Entry {
    char date[DATE_SIZE];
    char text[ENTRY_SIZE];
};

int main() {
    struct tm *t;
    time_t now;
    char date_string[DATE_SIZE];
    struct Entry *entries = NULL;
    int num_entries = 0;
    int i;
    char input[ENTRY_SIZE];

    // get current date
    now = time(NULL);
    t = localtime(&now);
    strftime(date_string, sizeof(date_string), "%F", t);

    // load diary entries from file
    FILE *fp = fopen("diary.txt", "r");
    if (fp) {
        char line[ENTRY_SIZE];
        while (fgets(line, sizeof(line), fp)) {
            if (line[0] == '\n') {
                continue;
            }
            struct Entry e;
            strcpy(e.date, strtok(line, " "));
            strcpy(e.text, strtok(NULL, ""));
            entries = realloc(entries, sizeof(struct Entry) * (num_entries + 1));
            entries[num_entries] = e;
            num_entries++;
        }
        fclose(fp);
    }

    // print existing entries
    printf("Previous entries:\n\n");
    for (i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].text);
    }

    // prompt for new entry
    printf("\nNew entry for %s:\n", date_string);
    fgets(input, sizeof(input), stdin);

    // add new entry to array and file
    struct Entry new_entry;
    strcpy(new_entry.date, date_string);
    strcpy(new_entry.text, input);
    entries = realloc(entries, sizeof(struct Entry) * (num_entries + 1));
    entries[num_entries] = new_entry;
    num_entries++;
    fp = fopen("diary.txt", "a");
    fprintf(fp, "%s %s", new_entry.date, new_entry.text);
    fclose(fp);

    // print all entries
    printf("\nAll entries:\n\n");
    for (i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].text);
    }

    // free memory
    free(entries);

    return 0;
}