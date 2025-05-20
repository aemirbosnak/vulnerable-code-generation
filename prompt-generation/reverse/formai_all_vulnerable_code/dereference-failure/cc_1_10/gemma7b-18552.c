//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONSPIRACY 10

typedef struct Conspiracy
{
    char* name;
    char* description;
    struct Conspiracy* next;
} Conspiracy;

Conspiracy* createConspiracy(char* name, char* description)
{
    Conspiracy* conspiracy = malloc(sizeof(Conspiracy));
    conspiracy->name = strdup(name);
    conspiracy->description = strdup(description);
    conspiracy->next = NULL;

    return conspiracy;
}

Conspiracy* addConspiracy(Conspiracy* head, char* name, char* description)
{
    Conspiracy* newConspiracy = createConspiracy(name, description);

    if (head == NULL)
    {
        head = newConspiracy;
    }
    else
    {
        head->next = newConspiracy;
    }

    return head;
}

void printConspiracy(Conspiracy* head)
{
    while (head)
    {
        printf("%s: %s\n", head->name, head->description);
        head = head->next;
    }
}

int main()
{
    Conspiracy* conspiracyHead = NULL;

    conspiracyHead = addConspiracy(conspiracyHead, "The Bamboo Network", "A secret organization of eco-terrorists who use bamboo weapons to fight against the government.");
    conspiracyHead = addConspiracy(conspiracyHead, "The Order of the Silver Dragon", "A secret society of assassins who protect the innocent from harm.");
    conspiracyHead = addConspiracy(conspiracyHead, "The Illuminati", "A secret society of wealthy and influential individuals who control the world from the shadows.");

    printConspiracy(conspiracyHead);

    return 0;
}