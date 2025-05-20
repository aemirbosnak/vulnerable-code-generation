//FormAI DATASET v1.0 Category: Spell checking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

char* words[MAX_NUM_WORDS];

char* read_file(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp);

    char* file_contents = (char*) malloc(file_size+1);
    fread(file_contents, 1, file_size, fp);
    fclose(fp);

    file_contents[file_size] = '\0';

    return file_contents;
}

char** tokenize(char* text, int* num_tokens) {
    char** tokens = (char**) malloc(MAX_NUM_WORDS * sizeof(char*));
    char* curr = text;

    int count = 0;

    while (*curr != '\0') {
        while (isspace(*curr)) curr++;
        char* start = curr;
        while (*curr != '\0' && !isspace(*curr)) curr++;
        if (curr - start > 0) {
            char* token = (char*) malloc(curr - start + 1);
            strncpy(token, start, curr - start);
            token[curr - start] = '\0';
            tokens[count++] = token;
        }
    }

    *num_tokens = count;

    return tokens;
}

char* strip_punc(char* word) {
    int len = strlen(word);
    char* stripped_word = (char*) malloc(len + 1);
    int stripped_len = 0;

    for (int i = 0; i < len; i++) {
        if (isalpha(word[i])) {
            stripped_word[stripped_len++] = tolower(word[i]);
        }
    }

    stripped_word[stripped_len] = '\0';

    return stripped_word;
}

void add_word(char* word) {
    char* stripped_word = strip_punc(word);
    int len = strlen(stripped_word);

    if (len == 0 || len > MAX_WORD_LENGTH) {
        return;
    }

    for (int i = 0; i < len; i++) {
        if (!isalpha(stripped_word[i])) {
            return;
        }
    }

    for (int i = 0; i < MAX_NUM_WORDS; i++) {
        if (words[i] == NULL) {
            words[i] = stripped_word;
            return;
        } else if (strcmp(words[i], stripped_word) == 0) {
            return;
        }
    }

    free(stripped_word);
}

void check_spelling(char** tokens, int num_tokens) {
    printf("Words not found in dictionary:\n");
    printf("-----------------------------\n");

    int count = 0;

    for (int i = 0; i < num_tokens; i++) {
        char* stripped_word = strip_punc(tokens[i]);
        int found = 0;

        if (strlen(stripped_word) == 0) {
            continue;
        }

        for (int j = 0; j < MAX_NUM_WORDS; j++) {
            if (words[j] != NULL && strcmp(words[j], stripped_word) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("%s\n", tokens[i]);
            count++;
        }

        free(stripped_word);
    }

    if (count == 0) {
        printf("All words are correctly spelled.\n");
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <dictionary file> <text file>\n", argv[0]);
        return 1;
    }

    char* dict = read_file(argv[1]);
    char** dict_tokens;
    int num_dict_tokens;
    dict_tokens = tokenize(dict, &num_dict_tokens);

    char* text = read_file(argv[2]);
    char** text_tokens;
    int num_text_tokens;
    text_tokens = tokenize(text, &num_text_tokens);

    for (int i = 0; i < num_dict_tokens; i++) {
        add_word(dict_tokens[i]);
    }

    check_spelling(text_tokens, num_text_tokens);

    for (int i = 0; i < num_dict_tokens; i++) {
        free(dict_tokens[i]);
    }
    free(dict);
    free(dict_tokens);

    for (int i = 0; i < num_text_tokens; i++) {
        free(text_tokens[i]);
    }
    free(text);
    free(text_tokens);

    for (int i = 0; i < MAX_NUM_WORDS; i++) {
        if (words[i] != NULL) {
            free(words[i]);
        }
    }

    return 0;
}