//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str[1000];
    printf("Enter a word: ");
    scanf("%s", str);

    char *p = str;
    int l = 0;
    while (*p) {
        l++;
        p++;
    }

    int i = 0;
    char arr[l];
    for (i = 0; i < l; i++) {
        arr[i] = str[i];
    }

    arr[l - 1] = '\0';

    char *w = arr;
    char **dict = (char **)malloc(1000 * sizeof(char *));
    dict = (char **)realloc(dict, l * sizeof(char *));

    FILE *fp = fopen("dictionary.txt", "r");
    char **words = (char **)malloc(1000 * sizeof(char *));
    words = (char **)realloc(words, l * sizeof(char *));

    int j = 0;
    char word[100];
    while (fscanf(fp, "%s", word) != EOF) {
        words[j] = (char *)malloc(strlen(word) + 1);
        strcpy(words[j], word);
        j++;
    }

    fclose(fp);

    int found = 0;
    for (i = 0; i < l; i++) {
        for (j = 0; words[j] != NULL; j++) {
            if (strcmp(arr[i], words[j]) == 0) {
                found = 1;
                break;
            }
        }
    }

    if (found) {
        printf("Word found!\n");
    } else {
        printf("Word not found.\n");
    }

    return 0;
}