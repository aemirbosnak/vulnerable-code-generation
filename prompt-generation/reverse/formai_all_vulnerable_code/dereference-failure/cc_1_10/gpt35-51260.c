//FormAI DATASET v1.0 Category: modern Encryption ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* encrypt(char* input, char* key)
{
    int i, j=0, n = strlen(key);

    char* output = (char*)malloc((strlen(input)+1)*sizeof(char));

    for(i=0; i<strlen(input); i++)
    {
        output[i] = (((input[i]-'a') + (key[j]-'a'))%26) + 'a';
        j = (j+1)%n;
    }

    output[strlen(input)] = '\0';

    return output;
}

char* decrypt(char* input, char* key)
{
    int i, j=0, n = strlen(key);
    
    char* output = (char*)malloc((strlen(input)+1)*sizeof(char));

    for(i=0; i<strlen(input); i++)
    {
        output[i] = (((input[i]-'a') - (key[j]-'a') + 26)%26) + 'a';
        j = (j+1)%n;
    }

    output[strlen(input)] = '\0';

    return output;
}

int main()
{
    char input[] = "hello world";
    char key[] = "secretkey";

    char* encrypted_text = encrypt(input, key);

    printf("Encrypted Message: %s\n", encrypted_text);

    char* decrypted_text = decrypt(encrypted_text, key);

    printf("Decrypted Message: %s\n", decrypted_text);

    free(encrypted_text);
    free(decrypted_text);

    return 0;
}