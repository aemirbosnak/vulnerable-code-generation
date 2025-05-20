//FormAI DATASET v1.0 Category: Spell checking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

struct node {
    char word[100];
    struct node* next;
};

struct node* dictionary[26];

void checkWord(char word[]) {
    int first = word[0] - 97;
    struct node* ptr = dictionary[first];
    bool found = false;

    while (ptr != NULL) {
        if (strcmp(ptr->word, word) == 0) {
            found = true;
            break;
        }
        ptr = ptr->next;
    }

    if (found) {
        printf("%s is spelled correctly!\n", word);
    } else {
        printf("%s is misspelled!\n", word);
    }
}

void insertWord(char word[]) {
    int first = word[0] - 97;
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    strcpy(newNode->word, word);
    newNode->next = dictionary[first];
    dictionary[first] = newNode;
}

int main() {
    // initialize dictionary with words
    insertWord("apple");
    insertWord("banana");
    insertWord("cherry");
    insertWord("dog");
    insertWord("elephant");
    insertWord("feline");
    insertWord("glacier");
    insertWord("hockey");
    insertWord("indigo");
    insertWord("juggle");
    insertWord("kangaroo");
    insertWord("laser");
    insertWord("million");
    insertWord("noodle");
    insertWord("orange");
    insertWord("pie");
    insertWord("quilt");
    insertWord("rainbow");
    insertWord("sorrow");
    insertWord("tangerine");
    insertWord("umbrella");
    insertWord("vase");
    insertWord("wonderful");
    insertWord("xylophone");
    insertWord("yellow");
    insertWord("zebra");

    // get user input
    char input[100];
    printf("Enter a word to check its spelling (or exit to quit):\n");
    scanf("%s", input);
    while (strcmp(input, "exit") != 0) {
        // check if input is only letters
        bool onlyLetters = true;
        for (int i = 0; i < strlen(input); i++) {
            if (!isalpha(input[i])) {
                onlyLetters = false;
                printf("Error: Word can only contain letters.\n");
                break;
            }
        }
        if (onlyLetters) {
            // convert word to lowercase
            for (int i = 0; i < strlen(input); i++) {
                input[i] = tolower(input[i]);
            }
            checkWord(input);
        }
        // get user input again
        printf("Enter a word to check its spelling (or exit to quit):\n");
        scanf("%s", input);
    }

    return 0;
}