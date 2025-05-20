//FormAI DATASET v1.0 Category: Linked list operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node Node; //alias for struct node

Node* createLinkedList(int n); //function to create a linked list of n nodes
void displayList(Node *head); //function to display the linked list
Node* insertAtBeginning(Node *head, int data); //function to insert a node at the beginning of the linked list
Node* insertAtEnd(Node *head, int data); //function to insert a node at the end of the linked list
Node* insertAtPosition(Node *head, int data, int position); //function to insert a node at a specified position in the linked list
Node* deleteFromBeginning(Node *head); //function to delete a node from the beginning of the linked list
Node* deleteFromEnd(Node *head); //function to delete a node from the end of the linked list
Node* deleteFromPosition(Node *head, int position); //function to delete a node from a specified position in the linked list

int main(){
    int n, data, position; //variables to hold user input
    Node *head = NULL; //initialize linked list to empty list
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    head = createLinkedList(n); //create linked list
    
    printf("\nLinked list created:\n");
    displayList(head); //display linked list
    
    printf("\nEnter data to insert at beginning of the list: ");
    scanf("%d", &data);
    head = insertAtBeginning(head, data); //insert node at beginning of linked list
    printf("\nLinked list after inserting at beginning:\n");
    displayList(head); //display updated linked list
    
    printf("\nEnter data to insert at end of the list: ");
    scanf("%d", &data);
    head = insertAtEnd(head, data); //insert node at end of linked list
    printf("\nLinked list after inserting at end:\n");
    displayList(head); //display updated linked list
    
    printf("\nEnter data and position to insert at a specific position in the list: ");
    scanf("%d%d", &data, &position);
    head = insertAtPosition(head, data, position); //insert node at specific position in linked list
    printf("\nLinked list after inserting at position %d:\n", position);
    displayList(head); //display updated linked list
    
    head = deleteFromBeginning(head); //delete node from beginning of linked list
    printf("\nLinked list after deleting from beginning:\n");
    displayList(head); //display updated linked list
    
    head = deleteFromEnd(head); //delete node from end of linked list
    printf("\nLinked list after deleting from end:\n");
    displayList(head); //display updated linked list
    
    printf("\nEnter position to delete node from: ");
    scanf("%d", &position);
    head = deleteFromPosition(head, position); //delete node from specified position in linked list
    printf("\nLinked list after deleting from position %d:\n", position);
    displayList(head); //display updated linked list
    
    return 0; //exit program
}

Node* createLinkedList(int n){
    int i, data; //initialize variables
    Node *head = NULL, *temp = NULL, *newNode = NULL; //initialize pointers
    
    for(i = 0; i < n; i++){ //loop through to create n nodes
        newNode = (Node*)malloc(sizeof(Node)); //allocate memory for new node
        printf("\nEnter data for node %d: ", i+1);
        scanf("%d", &data);
        newNode->data = data; //assign data to new node
        newNode->next = NULL; //set next pointer to NULL
        if(head == NULL){ //if linked list is empty
            head = newNode; //set head to new node
            temp = head; //set temp to head
        }
        else{ //if linked list is not empty
            temp->next = newNode; //set current nodes next pointer to new node
            temp = newNode; //move temp pointer to new node
        }
    }
    return head; //return linked list
}

void displayList(Node *head){
    Node *temp = head; //set temp pointer to head
    while(temp != NULL){ //loop while temp pointer is not NULL
        printf("%d -> ", temp->data); //print data of current node
        temp = temp->next; //move temp pointer to next node
    }
    printf("NULL\n"); //print NULL at end of linked list
}

Node* insertAtBeginning(Node *head, int data){
    Node *newNode = (Node*)malloc(sizeof(Node)); //allocate memory for new node
    newNode->data = data; //assign data to new node
    newNode->next = head; //set new node's next pointer to head
    head = newNode; //set head to new node
    return head; //return updated linked list
}

