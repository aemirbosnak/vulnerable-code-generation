//FormAI DATASET v1.0 Category: Spell checking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICT_SIZE 50000

typedef struct Node {
    char word[MAX_WORD_LENGTH];
    struct Node* next;
} Node;

Node* dict[DICT_SIZE] = {NULL};

int hash(char* word) {
    int sum = 0;
    for (int i = 0; i < strlen(word); i++) {
        sum += tolower(word[i]);
    }
    return (sum % DICT_SIZE);
}

void insertDictionary(char* word) {
    int index = hash(word);
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->next = dict[index];
    dict[index] = newNode;
}

int checkDictionary(char* word) {
    int index = hash(word);
    Node* temp = dict[index];
    while (temp) {
        if (!strcmp(temp->word, word)) {
            printf("Found %s in dictionary!\n", word);
            return 1;
        }
        temp = temp->next;
    }
    printf("%s not found in dictionary...\n", word);
    return 0;
}

int main() {
    FILE* fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error opening dictionary file!\n");
        return -1;
    }
    char buffer[MAX_WORD_LENGTH];
    while (fgets(buffer, MAX_WORD_LENGTH, fp)) {
        buffer[strlen(buffer)-1] = '\0';
        insertDictionary(buffer);
    }
    fclose(fp);
    printf("Dictionary loaded successfully.\n\n");

    char input[MAX_WORD_LENGTH];
    printf("Enter text to spell check:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);
    char* token = strtok(input, " \n");
    while (token != NULL) {
        int len = strlen(token);
        if (len != 0 && !isalpha(token[0])) {
            printf("'%c' is not a word!\n", token[0]);
        } else if (len > MAX_WORD_LENGTH) {
            printf("'%s' is too long!\n", token);
        } else {
            checkDictionary(token);
        }
        token = strtok(NULL, " \n");
    }
    return 0;
}