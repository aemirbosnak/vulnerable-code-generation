//FormAI DATASET v1.0 Category: Digital Diary ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 1000

// Structure to store diary entry details
struct entry {
    char date[12];
    char title[50];
    char content[MAX_SIZE];
};

// Function to create an entry in the diary
void createEntry() {
    struct entry e;
    printf("\nEnter the date (DD-MM-YYYY): ");
    scanf("%s", e.date);
    printf("Enter the title: ");
    scanf(" %[^\n]s", e.title);
    printf("Enter the content:\n");
    scanf(" %[^\n]s", e.content);
    // Append the diary file with the new entry
    FILE *fp = fopen("diary.txt", "a");
    fprintf(fp, "%s\n%s\n%s\n", e.date, e.title, e.content);
    fclose(fp);
    printf("\nEntry added successfully!\n");
}

// Function to view all entries in the diary
void viewEntries() {
    char str[MAX_SIZE];
    FILE *fp = fopen("diary.txt", "r");
    if (fp == NULL) {
        printf("\nDiary is empty!\n");
        return;
    }
    while (fgets(str, MAX_SIZE, fp) != NULL) {
        printf("%s", str);
    }
    fclose(fp);
}

// Function to search for an entry in the diary
void searchEntry() {
    char str[MAX_SIZE], search[MAX_SIZE];
    printf("\nEnter the search query: ");
    scanf(" %[^\n]s", search);
    FILE *fp = fopen("diary.txt", "r");
    if (fp == NULL) {
        printf("\nDiary is empty!\n");
        return;
    }
    while (fgets(str, MAX_SIZE, fp) != NULL) {
        if (strstr(str, search) != NULL) {
            printf("%s", str);
            fgets(str, MAX_SIZE, fp);
            printf("%s", str);
            fgets(str, MAX_SIZE, fp);
            printf("%s", str);
        }
    }
    fclose(fp);
}

// Function to delete an entry from the diary
void deleteEntry() {
    struct entry e;
    FILE *fpr = fopen("diary.txt", "r");
    FILE *fpw = fopen("temp.txt", "w");
    char date[12];
    int flag = 0;
    printf("\nEnter the date of the entry to be deleted: ");
    scanf("%s", date);
    while (fgets(e.date, 12, fpr) != NULL) {
        fgets(e.title, 50, fpr);
        fgets(e.content, MAX_SIZE, fpr);
        if (strcmp(e.date, date) == 0) {
            flag = 1;
            continue;
        }
        fprintf(fpw, "%s%s%s", e.date, e.title, e.content);
    }
    fclose(fpr);
    fclose(fpw);
    if (flag == 0) {
        printf("\nEntry not found!\n");
        remove("temp.txt");
        return;
    }
    remove("diary.txt");
    rename("temp.txt", "diary.txt");
    printf("\nEntry deleted successfully!\n");
}

int main() {
    int choice;
    do {
        printf("\nDigital Diary");
        printf("\n1. Create Entry");
        printf("\n2. View Entries");
        printf("\n3. Search Entries");
        printf("\n4. Delete Entry");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: createEntry();
                    break;
            case 2: viewEntries();
                    break;
            case 3: searchEntry();
                    break;
            case 4: deleteEntry();
                    break;
            case 5: printf("\nExiting...\n");
                    break;
            default: printf("\nInvalid choice!\n");
                     break;
        }
    } while(choice != 5);
    return 0;
}