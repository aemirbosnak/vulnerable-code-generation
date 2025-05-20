//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: shape shifting
// Shifting Cipher Encrypts files with a key
// Enter the file name, key as command line arguments
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // check for arguments
    if(argc != 3)
        return printf("Usage: %s filename key\n", argv[0]), 1;

    // instantiate key
    int key = atoi(argv[2]);
    if (key <= 0)
        return printf("Key must be positive."), 1;

    // open file
    FILE* fin = fopen(argv[1], "rb");
    if(!fin)
        return printf("Cannot open file %s", argv[1]), 1;

    // determine file length and allocate memory
    fseek(fin, 0L, SEEK_END);
    int file_len = ftell(fin);
    rewind(fin);
    char* buffer = malloc(file_len + 1);
    if(!buffer)
        return printf("Memory allocation failed"), 2;

    // read and encrypt
    int read;
    while ( (read = fread(buffer, 1, file_len, fin)) > 0)
    {
        for(int i = 0; i < read; i++)
            buffer[i] = (buffer[i] + key) % 256;
    }

    if(read == -1)
        return printf("Error reading file %s", argv[1]), 3;

    // write to new file
    fclose(fin);
    fin = fopen("encrypted.txt", "wb");
    if(!fin)
        return printf("Cannot open encrypted file"), 4;

    fwrite(buffer, 1, file_len, fin);
    fclose(fin);
    free(buffer);

    printf("Successfully encrypted %s with a key of %d", argv[1], key);
    return 0;
}