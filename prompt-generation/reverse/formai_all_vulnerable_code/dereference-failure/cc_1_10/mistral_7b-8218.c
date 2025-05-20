//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 10007

typedef struct HashNode {
    char str[1024];
    struct HashNode* next;
} HashNode;

unsigned long hash(char* str, unsigned long size) {
    unsigned long h = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        h += (unsigned char)str[i];
        h = h * 31 % size;
    }
    return h;
}

HashNode* createNode(char* str) {
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    strcpy(newNode->str, str);
    newNode->next = NULL;
    return newNode;
}

void addToHash(HashNode** hashTable, char* line) {
    unsigned long index = hash(line, TABLE_SIZE);
    HashNode* newNode = createNode(line);

    if (*hashTable == NULL) {
        *hashTable = newNode;
    } else {
        HashNode* current = *hashTable;
        while (current != NULL) {
            if (strcmp(current->str, line) == 0) {
                free(newNode);
                return;
            }
            current = current->next;
        }
        newNode->next = *hashTable;
        *hashTable = newNode;
    }
}

int readFileAndProcessLines(char* inputFile, char* outputFile) {
    FILE* input = fopen(inputFile, "r");
    FILE* output = fopen(outputFile, "w");

    if (input == NULL || output == NULL) {
        perror("Error opening files");
        return 1;
    }

    HashNode** hashTable = (HashNode**)calloc(TABLE_SIZE, sizeof(HashNode*));

    char line[1024];
    int linesProcessed = 0;

    while (fgets(line, sizeof(line), input) != NULL) {
        linesProcessed++;
        addToHash(hashTable, line);
        fprintf(output, "%s", line);
    }

    fclose(input);
    fclose(output);

    free(hashTable);

    printf("Processed %d unique lines from the input file.\n", linesProcessed);

    return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    return readFileAndProcessLines(argv[1], argv[2]);
}