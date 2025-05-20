//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 100

typedef struct Fact {
    int num;
    struct Fact *next;
} Fact;

void factorial(int n, Fact **result) {
    Fact *newNode = NULL;
    Fact *current = *result;

    if (n == 0) {
        *result = NULL;
        return;
    }

    newNode = (Fact *)malloc(sizeof(Fact));
    newNode->num = n;
    newNode->next = NULL;

    if (*result == NULL) {
        *result = newNode;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    factorial(n - 1, result);
}

void printList(Fact *list) {
    while (list != NULL) {
        printf("%d ", list->num);
        list = list->next;
    }
    printf("\n");
}

int main() {
    Fact *result = NULL;
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n > MAX_INPUT || n < 0) {
        printf("Invalid input. Please enter a number between 0 and %d.\n", MAX_INPUT);
        return 1;
    }

    factorial(n, &result);
    printf("Factorial of %d is: ", n);
    printList(result);

    while (result != NULL) {
        Fact *temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}