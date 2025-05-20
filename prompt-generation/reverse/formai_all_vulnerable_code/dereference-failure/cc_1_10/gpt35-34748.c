//FormAI DATASET v1.0 Category: Spell checking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORDS 50000
#define MAXLEN 100

char dictionary[MAXWORDS][MAXLEN];
int dictCount = 0;

int readDictionary(FILE *fp) {
    char word[MAXLEN];
    while (fscanf(fp, "%s", word) != EOF) {
        if (dictCount == MAXWORDS) {
            printf("Maximum dictionary size exceeded\n");
            return 1;
        }
        strcpy(dictionary[dictCount++], word);
    }
    return 0;
}

int isWord(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i])) {
            return 0;
        }
    }
    return 1;
}

void toLowerCase(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

int isCorrect(char *word) {
    int i;
    for (i = 0; i < dictCount; i++) {
        if (strcasecmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void removePunctuation(char *word) {
    int len = strlen(word);
    if (ispunct(word[len - 1])) {
        word[len - 1] = '\0';
    }
}

void checkWord(char *word) {
    if (!isWord(word)) {
        printf("The input contains non-alphabetic characters: %s\n", word);
        return;
    }
    toLowerCase(word);
    removePunctuation(word);
    if (isCorrect(word)) {
        printf("%s is spelled correctly!\n", word);
        return;
    }
    printf("Possible correct spellings for %s: \n", word);
    int i, j, d1, d2;
    for (i = 0; i < dictCount; i++) {
        d1 = strlen(word), d2 = strlen(dictionary[i]);
        if (abs(d1 - d2) > 1) {
            continue;
        }
        int editDist[d1 + 1][d2 + 1];
        for (j = 0; j <= d2; j++) {
            editDist[0][j] = j;
        }
        for (j = 0; j <= d1; j++) {
            editDist[j][0] = j;
        }
        for (j = 1; j <= d1; j++) {
            for (int k = 1; k <= d2; k++) {
                if (word[j - 1] == dictionary[i][k - 1]) {
                    editDist[j][k] = editDist[j - 1][k - 1];
                } else {
                    editDist[j][k] = 1 + (editDist[j - 1][k - 1] < editDist[j - 1][k] ?
                                          editDist[j - 1][k - 1] : editDist[j - 1][k]);
                    editDist[j][k] = (editDist[j][k] < editDist[j][k - 1] ?
                                          editDist[j][k] : editDist[j][k - 1]) + 1;
                }
            }
        }
        if (editDist[d1][d2] <= 1) {
            printf("%s\n", dictionary[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: spellcheck inputfile dictionaryfile\n");
        return 0;
    }
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL) {
        printf("Could not open input file %s\n", argv[1]);
        return 1;
    }
    FILE *dictfile = fopen(argv[2], "r");
    if (dictfile == NULL) {
        printf("Could not open dictionary file %s\n", argv[2]);
        return 1;
    }
    if (readDictionary(dictfile) != 0) {
        return 1;
    }
    char line[MAXLEN];
    while (fgets(line, MAXLEN, infile) != NULL) {
        char *token = strtok(line, " \n\t\r");
        while (token != NULL) {
            checkWord(token);
            token = strtok(NULL, " \n\t\r");
        }
    }
    fclose(infile);
    fclose(dictfile);
    return 0;
}