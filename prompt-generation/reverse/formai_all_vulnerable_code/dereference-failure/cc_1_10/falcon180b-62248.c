//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char *english;
    char *alien;
};

int main() {
    FILE *dict;
    char line[MAX_WORD_LENGTH];
    struct word words[MAX_WORDS];
    int count = 0;
    
    // Load dictionary file
    dict = fopen("dictionary.txt", "r");
    if (dict == NULL) {
        printf("Error: dictionary file not found.\n");
        return 1;
    }
    
    // Read words from file
    while (fgets(line, MAX_WORD_LENGTH, dict)!= NULL) {
        if (count >= MAX_WORDS) {
            printf("Error: too many words in dictionary.\n");
            fclose(dict);
            return 1;
        }
        words[count].english = strdup(line);
        
        // Convert to alien language
        for (int i = 0; i < strlen(words[count].english); i++) {
            if (isalpha(words[count].english[i])) {
                words[count].alien[i] = words[count].english[i] + 3;
            } else {
                words[count].alien[i] = words[count].english[i];
            }
        }
        words[count].alien[strlen(words[count].english)] = '\0';
        count++;
    }
    fclose(dict);
    
    // Translate sentence
    char sentence[MAX_WORD_LENGTH];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, MAX_WORD_LENGTH, stdin);
    
    // Split sentence into words
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        // Look up word in dictionary
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s -> %s\n", token, words[i].alien);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%s not found in dictionary.\n", token);
        }
        token = strtok(NULL, " ");
    }
    
    return 0;
}