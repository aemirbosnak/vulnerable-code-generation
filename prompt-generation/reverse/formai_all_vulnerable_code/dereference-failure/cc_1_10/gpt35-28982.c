//FormAI DATASET v1.0 Category: Digital Diary ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 50

typedef struct {
    int day;
    int month;
    int year;
    char text[255];
} DiaryEntry;

void welcomeMessage();
int readChoice();
void addDiaryEntry(DiaryEntry diary[], int count);
void viewDiaryEntries(DiaryEntry diary[], int count);
void saveDiaryEntries(DiaryEntry diary[], int count);
void loadDiaryEntries(DiaryEntry diary[], int *count);
void diaryMenu();

int main() {
    DiaryEntry diary[MAX_ENTRIES]; 
    int entryCount = 0; 
    int choice;
    
    loadDiaryEntries(diary, &entryCount);
    do {
        diaryMenu();
        choice = readChoice();
        switch(choice) {
            case 1:
                addDiaryEntry(diary, entryCount);
                entryCount++;
                break;
            case 2:
                viewDiaryEntries(diary, entryCount);
                break;
            case 3: 
                saveDiaryEntries(diary, entryCount);
                break;
            case 4: 
                printf("Exiting the diary program...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 4);

    return 0;
}

void diaryMenu() {
    printf("\n======= Digital Diary Menu =======\n");
    printf("1. Add diary entry\n");
    printf("2. View diary entries\n");
    printf("3. Save diary entries\n");
    printf("4. Exit\n");
    printf("===================================\n");
}

void welcomeMessage() {
    printf("Welcome to your digital diary!\n");
}

int readChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void addDiaryEntry(DiaryEntry diary[], int count) {
    DiaryEntry entry;
    printf("\nEnter the date of the diary entry (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &entry.day, &entry.month, &entry.year);
    printf("Enter the text of the diary entry (max 255 characters):\n");
    getchar(); 
    fgets(entry.text, 255, stdin);
    strcpy(diary[count].text, entry.text);
    diary[count].day = entry.day;
    diary[count].month = entry.month;
    diary[count].year = entry.year;
    printf("Diary entry added successfully\n");
}

void viewDiaryEntries(DiaryEntry diary[], int count) {
    int i;
    printf("\n========== Diary Entries ==========\n");
    for(i=0; i<count; i++) {
        printf("Date: %02d/%02d/%d\n", diary[i].day, diary[i].month, diary[i].year);
        printf("Entry: %s", diary[i].text);
        printf("\n");
    }
}

void saveDiaryEntries(DiaryEntry diary[], int count) {
    FILE *fp;
    int i;

    fp = fopen("diary.txt", "w");
    if(fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    for(i=0; i<count; i++) {
        fprintf(fp, "%02d/%02d/%d\n%s\n", diary[i].day, diary[i].month, diary[i].year, diary[i].text);
    }
    fclose(fp);
    printf("Diary entries saved to file successfully\n");
}

void loadDiaryEntries(DiaryEntry diary[], int *count) {
    FILE *fp;
    DiaryEntry entry;
    char line[255];
    char *dateString;

    fp = fopen("diary.txt", "r");
    if(fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    while(fgets(line, 255, fp)) {
        dateString = strtok(line, "/");
        entry.day = atoi(dateString);
        dateString = strtok(NULL, "/");
        entry.month = atoi(dateString);
        dateString = strtok(NULL, "\n");
        entry.year = atoi(dateString);

        fgets(entry.text, 255, fp);
        strcpy(diary[*count].text, entry.text);
        diary[*count].day = entry.day;
        diary[*count].month = entry.month;
        diary[*count].year = entry.year;
        (*count)++;
    }
    fclose(fp);
    printf("Diary entries loaded from file successfully\n");
}