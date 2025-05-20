//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char time[10];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

int main() {
    FILE *diaryFile;
    DiaryEntry diary[MAX_ENTRIES];
    int numEntries = 0;
    int choice;
    char filename[50];
    char entry[MAX_ENTRY_LENGTH];
    time_t now;
    struct tm *timeinfo;

    srand(time(NULL));
    now = time(NULL);
    timeinfo = localtime(&now);
    strftime(filename, sizeof(filename), "diary_%d%m%Y.txt", timeinfo);

    diaryFile = fopen(filename, "a+");
    if (diaryFile == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (numEntries < MAX_ENTRIES) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add entry\n2. View entries\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter your entry:\n");
            fgets(entry, MAX_ENTRY_LENGTH, stdin);
            strcpy(diary[numEntries].entry, entry);
            strcpy(diary[numEntries].date, asctime(timeinfo));
            strcpy(diary[numEntries].time, ctime(&now));
            numEntries++;
            break;

        case 2:
            printf("\nEntries:\n");
            for (int i = 0; i < numEntries; i++) {
                printf("%s\n%s\n%s\n", diary[i].date, diary[i].time, diary[i].entry);
            }
            break;

        case 3:
            fclose(diaryFile);
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    fclose(diaryFile);
    return 0;
}