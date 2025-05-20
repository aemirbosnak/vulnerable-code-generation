//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CONSPIRACY_MEMBERS 10

typedef struct Conspirator {
    char name[20];
    int age;
    struct Conspirator* next;
} Conspirator;

Conspirator* createConspirator(char* name, int age) {
    Conspirator* conspirator = malloc(sizeof(Conspirator));
    strcpy(conspirator->name, name);
    conspirator->age = age;
    conspirator->next = NULL;
    return conspirator;
}

void addConspirator(Conspirator* head, char* name, int age) {
    Conspirator* conspirator = createConspirator(name, age);
    if (head == NULL) {
        head = conspirator;
    } else {
        conspirator->next = head;
        head = conspirator;
    }
}

void printConspirators(Conspirator* head) {
    while (head) {
        printf("%s (%d) ", head->name, head->age);
        head = head->next;
    }
    printf("\n");
}

int main() {
    time_t t = time(NULL);
    srand(t);

    Conspirator* head = NULL;
    addConspirator(head, "John Doe", 25);
    addConspirator(head, "Jane Doe", 30);
    addConspirator(head, "Bob Smith", 40);
    addConspirator(head, "Alice White", 20);

    printConspirators(head);

    // Random conspiracy theory
    int numConspirators = rand() % MAX_CONSPIRACY_MEMBERS + 1;
    printf("There are a total of %d conspirators...\n", numConspirators);

    Conspirator* currentConspirator = head;
    for (int i = 0; i < numConspirators; i++) {
        currentConspirator = currentConspirator->next;
    }

    printf("The mastermind behind the conspiracy is: %s\n", currentConspirator->name);

    return 0;
}