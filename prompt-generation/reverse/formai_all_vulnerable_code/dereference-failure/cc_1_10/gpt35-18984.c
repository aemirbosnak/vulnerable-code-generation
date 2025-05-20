//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cat_to_english(char*);
char* english_to_cat(char*);

int main() {
    char input[100];

    printf("\nWelcome to the C Cat Language Translator\n");
    printf("=========================================\n");

    while(1) {
        printf("Enter a sentence to be translated: ");
        fgets(input, sizeof(input), stdin);
        strtok(input, "\n");

        if(input[0] == '\0') {
            printf("Exiting program...\n");
            break;
        }

        if(input[0] >= 'a' && input[0] <= 'z') {
            printf("%s", english_to_cat(input));
        } else {
            printf("%s", cat_to_english(input));
        }

        printf("\n");
    }

    return 0;
}

char* cat_to_english(char* input) {
    char* output = (char*)malloc(strlen(input) * 3 + 1);
    char* token;
    char* delimiter = " ";

    while((token = strtok(input, delimiter)) != NULL) {
        input = NULL;

        if(strcmp(token, "meow") == 0) {
            strcat(output, "I");
        } else if(strcmp(token, "purr") == 0) {
            strcat(output, "am");
        } else if(strcmp(token, "hiss") == 0) {
            strcat(output, "angry");
        } else if(strcmp(token, "chirp") == 0) {
            strcat(output, "happy");
        } else if(strcmp(token, "scratch") == 0) {
            strcat(output, "need attention");
        }

        strcat(output, " ");
    }

    return output;
}

char* english_to_cat(char* input) {
    char* output = (char*)malloc(strlen(input) * 3 + 1);
    char* token;
    char* delimiter = " ";
    char* translation;

    while((token = strtok(input, delimiter)) != NULL) {
        input = NULL;

        if(strcmp(token, "I") == 0) {
            translation = "meow";
        } else if(strcmp(token, "am") == 0) {
            translation = "purr";
        } else if(strcmp(token, "angry") == 0) {
            translation = "hiss";
        } else if(strcmp(token, "happy") == 0) {
            translation = "chirp";
        } else if(strcmp(token, "need") == 0 && strcmp(strtok(NULL, delimiter), "attention") == 0) {
            translation = "scratch";
        } else {
            strcat(output, token);
            strcat(output, " ");
            continue;
        }

        strcat(output, translation);
        strcat(output, " ");
    }

    return output;
}