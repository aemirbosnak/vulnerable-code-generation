//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_LINKS 100

typedef struct Link {
    char name[10];
    struct Link* next;
} Link;

void printChain(Link* chain) {
    Link* current = chain;
    while (current != NULL) {
        printf("%s -> ", current->name);
        fflush(stdout);
        usleep(100000);
        current = current->next;
    }
    printf("NULL\n");
}

void createChain(Link** chain, int size) {
    *chain = NULL;
    for (int i = 0; i < size; i++) {
        Link* newLink = (Link*)malloc(sizeof(Link));
        sprintf(newLink->name, "Link %d", i);
        newLink->next = *chain;
        *chain = newLink;
    }
}

int main() {
    srand(time(NULL));
    Link* chain = NULL;
    int size = 5;

    printf("Creating a chain mail armor of size %d:\n", size);
    createChain(&chain, size);
    printChain(chain);

    printf("\nVisualizing the armor:\n");
    for (int i = 0; i < 10; i++) {
        int randomIndex = rand() % size;
        Link* current = chain;
        for (int j = 0; j < randomIndex; j++) {
            current = current->next;
        }
        printf("Attacker strikes %s!\n", current->name);
        sleep(1);
        system("clear");
        printChain(chain);
    }

    printf("\nThe armor has been successfully visualized!\n");

    return 0;
}