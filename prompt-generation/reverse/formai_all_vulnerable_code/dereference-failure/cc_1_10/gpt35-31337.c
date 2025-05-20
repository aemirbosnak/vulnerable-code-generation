//FormAI DATASET v1.0 Category: File Encyptor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an encryption key
const int key = 10;

int main(void) {
    char input_file[50], output_file[50];

    // Accept input file name
    printf("Enter input file name: ");
    scanf("%s", input_file);

    // Accept output file name
    printf("Enter output file name: ");
    scanf("%s", output_file);

    // Open input file
    FILE* in_file = fopen(input_file, "rb");
    if (!in_file) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Open output file
    FILE* out_file = fopen(output_file, "wb");
    if (!out_file) {
        printf("Error: Could not create output file.\n");
        fclose(in_file);
        return 1;
    }

    // Read all bytes from input file
    int num_bytes;
    char* buffer;
    fseek(in_file, 0, SEEK_END);
    num_bytes = ftell(in_file);
    fseek(in_file, 0, SEEK_SET);
    buffer = (char*)malloc(num_bytes + 1);
    fread(buffer, 1, num_bytes, in_file);
    fclose(in_file);
    buffer[num_bytes] = '\0';

    // Encypt the data
    for (int i = 0; i < strlen(buffer); i++) {
        buffer[i] += key;
    }

    // Write encrypted data to output file
    fwrite(buffer, 1, num_bytes, out_file);
    fclose(out_file);
    free(buffer);

    printf("Encryption successful.\n");

    return 0;
}