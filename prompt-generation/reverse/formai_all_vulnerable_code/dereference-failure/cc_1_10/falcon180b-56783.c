//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void encrypt(char* input_file, char* output_file, int key)
{
    FILE* input = fopen(input_file, "r");
    FILE* output = fopen(output_file, "w");

    if (input == NULL || output == NULL)
    {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char buffer[1024];
    int buffer_index = 0;

    while (fgets(buffer, sizeof(buffer), input)!= NULL)
    {
        for (int i = 0; i < strlen(buffer); i++)
        {
            if (isalpha(buffer[i]))
            {
                char letter = buffer[i];

                if (isupper(letter))
                {
                    letter = letter + key - 65;

                    if (letter > 90)
                    {
                        letter = letter - 26;
                    }
                }
                else
                {
                    letter = letter + key - 97;

                    if (letter > 122)
                    {
                        letter = letter - 26;
                    }
                }

                buffer[i] = letter;
            }
        }

        fputs(buffer, output);
    }

    fclose(input);
    fclose(output);
}

void decrypt(char* input_file, char* output_file, int key)
{
    FILE* input = fopen(input_file, "r");
    FILE* output = fopen(output_file, "w");

    if (input == NULL || output == NULL)
    {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char buffer[1024];
    int buffer_index = 0;

    while (fgets(buffer, sizeof(buffer), input)!= NULL)
    {
        for (int i = 0; i < strlen(buffer); i++)
        {
            if (isalpha(buffer[i]))
            {
                char letter = buffer[i];

                if (isupper(letter))
                {
                    letter = letter - key - 65;

                    if (letter < 65)
                    {
                        letter = letter + 26;
                    }
                }
                else
                {
                    letter = letter - key - 97;

                    if (letter < 97)
                    {
                        letter = letter + 26;
                    }
                }

                buffer[i] = letter;
            }
        }

        fputs(buffer, output);
    }

    fclose(input);
    fclose(output);
}

int main()
{
    srand(time(NULL));
    int key = rand() % 26 + 1;

    printf("Key: %d\n", key);

    char input_file[50] = "input.txt";
    char output_file[50] = "output.txt";

    encrypt(input_file, output_file, key);
    decrypt(output_file, input_file, key);

    return 0;
}