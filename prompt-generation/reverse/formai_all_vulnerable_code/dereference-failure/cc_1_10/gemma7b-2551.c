//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Compressor {
    Node* head;
    int compressed_size;
    int original_size;
} Compressor;

void insert_node(Compressor* compressor, char data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (compressor->head == NULL) {
        compressor->head = new_node;
    } else {
        compressor->head->next = new_node;
        compressor->head = new_node;
    }

    compressor->compressed_size++;
}

void compress(Compressor* compressor) {
    char previous_char = '\0';
    int count = 1;

    for (Node* node = compressor->head; node != NULL; node = node->next) {
        if (node->data == previous_char) {
            count++;
        } else {
            insert_node(compressor, previous_char);
            insert_node(compressor, count);
            previous_char = node->data;
            count = 1;
        }
    }

    insert_node(compressor, previous_char);
    insert_node(compressor, count);
}

void decompress(Compressor* compressor) {
    int i = 0;
    char previous_char = '\0';
    int count = 1;

    for (Node* node = compressor->head; node != NULL; node = node->next) {
        if (node->data == previous_char) {
            count++;
        } else {
            for (int j = 0; j < count; j++) {
                insert_node(compressor, previous_char);
            }
            previous_char = node->data;
            count = 1;
        }
    }
}

int main() {
    Compressor* compressor = malloc(sizeof(Compressor));
    compressor->head = NULL;
    compressor->compressed_size = 0;
    compressor->original_size = 0;

    char original_string[] = "This is a string that I want to compress";
    for (int i = 0; original_string[i] != '\0'; i++) {
        insert_node(compressor, original_string[i]);
    }

    compress(compressor);

    char compressed_string[MAX_BUFFER_SIZE];
    int compressed_size = 0;

    for (Node* node = compressor->head; node != NULL; node = node->next) {
        if (node->data != '\0') {
            compressed_string[compressed_size++] = node->data;
        }
    }

    printf("Original string:\n");
    printf("%s\n", original_string);

    printf("Compressed string:\n");
    printf("%s\n", compressed_string);

    printf("Compressed size: %d\n", compressed_size);

    decompress(compressor);

    printf("Decompressed string:\n");
    printf("%s\n", original_string);

    return 0;
}