//FormAI DATASET v1.0 Category: Compression algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CharNode {
    char data;
    struct CharNode* next;
} CharNode;

void pushChar(CharNode** head, char data) {
    CharNode* newNode = (CharNode*)malloc(sizeof(CharNode));
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
}

char popChar(CharNode** head) {
    CharNode* temp = (*head);
    char data = temp->data;
    (*head) = temp->next;
    free(temp);
    return data;
}

void compress(char* inputFilename, char* outputFilename) {
    FILE *input, *output;
    input = fopen(inputFilename, "r");
    output = fopen(outputFilename, "w");

    if (input == NULL || output == NULL) {
        printf("Error: Unable to open files.");
        exit(1);
    }

    CharNode* head = NULL;
    char currentChar;
    int count = 0;

    currentChar = fgetc(input);
    while (currentChar != EOF) {
        if (count == 0) {
            pushChar(&head, currentChar);
        } else if (head->data == currentChar) {
            count++;
        } else {
            fputc(count + '0', output);
            fputc(head->data, output);
            popChar(&head);
            count = 0;
        }
        currentChar = fgetc(input);
    }

    if (count > 0) {
        fputc(count + '0', output);
        fputc(head->data, output);
        popChar(&head);
    }

    fclose(input);
    fclose(output);
}

void decompress(char* inputFilename, char* outputFilename) {
    FILE *input, *output;
    input = fopen(inputFilename, "r");
    output = fopen(outputFilename, "w");

    if (input == NULL || output == NULL) {
        printf("Error: Unable to open files.");
        exit(1);
    }

    char currentChar = fgetc(input);
    while (currentChar != EOF) {
        int count = currentChar - '0';
        currentChar = fgetc(input);
        for (int i = 0; i < count; i++) {
            fputc(currentChar, output);
        }
        currentChar = fgetc(input);
    }

    fclose(input);
    fclose(output);
}

int main() {
    char* inputFilename = "input.txt";
    char* compressedFilename = "compressed.txt";
    char* decompressedFilename = "decompressed.txt";
    char* outputFilename = "output.txt";

    FILE *input, *output;
    input = fopen(inputFilename, "w");
    if (input == NULL) {
        printf("Error: Unable to open input file.");
        exit(1);
    }
    fprintf(input, "AAAABBBCCDAA");
    fclose(input);

    compress(inputFilename, compressedFilename);
    decompress(compressedFilename, decompressedFilename);

    input = fopen(inputFilename, "r");
    output = fopen(outputFilename, "r");

    if (input == NULL || output == NULL) {
        printf("Error: Unable to open files.");
        exit(1);
    }

    char inputChar = fgetc(input);
    char outputChar = fgetc(output);

    while (inputChar != EOF && outputChar != EOF) {
        if (inputChar != outputChar) {
            printf("Error: Input and output do not match.");
            exit(1);
        }
        inputChar = fgetc(input);
        outputChar = fgetc(output);
    }

    printf("Compression and decompression successful.\n");

    fclose(input);
    fclose(output);

    return 0;
}