//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    FILE *diary;
    Entry entries[MAX_ENTRIES] = {{0}};
    int num_entries = 0;
    char choice;
    time_t now;

    diary = fopen("diary.txt", "r");

    if (diary == NULL) {
        printf("Diary file not found. Creating new file.\n");
        fclose(diary);
        diary = fopen("diary.txt", "w");
        fclose(diary);
    } else {
        fclose(diary);
    }

    while (1) {
        printf("Digital Diary\n");
        printf("1. Write a new entry\n");
        printf("2. Read entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter your entry:\n");
                fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
                entries[num_entries].entry[strcspn(entries[num_entries].entry, "\n")] = '\0';
                entries[num_entries].date[0] = '\0';
                strcat(entries[num_entries].date, asctime(localtime(&now)));
                num_entries++;
                if (num_entries >= MAX_ENTRIES) {
                    printf("Diary full. Cannot add more entries.\n");
                } else {
                    printf("Entry added.\n");
                }
                break;
            case '2':
                diary = fopen("diary.txt", "r");
                if (diary == NULL) {
                    printf("Diary file not found.\n");
                } else {
                    printf("Diary entries:\n");
                    rewind(diary);
                    while (fgets(entries[0].entry, MAX_ENTRY_LENGTH, diary)!= NULL) {
                        printf("%s\n", entries[0].entry);
                    }
                    fclose(diary);
                }
                break;
            case '3':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}