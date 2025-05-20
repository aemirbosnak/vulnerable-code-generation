//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: creative
#include <stdio.h>
#include <stdlib.h>

typedef struct Fact {
    int num;
    struct Fact *next;
} Fact;

void factorial_recursive(int n, Fact **head) {
    if (n <= 0) {
        *head = malloc(sizeof(Fact));
        (*head)->num = 1;
        (*head)->next = NULL;
        return;
    }

    Fact *new_fact = malloc(sizeof(Fact));
    new_fact->num = n;
    new_fact->next = NULL;

    factorial_recursive(n - 1, &new_fact->next);
    new_fact->next = *head;
    *head = new_fact;
}

void print_list(Fact *head) {
    while (head != NULL) {
        printf("%d ", head->num);
        Fact *temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    Fact *head = NULL;
    factorial_recursive(n, &head);

    printf("Factorial of %d = ", n);
    print_list(head);
    printf("\n");

    while (head != NULL) {
        Fact *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}