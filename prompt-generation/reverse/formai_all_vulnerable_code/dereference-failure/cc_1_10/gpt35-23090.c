//FormAI DATASET v1.0 Category: Digital Diary ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct digital_diary {
    char title[50];
    char content[500];
    int day;
    int month;
    int year;
    struct digital_diary* next;
};

struct digital_diary* head = NULL;

void add_entry() {
    struct digital_diary* new_entry = (struct digital_diary*)malloc(sizeof(struct digital_diary));
    printf("Enter title: ");
    scanf("%s", new_entry->title);
    printf("Enter content: ");
    scanf(" %[^\n]s", new_entry->content);
    printf("Enter date (dd mm yyyy): ");
    scanf("%d %d %d", &new_entry->day, &new_entry->month, &new_entry->year);
    new_entry->next = NULL;
    if (head == NULL) {
        head = new_entry;
    } else {
        struct digital_diary* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_entry;
    }
}

void view_entries() {
    struct digital_diary* temp = head;
    while(temp != NULL) {
        printf("\nTitle : %s\n", temp->title);
        printf("Date : %d-%d-%d\n", temp->day,temp->month,temp->year);
        printf("Content : %s\n", temp->content);
        temp = temp->next;
    }
}

void search_entry() {
    int search_day,search_month,search_year;
    printf("Enter date to be searched (dd mm yyyy): ");
    scanf("%d %d %d",&search_day,&search_month,&search_year);
    struct digital_diary* temp = head;
    while(temp != NULL) {
        if(temp->day == search_day && temp->month == search_month && temp->year == search_year){
            printf("\nTitle : %s\n", temp->title);
            printf("Date : %d-%d-%d\n", temp->day,temp->month,temp->year);
            printf("Content : %s\n", temp->content);
            return;
        }
        temp = temp->next;
    }
    printf("Entry not found for date: %d-%d-%d\n",search_day,search_month,search_year);
}

void delete_entry() {
    int del_day,del_month,del_year;
    printf("Enter date of entry to be deleted (dd mm yyyy): ");
    scanf("%d %d %d",&del_day,&del_month,&del_year);
    struct digital_diary* curr = head;
    struct digital_diary* prev = NULL;
    while(curr != NULL) {
        if(curr->day == del_day && curr->month == del_month && curr->year == del_year) {
            if(prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            printf("Entry for date %d-%d-%d has been deleted.\n",del_day,del_month,del_year);
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Entry not found for date: %d-%d-%d\n",del_day,del_month,del_year);
}

int main() {
    printf("\n---Welcome to Digital Diary Manager---\n");
    int choice;
    do {
        printf("\nChoose an action:\n");
        printf("1. Add Diary Entry\n");
        printf("2. View All Entries\n");
        printf("3. Search for an Entry\n");
        printf("4. Delete an Entry\n");
        printf("5. Exit\n");
        printf("Enter choice (1-5): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                delete_entry();
                break;
            case 5:
                printf("\nThank you for using Digital Diary Manager!\n");
                break;
            default:
                printf("\nInvalid choice. Please choose between 1-5.\n");
        }
    } while(choice != 5);
    return 0;
}