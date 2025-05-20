//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct Knight {
    char name[MAX_NAME_LENGTH];
    int level;
    int experience;
    struct Knight *next;
} Knight;

Knight *createKnight(char *name, int level, int experience) {
    Knight *knight = malloc(sizeof(Knight));
    strcpy(knight->name, name);
    knight->level = level;
    knight->experience = experience;
    knight->next = NULL;
    return knight;
}

void addKnight(Knight *head, char *name, int level, int experience) {
    Knight *newKnight = createKnight(name, level, experience);
    if (head == NULL) {
        head = newKnight;
    } else {
        Knight *currentKnight = head;
        while (currentKnight->next) {
            currentKnight = currentKnight->next;
        }
        currentKnight->next = newKnight;
    }
}

void printKnights(Knight *head) {
    Knight *currentKnight = head;
    printf("List of Knights:\n");
    while (currentKnight) {
        printf("Name: %s, Level: %d, Experience: %d\n", currentKnight->name, currentKnight->level, currentKnight->experience);
        currentKnight = currentKnight->next;
    }
}

int main() {
    Knight *head = NULL;
    addKnight(head, "Sir Robin", 5, 100);
    addKnight(head, "Sir Alan", 3, 50);
    addKnight(head, "Sir William", 7, 150);
    printKnights(head);

    return 0;
}