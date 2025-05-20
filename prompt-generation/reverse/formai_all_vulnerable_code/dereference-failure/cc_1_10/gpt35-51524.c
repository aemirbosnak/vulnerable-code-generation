//FormAI DATASET v1.0 Category: Encryption ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

char *kc_encrypt(char *input, int key)
{
    int i;
    char *output = malloc(sizeof(char) * strlen(input));
    for (i = 0; i < strlen(input); i++)
    {
        output[i] = input[i] ^ key;
    }
    return output;
}

char *kc_decrypt(char *input, int key)
{
    int i;
    char *output = malloc(sizeof(char) * strlen(input));
    for (i = 0; i < strlen(input); i++)
    {
        output[i] = input[i] ^ key;
    }
    return output;
}

int main(int argc, char **argv)
{
    int i, key;
    char *input, *output, *decrypted;

    if (argc < 2)
    {
        printf("Usage: %s <input string> <key>\n", argv[0]);
        exit(1);
    }

    input = argv[1];
    key = atoi(argv[2]);

    output = kc_encrypt(input, key);
    printf("Encrypted output: %s\n", output);

    decrypted = kc_decrypt(output, key);
    printf("Decrypted output: %s\n", decrypted);

    free(output);
    free(decrypted);

    return 0;
}