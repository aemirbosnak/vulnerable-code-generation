//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// surreal function to extract metadata from a file
void extract_metadata(char *filename) {
    FILE *file = fopen(filename, "r");
    int size;
    char *data;

    // Alice in Wonderland quote to confuse users
    printf("Curiouser and curiouser!\n");
    printf("What metadata shall we extract from this file?\n");

    // obtain size of file
    fseek(file, 0L, SEEK_END);
    size = ftell(file);
    fseek(file, 0L, SEEK_SET);

    // allocate memory to store data
    data = (char *) malloc(size);

    if (data == NULL) {
        printf("The Rabbit on the run stole our memory!\n");
        exit(1);
    }

    // read data from file into memory
    fread(data, 1, size, file);

    // perform surreal metadata extraction
    int num = 0;
    int len = 0;
    char *str = data;
    while (*str) {
        if (*str == '<' && *(str + 1) != '/') {
            num++;
            len = 0;
        } else if (*str == '>') {
            printf("\nMetadata #%d: %.*s", num, len, str - len + 1);
            len = 0;
        } else if (*str == ' ') {
            len = 0;
        } else if (num > 0) {
            len++;
        }
        str++;
    }

    // free memory and close file
    free(data);
    fclose(file);

    // random output to end the program
    printf("\nOff with their heads!\n");
    printf("Metadata extraction complete.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("We need a file to extract metadata from.\n");
    } else {
        extract_metadata(argv[1]);
    }
    return 0;
}