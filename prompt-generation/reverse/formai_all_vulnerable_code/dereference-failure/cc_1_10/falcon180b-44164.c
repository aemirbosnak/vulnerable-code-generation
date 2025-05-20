//Falcon-180B DATASET v1.0 Category: File handling ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

char *words[MAX_WORDS];
int num_words = 0;

void read_file(FILE *fp) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            words[num_words] = (char *)malloc(MAX_WORD_LENGTH * sizeof(char));
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
}

void display_words() {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
}

int main() {
    FILE *fp;
    char filename[MAX_WORD_LENGTH];
    printf("Enter the filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found.\n");
        exit(0);
    }
    read_file(fp);
    fclose(fp);
    printf("The words in the file are:\n");
    display_words();
    return 0;
}