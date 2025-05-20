//FormAI DATASET v1.0 Category: Compression algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Struct for the compressed file*/
typedef struct CompressedData {
    char* data; //compressed data
    size_t size; //size of compressed data
} CompressedData;

/*Function to Compress the data*/
CompressedData Compress(char* input, size_t size) {
    CompressedData compData = {0};
    char* compressedData = NULL;
    
    //initialize table for dictionary
    const size_t tableSize = 256;
    char** dictionary = (char**) malloc(sizeof(char*) * tableSize);
    for(int i = 0; i < tableSize; ++i) {
        dictionary[i] = (char*) malloc(sizeof(char));
        dictionary[i][0] = i;
    }

    int lzwCode = tableSize; //start of first free code
    int dictIndex = tableSize; //index for new entry in dictionary
    int inputIndex = 1; //start at second input
    char* currentInput = (char*) malloc(sizeof(char));
    currentInput[0] = input[0]; //initialize first character
    int currentCode;
    char* concatenatedInput;

    while(inputIndex <= size) {
        concatenatedInput = (char*) malloc(sizeof(char) * (strlen(currentInput) + 2)); //maximum input size is currentInput + new char + null terminator
        sprintf(concatenatedInput, "%s%c", currentInput, input[inputIndex]);
        if(strstr(*dictionary, concatenatedInput)) { //current input + next char in dictionary
            currentInput = concatenatedInput;
        }
        else { //add new code to dictionary
            currentCode = (int)*currentInput;
            for(int i = 0; i < dictIndex; ++i) {
                if(strcmp(dictionary[i], currentInput) == 0) {
                    currentCode = i;
                    break;
                }
            }
            compressedData = (char*) realloc(compressedData, sizeof(char) * (compData.size + sizeof(int))); //realloc compressed data and add code
            memcpy(compressedData + compData.size, &currentCode, sizeof(int));
            compData.size += sizeof(int);
            dictionary[dictIndex] = concatenatedInput;
            ++dictIndex;
            currentInput = (char*) malloc(sizeof(char));
            currentInput[0] = input[inputIndex];
        }
        ++inputIndex;
    }

    currentCode = (int)*currentInput;
    for(int i = 0; i < dictIndex; ++i) {
        if(strcmp(dictionary[i], currentInput) == 0) {
            currentCode = i;
            break;
        }
    }
    compressedData = (char*) realloc(compressedData, sizeof(char) * (compData.size + sizeof(int)));
    memcpy(compressedData + compData.size, &currentCode, sizeof(int)); //add final code
    compData.size += sizeof(int);
    compData.data = compressedData;
    return compData;
}

/*Function to Decompress the data*/
char* Decompress(char* input, size_t size) {
    const size_t tableSize = 256;
    char** dictionary = (char**) malloc(sizeof(char*) * tableSize);
    for(int i = 0; i < tableSize; ++i) {
        dictionary[i] = (char*) malloc(sizeof(char));
        dictionary[i][0] = i;
    }

    int lzwCode = tableSize;
    int dictIndex = tableSize;
    char* decodedData = (char*) malloc(sizeof(char) * size);
    int outputIndex = 0;
    int currentCode, oldCode;
    char* nextInput;

    memcpy(&currentCode, input, sizeof(int));
    decodedData[0] = currentCode;
    ++outputIndex;
    nextInput = dictionary[currentCode];
    ++input;

    while(input - size < 0) {
        memcpy(&currentCode, input, sizeof(int));
        ++input;
        if(currentCode >= dictIndex) {
            strcat(nextInput, &nextInput[0]); //concatenate previous input
        }
        else {
            nextInput = dictionary[currentCode];
        }
        strcpy(&decodedData[outputIndex], nextInput); //copy new input
        outputIndex += strlen(nextInput);
        oldCode = currentCode;
        currentCode = dictIndex;
        dictionary[dictIndex] = (char*) malloc(sizeof(char) * (strlen(nextInput) + 2)); //create new dictionary entry
        sprintf(dictionary[dictIndex], "%s%c", dictionary[oldCode], *nextInput);
        ++dictIndex;
    }

    for(int i = 0; i < tableSize; ++i) {
        free(dictionary[i]);
    }
    free(dictionary);
    return decodedData;
}

int main() {
    char* input = "This is a test string";
    printf("Original string: %s\n", input);
    CompressedData compressed = Compress(input, strlen(input));
    printf("Compressed size: %zd\n", compressed.size);
    char* decompressed = Decompress(compressed.data, compressed.size);
    printf("Decompressed string: %s\n", decompressed);
    free(compressed.data);
    free(decompressed);
    return 0;
}