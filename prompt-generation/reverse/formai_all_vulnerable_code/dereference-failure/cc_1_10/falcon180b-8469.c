//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1000
#define MAX_WORD_SIZE 100
#define MAX_FILE_NAME_SIZE 100
#define MAX_EBOOK_CONTENTS_SIZE 1000000

typedef struct {
    char filename[MAX_FILE_NAME_SIZE];
    char contents[MAX_EBOOK_CONTENTS_SIZE];
} Ebook;

Ebook* createEbook(char* filename) {
    Ebook* ebook = (Ebook*) malloc(sizeof(Ebook));
    strcpy(ebook->filename, filename);
    ebook->contents[0] = '\0';
    return ebook;
}

void deleteEbook(Ebook* ebook) {
    free(ebook);
}

int readEbook(Ebook* ebook) {
    FILE* fp;
    char line[MAX_LINE_SIZE];
    char* word;
    int count = 0;
    fp = fopen(ebook->filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return -1;
    }
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        count++;
        int i = 0;
        while (i < strlen(line) && isspace(line[i])) {
            i++;
        }
        if (i == strlen(line)) {
            continue;
        }
        word = (char*) malloc((strlen(line) - i + 1) * sizeof(char));
        strcpy(word, &line[i]);
        strcat(ebook->contents, word);
        strcat(ebook->contents, " ");
        free(word);
    }
    fclose(fp);
    return count;
}

int searchEbook(Ebook* ebook, char* keyword) {
    char* contents = ebook->contents;
    char* token = strtok(contents, " ");
    while (token!= NULL) {
        if (strcmp(token, keyword) == 0) {
            return 1;
        }
        token = strtok(NULL, " ");
    }
    return 0;
}

int main() {
    Ebook* ebook;
    char filename[MAX_FILE_NAME_SIZE];
    printf("Enter ebook filename: ");
    scanf("%s", filename);
    ebook = createEbook(filename);
    int count = readEbook(ebook);
    printf("Ebook contents:\n%s\n", ebook->contents);
    char keyword[MAX_WORD_SIZE];
    printf("Enter keyword to search: ");
    scanf("%s", keyword);
    if (searchEbook(ebook, keyword)) {
        printf("Keyword found!\n");
    } else {
        printf("Keyword not found.\n");
    }
    deleteEbook(ebook);
    return 0;
}