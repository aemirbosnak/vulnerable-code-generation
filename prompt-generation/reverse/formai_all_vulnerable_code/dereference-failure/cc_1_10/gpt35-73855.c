//FormAI DATASET v1.0 Category: Mailing list manager ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct for email node
typedef struct email_node{
    char email[50];
    struct email_node* next;
} email_node;

// struct for mailing list
typedef struct mailing_list{
    char name[50];
    email_node *head;
} mailing_list;

// function to add email to mailing list
void add_email_to_list(mailing_list* list, char* email){
    email_node* new_email = (email_node*) malloc(sizeof(email_node));
    strcpy(new_email->email, email);
    new_email->next = NULL;

    // check if mailing list is empty
    if(list->head == NULL){
        list->head = new_email;
        return;
    }

    // add email to end of list
    email_node* temp = list->head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_email;
}

// function to remove email from mailing list
void remove_email_from_list(mailing_list* list, char* email){
    email_node* temp = list->head;
    email_node* prev = NULL;

    // search for email in list
    while(temp != NULL){
        if(strcmp(temp->email, email) == 0){
            // email found, remove from list
            if(prev == NULL){
                // email is first node
                list->head = temp->next;
            }
            else{
                // email is in middle or end of list
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    // email not found in list
    printf("Email not found in the mailing list.\n");
}

// function to print all emails in mailing list
void print_list(mailing_list* list){
    email_node* temp = list->head;
    printf("Mailing list: %s\n", list->name);
    while(temp != NULL){
        printf("%s\n", temp->email);
        temp = temp->next;
    }
}

int main(){
    mailing_list* list1 = (mailing_list*) malloc(sizeof(mailing_list));
    strcpy(list1->name, "List 1");
    list1->head = NULL;

    mailing_list* list2 = (mailing_list*) malloc(sizeof(mailing_list));
    strcpy(list2->name, "List 2");
    list2->head = NULL;

    // add emails to mailing list 1
    add_email_to_list(list1, "john@example.com");
    add_email_to_list(list1, "jane@example.com");

    // add emails to mailing list 2
    add_email_to_list(list2, "bob@example.com");
    add_email_to_list(list2, "anne@example.com");

    // print mailing list 1
    print_list(list1);

    // remove jane from mailing list 1
    remove_email_from_list(list1, "jane@example.com");

    // print mailing list 1 again
    print_list(list1);

    // print mailing list 2
    print_list(list2);

    // free memory
    email_node* temp = list1->head;
    while(temp != NULL){
        email_node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(list1);

    temp = list2->head;
    while(temp != NULL){
        email_node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(list2);

    return 0;
}