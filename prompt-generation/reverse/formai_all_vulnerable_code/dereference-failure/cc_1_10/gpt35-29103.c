//FormAI DATASET v1.0 Category: Digital Diary ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct DiaryEntry {
    char date[11];
    char title[50];
    char content[1000];
    struct DiaryEntry* next;
};

typedef struct DiaryEntry Diary;

// Function to display the menu
void display_menu() {
    printf("1. Add an entry\n");
    printf("2. View all entries\n");
    printf("3. Search for an entry\n");
    printf("4. Delete an entry\n");
    printf("5. Exit\n");
}

// Function to add a new diary entry
Diary* add_entry(Diary* head) {
    Diary* new_entry = (Diary*)malloc(sizeof(Diary));
    time_t t = time(NULL);
    struct tm* timeptr = localtime(&t);
    strftime(new_entry->date, 11, "%d/%m/%Y", timeptr);
    printf("Enter the title: ");
    scanf(" %[^\n]s",new_entry->title);
    printf("Enter the content: ");
    scanf(" %[^\n]s",new_entry->content);
    new_entry->next = head;
    head = new_entry;
    printf("Entry added successfully!\n");
    return head;
}

// Function to view all diary entries
void view_entries(Diary* head) {
    Diary* current = head;
    if(current == NULL) {
        printf("No entries found!\n");
        return;
    }
    int count = 1;
    while(current != NULL) {
        printf("\nEntry %d:\nDate: %s\n", count, current->date);
        printf("Title: %s\n", current->title);
        printf("Content: %s\n", current->content);
        current = current->next;
        count++;
    }
}

// Function to search for a diary entry
void search_entry(Diary* head) {
    Diary* current = head;
    if(current == NULL) {
        printf("No entries found!\n");
        return;
    }
    char search_term[50];
    printf("Enter the search term: ");
    scanf(" %[^\n]s", search_term);
    int count = 0;
    while(current != NULL) {
        if(strstr(current->title, search_term) || strstr(current->content, search_term)) {
            printf("\nResult %d:\nDate: %s\n", count+1, current->date);
            printf("Title: %s\n", current->title);
            printf("Content: %s\n", current->content);
            count++;
        }
        current = current->next;
    }
    if(count == 0) {
        printf("No matches found for '%s'.\n", search_term);
    }
}

// Function to delete a diary entry
Diary* delete_entry(Diary* head) {
    Diary* current = head;
    Diary* prev = NULL;
    if(current == NULL) {
        printf("No entries found!\n");
        return NULL;
    }
    char delete_title[50];
    printf("Enter the title of the entry to be deleted: ");
    scanf(" %[^\n]s", delete_title);
    while(current != NULL) {
        if(strcmp(current->title, delete_title) == 0) {
            if(prev == NULL) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }
            free(current);
            printf("Entry successfully deleted!\n");
            return head;
        }
        prev = current;
        current = current->next;
    }
    printf("No entry found with title '%s'.\n", delete_title);
    return head;
}

int main() {
    Diary* head = NULL;
    int choice;
    do {
        display_menu();
        printf("Enter choice: ");
        scanf(" %d", &choice);
        switch(choice) {
            case 1: 
                head = add_entry(head);
                break;
            case 2:
                view_entries(head);
                break;
            case 3:
                search_entry(head);
                break;
            case 4:
                head = delete_entry(head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 5);
    return 0;
}