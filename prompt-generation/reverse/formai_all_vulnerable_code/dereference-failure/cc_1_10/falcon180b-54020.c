//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to check if a given word is in the dictionary
int check_word(char *word, char *dictionary) {
    FILE *fp;
    char ch;
    int found = 0;
    fp = fopen(dictionary, "r");
    if (fp == NULL) {
        printf("Error opening dictionary file\n");
        exit(1);
    }
    while ((ch = fgetc(fp))!= EOF) {
        if (tolower(ch) == tolower(word[0])) {
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (found) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check spelling of a sentence
void spell_check(char *sentence, char *dictionary) {
    char *word;
    char *temp;
    int len;
    int i;
    int j;
    int k;
    int flag;
    word = strtok(sentence, " ");
    while (word!= NULL) {
        len = strlen(word);
        flag = 0;
        for (i = 0; i < len; i++) {
            if (!isalpha(word[i])) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            temp = (char *) malloc(len + 1);
            strcpy(temp, word);
            for (i = 0; i < len; i++) {
                temp[i] = tolower(temp[i]);
            }
            if (check_word(temp, dictionary) == 0) {
                printf("Possible spelling mistake: %s\n", word);
            }
            free(temp);
        }
        word = strtok(NULL, " ");
    }
}

// Main function
int main() {
    char sentence[1000];
    char dictionary[1000];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    printf("Enter the dictionary file name: ");
    fgets(dictionary, sizeof(dictionary), stdin);
    spell_check(sentence, dictionary);
    return 0;
}