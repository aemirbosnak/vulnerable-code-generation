//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <plaintext> <cipher>\n", argv[0]);
        return 1;
    }

    FILE *inFile = fopen(argv[1], "r");
    if (inFile == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    FILE *outFile = fopen(argv[2], "w");
    if (outFile == NULL) {
        fclose(inFile);
        printf("Error opening output file\n");
        return 1;
    }

    char cipher[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char plaintext[26] = "abcdefghijklmnopqrstuvwxyz";

    char plain[10000];
    int len = 0;

    while (fgets(plain, sizeof(plain), inFile)) {
        len = strlen(plain);

        if (len == 0) {
            continue;
        }

        for (int i = 0; i < len; i++) {
            int index = (int) plaintext[plain[i] - 'a'] + (int) (atoi(argv[3]) % 26);

            if (index >= 26) {
                index -= 26;
            }

            plain[i] = cipher[index];
        }

        fputs(plain, outFile);
    }

    fclose(inFile);
    fclose(outFile);

    return 0;
}