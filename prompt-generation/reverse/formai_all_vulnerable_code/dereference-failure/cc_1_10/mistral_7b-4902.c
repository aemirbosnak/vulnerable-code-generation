//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHAINS 1024
#define ELEMENT_SIZE 128

typedef struct Chain {
    char data[ELEMENT_SIZE];
    struct Chain* next;
} Chain;

Chain* createChain() {
    Chain* newChain = (Chain*) malloc(sizeof(Chain));
    if (newChain == NULL) {
        printf("Error: Failed to allocate memory for new chain.\n");
        exit(1);
    }
    newChain->next = NULL;
    return newChain;
}

void addToChain(Chain** head, char* data) {
    Chain* newChain = createChain();
    strcpy(newChain->data, data);

    if (*head == NULL) {
        *head = newChain;
    } else {
        Chain* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newChain;
    }
}

int findDataInChain(Chain* head, char* data) {
    Chain* temp = head;

    while (temp != NULL) {
        if (strcmp(temp->data, data) == 0) {
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

int main() {
    Chain* chains[MAX_CHAINS] = {0};
    srand(time(NULL));

    for (int i = 0; i < 100000; i++) {
        char data[ELEMENT_SIZE];
        snprintf(data, ELEMENT_SIZE, "Element %d", i);

        if (rand() % 2) {
            addToChain(chains, data);
        }
    }

    clock_t start = clock();

    for (int i = 0; i < 10000; i++) {
        char searchData[ELEMENT_SIZE];
        snprintf(searchData, ELEMENT_SIZE, "Element %d", rand() % 100000);

        if (!findDataInChain(chains[rand() % MAX_CHAINS], searchData)) {
            printf("Error: Data %s not found in chain %d.\n", searchData, rand() % MAX_CHAINS);
            exit(1);
        }
    }

    clock_t end = clock();
    double executionTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Data search completed successfully in %fs.\n", executionTime);

    return 0;
}