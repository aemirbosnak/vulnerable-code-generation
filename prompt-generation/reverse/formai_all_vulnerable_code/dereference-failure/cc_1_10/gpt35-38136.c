//FormAI DATASET v1.0 Category: Linked list operations ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node NODE;

NODE* insert_at_beginning(NODE *head, int value)
{
    NODE *temp = (NODE*) malloc(sizeof(NODE));
    temp->data = value;
    temp->next = head;
    head = temp;
    return head;
}

NODE* insert_at_end(NODE *head, int value)
{
    NODE *temp = (NODE*) malloc(sizeof(NODE));
    temp->data = value;
    temp->next = NULL;
    if(head == NULL)
        head = temp;
    else
    {
        NODE *temp_ptr = head;
        while(temp_ptr->next != NULL)
            temp_ptr = temp_ptr->next;
        temp_ptr->next = temp;
    }
    return head;
}

NODE* delete_at_beginning(NODE *head)
{
    if(head == NULL)
        printf("Empty List! Cannot delete.\n");
    else
    {
        NODE *temp = head;
        head = head->next;
        printf("Deleted node with value: %d\n", temp->data);
        free(temp);
    }
    return head;
}

NODE* delete_at_end(NODE *head)
{
    if(head == NULL)
        printf("Empty List! Cannot delete.\n");
    else if(head->next == NULL)
    {
        printf("Deleted node with value: %d\n", head->data);
        free(head);
        head = NULL;
    }
    else
    {
        NODE *temp_ptr = head;
        while(temp_ptr->next->next != NULL)
            temp_ptr = temp_ptr->next;
        NODE *temp = temp_ptr->next;
        printf("Deleted node with value: %d\n", temp->data);
        free(temp);
        temp_ptr->next = NULL;
    }
    return head;
}

void display_list(NODE *head)
{
    if(head == NULL)
        printf("Empty List!\n");
    else
    {
        NODE *temp_ptr = head;
        printf("List Contents: ");
        while(temp_ptr != NULL)
        {
            printf("%d ", temp_ptr->data);
            temp_ptr = temp_ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    NODE *head = NULL;
    int choice, value;
    do
    {
        printf("\nLinked List Operations\n");
        printf("----------------------------\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete at Beginning\n");
        printf("4. Delete at End\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                head = insert_at_beginning(head, value);
                break;
            case 2:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                head = insert_at_end(head, value);
                break;
            case 3:
                head = delete_at_beginning(head);
                break;
            case 4:
                head = delete_at_end(head);
                break;
            case 5:
                display_list(head);
                break;
            case 6:
                printf("Exiting Program... Thank you!\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    } while(choice != 6);
    return 0;
}