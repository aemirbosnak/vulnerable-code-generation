//Falcon2-11B DATASET v1.0 Category: Image to ASCII art converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertImageToAscii(char* input, char* output) {
    FILE *fp;
    char *buffer;
    char *ptr;
    char *start;

    size_t size = 0;

    fp = fopen(input, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    buffer = (char*)malloc(size * sizeof(char));
    if (buffer == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    start = buffer;

    while (fgets(buffer, size, fp)!= NULL) {
        ptr = buffer;

        while (*ptr!= '\0' && *ptr!= '\n') {
            *ptr = toupper(*ptr);
            ptr++;
        }
    }

    fclose(fp);

    fp = fopen(output, "w");
    if (fp == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    ptr = buffer;

    while (*ptr!= '\0') {
        fprintf(fp, "%c", *ptr);
        ptr++;
    }

    fclose(fp);

    free(buffer);
}

int main() {
    char* input = "image.jpg";
    char* output = "ascii.txt";

    convertImageToAscii(input, output);

    return 0;
}