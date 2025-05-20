//FormAI DATASET v1.0 Category: Mailing list manager ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char email[50];
    struct node *next;
};

typedef struct node node;

node* create_node(char email[50]){
    node *new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->email, email);
    new_node->next = NULL;
    return new_node;
}

node* insert_node(node* head, node* new_node){
    if(head == NULL){
        head = new_node;
    }
    else{
        node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
}

node* delete_node(node* head, char email[50]){
    if(head == NULL){
        printf("\nList is empty.\n");
    }
    else if(strcmp(head->email,email) == 0){
        node* temp = head;
        head = head->next;
        free(temp);
        printf("\nEmail (%s) deleted successfully.\n",email);
    }
    else{
        node* temp = head;
        while(temp->next != NULL){
            if(strcmp(temp->next->email,email) == 0){
                node* del_node = temp->next;
                temp->next = del_node->next;
                free(del_node);
                printf("\nEmail (%s) deleted successfully.\n",email);
                return head;
            }
            temp = temp->next;
        }
        printf("\nEmail (%s) not found.\n",email);
    }
    return head;
}

void display_list(node* head){
    if(head == NULL){
        printf("\nList is empty.\n");
    }
    else{
        printf("\nMailing List:\n");
        node *temp = head;
        while(temp != NULL){
            printf("%s\n",temp->email);
            temp = temp->next;
        }
    }
}

int main(){
    node *head = NULL;
    int choice;
    char email[50];

    while(1){
        printf("\n---Mailing List Manager---\n");
        printf("1. Add email\n");
        printf("2. Delete email\n");
        printf("3. Display mailing list\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("\nEnter email to add: ");
                scanf("%s",email);
                node *new_node = create_node(email);
                head = insert_node(head,new_node);
                break;

            case 2:
                printf("\nEnter email to delete: ");
                scanf("%s",email);
                head = delete_node(head,email);
                break;

            case 3:
                display_list(head);
                break;

            case 4:
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }

    return 0;
}