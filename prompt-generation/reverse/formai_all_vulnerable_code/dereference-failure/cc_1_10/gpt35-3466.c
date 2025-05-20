//FormAI DATASET v1.0 Category: Data structures visualization ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 10
#define BUFFER_SIZE 1024

/* Define data structure for node */
typedef struct node {
    int value;
    struct node *next;
} Node;

/* Function to insert a node at the beginning of the list */
void insert_node(Node **head, int value) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = *head;
    *head = new_node;
}

/* Function to print the linked list */
void print_list(Node *head) {
    Node *current_node = head;

    while (current_node != NULL) {
        printf("%d -> ", current_node->value);
        current_node = current_node->next;
    }
    printf("NULL\n");
}

/* Function to shuffle an array */
void shuffle_array(int *array, int size) {
    srand(time(NULL));

    for (int i = 0; i < size - 1; i++) {
        int j = i + rand() / (RAND_MAX / (size - i) + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

/* Function to create a linked list from an array of integers */
Node *create_list_from_array(int *array, int size) {
    Node *head = NULL;

    for (int i = 0; i < size; i++) {
        insert_node(&head, array[i]);
    }

    return head;
}

/* Main function */
int main() {
    int numbers[MAX_NUMBERS];
    char buffer[BUFFER_SIZE];
    Node *head = NULL;

    /* Populate the array with random numbers between 0 and 99 */
    for (int i = 0; i < MAX_NUMBERS; i++) {
        numbers[i] = rand() % 100;
    }

    /* Shuffle the array */
    shuffle_array(numbers, MAX_NUMBERS);

    /* Create a linked list from the shuffled array */
    head = create_list_from_array(numbers, MAX_NUMBERS);

    /* Print the linked list */
    print_list(head);

    return 0;
}