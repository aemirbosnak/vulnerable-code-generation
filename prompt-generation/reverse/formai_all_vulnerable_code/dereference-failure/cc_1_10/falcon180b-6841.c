//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#define MAX_SIZE 100000

int main()
{
    FILE *input_file, *output_file;
    char input_filename[50], output_filename[50];
    char *key;
    int key_size, i, j, k;
    char text[MAX_SIZE];
    char encrypted_text[MAX_SIZE];
    int text_size, encrypted_text_size;

    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);
    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "r");
    if(input_file == NULL)
    {
        printf("Error: Input file not found.\n");
        exit(1);
    }

    fseek(input_file, 0, SEEK_END);
    text_size = ftell(input_file);
    rewind(input_file);

    fread(text, 1, text_size, input_file);
    fclose(input_file);

    printf("Enter the encryption key: ");
    scanf("%s", key);
    key_size = strlen(key);

    for(i=0; i<text_size; i++)
    {
        if(isalpha(text[i]))
        {
            j = tolower(text[i]) - 97;
            k = (j + key_size) % 26;
            encrypted_text[i] = (char)(k + 97);
        }
        else
        {
            encrypted_text[i] = text[i];
        }
    }

    encrypted_text_size = strlen(encrypted_text);

    output_file = fopen(output_filename, "w");
    if(output_file == NULL)
    {
        printf("Error: Output file could not be created.\n");
        exit(1);
    }

    fwrite(encrypted_text, 1, encrypted_text_size, output_file);
    fclose(output_file);

    printf("File encryption successful.\n");

    return 0;
}