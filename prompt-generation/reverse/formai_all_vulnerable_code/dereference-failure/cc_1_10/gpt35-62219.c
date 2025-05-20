//FormAI DATASET v1.0 Category: Compression algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char *str) {
    int i, j, n;
    int length = strlen(str);
    int count = 0;

    for(i = 0; i < length; i++) {
        count++;

        if(str[i] != str[i+1]) {
            printf("%c%d", str[i], count);
            count = 0;
        }
    }
}

void decompress(char *str) {
    int i, j, n, p;
    int length = strlen(str);
    char *temp = (char*) malloc(length * sizeof(char));

    for(i = 0, j = 0; i < length; i++, j++) {
        if(str[i] >= '0' && str[i] <= '9') {
            n = str[i] - '0';
            p = i + 1;

            while(str[p] >= '0' && str[p] <= '9') {
                n = n * 10 + (str[p] - '0');
                p++;
            }

            while(n--) {
                temp[j] = str[i-1];
                j++;
            }
        }
    }

    temp[j] = '\0';

    printf("%s", temp);
}

int main() {
    char str[100];
    int choice;

    printf("Enter the string to compress: ");
    scanf("%s", str);

    printf("\nSelect an operation:\n");
    printf("1. Compress\n");
    printf("2. Decompress\n");
    printf("Choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Compressed string: ");
            compress(str);
            break;
        case 2:
            printf("Decompressed string: ");
            decompress(str);
            break;
        default:
            printf("Invalid Choice!");
            break;
    }

    return 0;
}