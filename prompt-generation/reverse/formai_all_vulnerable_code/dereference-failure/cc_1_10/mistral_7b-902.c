//MISTRAL-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 100

typedef struct {
    char description[MAX_LINE];
    char* next;
} node;

node* createNode(char description[], node* next) {
    node* newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->description, description);
    newNode->next = next;
    return newNode;
}

void printDescription(node* current) {
    printf("\n%s\n", current->description);
}

node* getNext(node* current) {
    return current->next;
}

void setupGame() {
    node* start = createNode("You stand before an ancient temple, covered in vines and moss. The air is thick with the scent of decay.\n", NULL);
    node* templeEntrance = createNode("As you approach the temple entrance, you notice a series of traps designed to keep intruders out.\n", start);
    node* trapRoom = createNode("You've successfully navigated the traps and enter the trap room. There are three doors before you.\n", templeEntrance);
    node* treasureRoom = createNode("You've entered the treasure room! But beware, there's a guard here who's not likely to let you leave unscathed.\n", NULL);
    node* fightGuard = createNode("You engage in a fierce battle with the guard. You manage to defeat him and claim the treasure!\n", treasureRoom);
    node* die = createNode("You're not quick enough and the guard kills you. Game over.\n", NULL);
    node* door1 = createNode("You choose door number 1. It leads to a dead end.\n", trapRoom);
    node* door2 = createNode("You choose door number 2. It leads to the treasure room!\n", fightGuard);
    node* door3 = createNode("You choose door number 3. It leads to your death.\n", die);

    start->next = templeEntrance;
    templeEntrance->next = trapRoom;
    trapRoom->next = treasureRoom;
    treasureRoom->next = fightGuard;
    fightGuard->next = door1;
    door1->next = door2;
    door2->next = door3;

    node* current = start;
    while (current != NULL) {
        printDescription(current);
        char choice[10];
        scanf("%s", choice);
        if (strstr(current->description, "You choose door number 1") != NULL) {
            current = door1;
        } else if (strstr(current->description, "You choose door number 2") != NULL) {
            current = door2;
        } else if (strstr(current->description, "You choose door number 3") != NULL) {
            current = door3;
        } else {
            printf("Invalid choice. Try again.\n");
            continue;
        }
    }
}

int main() {
    setupGame();
    return 0;
}