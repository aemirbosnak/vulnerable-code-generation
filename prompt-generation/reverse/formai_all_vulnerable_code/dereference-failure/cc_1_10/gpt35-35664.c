//FormAI DATASET v1.0 Category: Linked list operations ; Style: synchronous
#include<stdio.h>
typedef struct node{
    int data;
    struct node *next;
}Node;

Node *head = NULL; //initializing the head to null

Node* createNode(int data){  //function to create new Node 
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to insert node at specific location
Node* insertAtLoc(int data, int loc){
    Node *newNode, *temp;
    int i;
    newNode = createNode(data);
    if(loc == 1){                       //case when the user inputs the value of 1
        newNode->next = head;
        head = newNode;
        return head;
    }
    else {                              //if node is not inserted at the beginning
        temp = head;
        for(i=1; i<loc-1 && temp!=NULL ; i++){
            temp = temp->next;
        }
        if(temp == NULL){               //if the position entered is invalid
            printf("Invalid Location\n");
            return head;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        return head;
    }
}

//Function to delete a node from the linked list.
Node* deleteNode(int value){
    Node *temp, *prev=NULL;
    if(head == NULL){
        printf("List is Empty\n");
        return NULL;
    }
    if(head->data == value){
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    else{
        temp = head;
        while( temp != NULL && temp->data != value){
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL){
            printf("Node not found\n");
            return head;
        }
        prev->next = temp->next;
        free(temp);
        return head;
    }
}

//Function to display the linked list
void displayList(){
    Node *temp;
    temp = head;
    if(temp == NULL){
        printf("List is Empty\n");
        return;
    }
    printf("List Elements are : ");
    while (temp != NULL ){
        printf("%d ", temp->data );
        temp = temp->next;
    }
    printf("\n");
    return;
}

int main(){
    int choice, value, loc;
    printf("Enter 1 to insert node\n");
    printf("Enter 2 to delete node\n");
    printf("Enter 3 to display list\n");
    printf("Enter 4 to exit\n");
    while(1){                             //loop until user chooses to exit
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Enter the node value : ");
                    scanf("%d", &value);
                    printf("Enter the location : ");
                    scanf("%d", &loc);
                    head = insertAtLoc( value, loc);
                    printf("Node inserted successfully\n");
                    break;
            case 2: printf("Enter the node value to delete : ");
                    scanf("%d", &value);
                    head = deleteNode(value);
                    printf("Node deleted successfully\n");
                    break;
            case 3: displayList();
                    break;
            case 4: exit(0);
                    break;
            default: printf("Invalid Choice\n"); 
        }
    }
    return 0;
}