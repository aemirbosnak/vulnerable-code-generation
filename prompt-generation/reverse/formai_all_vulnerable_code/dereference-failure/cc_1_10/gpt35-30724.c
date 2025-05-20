//FormAI DATASET v1.0 Category: Data structures visualization ; Style: random
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node Node;

Node* createLinkedList(int n);
void displayLinkedList(Node* temp);

int main(){

    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    Node* head = NULL;
    head = createLinkedList(n);

    printf("Your linked list visualization:\n\n");
    displayLinkedList(head);
    return 0;
}


Node* createLinkedList(int n){
    Node* head = NULL;
    Node* temp = NULL;
    Node* p = NULL;
    int i;

    for(i=0;i<n;i++){
        temp = (Node*)malloc(sizeof(Node));
        printf("Enter the data for node %d: ", (i+1));
        scanf("%d", &(temp->data));
        temp->next = NULL;

        if(head == NULL){
            head = temp;
        }else{
            p = head;
            while(p->next != NULL){
                p = p->next;
            }
            p->next = temp;
        }
    }

    return head;

}

void displayLinkedList(Node* temp){

    int i;
    while(temp != NULL){
        printf("\t\t\t\t            *-----------*\n");
        printf("\t\t\t\t            | %d | %p \n", temp->data, temp->next);
        printf("\t\t\t\t            *-----------*\n");
        temp = temp->next;
    }

    printf("\t\t\t\t\t| NULL |\n");
    printf("\t\t\t\t\t|       |\n");
    printf("\t\t\t\t\tV       V\n");
    printf("\t\t\t\t     *********\n");
}