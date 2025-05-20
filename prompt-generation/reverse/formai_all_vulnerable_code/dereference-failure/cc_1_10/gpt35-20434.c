//FormAI DATASET v1.0 Category: Linked list operations ; Style: thriller
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* create_node(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(struct node** head, int data){
    struct node* new_node = create_node(data);

    if(*head == NULL){
        *head = new_node;
    }else{
        struct node* current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_node;
    }
    printf("%d added to the list\n", data);
}

void delete_node(struct node** head, int data){
    if(*head == NULL){
        printf("The list is empty\n");
    }else{
        struct node* current = *head;
        struct node* previous = *head;

        while(current != NULL && current->data != data){
            previous = current;
            current = current->next;
        }

        if(current == NULL){
            printf("%d does not exist in the list\n", data);
        }else if(current == *head){
            *head = current->next;
            free(current);
            printf("%d deleted from the list\n", data);
        }else{
            previous->next = current->next;
            free(current);
            printf("%d deleted from the list\n", data);
        }
    }
}

void display_list(struct node* head){
    if(head == NULL){
        printf("The list is empty\n");
    }else{
        printf("The list is: ");
        while(head != NULL){
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

int main(){
    struct node* head = NULL;
    int choice, data;

    do{
        printf("Press 1 to add node\n");
        printf("Press 2 to delete node\n");
        printf("Press 3 to display list\n");
        printf("Press 4 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data to add: ");
                scanf("%d", &data);
                add_node(&head, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                delete_node(&head, data);
                break;
            case 3:
                display_list(head);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(1);
    return 0;
}