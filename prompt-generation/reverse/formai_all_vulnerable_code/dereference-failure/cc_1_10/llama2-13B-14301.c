//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NUMBER 1000000
#define MIN_NUMBER 1

// Define a struct to represent a number
struct number {
    int value;
    struct number *next;
};

// Define a function to create a new number
struct number* new_number(int value) {
    struct number* new_node = (struct number*) malloc(sizeof(struct number));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Define a function to add two numbers
struct number* add(struct number* a, struct number* b) {
    struct number* result = NULL;
    int carry = 0;

    while (a && b) {
        int sum = a->value + b->value + carry;
        carry = (sum / 10) + (a->value >= b->value);
        sum %= 10;

        if (result == NULL) {
            result = new_number(sum);
        } else {
            result->next = new_number(sum);
        }

        a = a->next;
        b = b->next;
    }

    if (a || b) {
        while (a || b) {
            int sum = a->value + b->value + carry;
            carry = (sum / 10) + (a->value >= b->value);
            sum %= 10;

            if (result == NULL) {
                result = new_number(sum);
            } else {
                result->next = new_number(sum);
            }

            a = a->next;
            b = b->next;
        }
    }

    return result;
}

// Define a function to print a number
void print_number(struct number* n) {
    while (n != NULL) {
        printf("%d", n->value);
        n = n->next;
    }
    printf("\n");
}

int main() {
    struct number* n1 = new_number(1);
    struct number* n2 = new_number(2);
    struct number* n3 = new_number(3);
    struct number* n4 = new_number(4);

    // Add n1 and n2
    struct number* result1 = add(n1, n2);

    // Add n3 and n4
    struct number* result2 = add(n3, n4);

    // Print the results
    print_number(result1);
    print_number(result2);

    return 0;
}