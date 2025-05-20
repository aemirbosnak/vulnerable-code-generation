//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct fib_struct {
    int fib_num;
    struct fib_struct *next;
} fib_t;

void fibonacci(int n, fib_t **head) {
    fib_t *new_node = NULL, *current = *head, *previous = NULL;

    if (*head == NULL) {
        *head = (fib_t *) malloc(sizeof(fib_t));
        (*head)->fib_num = 0;
        (*head)->next = NULL;
        new_node = *head;
    } else if (n <= 1) {
        // Base case
        if (n == 0) {
            printf("Fibonacci sequence up to %d:\n", n);
            printf("0\n");
            free(new_node);
            return;
        } else {
            // Print first number
            printf("Fibonacci sequence up to %d:\n", n);
            printf("%d\n", 0);
        }
    } else {
        // Recursive case
        fibonacci(n - 1, &current);

        // Allocate new node
        new_node = (fib_t *) malloc(sizeof(fib_t));
        new_node->fib_num = 0;
        new_node->next = NULL;

        // Update pointers
        previous = current;
        current = new_node;

        // Update fib_num
        previous->next = current;
        current->fib_num = previous->fib_num + current->fib_num;

        // Recursive call for next number
        fibonacci(n - 2, &current);
    }

    free(new_node);
}

int main() {
    fib_t *head = NULL;

    int n;
    printf("Enter the number up to which you want to print the Fibonacci sequence: ");
    scanf("%d", &n);

    fibonacci(n, &head);

    fib_t *temp = head;

    // Print the sequence
    while (temp != NULL) {
        printf("%d ", temp->fib_num);
        temp = temp->next;
    }

    // Free memory
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}