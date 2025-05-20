//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct FruitNode {
    char name[20];
    char color;
    struct FruitNode* next;
} FruitNode;

void printList(FruitNode* head) {
    if (!head) {
        printf("Empty List\n");
        return;
    }

    FruitNode* current = head;

    do {
        printf("%c %s -> ", current->color, current->name);
        current = current->next;
    } while (current != head);

    printf("End\n");
}

void addFruit(FruitNode** head, char* name, char color) {
    FruitNode* newNode = (FruitNode*)malloc(sizeof(FruitNode));
    strcpy(newNode->name, name);
    newNode->color = color;

    if (*head) {
        FruitNode* last = *head;
        while (last->next) last = last->next;
        last->next = newNode;
        newNode->next = *head;
        *head = newNode;
    } else {
        *head = newNode;
        newNode->next = *head;
    }
}

int main() {
    FruitNode* fruitList = NULL;

    addFruit(&fruitList, "Apple", 'R');
    addFruit(&fruitList, "Banana", 'Y');
    addFruit(&fruitList, "Cherry", 'R');
    addFruit(&fruitList, "Durian", 'O');
    addFruit(&fruitList, "Elderberry", 'P');

    printf("Circular Linked List of Fruits:\n");
    printList(fruitList);

    free(fruitList);

    return 0;
}

/*
Output:

Circular Linked List of Fruits:
R Apple -> Y Banana -> R Cherry -> O Durian -> P Elderberry -> R Apple
End
*/