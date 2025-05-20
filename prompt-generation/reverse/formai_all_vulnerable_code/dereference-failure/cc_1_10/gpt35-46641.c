//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// define the constants
#define MAX_WEIGHT 50
#define MAX_BAGS 100
#define MAX_STACK 10

// declare the global variables
int total_bags = 0;
int checked_bags = 0;
int max_stack_size = 0;
int total_weight = 0;
int remaining_weight = 0;

// define the baggage struct
typedef struct Baggage {
    int id;
    int weight;
    bool is_checked;
} Baggage;

// define the stack struct
typedef struct BaggageStack {
    Baggage* items[MAX_STACK];
    int top;
} BaggageStack;

// creates a new baggage
Baggage* new_baggage(int weight, bool is_checked) {
    Baggage* baggage = (Baggage*) malloc(sizeof(Baggage));
    baggage->id = total_bags;
    baggage->weight = weight;
    baggage->is_checked = is_checked;
    return baggage;
}

// initializes a new stack
BaggageStack* init_stack() {
    BaggageStack* stack = (BaggageStack*) malloc(sizeof(BaggageStack));
    stack->top = -1;
    return stack;
}

// checks if the stack is empty
bool is_empty(BaggageStack* stack) {
    return stack->top == -1;
}

// checks if the stack is full
bool is_full(BaggageStack* stack) {
    return stack->top == MAX_STACK - 1;
}

// push a baggage to the stack
void push(BaggageStack* stack, Baggage* baggage) {
    if (is_full(stack)) {
        printf("Cannot push baggage ID %d: Stack is full.\n", baggage->id);
        return;
    }
    stack->items[++stack->top] = baggage;
    if (stack->top > max_stack_size) {
        max_stack_size = stack->top;
    }
}

// pop a baggage from the stack
Baggage* pop(BaggageStack* stack) {
    if (is_empty(stack)) {
        return NULL;
    }
    return stack->items[stack->top--];
}

// the main function
int main() {
    srand(time(NULL)); // initialize the random seed

    printf("Welcome to the airport baggage handling simulation.\n");

    BaggageStack* checked_stack = init_stack(); // create the checked baggage stack
    BaggageStack* hand_stack = init_stack(); // create the hand baggage stack

    for (int i = 0; i < MAX_BAGS; i++) {
        int weight = rand() % MAX_WEIGHT + 1; // generate the baggage weight
        if (total_weight + weight > MAX_WEIGHT * MAX_BAGS) { // so we don't exceed the limit
            break;
        }
        Baggage* baggage = new_baggage(weight, rand() % 2 == 0); // randomly decide if the baggage is checked or hand
        total_bags++;
        total_weight += weight;
        if (baggage->is_checked) { // add the baggage to the appropriate stack
            push(checked_stack, baggage);
            checked_bags++;
        } else {
            push(hand_stack, baggage);
            remaining_weight += weight;
        }
    }

    printf("Total bags: %d\n", total_bags);
    printf("Total weight: %d kg\n", total_weight);
    printf("Checked bags: %d\n", checked_bags);
    printf("Hand bags: %d\n", total_bags - checked_bags);
    printf("Remaining weight: %d kg\n", remaining_weight);
    printf("Maximum stack size: %d\n", max_stack_size);
    
    printf("Thank you for using the airport baggage handling simulation.\n");

    return 0;
}