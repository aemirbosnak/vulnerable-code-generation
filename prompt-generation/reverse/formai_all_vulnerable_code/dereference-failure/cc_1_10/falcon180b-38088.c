//Falcon-180B DATASET v1.0 Category: Text processing ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORDS][50];
    int count[MAX_WORDS];
} WordFrequency;

void read_file(FILE *fp, WordFrequency *wf) {
    char ch;
    int index = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            index = 0;
            while (isalpha(ch)) {
                wf->word[index][wf->count[index]] = tolower(ch);
                index++;
                ch = fgetc(fp);
            }
            wf->word[index][wf->count[index]] = '\0';
            wf->count[index]++;
        }
    }
}

void display_frequencies(WordFrequency *wf) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (wf->count[i] > 0) {
            printf("%s: %d\n", wf->word[i], wf->count[i]);
        }
    }
}

int main() {
    FILE *fp;
    WordFrequency wf;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open input file.\n");
        return 1;
    }

    read_file(fp, &wf);
    fclose(fp);

    display_frequencies(&wf);

    return 0;
}