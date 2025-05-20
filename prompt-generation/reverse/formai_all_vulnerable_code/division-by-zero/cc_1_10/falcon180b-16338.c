//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FILE_LENGTH 1000000
#define MAX_KEY_LENGTH 100
#define MAX_ROUNDS 100

int main(int argc, char *argv[]) {
    FILE *file, *output;
    char key[MAX_KEY_LENGTH];
    int key_length, rounds, i, j;
    char buffer[MAX_FILE_LENGTH];
    int file_length;

    // Get key and number of rounds from user
    printf("Enter encryption key: ");
    scanf("%s", key);
    printf("Enter number of rounds: ");
    scanf("%d", &rounds);

    // Open input file
    file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Get file length
    fseek(file, 0, SEEK_END);
    file_length = ftell(file);
    rewind(file);

    // Read input file into buffer
    fread(buffer, 1, file_length, file);
    fclose(file);

    // Encrypt buffer using key and number of rounds
    for (i = 0; i < rounds; i++) {
        for (j = 0; j < file_length; j++) {
            buffer[j] ^= key[i % key_length];
        }
    }

    // Open output file
    output = fopen("encrypted.txt", "wb");
    if (output == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    // Write encrypted buffer to output file
    fwrite(buffer, 1, file_length, output);
    fclose(output);

    printf("File encrypted successfully.\n");
    return 0;
}