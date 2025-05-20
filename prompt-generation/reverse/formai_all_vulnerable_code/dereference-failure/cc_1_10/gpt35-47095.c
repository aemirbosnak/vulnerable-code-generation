//FormAI DATASET v1.0 Category: Compression algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_SIZE 1000

struct node {
    uint8_t data;
    struct node* next;
};

int is_head(struct node* head, struct node* ptr) {
    return head == ptr;
}

void remove_node(struct node** head, struct node* ptr) {
    if (is_head(*head, ptr)) {
        *head = ptr->next;
    }
    struct node* prev = *head;
    while (prev->next != ptr) {
        prev = prev->next;
    }
    prev->next = ptr->next;
    free(ptr);
}

void insert_node(struct node** head, uint8_t data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

struct node* find_occurrence(struct node* head, uint8_t data) {
    while (head != NULL) {
        if (head->data == data) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void encode_file(const char* file_in, const char* file_out) {
    // Open input file
    FILE* fin = fopen(file_in, "rb");
    if (fin == NULL) {
        printf("Error opening input file.\n");
        return;
    }

    // Create output file
    FILE* fout = fopen(file_out, "wb");
    if (fout == NULL) {
        printf("Error creating output file.\n");
        return;
    }

    // Initialize dictionary
    struct node* dictionary = NULL;

    // Read bytes from input file and encode
    uint8_t byte;
    while (fread(&byte, sizeof(byte), 1, fin)) {
        // If byte is not in dictionary, add it and output its ASCII equivalent
        struct node* occurrence = find_occurrence(dictionary, byte);
        if (occurrence == NULL) {
            insert_node(&dictionary, byte);
            fwrite(&byte, sizeof(byte), 1, fout);
        }
        // If byte is in dictionary, remove it and output its index in the dictionary
        else {
            uint8_t index = 1;
            struct node* ptr = dictionary;
            while (!is_head(ptr, occurrence)) {
                ptr = ptr->next;
                index++;
            }
            fwrite(&index, sizeof(index), 1, fout);
            remove_node(&dictionary, occurrence);
            insert_node(&dictionary, byte);
        }
    }

    // Free dictionary
    struct node* ptr = dictionary;
    while (ptr != NULL) {
        struct node* temp = ptr;
        ptr = ptr->next;
        free(temp);
    }

    // Close input and output files
    fclose(fin);
    fclose(fout);
}

void decode_file(const char* file_in, const char* file_out) {
    // Open input file
    FILE* fin = fopen(file_in, "rb");
    if (fin == NULL) {
        printf("Error opening input file.\n");
        return;
    }

    // Create output file
    FILE* fout = fopen(file_out, "wb");
    if (fout == NULL) {
        printf("Error creating output file.\n");
        return;
    }

    // Initialize dictionary
    struct node* dictionary = NULL;

    // Read bytes from input file and decode
    uint8_t byte, next_byte;
    fread(&byte, sizeof(byte), 1, fin);
    fwrite(&byte, sizeof(byte), 1, fout);
    while (fread(&next_byte, sizeof(next_byte), 1, fin)) {
        // If byte is an index, find and output corresponding byte in dictionary
        if (next_byte > 0) {
            uint8_t index = next_byte;
            struct node* ptr = dictionary;
            while (index > 1) {
                ptr = ptr->next;
                index--;
            }
            byte = ptr->data;
            fwrite(&byte, sizeof(byte), 1, fout);
        }
        // If byte is not an index, add it to dictionary and output its value
        else {
            byte = next_byte;
            insert_node(&dictionary, byte);
            fwrite(&byte, sizeof(byte), 1, fout);
        }
    }

    // Free dictionary
    struct node* ptr = dictionary;
    while (ptr != NULL) {
        struct node* temp = ptr;
        ptr = ptr->next;
        free(temp);
    }

    // Close input and output files
    fclose(fin);
    fclose(fout);
}

int main() {
    int option;
    char file_in[MAX_SIZE], file_out[MAX_SIZE];

    printf("Select an option:\n1. Encode file\n2. Decode file\nOption: ");
    scanf("%d", &option);

    printf("Input file: ");
    scanf("%s", file_in);

    printf("Output file: ");
    scanf("%s", file_out);

    if (option == 1) {
        encode_file(file_in, file_out);
    }
    else if (option == 2) {
        decode_file(file_in, file_out);
    }
    else {
        printf("Invalid option.\n");
        return 1;
    }

    return 0;
}