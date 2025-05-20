//FormAI DATASET v1.0 Category: Digital Diary ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_ENTRIES 50
#define MAX_ENTRY_LENGTH 200

struct Entry {
    char *date;
    char *text;
    struct Entry *next;
};

struct Diary {
    struct Entry *head;
    int entries;
};

/* Function to create a new entry */
void createEntry(struct Diary *diary) {
    char text[MAX_ENTRY_LENGTH];
    char *date = (char*)malloc(sizeof(char) * 20);

    time_t now = time(NULL);
    strftime(date, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));

    printf("Enter the entry text (Maximum 200 characters):\n");
    scanf(" %[^\n]s", text);

    struct Entry *entry = (struct Entry*)malloc(sizeof(struct Entry));
    entry->date = date;
    entry->text = (char*)malloc(sizeof(char) * (strlen(text) + 1));
    strcpy(entry->text, text);
    entry->next = NULL;

    if(diary->head == NULL) {
        diary->head = entry;
    } else {
        struct Entry *temp = diary->head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = entry;
    }
    diary->entries++;
}

/* Function to delete an entry */
void deleteEntry(struct Diary *diary) {
    if(diary->head == NULL) {
        printf("Diary is empty! No entries to delete.\n");
        return;
    }

    char date[20];
    printf("Enter the date (YYYY-MM-DD HH:MM:SS format) of the entry you want to delete:\n");
    scanf(" %[^\n]s", date);

    struct Entry *temp = diary->head;
    struct Entry *prev = NULL;

    while(temp != NULL && strcmp(temp->date, date) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("No entry found with the given date.\n");
        return;
    }

    if(prev == NULL) {
        diary->head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp->date);
    free(temp->text);
    free(temp);
    diary->entries--;
    printf("Entry deleted successfully!\n");
}

/* Function to display all entries */
void displayAllEntries(struct Diary *diary) {
    if(diary->head == NULL) {
        printf("Diary is empty! No entries to display.\n");
        return;
    }

    struct Entry *temp = diary->head;
    while(temp != NULL) {
        printf("Date: %s\n", temp->date);
        printf("Entry: %s\n", temp->text);
        temp = temp->next;
    }
}

/* Function to display menu */
void displayMenu() {
    printf("\n\n");
    printf("Welcome to Digital Diary App\n");
    printf("----------------------------\n");
    printf("1. Create new entry\n");
    printf("2. Delete an entry\n");
    printf("3. Display all entries\n");
    printf("4. Exit\n");
    printf("----------------------------\n");
    printf("Enter your choice (1-4):\n");
}

int main() {
    struct Diary diary;
    diary.head = NULL;
    diary.entries = 0;

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createEntry(&diary);
                break;
            case 2:
                deleteEntry(&diary);
                break;
            case 3:
                displayAllEntries(&diary);
                break;
            case 4:
                printf("Thank you for using Digital Diary App. Goodbye!\n");
                break;
            default:
                printf("Invalid Input! Please try again.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}