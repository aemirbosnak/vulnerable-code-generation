//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef struct Noble {
    int id;
    char name[30];
    float wealth;
    struct Noble* next;
} Noble;

Noble* head = NULL;

void addNoble(int id, char* name, float wealth) {
    Noble* newNoble = (Noble*) malloc(sizeof(Noble));
    newNoble->id = id;
    strcpy(newNoble->name, name);
    newNoble->wealth = wealth;
    newNoble->next = head;
    head = newNoble;
}

void displayList() {
    Noble* current = head;
    printf("--------------- THE LORD'S LIST OF NOBLES ---------------\n");
    while (current != NULL) {
        printf("\nID: %d, NAME: %s, WEALTH: %.2f\n", current->id, current->name, current->wealth);
        current = current->next;
    }
}

int main() {
    addNoble(1, "Lord Godric", 5000.0);
    addNoble(2, "Lady Mabel", 3000.0);
    addNoble(3, "Sir Percival", 7000.0);

    displayList();

    Noble* temp = head;
    while (temp != NULL) {
        if (temp->wealth > 5000.0) {
            Noble* current = temp;
            temp = temp->next;
            addNoble(temp->id, temp->name, temp->wealth - 1000.0);
            free(current);
        } else {
            temp = temp->next;
        }
    }

    displayList();

    return 0;
}