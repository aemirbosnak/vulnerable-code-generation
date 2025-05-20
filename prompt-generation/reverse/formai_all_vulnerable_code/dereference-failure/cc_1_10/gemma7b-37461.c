//Gemma-7B DATASET v1.0 Category: Table Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_SUSPECTS 5

typedef struct Suspect {
    char name[20];
    int age;
    int room_num;
    struct Suspect* next;
} Suspect;

Suspect* insertSuspect(Suspect* head, char* name, int age, int room_num) {
    Suspect* newSuspect = malloc(sizeof(Suspect));
    strcpy(newSuspect->name, name);
    newSuspect->age = age;
    newSuspect->room_num = room_num;
    newSuspect->next = NULL;

    if (head == NULL) {
        head = newSuspect;
    } else {
        Suspect* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newSuspect;
    }

    return head;
}

void findSuspect(Suspect* head, char* name) {
    Suspect* temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            printf("Suspect found: %s, room number: %d\n", temp->name, temp->room_num);
            return;
        }
        temp = temp->next;
    }

    printf("Suspect not found.\n");
}

int main() {
    Suspect* head = NULL;
    head = insertSuspect(head, "Holmes", 45, 201);
    insertSuspect(head, "Watson", 25, 202);
    insertSuspect(head, "Lestrade", 30, 203);
    insertSuspect(head, "Mrs. Hudson", 60, 204);
    insertSuspect(head, "The Hound", 22, 205);

    findSuspect(head, "Lestrade");

    return 0;
}