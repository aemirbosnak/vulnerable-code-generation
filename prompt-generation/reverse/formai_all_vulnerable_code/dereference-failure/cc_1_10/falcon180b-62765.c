//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 100
#define MAX_LINES 5000

char* remove_punctuation(char* str);
int is_valid_word(char* word);
int compare_words(const void* a, const void* b);

int main(int argc, char** argv) {
    FILE* file = fopen("medieval_tale.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int line_count = 0;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char* cleaned_line = remove_punctuation(line);
        char* words[MAX_LINES];
        int num_words = 0;
        char* word = strtok(cleaned_line, " ");
        while (word!= NULL) {
            if (is_valid_word(word)) {
                words[num_words++] = word;
            }
            word = strtok(NULL, " ");
        }
        qsort(words, num_words, sizeof(char*), compare_words);
        for (int i = 0; i < num_words; i++) {
            printf("%s ", words[i]);
        }
        printf("\n");
        line_count++;
        if (line_count >= MAX_LINES) {
            break;
        }
    }

    fclose(file);
    return 0;
}

char* remove_punctuation(char* str) {
    char* result = malloc(strlen(str) + 1);
    char* dest = result;
    for (char* src = str; *src!= '\0'; src++) {
        if (!isalnum(*src)) {
            continue;
        }
        *dest++ = tolower(*src);
    }
    *dest = '\0';
    return result;
}

int is_valid_word(char* word) {
    int length = strlen(word);
    if (length <= 0 || length > MAX_WORD_LENGTH) {
        return 0;
    }
    return 1;
}

int compare_words(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}