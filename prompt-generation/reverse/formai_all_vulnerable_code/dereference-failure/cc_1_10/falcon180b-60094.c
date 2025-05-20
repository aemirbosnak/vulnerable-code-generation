//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[50];
    int age;
} Person;

typedef struct node {
    Person data;
    struct node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} LinkedList;

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void addNode(LinkedList* list, Person person) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data.name, person.name);
    newNode->data.age = person.age;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    list->size++;
}

void printLinkedList(LinkedList* list) {
    Node* temp = list->head;
    printf("Name\tAge\n");
    while (temp!= NULL) {
        printf("%s\t%d\n", temp->data.name, temp->data.age);
        temp = temp->next;
    }
}

void deleteNode(LinkedList* list, char* name) {
    Node* temp = list->head;
    Node* prev = NULL;

    while (temp!= NULL && strcmp(temp->data.name, name)!= 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node not found.\n");
        return;
    }

    if (prev == NULL) {
        list->head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    list->size--;
}

int main() {
    LinkedList* list = createLinkedList();

    addNode(list, (Person){"John", 25});
    addNode(list, (Person){"Jane", 30});
    addNode(list, (Person){"Bob", 20});

    printLinkedList(list);

    deleteNode(list, "Bob");

    printLinkedList(list);

    return 0;
}