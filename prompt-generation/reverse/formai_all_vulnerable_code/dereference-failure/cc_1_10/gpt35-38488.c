//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mailing_list {
    char *name;
    char *address;
    char *email;
    struct mailing_list *next;
};

typedef struct mailing_list MailingList;

void addToList(MailingList **list, char *name, char *address, char *email) {
    MailingList *new_node = (MailingList*) malloc(sizeof(MailingList));
    new_node->name = (char*) malloc(sizeof(char)*(strlen(name)+1));
    strcpy(new_node->name, name);
    new_node->address = (char*) malloc(sizeof(char)*(strlen(address)+1));
    strcpy(new_node->address, address);
    new_node->email = (char*) malloc(sizeof(char)*(strlen(email)+1));
    strcpy(new_node->email, email);
    new_node->next = NULL;
    if(*list == NULL) {
        *list = new_node;
    } else {
        MailingList *current_node = *list;
        while(current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

void removeFromList(MailingList **list, char *name) {
    MailingList *current_node = *list;
    MailingList *previous_node = NULL;

    while(current_node != NULL && strcmp(current_node->name, name) != 0) {
        previous_node = current_node;
        current_node = current_node->next;
    }

    if(current_node == NULL) {
        printf("Sorry, %s is not found in the mailing list\n", name);
    } else {
        if(previous_node == NULL) {
            *list = current_node->next;
        } else {
            previous_node->next = current_node->next;
        }
        free(current_node->name);
        free(current_node->address);
        free(current_node->email);
        free(current_node);
        printf("Farewell, %s has been removed from the mailing list\n", name);
    }
}

int main() {
    MailingList *list = NULL;

    addToList(&list, "Romeo Montague", "Verona, Italy", "romeo@montague.net");
    addToList(&list, "Juliet Capulet", "Verona, Italy", "juliet@capulet.net");

    char name[20];
    printf("Enter name to remove from mailing list: ");
    scanf("%s", name);
    removeFromList(&list, name);

    return 0;
}