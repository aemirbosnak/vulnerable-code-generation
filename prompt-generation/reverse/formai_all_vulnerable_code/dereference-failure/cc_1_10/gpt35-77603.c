//FormAI DATASET v1.0 Category: Mailing list manager ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

//Structure for each email node in the Linked List
typedef struct Email {
    char *email_address;
    struct Email *next;
} Email;

//Structure for the mailing list
typedef struct MailingList {
    char *name;
    Email *emails;
} MailingList;

//Function to create a new mailing list
MailingList* createList(char *name) {
    MailingList *new_list = (MailingList*) malloc(sizeof(MailingList));
    new_list->name = name;
    new_list->emails = NULL;
    return new_list;
}

//Function to add a new email to the mailing list
void addEmail(MailingList *list, char *email) {
    Email *new_email = (Email*) malloc(sizeof(Email));
    new_email->email_address = email;
    new_email->next = NULL;

    if(list->emails == NULL) {
        list->emails = new_email;
    } else {
        Email *current = list->emails;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = new_email;
    }
}

//Function to print the mailing list
void printList(MailingList *list) {
    printf("Mailing List: %s\n", list->name);
    Email *current = list->emails;
    while(current != NULL) {
        printf("%s\n", current->email_address);
        current = current->next;
    }
}

//Function to delete an email from the mailing list
void deleteEmail(MailingList *list, char *email) {
    Email *current = list->emails;
    Email *prev = NULL;
    while(current != NULL) {
        if(current->email_address == email) {
            if(prev == NULL) {
                list->emails = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

//Main Function
int main() {
    MailingList *list1 = createList("Friends");
    addEmail(list1, "friend1@gmail.com");
    addEmail(list1, "friend2@gmail.com");
    addEmail(list1, "friend3@gmail.com");
    printList(list1);
    deleteEmail(list1, "friend2@gmail.com");
    printList(list1);
    return 0;
}