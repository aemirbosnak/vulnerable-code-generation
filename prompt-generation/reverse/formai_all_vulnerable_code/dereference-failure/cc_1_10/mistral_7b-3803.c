//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Date and Time Structure
typedef struct {
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int second;
} DiaryEntry;

// Initialize Function
void initDiaryEntry(DiaryEntry *entry) {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    entry->day = timeinfo->tm_mday;
    entry->month = timeinfo->tm_mon + 1;
    entry->year = timeinfo->tm_year + 1900;
    entry->hour = timeinfo->tm_hour;
    entry->minute = timeinfo->tm_min;
    entry->second = timeinfo->tm_sec;
}

// Display Function
void displayDiaryEntry(DiaryEntry *entry) {
    printf("-----------------------------\n");
    printf("| Date : %d-%d-%d |\n", entry->year, entry->month, entry->day);
    printf("| Time : %d:%d:%d |\n", entry->hour, entry->minute, entry->second);
    printf("-----------------------------\n");
}

// Update Function
void updateDiaryEntry(DiaryEntry *entry) {
    char input[11];

    printf("Enter new date (dd-mm-yyyy) : ");
    scanf("%s", input);
    sscanf(input, "%d-%d-%d", &entry->day, &entry->month, &entry->year);

    printf("Enter new time (hh:mm:ss) : ");
    scanf("%s", input);
    sscanf(input, "%d:%d:%d", &entry->hour, &entry->minute, &entry->second);
}

// Menu Function
void printMenu() {
    printf("-----------------------------------------\n");
    printf("|             Digital Diary Menu           |\n");
    printf("| 1. Initialize Diary Entry              |\n");
    printf("| 2. Display Diary Entry                |\n");
    printf("| 3. Update Diary Entry                |\n");
    printf("| 4. Exit                              |\n");
    printf("-----------------------------------------\n");
}

int main() {
    DiaryEntry diaryEntry;
    int choice;

    while(1) {
        printMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                initDiaryEntry(&diaryEntry);
                break;
            case 2:
                displayDiaryEntry(&diaryEntry);
                break;
            case 3:
                updateDiaryEntry(&diaryEntry);
                displayDiaryEntry(&diaryEntry);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid Option!\n");
        }
    }

    return 0;
}