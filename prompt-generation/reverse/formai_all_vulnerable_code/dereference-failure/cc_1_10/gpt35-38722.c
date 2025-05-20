//FormAI DATASET v1.0 Category: Digital Diary ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

struct Entry {
    char date[20];
    char title[50];
    char content[1000];
};

void printHeader() {
    printf("\n=============================================\n");
    printf("|               DIGITAL DIARY               |\n");
    printf("=============================================\n\n");
}

void printMenu() {
    printf("1. Create a new entry\n");
    printf("2. View a specific entry\n");
    printf("3. View all entries\n");
    printf("4. Exit\n");
    printf("\nChoose an option: ");
}

void createEntry(struct Entry entries[], int *count) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char date[20];
    snprintf(date, 20, "%d-%02d-%02d", tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday);

    printf("\nEnter the title: ");
    char title[50];
    scanf(" %[^\n]", title);

    printf("Enter the content:\n");
    char content[1000];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, stdin)) != -1) {
        strcat(content, line);
        if (strlen(content) >= 980) {
            printf("The entry is too long. Maximum of 1000 characters allowed.\n");
            free(line);
            return;
        }
    }
    free(line);

    strcpy(entries[*count].date, date);
    strcpy(entries[*count].title, title);
    strcpy(entries[*count].content, content);
    (*count)++;
    printf("\nEntry created successfully!\n");
}

void viewSpecificEntry(struct Entry entries[], int count) {
    if (count == 0) {
        printf("\nThere are no entries to view.\n");
        return;
    }

    printf("\nEnter the date of the entry you want to view (YYYY-MM-DD): ");
    char date[20];
    scanf(" %[^\n]", date);

    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].date, date) == 0) {
            printf("\nDate : %s\n", entries[i].date);
            printf("Title: %s\n", entries[i].title);
            printf("Content:\n%s\n", entries[i].content);
            return;
        }
    }
    printf("\nNo entry found for that date.\n");
}

void viewAllEntries(struct Entry entries[], int count) {
    if (count == 0) {
        printf("\nThere are no entries to view.\n");
        return;
    }

    printf("\nAll entries:\n\n");
    for (int i = 0; i < count; i++) {
        printf("Date : %s\n", entries[i].date);
        printf("Title: %s\n", entries[i].title);
    }
}

int main() {
    struct Entry entries[MAX_ENTRIES];
    int count = 0;
    int choice;

    printHeader();

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createEntry(entries, &count);
                break;

            case 2:
                viewSpecificEntry(entries, count);
                break;

            case 3:
                viewAllEntries(entries, count);
                break;

            case 4:
                printf("\nThank you for using DIGITAL DIARY. Goodbye!\n\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice. Please choose again.\n");
                break;
        }
    } while (1);

    return 0;
}