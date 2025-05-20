//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 5000

struct Entry {
    char date[20];
    char time[10];
    char text[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *file;
    int num_entries = 0;
    struct Entry entries[MAX_ENTRIES];
    char input[MAX_ENTRY_LENGTH];
    time_t now;

    file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("Diary file not found. Creating new file...\n");
        file = fopen("diary.txt", "w");
        if (file == NULL) {
            printf("Error creating diary file.\n");
            exit(1);
        }
        fprintf(file, "Welcome to your digital diary!\n");
        fprintf(file, "Use the following format for your entries:\n");
        fprintf(file, "Date (YYYY-MM-DD): Time (HH:MM:SS): Entry\n");
        fclose(file);
        file = fopen("diary.txt", "r");
    }

    while (fgets(input, MAX_ENTRY_LENGTH, file)!= NULL) {
        if (strlen(input) > 0 && input[0]!= '\n') {
            num_entries++;
            if (num_entries > MAX_ENTRIES) {
                printf("Diary is full. Please delete some entries.\n");
                exit(1);
            }
            sscanf(input, "%s %s %s", entries[num_entries-1].date, entries[num_entries-1].time, entries[num_entries-1].text);
        }
    }

    fclose(file);

    while (1) {
        printf("Enter your entry (or type 'quit' to exit):\n");
        fgets(input, MAX_ENTRY_LENGTH, stdin);
        if (strcmp(input, "quit") == 0) {
            break;
        }

        time(&now);
        strftime(entries[num_entries].date, 20, "%Y-%m-%d", localtime(&now));
        strftime(entries[num_entries].time, 10, "%H:%M:%S", localtime(&now));
        strcpy(entries[num_entries].text, input);
        num_entries++;

        if (num_entries > MAX_ENTRIES) {
            printf("Diary is full. Please delete some entries.\n");
            exit(1);
        }

        file = fopen("diary.txt", "a");
        fprintf(file, "%s %s %s\n", entries[num_entries-1].date, entries[num_entries-1].time, entries[num_entries-1].text);
        fclose(file);
    }

    return 0;
}