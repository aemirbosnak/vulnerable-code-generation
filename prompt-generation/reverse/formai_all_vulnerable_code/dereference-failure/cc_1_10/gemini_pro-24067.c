//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1024

struct node {
    char data;
    struct node *next;
};

struct node *head = NULL;

void insert_node(char data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    
    if (head == NULL) {
        head = new_node;
    } else {
        struct node *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

char* compress_string(char *input) {
    int input_size = strlen(input);
    int compressed_size = 0;
    
    for (int i = 0; i < input_size; i++) {
        char current_char = input[i];
        int count = 1;
        
        while (i + 1 < input_size && input[i + 1] == current_char) {
            count++;
            i++;
        }
        
        compressed_size += 1 + (count > 9 ? 2 : 1);  // 1 for the character, 1 or 2 for the count
    }
    
    char *compressed_string = (char *)malloc(compressed_size + 1);
    int compressed_index = 0;
    
    for (int i = 0; i < input_size; i++) {
        char current_char = input[i];
        int count = 1;
        
        while (i + 1 < input_size && input[i + 1] == current_char) {
            count++;
            i++;
        }
        
        compressed_string[compressed_index++] = current_char;
        
        if (count > 9) {
            compressed_string[compressed_index++] = (count / 10) + '0';
            compressed_string[compressed_index++] = (count % 10) + '0';
        } else {
            compressed_string[compressed_index++] = count + '0';
        }
    }
    
    compressed_string[compressed_index] = '\0';
    
    return compressed_string;
}

void print_linked_list() {
    struct node *current_node = head;
    
    while (current_node != NULL) {
        printf("%c", current_node->data);
        current_node = current_node->next;
    }
    
    printf("\n");
}

int main() {
    char input[MAX_INPUT_SIZE];
    
    printf("Enter a string to compress: ");
    gets(input);
    
    char *compressed_string = compress_string(input);
    
    printf("Compressed string: %s\n", compressed_string);
    
    printf("Linked list representation of the compressed string:\n");
    for (int i = 0; i < strlen(compressed_string); i++) {
        insert_node(compressed_string[i]);
    }
    print_linked_list();
    
    return 0;
}