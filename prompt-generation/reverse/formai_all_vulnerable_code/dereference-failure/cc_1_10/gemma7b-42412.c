//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16

typedef struct Node {
    char key[KEY_SIZE];
    struct Node* next;
} Node;

void encrypt_file(Node* head) {
    FILE* file = fopen("file.txt", "r");
    char buffer[1024];
    int read_size;

    while ((read_size = fread(buffer, 1, 1024, file)) > 0) {
        for (int i = 0; i < read_size; i++) {
            buffer[i] ^= head->key[i % KEY_SIZE];
        }
        fwrite(buffer, 1, read_size, file);
    }

    fclose(file);
}

int main() {
    Node* head = malloc(sizeof(Node));
    head->key[0] = 'a';
    head->key[1] = 'b';
    head->key[2] = 'c';
    head->key[3] = 'd';
    head->key[4] = 'e';
    head->key[5] = 'f';
    head->key[6] = 'g';
    head->key[7] = 'h';
    head->key[8] = 'i';
    head->key[9] = 'j';
    head->key[10] = 'k';
    head->key[11] = 'l';
    head->key[12] = 'm';
    head->key[13] = 'n';
    head->key[14] = 'o';
    head->key[15] = 'p';
    head->next = NULL;

    encrypt_file(head);

    return 0;
}