Node* insertAtEnd(Node *head, int data){
    Node *newNode = (Node*)malloc(sizeof(Node)); //allocate memory for new node
    newNode->data = data; //assign data to new node
    newNode->next = NULL; //set new node's next pointer to NULL
    Node *temp = head; //set temp pointer to head
    while(temp->next != NULL){ //loop until end of linked list is reached
        temp = temp->next; //move temp pointer to next node
    }
    temp->next = newNode; //set current node's next pointer to new node
    return head; //return updated linked list
}

Node* insertAtPosition(Node *head, int data, int position){
    Node *newNode = (Node*)malloc(sizeof(Node)); //allocate memory for new node
    newNode->data = data; //assign data to new node
    newNode->next = NULL; //set new node's next pointer to NULL
    Node *temp = head, *prev = NULL; //set temp pointer to head and prev pointer to NULL
    int i;
    for(i = 1; i < position && temp != NULL; i++){ //loop until specified position is reached or end of linked list is reached
        prev = temp; //set prev pointer to current node
        temp = temp->next; //move temp pointer to next node
    }
    if(position == 1){ //if inserting at beginning of linked list
        head = insertAtBeginning(head, data); //insert at beginning
        return head; //return updated linked list
    }
    else if(temp == NULL && position != i){ //if linked list is not long enough for specified position
        printf("\nError: Linked list is not long enough to insert at position %d!\n", position);
        free(newNode); //free allocated memory for new node
        return head; //return unmodified linked list
    }
    else{ //insert new node at specified position
        prev->next = newNode; //set prev node's next pointer to new node
        newNode->next = temp; //set new node's next pointer to current node
        return head; //return updated linked list
    }
}

Node* deleteFromBeginning(Node *head){
    if(head == NULL){ //if linked list is empty
        printf("\nError: Linked list is empty!\n");
        return head; //return unmodified linked list
    }
    else{ //delete node from beginning
        Node *temp = head; //set temp pointer to head
        head = head->next; //set head to second node in linked list
        free(temp); //free memory for deleted node
        return head; //return updated linked list
    }
}

Node* deleteFromEnd(Node *head){
    if(head == NULL){ //if linked list is empty
        printf("\nError: Linked list is empty!\n");
        return head; //return unmodified linked list
    }
    else if(head->next == NULL){ //if linked list only has one node
        free(head); //free memory for only node
        head = NULL; //set head to NULL
        return head; //return updated linked list
    }
    else{ //delete node from end
        Node *temp = head, *prev = NULL; //set temp pointer to head and prev pointer to NULL
        while(temp->next != NULL){ //loop until end of linked list is reached
            prev = temp; //set prev node to current node
            temp = temp->next; //move temp pointer to next node
        }
        prev->next = NULL; //set second to last node's next pointer to NULL
        free(temp); //free memory for deleted node
        return head; //return updated linked list
    }
}

Node* deleteFromPosition(Node *head, int position){
    if(head == NULL){ //if linked list is empty
        printf("\nError: Linked list is empty!\n");
        return head; //return unmodified linked list
    }
    Node *temp = head, *prev = NULL; //set temp pointer to head and prev pointer to NULL
    int i;
    for(i = 1; i < position && temp != NULL; i++){ //loop until specified position is reached or end of linked list is reached
        prev = temp; //set prev node to current node
        temp = temp->next; //move temp pointer to next node
    }
    if(temp == NULL && position != i){ //if linked list is not long enough for specified position
        printf("\nError: Linked list is not long enough to delete node at position %d!\n", position);
        return head; //return unmodified linked list
    }
    else if(position == 1){ //if deleting first node
        head = deleteFromBeginning(head); //delete from beginning
        return head; //return updated linked list
    }
    else if(temp->next == NULL){ //if deleting last node
        head = deleteFromEnd(head); //delete from end
        return head; //return updated linked list
    }
    else{ //delete node from specified position
        prev->next = temp->next; //set prev node's next pointer to node after deleted node
        free(temp); //free memory for deleted node
        return head; //return updated linked list
    }
}