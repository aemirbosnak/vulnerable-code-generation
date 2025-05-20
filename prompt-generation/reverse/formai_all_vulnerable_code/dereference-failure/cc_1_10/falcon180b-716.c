//Falcon-180B DATASET v1.0 Category: System event logger ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Node structure*/
typedef struct node{
    int data;
    struct node* next;
} Node;

/*Linked List structure*/
typedef struct list{
    Node* head;
    int size;
} List;

/*Function to create a new node*/
Node* create_node(int data){
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/*Function to add a node at the end of the list*/
void add_node(List* list, int data){
    Node* new_node = create_node(data);
    Node* temp = list->head;
    if(temp == NULL){
        list->head = new_node;
    }
    else{
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    list->size++;
}

/*Function to print the list*/
void print_list(List* list){
    Node* temp = list->head;
    printf("List: ");
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/*Function to search for a node in the list*/
Node* search_node(List* list, int data){
    Node* temp = list->head;
    while(temp!= NULL){
        if(temp->data == data){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

/*Function to delete a node from the list*/
void delete_node(List* list, int data){
    Node* temp = search_node(list, data);
    if(temp!= NULL){
        if(temp == list->head){
            list->head = temp->next;
        }
        else{
            Node* prev = list->head;
            while(prev->next!= temp){
                prev = prev->next;
            }
            prev->next = temp->next;
        }
        free(temp);
        list->size--;
    }
}

/*Function to log an event*/
void log_event(List* list, char* event){
    Node* temp = create_node(strlen(event));
    strcpy(temp->data, event);
    add_node(list, strlen(event));
}

/*Main function*/
int main(){
    List event_log;
    event_log.head = NULL;
    event_log.size = 0;
    log_event(&event_log, "Program started");
    log_event(&event_log, "Memory allocated");
    int choice;
    printf("Enter 1 to add an event or 2 to delete an event: ");
    scanf("%d", &choice);
    while(choice!= 3){
        if(choice == 1){
            char event[100];
            printf("Enter the event: ");
            scanf("%s", event);
            log_event(&event_log, event);
        }
        else if(choice == 2){
            printf("Enter the event to delete: ");
            char event[100];
            scanf("%s", event);
            Node* temp = search_node(&event_log, strlen(event));
            if(temp!= NULL){
                delete_node(&event_log, strlen(event));
                printf("Event deleted\n");
            }
            else{
                printf("Event not found\n");
            }
        }
        else{
            printf("Invalid choice\n");
        }
        printf("Enter 1 to add an event or 2 to delete an event: ");
        scanf("%d", &choice);
    }
    print_list(&event_log);
    return 0;
}