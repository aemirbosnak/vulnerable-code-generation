//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: inquisitive
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

void add_node(node_t **head, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        node_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void print_list_visually(node_t *head) {
    node_t *current = head;
    int max_len = 0;
    while (current != NULL) {
        int len = 0;
        node_t *temp = current;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
        if (len > max_len) {
            max_len = len;
        }
        current = current->next;
    }
    // Create a 2D array to store the visualization
    char **vis = malloc(max_len * sizeof(char *));
    for (int i = 0; i < max_len; i++) {
        vis[i] = malloc((max_len + 1) * sizeof(char));
    }
    // Initialize the 2D array with spaces
    for (int i = 0; i < max_len; i++) {
        for (int j = 0; j < max_len; j++) {
            vis[i][j] = ' ';
        }
    }
    // Insert the data into the 2D array
    current = head;
    int row = 0;
    int col = 0;
    while (current != NULL) {
        vis[row][col] = current->data + '0';
        row++;
        if (row == max_len) {
            row = 0;
            col++;
        }
        current = current->next;
    }
    // Print the 2D array
    for (int i = 0; i < max_len; i++) {
        for (int j = 0; j < max_len; j++) {
            printf("%c", vis[i][j]);
        }
        printf("\n");
    }
}

bool is_palindrome(node_t *head) {
    node_t *slow = head;
    node_t *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast != NULL) {
        slow = slow->next;
    }
    node_t *reversed = NULL;
    while (slow != NULL) {
        node_t *new_node = malloc(sizeof(node_t));
        new_node->data = slow->data;
        new_node->next = reversed;
        reversed = new_node;
        slow = slow->next;
    }
    while (head != NULL && reversed != NULL) {
        if (head->data != reversed->data) {
            return false;
        }
        head = head->next;
        reversed = reversed->next;
    }
    return true;
}

int main() {
    node_t *head = NULL;
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 2);
    add_node(&head, 1);
    print_list(head);
    print_list_visually(head);
    printf("%s\n", is_palindrome(head) ? "True" : "False");
    return 0;
}