//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Member {
    char email[100];
    struct Member* next;
} Member;

typedef struct MailingList {
    Member* head;
    int count;
} MailingList;

MailingList* createMailingList() {
    MailingList* list = (MailingList*)malloc(sizeof(MailingList));
    list->head = NULL;
    list->count = 0;
    return list;
}

void addMember(MailingList* list, const char* email) {
    Member* newMember = (Member*)malloc(sizeof(Member));
    strcpy(newMember->email, email);
    newMember->next = list->head;
    list->head = newMember;
    list->count++;
    printf("Added %s to the mailing list.\n", email);
}

void deleteMember(MailingList* list, const char* email) {
    Member* current = list->head;
    Member* previous = NULL;

    while (current != NULL && strcmp(current->email, email) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Email %s not found in the mailing list.\n", email);
        return;
    }

    if (previous == NULL) {
        list->head = current->next; // Deleting the head
    } else {
        previous->next = current->next; // Bypass deleted member
    }

    free(current);
    list->count--;
    printf("Deleted %s from the mailing list.\n", email);
}

void displayMailingList(MailingList* list) {
    if (list->count == 0) {
        printf("The mailing list is currently empty.\n");
        return;
    }

    printf("Current Mailing List members:\n");
    Member* current = list->head;
    while (current != NULL) {
        printf("- %s\n", current->email);
        current = current->next;
    }
}

void saveMailingListToFile(MailingList* list, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    Member* current = list->head;
    while (current != NULL) {
        fprintf(file, "%s\n", current->email);
        current = current->next;
    }
    
    fclose(file);
    printf("Mailing list saved to %s.\n", filename);
}

void freeMailingList(MailingList* list) {
    Member* current = list->head;
    while (current != NULL) {
        Member* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

int main() {
    MailingList* mailingList = createMailingList();
    int choice;
    char email[100];
    const char* filename = "mailing_list.txt";

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add Member\n");
        printf("2. Delete Member\n");
        printf("3. Display Members\n");
        printf("4. Save to File\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                addMember(mailingList, email);
                break;
            case 2:
                printf("Enter email to delete: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0;
                deleteMember(mailingList, email);
                break;
            case 3:
                displayMailingList(mailingList);
                break;
            case 4:
                saveMailingListToFile(mailingList, filename);
                break;
            case 5:
                freeMailingList(mailingList);
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}