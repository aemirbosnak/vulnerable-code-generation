//FormAI DATASET v1.0 Category: Mailing list manager ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a maximum email length for convenience
#define MAX_EMAIL_LENGTH 256 

// define a struct to represent an email node
typedef struct EmailNode {
    char email[MAX_EMAIL_LENGTH];
    struct EmailNode* next;
} EmailNode;

// define a struct to represent the mailing list
typedef struct MailingList {
    EmailNode* head;
    int size;
} MailingList;

// function to add an email to the mailing list
void add_email(MailingList* list, char* email) {
    // create a new email node
    EmailNode* new_node = (EmailNode*)malloc(sizeof(EmailNode));
    strcpy(new_node->email, email);
    new_node->next = NULL;
    
    // if the list is empty, the new node becomes the head
    if (list->head == NULL) {
        list->head = new_node;
    }
    // otherwise, link the new node to the end of the list
    else {
        EmailNode* cur_node = list->head;
        while (cur_node->next != NULL) {
            cur_node = cur_node->next;
        }
        cur_node->next = new_node;
    }
    
    // increment the size of the list
    list->size++;
}

// function to remove an email from the mailing list
void remove_email(MailingList* list, char* email) {
    // if the list is empty, do nothing
    if (list->head == NULL) {
        return;
    }
    
    // if the head node matches the given email, remove it
    if (strcmp(list->head->email, email) == 0) {
        EmailNode* temp_node = list->head;
        list->head = list->head->next;
        free(temp_node);
        list->size--;
        return;
    }
    
    // otherwise, search for the node containing the email and remove it
    EmailNode* prev_node = list->head;
    EmailNode* cur_node = list->head->next;
    while (cur_node != NULL) {
        if (strcmp(cur_node->email, email) == 0) {
            prev_node->next = cur_node->next;
            free(cur_node);
            list->size--;
            return;
        }
        prev_node = cur_node;
        cur_node = cur_node->next;
    }
}

// function to print the contents of the mailing list
void print_list(MailingList* list) {
    printf("Mailing List:\n");
    printf("-------------\n");
    EmailNode* cur_node = list->head;
    while (cur_node != NULL) {
        printf("%s\n", cur_node->email);
        cur_node = cur_node->next;
    }
}

int main() {
    MailingList* list = (MailingList*)malloc(sizeof(MailingList));
    list->head = NULL;
    list->size = 0;
    
    add_email(list, "john@example.com");
    add_email(list, "jane@example.com");
    add_email(list, "bob@example.com");
    print_list(list);
    
    remove_email(list, "jane@example.com");
    print_list(list);
    
    free(list);
    
    return 0;
}