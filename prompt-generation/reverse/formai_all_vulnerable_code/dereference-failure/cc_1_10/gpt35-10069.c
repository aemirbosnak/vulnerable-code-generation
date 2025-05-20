//FormAI DATASET v1.0 Category: Digital Diary ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void displayMenu();
void addEntry();
void viewEntries();
void deleteEntry();
void searchEntries();

typedef struct DiaryEntry {
    int day, month, year;
    char message[1000];
} Entry;

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                searchEntries();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 5);

    return 0;
}

void displayMenu() {
    printf("---------------------------------------------------------------\n");
    printf("DIGITAL DIARY\n");
    printf("---------------------------------------------------------------\n");
    printf("1. Add an entry\n");
    printf("2. View entries\n");
    printf("3. Delete an entry\n");
    printf("4. Search entries\n");
    printf("5. Exit\n");
    printf("---------------------------------------------------------------\n");
    printf("Enter your choice: ");
}

void addEntry() {
    FILE *fp;
    Entry newEntry;
    fp = fopen("diary.txt", "a");
    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("Enter date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &newEntry.day, &newEntry.month, &newEntry.year);
    getchar();
    printf("Enter message:\n");
    fgets(newEntry.message, 1000, stdin);
    fprintf(fp, "%d/%d/%d %s\n", newEntry.day, newEntry.month, newEntry.year, newEntry.message);
    fclose(fp);
    printf("Entry added successfully!\n");
}

void viewEntries() {
    FILE *fp;
    char c;
    fp = fopen("diary.txt", "r");
    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    printf("---------------------------------------------------------------\n");
    printf("VIEW ENTRIES\n");
    printf("---------------------------------------------------------------\n");
    while((c = getc(fp)) != EOF) {
        printf("%c", c);
    }
    fclose(fp);
    printf("---------------------------------------------------------------\n");
}

void deleteEntry() {
    FILE *fp1, *fp2;
    char date[11], message[1000], temp[1000];
    int flag = 0;
    fp1 = fopen("diary.txt", "r");
    fp2 = fopen("tempDiary.txt", "w");
    if(fp1 == NULL || fp2 == NULL) {
        printf("Error opening files!\n");
        exit(1);
    }
    printf("Enter date of entry to be deleted (dd/mm/yyyy): ");
    scanf("%s", date);
    while(fgets(temp, 1000, fp1) != NULL) {
        strcpy(message, temp + 11);
        if(strncmp(temp, date, 10) == 0) {
            flag = 1;
            continue;
        }
        fprintf(fp2, "%s", temp);
    }
    fclose(fp1);
    fclose(fp2);
    if(flag == 0) {
        printf("Entry not found!\n");
        remove("tempDiary.txt");
    }
    else {
        remove("diary.txt");
        rename("tempDiary.txt", "diary.txt");
        printf("Entry deleted successfully!\n");
    }
}

void searchEntries() {
    FILE *fp;
    char date[11], message[1000], temp[1000];
    int flag = 0;
    fp = fopen("diary.txt", "r");
    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    printf("Enter date of entry to search for (dd/mm/yyyy): ");
    scanf("%s", date);
    printf("---------------------------------------------------------------\n");
    printf("SEARCH RESULTS\n");
    printf("---------------------------------------------------------------\n");
    while(fgets(temp, 1000, fp) != NULL) {
        strcpy(message, temp + 11);
        if(strncmp(temp, date, 10) == 0) {
            flag = 1;
            printf("%s", temp);
        }
    }
    fclose(fp);
    if(flag == 0) {
        printf("No entries found!\n");
    }
    printf("---------------------------------------------------------------\n");
}