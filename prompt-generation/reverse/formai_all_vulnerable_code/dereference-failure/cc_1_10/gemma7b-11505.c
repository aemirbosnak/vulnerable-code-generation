//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GHOSTS 10

typedef struct Ghost {
    char name[20];
    int age;
    float fear_level;
    struct Ghost* next;
} Ghost;

Ghost* createGhost(char* name, int age, float fear_level) {
    Ghost* ghost = (Ghost*)malloc(sizeof(Ghost));
    strcpy(ghost->name, name);
    ghost->age = age;
    ghost->fear_level = fear_level;
    ghost->next = NULL;
    return ghost;
}

void addGhost(Ghost* head, char* name, int age, float fear_level) {
    Ghost* newGhost = createGhost(name, age, fear_level);
    if (head == NULL) {
        head = newGhost;
    } else {
        head->next = newGhost;
        head = newGhost;
    }
}

void hauntHouse(Ghost* head) {
    time_t t = time(NULL);
    srand(t);

    while (head) {
        int rand_num = rand() % MAX_GHOSTS;
        Ghost* currentGhost = head;

        for (int i = 0; i < rand_num; i++) {
            currentGhost = currentGhost->next;
        }

        printf("%s is haunting you!\n", currentGhost->name);
        sleep(1);
    }
}

int main() {
    Ghost* head = NULL;
    addGhost(head, "John Doe", 20, 0.8);
    addGhost(head, "Mary Smith", 30, 0.6);
    addGhost(head, "Peter Jones", 40, 0.9);

    hauntHouse(head);

    return 0;
}