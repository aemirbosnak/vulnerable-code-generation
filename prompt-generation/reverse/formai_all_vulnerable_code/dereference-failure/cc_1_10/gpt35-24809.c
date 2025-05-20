//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: interoperable
#include <stdio.h>
#include <string.h>

/* Function to check if a given word is present in the alien language */
int isPresent(char *word, char *alienLang[]) {
    int i = 0;
    while (alienLang[i] != NULL) {
        if (strcmp(word, alienLang[i]) == 0) {
            return 1;
        }
        i++;
    }
    return 0;
}

/* Function to translate a given sentence from alien language to English language */
char* translate(char *sentence, char *alienLang[], char *englishLang[]) {
    char *token;
    char *englishSentence = "";
    int found = 0;

    /* Tokenize the sentence */
    token = strtok(sentence, " ");

    while (token != NULL) {
        /* Check if the token represents a word in alien language */
        if (isPresent(token, alienLang)) {
            int index = 0;
            while (alienLang[index] != NULL) {
                if (strcmp(token, alienLang[index]) == 0) {
                    /* Append the English equivalent of the alien word to the English sentence */
                    englishSentence = strcat(englishSentence, englishLang[index]);
                    englishSentence = strcat(englishSentence, " ");
                    found = 1;
                    break;
                }
                index++;
            }
        } else {
            /* Token is in English already, append it to the English sentence */
            englishSentence = strcat(englishSentence, token);
            englishSentence = strcat(englishSentence, " ");
        }

        /* Get the next token */
        token = strtok(NULL, " ");
    }

    if (found == 0) {
        /* No words were translated */
        return "\nSorry, could not translate: ";
    } else {
        /* Remove the extra space at the end of the sentence */
        englishSentence[strlen(englishSentence)-1] = '\0';
        return englishSentence;
    }
}

int main() {
    /* Alien language words and their English equivalent */
    char *alienLang[] = {"blorx", "sesh", "glix", NULL};
    char *englishLang[] = {"hello", "world", "how", NULL};

    /* Get input sentence */
    char sentence[100];
    printf("Enter the sentence to translate:\n");
    fgets(sentence, 100, stdin);

    /* Translate the sentence */
    char *englishSentence = translate(sentence, alienLang, englishLang);
    printf("%s%s%s", "\nTranslated sentence: ", englishSentence, "\n");

    return 0;
}