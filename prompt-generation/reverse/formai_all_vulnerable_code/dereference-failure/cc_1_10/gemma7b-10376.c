//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost Ghost;
struct Ghost {
    char name[20];
    int age;
    float haunt_level;
    Ghost* next;
};

Ghost* create_ghost(char* name, int age, float haunt_level) {
    Ghost* new_ghost = malloc(sizeof(Ghost));
    strcpy(new_ghost->name, name);
    new_ghost->age = age;
    new_ghost->haunt_level = haunt_level;
    new_ghost->next = NULL;
    return new_ghost;
}

void add_ghost(Ghost* head, Ghost* new_ghost) {
    if (head == NULL) {
        head = new_ghost;
    } else {
        new_ghost->next = head;
        head = new_ghost;
    }
}

void haunt(Ghost* head) {
    while (head) {
        printf("The spirit of %s whispers secrets in your ear...\n", head->name);
        sleep(head->haunt_level);
        head = head->next;
    }
}

int main() {
    Ghost* head = NULL;
    head = create_ghost("The Bloody Countess", 30, 4.5);
    add_ghost(head, create_ghost("The Disembodied Hand", 20, 3.2));
    add_ghost(head, create_ghost("The Withering Witch", 60, 2.1));

    haunt(head);

    return 0;
}