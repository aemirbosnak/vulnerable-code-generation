//GEMINI-pro DATASET v1.0 Category: Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node {
    char *data;
    struct node *next;
} node;

// Create a new node
node *create_node(char *data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = strdup(data);
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of the list
void insert_at_beginning(node **head, char *data) {
    node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a node at the end of the list
void insert_at_end(node **head, char *data) {
    node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Print the list
void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Destroy the list
void destroy_list(node *head) {
    node *current = head;
    while (current != NULL) {
        node *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
}

// Get a random node from the list
node *get_random_node(node *head) {
    int length = 0;
    node *current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }

    int random_index = rand() % length;
    current = head;
    for (int i = 0; i < random_index; i++) {
        current = current->next;
    }

    return current;
}

// Play the game
void play_game(node *head) {
    int num_players = 2;
    int current_player = 0;
    int num_rounds = 10;

    while (num_rounds > 0) {
        node *random_node = get_random_node(head);
        printf("Player %d, it's your turn! Write a romantic poem for %s:\n", current_player + 1, random_node->data);
        char poem[1024];
        fgets(poem, 1024, stdin);
        printf("Aww, that's so sweet! Player %d wins this round!\n", current_player + 1);
        num_rounds--;
        current_player = (current_player + 1) % num_players;
    }

    printf("Game over! Player %d wins!\n", current_player + 1);
}

int main() {
    srand(time(NULL));

    // Create the list of names
    node *head = NULL;
    insert_at_beginning(&head, "Alice");
    insert_at_beginning(&head, "Bob");
    insert_at_beginning(&head, "Eve");
    insert_at_beginning(&head, "John");

    // Play the game
    play_game(head);

    // Destroy the list
    destroy_list(head);

    return 0;
}