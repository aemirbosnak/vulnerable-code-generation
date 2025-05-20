//FormAI DATASET v1.0 Category: Digital Diary ; Style: distributed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ENTRIES_PER_PAGE 10

struct DiaryEntry {
    int id;
    char date[11];
    char content[1001];
};

struct Page {
    int pageNumber;
    struct DiaryEntry entries[ENTRIES_PER_PAGE];
    struct Page* next;
};

struct Page* createNewPage(int pageNumber) {
    struct Page* newPage = (struct Page*) malloc(sizeof(struct Page));
    newPage->pageNumber = pageNumber;
    newPage->next = NULL;
    for (int i = 0; i < ENTRIES_PER_PAGE; i++) {
        newPage->entries[i].id = 0;
        strcpy(newPage->entries[i].date, "");
        strcpy(newPage->entries[i].content, "");
    }
    return newPage;
}

struct Page* addNewEntry(struct Page* head) {
    struct DiaryEntry newEntry;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char currentDate[11];
    sprintf(currentDate, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    strcpy(newEntry.date, currentDate);
    printf("\nEnter your diary entry for %s:\n", currentDate);
    fgets(newEntry.content, 1001, stdin);
    for (struct Page* ptr = head; ptr != NULL; ptr = ptr->next) {
        for (int i = 0; i < ENTRIES_PER_PAGE; i++) {
            if (ptr->entries[i].id == 0) {
                ptr->entries[i].id = ptr->pageNumber * ENTRIES_PER_PAGE + i + 1;
                strcpy(ptr->entries[i].date, newEntry.date);
                strcpy(ptr->entries[i].content, newEntry.content);
                printf("\nEntry added with ID %d\n", ptr->entries[i].id);
                return head;
            }
        }
        if (ptr->next == NULL) {
            struct Page* newPage = createNewPage(ptr->pageNumber + 1);
            ptr->next = newPage;
            printf("\nNew page created, entry added with ID %d\n", newPage->entries[0].id);
            newPage->entries[0] = newEntry;
            newPage->entries[0].id = newPage->pageNumber * ENTRIES_PER_PAGE + 1;
            return head;
        }
    }
    return head;
}

void printEntry(struct DiaryEntry entry) {
    printf("\n[ID: %d]\nDate: %s\nContent: %s\n", entry.id, entry.date, entry.content);
}

void printAllEntries(struct Page* head) {
    int counter = 0;
    for (struct Page* ptr = head; ptr != NULL; ptr = ptr->next) {
        for (int i = 0; i < ENTRIES_PER_PAGE; i++) {
            if (ptr->entries[i].id != 0) {
                printEntry(ptr->entries[i]);
                counter++;
            }
        }
    }
    if (counter == 0) {
        printf("\nThere are no diary entries yet.\n");
    }
}

void searchEntries(struct Page* head) {
    char keyword[1001];
    printf("\nEnter a keyword to search for:\n");
    fgets(keyword, 1001, stdin);
    int counter = 0;
    for (struct Page* ptr = head; ptr != NULL; ptr = ptr->next) {
        for (int i = 0; i < ENTRIES_PER_PAGE; i++) {
            if (ptr->entries[i].id != 0) {
                if (strstr(ptr->entries[i].content, keyword) != NULL) {
                    printEntry(ptr->entries[i]);
                    counter++;
                }
            }
        }
    }
    if (counter == 0) {
        printf("\nNo entries matching the keyword \"%s\" were found.\n", keyword);
    }
}

int main() {
    struct Page* head = createNewPage(1);

    while (1) {
        printf("Digital Diary Menu\n");
        printf("1. Add new entry\n");
        printf("2. Print all entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("Enter your choice:\n");

        char choice[2];
        fgets(choice, 2, stdin);

        switch (choice[0]) {
            case '1': 
                head = addNewEntry(head);
                break;
            case '2':
                printAllEntries(head);
                break;
            case '3':
                searchEntries(head);
                break;
            case '4':
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }

    return 0;
}