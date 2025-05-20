//FormAI DATASET v1.0 Category: Compression algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000                        // Maximum size of the input file
#define DICTIONARY_SIZE 500                  // Maximum size of the dictionary

// Structure of a single node in the dictionary
typedef struct Node {
    char data;
    int code;
    struct Node* next;
} Node;

// Function declarations
void compress(char* input_file, char* output_file);
Node* build_dictionary(char* input_file);
int search_dictionary(Node* dictionary, char c);
void add_to_dictionary(Node** dictionary, char c, int code);
void print_dictionary(Node* dictionary);
void write_to_file(int* buffer, int count, FILE* fp);

// Main function
int main() {
    char* input_file = "input.txt";          // Input file
    char* output_file = "output.bin";        // Compressed file

    compress(input_file, output_file);

    return 0;
}

// Function that performs the compression operation
void compress(char* input_file, char* output_file) {
    Node* dictionary = build_dictionary(input_file);  // Build the dictionary from input file
    FILE* in_fp = fopen(input_file, "r");             // Open input file for reading
    FILE* out_fp = fopen(output_file, "wb");          // Open output file for writing

    if (in_fp == NULL || out_fp == NULL) {
        printf("Error opening file");
        exit(1);
    }

    int buffer[MAX_SIZE];                 // Buffer to store the binary code
    int count = 0;                        // Counter to keep track of buffer size
    char c;
    int code;
    int dictionary_index;

    // Traverse the input file and compress each character using dictionary entries
    while ((c = fgetc(in_fp)) != EOF) {
        dictionary_index = search_dictionary(dictionary, c);
        code = dictionary_index + DICTIONARY_SIZE;
        buffer[count++] = code;
        add_to_dictionary(&dictionary, c, code);
    }

    // Write the compressed binary code to the output file
    write_to_file(buffer, count, out_fp);

    // Free memory allocated to the dictionary
    Node* temp;
    while (dictionary != NULL) {
        temp = dictionary;
        dictionary = dictionary->next;
        free(temp);
    }

    fclose(in_fp);                       // Close input file
    fclose(out_fp);                      // Close output file
}

// Function that builds the initial dictionary from the input file
Node* build_dictionary(char* input_file) {
    FILE* in_fp = fopen(input_file, "r");  // Open input file for reading
    Node* dictionary = NULL;

    if (in_fp == NULL) {
        printf("Error opening file");
        exit(1);
    }

    char c;
    int code = 0;

    // Traverse the input file and add each unique character to the dictionary
    while ((c = fgetc(in_fp)) != EOF) {
        if (search_dictionary(dictionary, c) == -1) {
            add_to_dictionary(&dictionary, c, code++);
        }
    }

    fclose(in_fp);                       // Close input file

    return dictionary;
}

// Function that searches the dictionary for a given character and returns its code
int search_dictionary(Node* dictionary, char c) {
    Node* temp = dictionary;

    while (temp != NULL) {
        if (temp->data == c) {
            return temp->code;
        }
        temp = temp->next;
    }
    return -1;
}

// Function that adds a new character and its code to the dictionary
void add_to_dictionary(Node** dictionary, char c, int code) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = c;
    new_node->code = code;
    new_node->next = *dictionary;
    *dictionary = new_node;
}

// Function that prints the dictionary
void print_dictionary(Node* dictionary) {
    printf("Dictionary:\n");
    Node* temp = dictionary;
    while (temp != NULL) {
        printf("%c: %d\n", temp->data, temp->code);
        temp = temp->next;
    }
    printf("\n");
}

// Function that writes the compressed binary code to the output file
void write_to_file(int* buffer, int count, FILE* fp) {
    int i, j;
    char byte = 0;
    int bit_position = 8;

    for (i = 0; i < count; i++) {
        for (j = 10; j >= 0; j--) {
            if ((buffer[i] >> j) & 1) {
                byte |= 1 << --bit_position;
            }
            else {
                bit_position--;
            }
            if (bit_position == 0) {
                fwrite(&byte, sizeof(char), 1, fp);
                byte = 0;
                bit_position = 8;
            }
        }
    }

    if (bit_position != 8) {
        byte <<= bit_position;
        fwrite(&byte, sizeof(char), 1, fp);
    }
}