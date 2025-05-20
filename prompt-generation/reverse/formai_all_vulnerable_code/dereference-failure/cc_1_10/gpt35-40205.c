//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decode(char* code);

int main()
{
    char* alienCode = "QGFHTIOPMNLKJ";
    decode(alienCode);
    
    return 0;
}


void decode(char* code)
{
    int len = strlen(code);
    char* decoded = malloc(len*sizeof(char));
    
    for(int i=0; i<len; i++)
    {
        switch(code[i])
        {
            case 'Q':
                decoded[i] = 'A';
                break;
            case 'G':
                decoded[i] = 'B';
                break;
            case 'F':
                decoded[i] = 'C';
                break;
            case 'H':
                decoded[i] = 'D';
                break;
            case 'T':
                decoded[i] = 'E';
                break;
            case 'I':
                decoded[i] = 'F';
                break;
            case 'O':
                decoded[i] = 'G';
                break;
            case 'P':
                decoded[i] = 'H';
                break;
            case 'M':
                decoded[i] = 'I';
                break;
            case 'N':
                decoded[i] = 'J';
                break;
            case 'L':
                decoded[i] = 'K';
                break;
            case 'K':
                decoded[i] = 'L';
                break;
            case 'J':
                decoded[i] = 'M';
                break;
            default:
                printf("Unknown code detected. \n");
                break;
        }
    }
    
    printf("Decoded Message: %s\n", decoded);
    free(decoded);
    return;
}