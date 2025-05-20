//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

void huffman_coding(char **code, int *len, char *str)
{
    int frequency[MAX] = {0};
    int i, j, k, max_freq = 0;
    char *huff_tree = NULL;

    for (i = 0; str[i] != '\0'; i++)
    {
        frequency[str[i]]++;
    }

    for (i = 0; frequency[i] != 0; i++)
    {
        if (frequency[i] > max_freq)
        {
            max_freq = frequency[i];
        }
    }

    huff_tree = (char *)malloc((max_freq + 1) * sizeof(char));
    huff_tree[0] = '\0';

    for (i = 0; str[i] != '\0'; i++)
    {
        k = frequency[str[i]] - 1;
        for (j = max_freq; j >= k; j--)
        {
            huff_tree[j] = str[i];
        }
    }

    code = (char *)malloc((*len) * sizeof(char));
    *len = 0;

    for (i = 0; huff_tree[i] != '\0'; i++)
    {
        code[*len] = huff_tree[i];
        (*len)++;
    }

    free(huff_tree);
}

int main()
{
    char str[] = "This is a sample text for Huffman coding.";
    char **code = NULL;
    int len = 0;

    huffman_coding(code, &len, str);

    printf("Huffman code:\n");
    for (int i = 0; code[i] != '\0'; i++)
    {
        printf("%c ", code[i]);
    }

    printf("\nTotal code length: %d", len);

    return 0;
}