//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FruitNode {
    char fruitName[20];
    struct FruitNode* next;
} FruitNode;

FruitNode* createNode(const char* fruit) {
    FruitNode* newNode = (FruitNode*)malloc(sizeof(FruitNode));
    strcpy(newNode->fruitName, fruit);
    newNode->next = NULL;
    return newNode;
}

void addFruit(FruitNode** head, const char* fruit) {
    FruitNode* newNode = createNode(fruit);
    if (*head == NULL) {
        *head = newNode;
    } else {
        FruitNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayFruits(FruitNode* head) {
    printf("🍎🌟 Welcome to the Fruity Friends List! 🌟🍎\n");
    printf("Let's see what scrumptious fruits we have:\n");

    if (head == NULL) {
        printf("Oh no! The fruit basket is empty! 😢\n");
        return;
    }

    FruitNode* temp = head;
    while (temp != NULL) {
        printf("🎉 %s 🎉\n", temp->fruitName);
        temp = temp->next;
    }
    printf("🍉🍌 Thanks for visiting the fruity friends list! 🍌🍉\n");
}

void freeList(FruitNode* head) {
    FruitNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    FruitNode* fruitBasket = NULL;

    printf("🌈 Let's fill our fruit basket! Enter up to 5 fruits.\n");

    for (int i = 0; i < 5; ++i) {
        char fruit[20];
        printf("Enter fruit %d: ", i + 1);
        scanf("%19s", fruit);
        addFruit(&fruitBasket, fruit);
    }

    displayFruits(fruitBasket);
    freeList(fruitBasket);

    return 0;
}