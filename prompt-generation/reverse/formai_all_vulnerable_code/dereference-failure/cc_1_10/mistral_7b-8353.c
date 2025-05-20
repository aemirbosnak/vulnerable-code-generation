//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Word {
    char *word;
    int count;
} Word;

void toLowerCase(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (isupper((unsigned char)str[i]))
            str[i] += ('a' - 'A');
        i++;
    }
}

int hashFunction(char *str, int size) {
    int hash = 0;
    int i = 0;

    while (str[i] != '\0') {
        hash += (unsigned int)str[i] * (i + 1);
        i++;
    }

    return hash % size;
}

int main() {
    int size = 101;
    Word *hashTable = (Word *)malloc(size * sizeof(Word));

    char line[1024];
    FILE *file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error: Unable to open file\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, " ");
        int index;

        if (token == NULL)
            continue;

        toLowerCase(token);

        index = hashFunction(token, size);

        if (hashTable[index].word == NULL) {
            hashTable[index].word = (char *)malloc((strlen(token) + 1) * sizeof(char));
            strcpy(hashTable[index].word, token);
            hashTable[index].count = 1;
        } else {
            hashTable[index].count++;
        }

        token = strtok(NULL, " ");
    }

    fclose(file);

    printf("\nWord Frequency Count:\n");
    for (int i = 0; i < size; i++) {
        if (hashTable[i].word != NULL) {
            printf("%s : %d\n", hashTable[i].word, hashTable[i].count);
            free(hashTable[i].word);
        }
    }

    free(hashTable);

    return 0;
}