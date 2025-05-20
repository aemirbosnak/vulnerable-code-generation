//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *english;
    char *cCode;
} Translation;

Translation phrases[] = {
    {"Hello World!", "printf(\"Hello World!\");"},
    {"Print X!", "printf(\"Print X!\");"},
    {"Variable X = Y;", "int X = Y;"},
    {"Add X and Y", "X += Y;"},
    {"Subtract Y from X", "X -= Y;"},
    {"Multiply X by Y", "X *= Y;"},
    {"Divide X by Y", "X /= Y;"},
    {"Assign value Z to X", "X = Z;"},
    {"If X is true", "if (X) {"},
    {"Print this message if X is true", "printf(\"This message is true!\");"},
    {"Else if Y is true", "} else if (Y) {"},
    {"Print this message if Y is true", "printf(\"This message is true!\");"},
    {"Else", "} else {"},
    {"Print this message if X is false", "printf(\"This message is false!\");"},
    {"End if", "}"},
    {"While X is true", "while (X) {"},
    {"Do this while X is true", ""},
    {"End while", "}"},
    {"For loop starting at X and ending at Y", "for (int i = X; i <= Y; i++) {"},
    {"Do this for each iteration", ""},
    {"End for loop", "}"}
};

int main(int argc, char *argv[]) {
    int len, i;
    char sentence[100][50];
    char *token;
    char words[10][50];
    char temp[100];

    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    strcpy(temp, argv[1]);
    len = strlen(temp);

    int j = 0;
    for (i = 0; i < len; i++) {
        if (isspace(temp[i])) {
            sentence[j][i] = '\0';
            j++;
            i++;
        } else {
            sentence[j][i] = temp[i];
        }
    }

    for (i = 0; i < 10 && j < 10; i++, j++) {
        token = strtok(sentence[i], " ");
        strcpy(words[i], token);

        for (int k = 0; phrases[k].english != NULL; k++) {
            if (strcmp(phrases[k].english, words[i]) == 0) {
                printf("%s --> %s\n", words[i], phrases[k].cCode);
                strcat(temp, phrases[k].cCode);
                strcat(temp, " ");
                i--;
                break;
            }
        }
    }

    printf("\nYour C code is:\n%s\n", temp);

    return 0;
}