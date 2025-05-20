//FormAI DATASET v1.0 Category: Memory management ; Style: active
#include<stdlib.h>
#include<stdio.h>

//defining a structure
struct node{
    int data;
    struct node *next;
};

//function to create a new node
struct node *create_node(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main(){
    int *arr, size, i;
    
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    
    arr = (int*)malloc(size * sizeof(int)); //dynamic memory allocation for array
    
    if(arr == NULL){
        printf("Memory not allocated!!");
        exit(0);
    }
    
    printf("Enter %d elements in the array: ", size);
    
    for(i=0;i<size;i++){
        scanf("%d", arr+i); //taking input of array elements
    }
    
    printf("Entered elements are: \n");
    
    for(i=0;i<size;i++){
        printf("%d ", *(arr+i)); //displaying elements
    }
    
    struct node *head, *temp;
    int n, data;
    
    printf("\nEnter the number of nodes: ");
    scanf("%d",&n);
    
    printf("\nEnter data of node 1: ");
    scanf("%d",&data);
    
    head = create_node(data);
    temp = head;
    
    for(i=2;i<=n;i++){
        printf("Enter data of node %d: ",i);
        scanf("%d",&data);
        temp->next = create_node(data);
        temp = temp->next;
    }
    
    printf("\nData entered in linked list:\n");
    
    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    
    return 0;
}