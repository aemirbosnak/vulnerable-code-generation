//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

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

void insert_at_end(struct node** head_ref, int new_data){
    struct node* new_node = create_node(new_data);
    struct node* last = *head_ref;

    if(*head_ref == NULL){
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    while(last->next!= NULL){
        last = last->next;
    }

    last->next = new_node;
    return;
}

void insert_at_beginning(struct node** head_ref, int new_data){
    struct node* new_node = create_node(new_data);

    new_node->next = *head_ref;
    *head_ref = new_node;
    return;
}

void delete_node(struct node** head_ref, int key){
    struct node* temp = *head_ref;
    struct node* prev;

    if(temp!= NULL && temp->data == key){
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while(temp!= NULL && temp->data!= key){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        return;
    }

    prev->next = temp->next;
    free(temp);
    return;
}

int search_element(struct node* head, int key){
    struct node* current = head;

    while(current!= NULL){
        if(current->data == key){
            return 1;
        }
        current = current->next;
    }

    return 0;
}

void print_list(struct node* node){
    while(node!= NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

int main(){
    int choice, data, key;
    struct node* head = NULL;

    do{
        printf("\nEnter your choice:\n");
        printf("1. Insert element at the beginning\n");
        printf("2. Insert element at the end\n");
        printf("3. Delete element\n");
        printf("4. Search element\n");
        printf("5. Print list\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert_at_beginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert_at_end(&head, data);
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &key);
                delete_node(&head, key);
                break;
            case 4:
                printf("Enter data to search: ");
                scanf("%d", &key);
                if(search_element(head, key)){
                    printf("%d found in the list.\n", key);
                }else{
                    printf("%d not found in the list.\n", key);
                }
                break;
            case 5:
                printf("List: ");
                print_list(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(1);

    return 0;
}