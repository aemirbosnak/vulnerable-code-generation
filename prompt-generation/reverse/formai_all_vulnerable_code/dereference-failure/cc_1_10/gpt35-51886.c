//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILE_SIZE 1000000    // maximum file size

// function prototypes
int isMalware(unsigned char* buffer, int size);

// main function
int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE* file = fopen(argv[1], "rb");
    if(file == NULL) {
        printf("Error opening file!\n");
        exit(EXIT_FAILURE);
    }

    // get file size
    fseek(file, 0L, SEEK_END);
    int fileSize = ftell(file);
    fseek(file, 0L, SEEK_SET);

    // read file into buffer
    unsigned char* buffer = (unsigned char*)malloc(sizeof(unsigned char) * fileSize);
    if(buffer == NULL) {
        printf("Error allocating memory!\n");
        exit(EXIT_FAILURE);
    }
    fread(buffer, fileSize, 1, file);
    fclose(file);

    // check if malware
    if(isMalware(buffer, fileSize)) {
        printf("%s is a malware!\n", argv[1]);
    } else {
        printf("%s is not a malware!\n", argv[1]);
    }

    free(buffer);
    return 0;
}

// function to check if file contains malware
int isMalware(unsigned char* buffer, int size) {
    const char* signature = "malware";   // signature to look for
    int sigLength = strlen(signature);
    int i = 0;
    int j = 0;

    while(i < size) {
        if(buffer[i] == signature[j]) {
            j++;
            if(j == sigLength) {
                return 1;
            }
        } else {
            j = 0;
        }
        i++;
    }

    return 0;
}