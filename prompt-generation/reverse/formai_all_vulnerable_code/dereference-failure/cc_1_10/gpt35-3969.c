//FormAI DATASET v1.0 Category: Mailing list manager ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct subscriber{
    char email[MAX];
    struct subscriber* next;
};
typedef struct subscriber Subscriber;
Subscriber* head = NULL;

Subscriber* create_subscriber(char email[]){
    Subscriber* new_subscriber = (Subscriber*)malloc(sizeof(Subscriber));
    strcpy(new_subscriber->email, email);
    new_subscriber->next = NULL;
    return new_subscriber;
}

Subscriber* search(char email[]){
    Subscriber* ptr = head;
    while(ptr != NULL){
        if(strcmp(ptr->email, email) == 0)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

void insert(char email[]){
    if(search(email) != NULL){
        printf("Subscriber already exists.\n");
        return;
    }
    Subscriber* new_subscriber = create_subscriber(email);
    if(head == NULL){
        head = new_subscriber;
        return;
    }
    Subscriber* ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new_subscriber;
}

void delete(char email[]){
    Subscriber *ptr1 = head, *ptr2;
    if(strcmp(head->email, email) == 0){
        head = head->next;
        free(ptr1);
        return;
    }
    while(ptr1 != NULL){
        if(strcmp(ptr1->email, email) == 0){
            ptr2->next = ptr1->next;
            free(ptr1);
            return;
        }
        ptr2 = ptr1;
        ptr1 = ptr1->next;
    }
    printf("Subscriber not found.\n");
}

void display(){
    Subscriber* ptr = head;
    printf("Mailing List\n");
    printf("------------\n");
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }
    while(ptr != NULL){
        printf("%s\n", ptr->email);
        ptr = ptr->next;
    }
}

int main(){
    int choice;
    char email[MAX];
    while(1){
        printf("\nMenu\n");
        printf("----\n");
        printf("1. Add Subscriber\n");
        printf("2. Delete Subscriber\n");
        printf("3. Display Mailing List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                printf("Enter email address: ");
                scanf("%s", email);
                insert(email);
                break;
            case 2:
                printf("Enter email address: ");
                scanf("%s", email);
                delete(email);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}