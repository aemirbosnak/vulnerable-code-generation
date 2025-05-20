//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_ENTRY 100

typedef struct DiaryEntry {
    char title[50];
    char content[200];
    int id;
    struct DiaryEntry *next;
} DiaryEntry;

DiaryEntry *head = NULL;

void addEntry(char *title, char *content) {
    DiaryEntry *newEntry = (DiaryEntry *) malloc(sizeof(DiaryEntry));
    if (newEntry == NULL) {
        printf("Error: Failed to allocate memory\n");
        return;
    }

    strcpy(newEntry->title, title);
    strcpy(newEntry->content, content);
    newEntry->id = head ? head->id + 1 : 1;
    newEntry->next = head;
    head = newEntry;
}

void displayMenu() {
    printf("\n-----------------------------\n");
    printf("|    Intelligent Diary        |\n");
    printf("|                            |\n");
    printf("|    1. Add new entry         |\n");
    printf("|    2. View entry            |\n");
    printf("|    3. Delete entry          |\n");
    printf("|    4. Search entry          |\n");
    printf("|    5. Exit                  |\n");
    printf("------------------------------\n");
}

void searchEntry(char *keyword) {
    DiaryEntry *current = head;

    while (current != NULL) {
        if (strstr(current->content, keyword) != NULL) {
            printf("\nEntry ID: %d", current->id);
            printf("\nTitle: %s", current->title);
            printf("\nContent: %s", current->content);
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Error: Entry not found\n");
    }
}

int main() {
    char title[50], content[200], keyword[50];
    int choice;

    srand(time(NULL));

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter content: ");
                scanf("%[^\n]s", content);
                addEntry(title, content);
                printf("Entry added successfully.\n");
                break;
            case 2:
                if (head == NULL) {
                    printf("Error: No entries found\n");
                    break;
                }
                printf("\nEntry ID: %d", head->id);
                printf("\nTitle: %s", head->title);
                printf("\nContent: %s\n", head->content);
                head = head->next;
                break;
            case 3:
                if (head == NULL) {
                    printf("Error: No entries found\n");
                    break;
                }
                DiaryEntry *temp = head;
                head = head->next;
                free(temp);
                printf("Entry deleted successfully.\n");
                break;
            case 4:
                printf("Enter keyword to search: ");
                scanf("%s", keyword);
                searchEntry(keyword);
                break;
            case 5:
                exit(0);
            default:
                printf("Error: Invalid choice\n");
        }
    }

    return 0;
}