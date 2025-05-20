//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to get frequency of a character
int getFrequency(char* string, int len)
{
    int freq[256] = {0};

    for (int i = 0; i < len; i++)
        freq[string[i]]++;

    return freq;
}

// function to get the probability of a character
float getProbability(int frequency, int totalChars)
{
    return frequency / totalChars;
}

// function to create Huffman codes
void createHuffmanCodes(int* frequencies, int numChars)
{
    int* codes = malloc(numChars * sizeof(int));
    int* tree = malloc(numChars * sizeof(int));
    int i, j, left, right;

    // construct the Huffman tree
    for (i = 0; i < numChars; i++)
    {
        tree[i] = -1;
        tree[i] = i;
    }

    for (i = 0; i < numChars; i++)
    {
        left = i;
        right = -1;

        for (j = 0; j < numChars; j++)
        {
            if (tree[j] == -1)
            {
                left = j;
                break;
            }
        }

        for (j = 0; j < numChars; j++)
        {
            if (tree[j] == -1)
            {
                right = j;
                break;
            }
        }

        tree[left] = right;
    }

    for (i = 0; i < numChars; i++)
    {
        if (tree[i]!= -1)
            continue;

        left = i;
        right = -1;

        for (j = 0; j < numChars; j++)
        {
            if (tree[j] == -1)
            {
                left = j;
                break;
            }
        }

        for (j = 0; j < numChars; j++)
        {
            if (tree[j] == -1)
            {
                right = j;
                break;
            }
        }

        tree[left] = right;
    }

    for (i = 0; i < numChars; i++)
    {
        codes[i] = 0;

        for (j = 0; j < numChars; j++)
        {
            if (tree[j] == i)
                codes[i] = j;
        }
    }
}

// function to encode a string using Huffman codes
char* encode(char* string, int* frequencies, int numChars)
{
    char* encodedString = malloc(sizeof(char) * strlen(string) * 2);

    for (int i = 0; i < strlen(string); i++)
    {
        int code = 0;

        for (int j = 0; j < numChars; j++)
        {
            if (frequencies[j] == 0)
                continue;

            if (string[i] == '0' + j)
            {
                code = j;
                break;
            }
        }

        encodedString[2 * i] = code + '0';
        encodedString[2 * i + 1] = '\0';
    }

    return encodedString;
}

// function to decode a string using Huffman codes
char* decode(char* encodedString, int* tree, int numChars)
{
    char* decodedString = malloc(sizeof(char) * strlen(encodedString));

    for (int i = 0; i < strlen(encodedString); i++)
    {
        int left = 0;
        int right = 0;

        for (int j = 0; j < numChars; j++)
        {
            if (tree[j] == encodedString[i])
            {
                left = j;
                break;
            }
        }

        for (int j = 0; j < numChars; j++)
        {
            if (tree[j] == encodedString[i])
            {
                right = j;
                break;
            }
        }

        decodedString[i] = '0' + left;
    }

    return decodedString;
}

int main()
{
    char* string = "hello world";
    int frequencies[256] = {0};

    for (int i = 0; i < strlen(string); i++)
        frequencies[string[i]]++;

    int numChars = 26;
    int* tree = malloc(numChars * sizeof(int));
    int* codes = malloc(numChars * sizeof(int));

    createHuffmanCodes(frequencies, numChars);

    for (int i = 0; i < strlen(string); i++)
    {
        int code = 0;

        for (int j = 0; j < numChars; j++)
        {
            if (frequencies[j] == 0)
                continue;

            if (string[i] == '0' + j)
            {
                code = j;
                break;
            }
        }

        codes[code] = i;
    }

    printf("Original String: %s\n", string);
    printf("Huffman Codes:\n");
    for (int i = 0; i < numChars; i++)
    {
        printf("%d = %c\n", i, codes[i] + '0');
    }

    printf("Encoded String: ");
    char* encodedString = encode(string, frequencies, numChars);
    printf("%s\n", encodedString);

    printf("Decoded String: %s\n", decode(encodedString, tree, numChars));

    free(encodedString);
    free(codes);
    free(tree);

    return 0;
}