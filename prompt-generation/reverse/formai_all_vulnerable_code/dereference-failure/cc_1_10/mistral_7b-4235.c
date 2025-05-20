//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: thoughtful
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024

void compress(char *input, char *output) {
    int i = 0;
    int count = 1;

    while (input[i] != '\0') {
        if (input[i] == input[i + 1]) {
            count++;
        } else {
            output[i] = input[i];
            if (count > 1) {
                char c = count + '0';
                output[++i] = c;
                count = 1;
            }
        }
        i++;
    }

    output[i] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input> <output>\n", argv[0]);
        return 1;
    }

    char input[BUF_SIZE];
    char output[BUF_SIZE];

    strcpy(input, argv[1]);

    compress(input, output);

    FILE *fp = fopen(argv[2], "w");

    if (fp == NULL) {
        perror("Error opening output file");
        return 1;
    }

    fwrite(output, sizeof(char), strlen(output), fp);
    fclose(fp);

    printf("Compressed data written to %s\n", argv[2]);

    return 0;
}