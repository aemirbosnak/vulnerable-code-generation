//FormAI DATASET v1.0 Category: Compression algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Define character linked list node
typedef struct character_node {
    char character;
    struct character_node *next;
} character_node;

// Define function to get length of linked list
int get_list_length(character_node *head) {
    int length = 0;
    character_node *current = head;
    
    while (current != NULL) {
        length++;
        current = current->next;
    }
    
    return length;
}

// Define function to compress string using character linked list
character_node *compress_string(char *input) {
    character_node *head = NULL;
    character_node *current = NULL;
    
    int i = 0;
    while (input[i] != '\0') {
        char current_char = input[i];
        int count = 1;
        i++;
        while (input[i] == current_char) {
            count++;
            i++;
        }
        character_node *new_node = malloc(sizeof(character_node));
        new_node->character = current_char;
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
            current = new_node;
        } else {
            current->next = new_node;
            current = new_node;
        }
        char count_str[10];
        sprintf(count_str, "%d", count);
        for (int j = 0; j < strlen(count_str); j++) {
            char count_char = count_str[j];
            character_node *new_count_node = malloc(sizeof(character_node));
            new_count_node->character = count_char;
            new_count_node->next = NULL;
            current->next = new_count_node;
            current = new_count_node;
        }
    }
    
    return head;
}

// Define function to decompress string using character linked list
char * decompress_string(character_node *head, int length) {
    char *output = malloc((length + 1) * sizeof(char));
    output[length] = '\0';
    character_node *current = head;
    int i = 0;
    while (current != NULL) {
        output[i] = current->character;
        if (current->next != NULL) {
            int count = 0;
            character_node *count_node = current->next;
            while (count_node->character >= '0' && count_node->character <= '9') {
                count = count * 10 + (count_node->character - '0');
                count_node = count_node->next;
            }
            for (int j = 0; j < count - 1; j++) {
                i++;
                output[i] = current->character;
            }
            current = count_node;
        } else {
            current = NULL;
        }
        i++;
    }
    
    return output;
}

// Test program
int main() {
    char input[MAX_LENGTH];
    printf("Enter a string to compress: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline
    character_node *compressed_list = compress_string(input);
    int length = get_list_length(compressed_list);
    char *decompressed_string = decompress_string(compressed_list, length);
    
    printf("Compressed string: ");
    character_node *current = compressed_list;
    while (current != NULL) {
        printf("%c", current->character);
        current = current->next;
    }
    printf("\n");
    
    printf("Decompressed string: %s\n", decompressed_string);
    
    return 0;
}