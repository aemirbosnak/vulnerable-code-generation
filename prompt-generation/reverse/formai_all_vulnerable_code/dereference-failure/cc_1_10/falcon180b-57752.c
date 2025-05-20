//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if (argc!= 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL)
    {
        printf("Error: File not found.\n");
        exit(1);
    }

    fseek(input_file, 0, SEEK_END);
    long file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    char *file_data = (char *)malloc(file_size + 1);
    if (file_data == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    fread(file_data, file_size, 1, input_file);
    fclose(input_file);

    int key = time(NULL) % 256;
    int i, j;
    for (i = 0; i < file_size; i++)
    {
        file_data[i] ^= key;
        key = (key * 3) % 256;
    }

    printf("Encrypted file: %s\n", argv[1]);

    FILE *output_file = fopen(argv[1], "wb");
    if (output_file == NULL)
    {
        printf("Error: File not found.\n");
        exit(1);
    }

    fwrite(file_data, file_size, 1, output_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");

    free(file_data);
    return 0;
}