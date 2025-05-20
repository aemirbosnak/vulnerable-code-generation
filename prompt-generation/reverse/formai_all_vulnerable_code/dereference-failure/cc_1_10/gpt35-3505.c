//FormAI DATASET v1.0 Category: Digital Diary ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_FILENAME 100

typedef struct {
    char date[11];
    char entry[1000];
} DiaryEntry;

void clearScreen() {
    system("clear");
}

void getDate(char* date) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date, "%02d-%02d-%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

int loadEntries(DiaryEntry* diary) {
    int numEntries = 0;
    FILE* fp;
    fp = fopen("diary.txt", "r");
    if (fp == NULL) {
        return 0;
    }
    while (!feof(fp) && numEntries < MAX_ENTRIES) {
        fscanf(fp, "%s %s\n", diary[numEntries].date, diary[numEntries].entry);
        numEntries++;
    }
    fclose(fp);
    return numEntries;
}

void saveEntries(DiaryEntry* diary, int numEntries) {
    FILE* fp;
    fp = fopen("diary.txt", "w");
    for (int i = 0; i < numEntries; i++) {
        fprintf(fp, "%s %s\n", diary[i].date, diary[i].entry);
    }
    fclose(fp);
}

void addEntry(DiaryEntry* diary, int* numEntries, char* date) {
    char entry[1000];
    clearScreen();
    printf("Enter your diary entry for the date %s:\n", date);
    fgets(entry, 1000, stdin);
    entry[strcspn(entry, "\n")] = 0;
    strcpy(diary[*numEntries].date, date);
    strcpy(diary[*numEntries].entry, entry);
    (*numEntries)++;
    saveEntries(diary, *numEntries);
    clearScreen();
    printf("Entry added successfully!\n");
}

void printEntries(DiaryEntry* diary, int numEntries) {
    clearScreen();
    if (numEntries == 0) {
        printf("No entries found.\n");
        return;
    }
    printf("My Digital Diary\n");
    printf("================\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s\n", diary[i].date);
        printf("----------------\n");
        printf("%s\n\n", diary[i].entry);
    }
}

void deleteEntry(DiaryEntry* diary, int* numEntries) {
    char date[11];
    int found = 0;
    clearScreen();
    printf("Enter the date of the entry you want to delete (dd-mm-yyyy):\n");
    scanf("%s", date);
    for (int i = 0; i < *numEntries; i++) {
        if (strcmp(diary[i].date, date) == 0) {
            found = 1;
            for (int j = i; j < *numEntries - 1; j++) {
                strcpy(diary[j].date, diary[j + 1].date);
                strcpy(diary[j].entry, diary[j + 1].entry);
            }
            (*numEntries)--;
            saveEntries(diary, *numEntries);
            clearScreen();
            printf("Entry deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Entry not found.\n");
    }
}

void showMenu() {
    clearScreen();
    printf("My Digital Diary\n");
    printf("================\n");
    printf("1. View entries\n");
    printf("2. Add new entry\n");
    printf("3. Delete an entry\n");
    printf("4. Exit\n");
}

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int numEntries = loadEntries(diary);
    char date[11];
    int choice;
    do {
        getDate(date);
        showMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printEntries(diary, numEntries);
                break;
            case 2:
                addEntry(diary, &numEntries, date);
                break;
            case 3:
                deleteEntry(diary, &numEntries);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\nPress enter to continue...");
        getchar();
        getchar();
    } while (choice != 4);

    return 0;
}