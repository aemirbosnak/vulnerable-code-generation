//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 256

typedef struct {
    unsigned char character;
    unsigned int frequency;
} Symbol;

typedef struct {
    Symbol* symbols;
    unsigned int size;
} SymbolTable;

typedef struct {
    unsigned char* code;
    unsigned int length;
} Code;

typedef struct {
    Code* codes;
    unsigned int size;
} CodeTable;

SymbolTable* createSymbolTable(unsigned char* message) {
    SymbolTable* symbolTable = malloc(sizeof(SymbolTable));
    symbolTable->symbols = malloc(MAX_CHARACTERS * sizeof(Symbol));
    symbolTable->size = 0;

    for (int i = 0; i < MAX_CHARACTERS; i++) {
        symbolTable->symbols[i].character = i;
        symbolTable->symbols[i].frequency = 0;
    }

    for (int i = 0; message[i] != '\0'; i++) {
        symbolTable->symbols[message[i]].frequency++;
    }

    for (int i = 0; i < MAX_CHARACTERS; i++) {
        if (symbolTable->symbols[i].frequency == 0) {
            symbolTable->symbols[i].character = 0;
        }
    }

    return symbolTable;
}

void sortSymbolTable(SymbolTable* symbolTable) {
    for (int i = 0; i < symbolTable->size; i++) {
        for (int j = i + 1; j < symbolTable->size; j++) {
            if (symbolTable->symbols[i].frequency > symbolTable->symbols[j].frequency) {
                Symbol temp = symbolTable->symbols[i];
                symbolTable->symbols[i] = symbolTable->symbols[j];
                symbolTable->symbols[j] = temp;
            }
        }
    }
}

CodeTable* createCodeTable(SymbolTable* symbolTable) {
    CodeTable* codeTable = malloc(sizeof(CodeTable));
    codeTable->codes = malloc(symbolTable->size * sizeof(Code));
    codeTable->size = symbolTable->size;

    for (int i = 0; i < symbolTable->size; i++) {
        codeTable->codes[i].code = malloc(MAX_CHARACTERS * sizeof(unsigned char));
        codeTable->codes[i].length = 0;
    }

    return codeTable;
}

void createHuffmanCode(SymbolTable* symbolTable, CodeTable* codeTable) {
    while (symbolTable->size > 1) {
        Symbol* left = &symbolTable->symbols[symbolTable->size - 1];
        Symbol* right = &symbolTable->symbols[symbolTable->size - 2];

        Symbol* newNode = malloc(sizeof(Symbol));
        newNode->character = 0;
        newNode->frequency = left->frequency + right->frequency;

        symbolTable->symbols[symbolTable->size - 1] = *newNode;
        symbolTable->symbols[symbolTable->size - 2] = *left;

        sortSymbolTable(symbolTable);

        for (int i = 0; i < codeTable->size; i++) {
            if (codeTable->codes[i].code[codeTable->codes[i].length - 1] == left->character) {
                codeTable->codes[i].code[codeTable->codes[i].length] = '0';
                codeTable->codes[i].length++;
            } else if (codeTable->codes[i].code[codeTable->codes[i].length - 1] == right->character) {
                codeTable->codes[i].code[codeTable->codes[i].length] = '1';
                codeTable->codes[i].length++;
            }
        }
    }
}

void printCodeTable(CodeTable* codeTable) {
    for (int i = 0; i < codeTable->size; i++) {
        printf("%c: ", codeTable->codes[i].code);

        for (int j = 0; j < codeTable->codes[i].length; j++) {
            printf("%c", codeTable->codes[i].code[j]);
        }

        printf("\n");
    }
}

void encodeMessage(unsigned char* message, CodeTable* codeTable, unsigned char* encodedMessage) {
    int encodedMessageIndex = 0;

    for (int i = 0; message[i] != '\0'; i++) {
        for (int j = 0; j < codeTable->size; j++) {
            if (codeTable->codes[j].code[0] == message[i]) {
                for (int k = 0; k < codeTable->codes[j].length; k++) {
                    encodedMessage[encodedMessageIndex] = codeTable->codes[j].code[k];
                    encodedMessageIndex++;
                }

                break;
            }
        }
    }

    encodedMessage[encodedMessageIndex] = '\0';
}

void decodeMessage(unsigned char* encodedMessage, CodeTable* codeTable, unsigned char* decodedMessage) {
    int decodedMessageIndex = 0;
    int codeTableIndex = 0;

    while (encodedMessage[decodedMessageIndex] != '\0') {
        while (codeTable->codes[codeTableIndex].code[codeTableIndex] != encodedMessage[decodedMessageIndex]) {
            codeTableIndex++;
        }

        decodedMessage[decodedMessageIndex] = codeTable->codes[codeTableIndex].code[0];
        decodedMessageIndex++;
        codeTableIndex = 0;
    }

    decodedMessage[decodedMessageIndex] = '\0';
}

int main() {
    unsigned char* message = (unsigned char*)"Huffman coding is a lossless data compression algorithm.";

    SymbolTable* symbolTable = createSymbolTable(message);
    sortSymbolTable(symbolTable);

    CodeTable* codeTable = createCodeTable(symbolTable);
    createHuffmanCode(symbolTable, codeTable);

    printCodeTable(codeTable);

    unsigned char* encodedMessage = malloc((strlen(message) + 1) * sizeof(unsigned char));
    encodeMessage(message, codeTable, encodedMessage);

    printf("Encoded message: %s\n", encodedMessage);

    unsigned char* decodedMessage = malloc((strlen(message) + 1) * sizeof(unsigned char));
    decodeMessage(encodedMessage, codeTable, decodedMessage);

    printf("Decoded message: %s\n", decodedMessage);

    return 0;
}