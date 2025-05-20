//FormAI DATASET v1.0 Category: Linked list operations ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insert_at_beginning(struct node** head_ref, int new_data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    printf("Wow, you just inserted %d at the beginning of the linked list!\n", new_data);
}

void insert_at_end(struct node** head_ref, int new_data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL){
        *head_ref = new_node;
        printf("Surprise! You just added the first element to the linked list with value %d!\n", new_data);
        return;
    }

    while (last->next != NULL){
        last = last->next;
    }

    last->next = new_node;
    printf("Boom! You just inserted %d at the end of the linked list!\n", new_data);
}

void delete_node(struct node **head_ref, int key){
    struct node* temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key){
        *head_ref = temp->next;
        free(temp);
        printf("Woohoo! You just deleted the first node with value %d!\n", key);
        return;
    }

    while (temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL){
        printf("Oops! %d not found in the linked list!\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Ha-ha! You just deleted a node with value %d!\n", key);
}

void print_list(struct node* node){
    printf("Surprise! The linked list now contains: ");
    while (node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main(){
    struct node* head = NULL;
    printf("Let's create a linked list filled with surprises!\n");
    printf("How many nodes would you like to create? ");
    int n, key;
    scanf("%d", &n);

    for (int i=1; i<=n; i++){
        printf("Enter value of node %d: ", i);
        int value;
        scanf("%d", &value);
        insert_at_end(&head, value);
    }

    printf("The initial linked list has been created with Surprise Values!\n");
    print_list(head);

    printf("Now it's time to delete some nodes!\n");
    printf("Enter a value to delete from the linked list: ");
    scanf("%d", &key);
    delete_node(&head, key);
    print_list(head);

    printf("Let's insert a Surprise node in the beginning of the list!\n");
    printf("Enter a value to insert at the beginning of the linked list: ");
    int value;
    scanf("%d", &value);
    insert_at_beginning(&head, value);
    print_list(head);

    return 0;
}