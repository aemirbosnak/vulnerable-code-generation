//FormAI DATASET v1.0 Category: Compression algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void compress(char* msg);

int main() {
    char* msg = (char*)malloc(sizeof(char)*MAX_SIZE);

    printf("Enter the message to compress: ");
    fgets(msg, MAX_SIZE, stdin);

    compress(msg);

    printf("The compressed message is: %s", msg);

    free(msg);
    return 0;
}

void compress(char* msg) {
    char compressed[MAX_SIZE];
    int count = 1;
    char current = msg[0];
    int i = 1;
    int j = 0;

    while (msg[i] != '\0') {
        if (msg[i] == current) {
            count++;
        }
        else {
            compressed[j++] = current;
            compressed[j++] = count + '0';

            current = msg[i];
            count = 1;
        }
        i++;
    }

    compressed[j++] = current;
    compressed[j++] = count + '0';
    compressed[j] = '\0';

    for (i = 0; i <= j; i++) {
        msg[i] = compressed[i];
    }
}