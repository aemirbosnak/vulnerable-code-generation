//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char *word;
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    WordCount *wc1 = (WordCount*)a;
    WordCount *wc2 = (WordCount*)b;
    if (wc1->count > wc2->count)
        return -1;
    else if (wc1->count < wc2->count)
        return 1;
    else
        return 0;
}

char* translate(char* sentence) {
    WordCount wc[1000];
    int i, j, k, n;
    char* token = strtok(sentence, " ");
    while (token!= NULL) {
        for (i = 0; i < strlen(token); i++) {
            if (token[i] == 'a' || token[i] == 'e' || token[i] == 'i' || token[i] == 'o' || token[i] == 'u') {
                strcat(token, "i");
                break;
            }
        }
        for (j = 0; j < strlen(token); j++) {
            if (token[j] =='s') {
                strcat(token, "z");
                break;
            }
        }
        for (k = 0; k < strlen(token); k++) {
            if (token[k] == 't') {
                strcat(token, "d");
                break;
            }
        }
        for (n = 0; n < strlen(token); n++) {
            if (token[n] == 'f') {
                strcat(token, "v");
                break;
            }
        }
        wc[i].word = strdup(token);
        wc[i].count = 1;
        i++;
    }
    qsort(wc, i, sizeof(WordCount), compare);
    char* result = (char*)malloc(1000000*sizeof(char));
    strcpy(result, "");
    for (int l = 0; l < i; l++) {
        strcat(result, wc[l].word);
        strcat(result, " ");
    }
    return result;
}

int main() {
    char sentence[1000];
    printf("Enter a sentence to translate into Alien language: ");
    scanf("%[^\n]", sentence);
    char* translated_sentence = translate(sentence);
    printf("Translated sentence: %s", translated_sentence);
    return 0;
}