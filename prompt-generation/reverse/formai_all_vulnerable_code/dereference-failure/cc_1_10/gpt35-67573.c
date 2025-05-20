//FormAI DATASET v1.0 Category: Digital Diary ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//Structure to store diary entries
struct Node {
    char date[25];
    char entry[1000];
    struct Node* next;
};

//Function to display all diary entries
void display_diary(struct Node* head) {
    if (head == NULL) {
        printf("You have not written any entries yet!\n");
        return;
    }
    printf("Here are all your diary entries:\n\n");
    int i = 1;
    while (head != NULL) {
        printf("Entry %d\n", i++);
        printf("Date: %s\n", head->date);
        printf("Entry: %s\n\n", head->entry);
        head = head->next;
    }
}

//Function to add new diary entry
struct Node* add_entry(struct Node* head) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter today's date (DD/MM/YYYY): ");
    scanf("%s", new_node->date);
    printf("Start writing your diary entry for %s:\n", new_node->date);
    getchar();
    fgets(new_node->entry, 1000, stdin);
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    }
    else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    printf("Your diary entry has been added successfully!\n");
    return head;
}

//Function to delete a diary entry
struct Node* delete_entry(struct Node* head) {
    if (head == NULL) {
        printf("You have not written any entries yet!\n");
        return head;
    }
    printf("Enter the date (DD/MM/YYYY) of the entry you want to delete: ");
    char date[25];
    scanf("%s", date);
    struct Node* temp1 = head;
    struct Node* temp2 = head->next;
    //If head node needs to be deleted
    if (strcmp(temp1->date, date) == 0) {
        head = head->next;
        free(temp1);
        printf("The diary entry for %s has been deleted successfully!\n", date);
        return head;
    }
    //If non-head node needs to be deleted
    while (temp2 != NULL) {
        if (strcmp(temp2->date, date) == 0) {
            temp1->next = temp2->next;
            free(temp2);
            printf("The diary entry for %s has been deleted successfully!\n", date);
            return head;
        }
        temp1 = temp2;
        temp2 = temp2->next;
    }
    printf("No diary entry found for %s!\n", date);
    return head;
}

int main() {
    printf("Welcome to your Digital Diary!\n");
    struct Node* head = NULL;
    int choice;
    while (1) {
        printf("Please choose an option:\n");
        printf("1. Display all diary entries\n");
        printf("2. Add a new diary entry\n");
        printf("3. Delete a diary entry\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_diary(head);
                break;
            case 2:
                head = add_entry(head);
                break;
            case 3:
                head = delete_entry(head);
                break;
            case 4:
                printf("Thank you for using Digital Diary!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}