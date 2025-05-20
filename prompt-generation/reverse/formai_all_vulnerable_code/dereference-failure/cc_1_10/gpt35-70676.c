//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: satisfied
// C Cat Language Translator
// By Chatbot

#include <stdio.h>
#include <string.h>

int countWords(char sentence[]) {
    int count = 0;
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == ' ') count++;
    }
    return count + 1;
}

void translate(char sentence[]) {
    char* catWords[] = {"meow", "purr", "hiss", "scratch", "litter box", "mouse", "kitten", "whiskers", "claw", "fur"};
    char* humanWords[] = {"hello", "love", "anger", "irritation", "bathroom", "computer", "baby cat", "hair on face", "finger nail", "hair"};
    int wordCount = countWords(sentence);
    char* words[wordCount];

    char* token = strtok(sentence, " ");
    int i = 0;
    while (token != NULL) {
        words[i] = token;
        token = strtok(NULL, " ");
        i++;
    }

    printf("\nCats say: ");
    for (int j = 0; j < wordCount; j++) {
        int found = 0;
        for (int k = 0; k < 10; k++) {
            if (strcmp(words[j], humanWords[k]) == 0) {
                printf("%s ", catWords[k]);
                found = 1;
                break;
            }
        }
        if (!found) printf("%s ", words[j]);
    }
    printf("\n");
}

int main() {
    char sentence[1000];
    printf("Enter a sentence in human language: ");
    fgets(sentence, 1000, stdin);
    sentence[strcspn(sentence, "\n")] = '\0';
    translate(sentence);
    return 0;
}