//FormAI DATASET v1.0 Category: Compression algorithms ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to compress a string using the Run-length encoding algorithm.
char* RLEcompress(char* str)
{
    char* compressedStr = (char*)malloc(strlen(str)*2 + 1); //allocate memory for compressed string

    int count=1;
    int index=0;
    for(int i=0;i<strlen(str);i++)
    {
        if(i==strlen(str)-1 || str[i]!=str[i+1]) //if current and next character are different
        {
            compressedStr[index++]= str[i];
            compressedStr[index++]= count +'0'; //convert integer count to char and add it to compressed string
            count=1;
        }
        else //if current and next character are same
        {
            count++;
        }
    }
    compressedStr[index]='\0'; //append string termination character
    return compressedStr;
}

//Function to decompress a string compressed using the Run-length encoding algorithm.
char* RLEdecompress(char* str)
{
    char* decompressedStr = (char*)malloc(strlen(str)+1); //allocate memory for decompressed string

    int index=0;
    for(int i=0;i<strlen(str);i+=2)
    {
        char ch=str[i];
        int count=str[i+1]-'0'; //convert char count to integer

        for(int j=0;j<count;j++)
        {
            decompressedStr[index++]= ch; //append char ch to decompressed string count number of times.
        }
    }
    decompressedStr[index]='\0'; //append string termination character
    return decompressedStr;
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", str); //reading input string with spaces until newline character

    char* compressed = RLEcompress(str);
    char* decompressed = RLEdecompress(compressed);

    printf("\nCompressed string: %s", compressed);
    printf("\nDecompressed string: %s", decompressed);

    free(compressed); //freeing allocated memory
    free(decompressed);

    return 0;
}