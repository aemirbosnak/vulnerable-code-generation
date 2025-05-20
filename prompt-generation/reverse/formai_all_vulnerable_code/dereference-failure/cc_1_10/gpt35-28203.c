//FormAI DATASET v1.0 Category: File Encyptor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_BUFFER_SIZE 100000

int main(int argc, char** argv) {

    // check if filename and key are provided in arguments
    if (argc != 3) {
        printf("Usage: ./encryptor <filename> <key>\n");
        return 1;
    }

    // open the file
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    // read the file into memory
    char* buffer = (char*) malloc(sizeof(char) * MAX_BUFFER_SIZE);
    if (!buffer) {
        printf("Could not allocate memory for buffer\n");
        fclose(fp);
        return 1;
    }
    size_t bytes_read = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, fp);
    fclose(fp);

    // get the key
    char* key = argv[2];
    int key_length = strlen(key);

    // do some math to encrypt the buffer
    for (int i = 0; i < bytes_read; i++) {
        buffer[i] ^= key[i % key_length];
    }

    // create the output filename
    char* output_filename = (char*) malloc(sizeof(char) * MAX_FILENAME_LENGTH);
    if (!output_filename) {
        printf("Could not allocate memory for output filename\n");
        free(buffer);
        return 1;
    }
    strcpy(output_filename, argv[1]);
    strcat(output_filename, ".encrypted");

    // write the encrypted buffer to the output file
    fp = fopen(output_filename, "w");
    if (!fp) {
        printf("Could not create output file %s\n", output_filename);
        free(buffer);
        free(output_filename);
        return 1;
    }
    fwrite(buffer, sizeof(char), bytes_read, fp);
    fclose(fp);

    // clean up memory
    free(buffer);
    free(output_filename);

    printf("File \"%s\" encrypted successfully!\n", argv[1]);

    return 0;
}