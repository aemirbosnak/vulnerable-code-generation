//Falcon-180B DATASET v1.0 Category: Text processing ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

char *words[MAX_WORDS];
int num_words = 0;

void read_file(char *filename) {
    FILE *fp;
    char ch;
    int i = 0;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: unable to open file %s\n", filename);
        exit(1);
    }
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            words[num_words] = (char *) malloc(MAX_WORD_LENGTH * sizeof(char));
            strcpy(words[num_words], "");
            i = 0;
            while (isalpha(ch)) {
                words[num_words][i++] = tolower(ch);
                ch = fgetc(fp);
            }
            words[num_words][i] = '\0';
            num_words++;
        }
    }
    fclose(fp);
}

void print_words() {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
}

void reverse_words() {
    char *temp;
    int i, j;
    for (i = 0; i < num_words / 2; i++) {
        temp = words[i];
        words[i] = words[num_words - i - 1];
        words[num_words - i - 1] = temp;
    }
}

void main() {
    char filename[100];
    printf("Enter the name of the file: ");
    scanf("%s", filename);
    read_file(filename);
    reverse_words();
    print_words();
}