//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum size for the input string
#define MAX_SIZE 1024

// Node structure for the linked list
typedef struct Node {
    char character;
    int frequency;
    struct Node* next;
} Node;

// Function to create a new node
Node* create_node(char character, int frequency) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->character = character;
    new_node->frequency = frequency;
    new_node->next = NULL;
    return new_node;
}

// Function to add a node to the list in sorted order
void add_node(Node** head, char character, int frequency) {
    Node* new_node = create_node(character, frequency);
    if (*head == NULL || (*head)->frequency > frequency) {
        new_node->next = *head;
        *head = new_node;
    } else {
        Node* current = *head;
        while (current->next != NULL && current->next->frequency <= frequency) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

// Function to free the list
void free_list(Node** head) {
    Node* current = *head;
    Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

// Function to count frequency of each character
Node* count_frequency(const char* str) {
    Node* frequency_list = NULL;
    int char_count[256] = {0};

    for (int i = 0; str[i]; i++) {
        char_count[(unsigned char)str[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (char_count[i] > 0) {
            add_node(&frequency_list, (char)i, char_count[i]);
        }
    }

    return frequency_list;
}

// Function to print the frequency list
void print_frequency_list(Node* head) {
    printf("Character Frequencies:\n");
    while (head != NULL) {
        printf("'%c' : %d\n", head->character, head->frequency);
        head = head->next;
    }
}

// Function to compress the string
char* compress_string(const char* str) {
    Node* frequency_list = count_frequency(str);
    print_frequency_list(frequency_list);

    int output_size = strlen(str) * 2; // Max size for compressed string
    char* compressed_str = (char*)malloc(output_size);
    if (!compressed_str) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    compressed_str[0] = '\0'; // Initialize the compressed string

    Node* current = frequency_list;
    while (current != NULL) {
        char buffer[6]; // 4 digits for frequency + null terminator
        snprintf(buffer, sizeof(buffer), "%c%d", current->character, current->frequency);
        strcat(compressed_str, buffer);
        current = current->next;
    }

    free_list(&frequency_list);
    return compressed_str;
}

int main() {
    char input_string[MAX_SIZE];

    printf("Enter a string to compress (max %d characters): ", MAX_SIZE - 1);
    fgets(input_string, MAX_SIZE, stdin);
    input_string[strcspn(input_string, "\n")] = 0; // Remove the newline character

    char* compressed_string = compress_string(input_string);
    printf("Compressed String: %s\n", compressed_string);

    free(compressed_string);
    return 0;
}