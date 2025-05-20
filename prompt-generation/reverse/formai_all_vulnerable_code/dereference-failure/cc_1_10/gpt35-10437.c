//FormAI DATASET v1.0 Category: Database simulation ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int id;
    char name[20];
    int age;
} Record;

typedef struct node {
    Record data;
    struct node* next;
} Node;

typedef struct {
    Node* head;
    int length;
} LinkedList;

void initialize(LinkedList* list) {
    list->head = NULL;
    list->length = 0;
}

void addRecord(LinkedList* list) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    printf("Enter record ID: ");
    scanf("%d", &newNode->data.id);

    printf("Enter record name: ");
    scanf("%s", newNode->data.name);

    printf("Enter record age: ");
    scanf("%d", &newNode->data.age);

    newNode->next = list->head;
    list->head = newNode;
    list->length++;
}

void removeRecord(LinkedList* list) {
    int id;
    printf("Enter the ID of the record to remove: ");
    scanf("%d", &id);

    Node* current = list->head;
    Node* previous = NULL;

    while(current != NULL) {
        if(current->data.id == id) {
            if(previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }

            free(current);
            printf("Record with ID %d removed.\n", id);
            list->length--;
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("No record with ID %d found.\n", id);
}

void displayRecord(LinkedList* list) {
    Node* current = list->head;

    while(current != NULL) {
        Record record = current->data;
        printf("ID: %d, Name: %s, Age: %d\n", record.id, record.name, record.age);

        current = current->next;
    }
}

void displayMenu() {
    printf("1. Add record\n");
    printf("2. Remove record\n");
    printf("3. Display records\n");
    printf("4. Quit\n");
}

int main() {
    LinkedList list;
    initialize(&list);

    int choice;
    do {
        displayMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addRecord(&list);
                break;
            case 2:
                removeRecord(&list);
                break;
            case 3:
                displayRecord(&list);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

    } while(choice != 4);

    return 0;
}