//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Parrot {
    char name[20];
    char phrase[50];
    struct Parrot *next;
} Parrot;

Parrot *head = NULL;

void createParrot(char *name, char *phrase) {
    Parrot *newParrot = (Parrot *) malloc(sizeof(Parrot));
    strcpy(newParrot->name, name);
    strcpy(newParrot->phrase, phrase);
    newParrot->next = head;
    head = newParrot;
}

void printParrotList() {
    Parrot *temp = head;
    printf("\nThe talking parrots are:\n");
    while (temp != NULL) {
        printf("\nName: %s", temp->name);
        printf("\nPhrase: %s", temp->phrase);
        temp = temp->next;
    }
}

void talkParrot(char *name) {
    Parrot *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("\n%s says: %s", temp->name, temp->phrase);
            return;
        }
        temp = temp->next;
    }
    printf("\nParrot %s not found!", name);
}

int main() {
    createParrot("Polly", "Hello there, matey!");
    createParrot("Molly", "Pretty birdie, wanna nut?");
    createParrot("Alex", "Squawk, squawk, I'm a clever parrot!");

    printParrotList();

    talkParrot("Molly");
    talkParrot("Polly");

    return 0;
}