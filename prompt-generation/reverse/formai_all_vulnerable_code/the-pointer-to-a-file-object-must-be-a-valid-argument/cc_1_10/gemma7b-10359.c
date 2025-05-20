//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Define a structure to store frequency of characters
    struct node {
        char character;
        int frequency;
        struct node* next;
    } node;

    // Create a binary tree to store characters and their frequencies
    struct node* root = NULL;

    // Read the text from the input file
    FILE* file = fopen("text.txt", "r");
    char text[1000];
    fgets(text, 1000, file);

    // Calculate the frequency of each character
    for (int i = 0; text[i] != '\0'; i++) {
        struct node* node_ptr = root;
        struct node* new_node = NULL;

        // Traverse the tree to see if the character already exists
        while (node_ptr) {
            if (text[i] == node_ptr->character) {
                node_ptr->frequency++;
                break;
            } else if (node_ptr->next == NULL) {
                new_node = malloc(sizeof(struct node));
                new_node->character = text[i];
                new_node->frequency = 1;
                new_node->next = NULL;

                if (root == NULL) {
                    root = new_node;
                } else {
                    node_ptr->next = new_node;
                }
                break;
            } else {
                node_ptr = node_ptr->next;
            }
        }
    }

    // Print the character frequencies
    struct node* current = root;
    printf("Character frequencies:\n");
    while (current) {
        printf("%c: %d\n", current->character, current->frequency);
        current = current->next;
    }

    // Free the memory allocated for the nodes
    free(root);

    return 0;
}