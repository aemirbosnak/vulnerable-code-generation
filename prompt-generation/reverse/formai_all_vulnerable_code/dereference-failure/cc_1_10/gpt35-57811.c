//FormAI DATASET v1.0 Category: Spell checking ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_LINE_LEN 500

typedef struct word {
    char* str;
    int line_no;
    struct word* next;
} word;

void insert_word(word** list, char* str, int line_no) {
    word* curr = *list;
    word* new_word = (word*)malloc(sizeof(word));
    new_word->str = str;
    new_word->line_no = line_no;
    if(!curr || strcmp(curr->str, str) > 0) {
        *list = new_word;
        new_word->next = curr;
    }
    else {
        while(curr->next && strcmp(curr->next->str, str) <= 0) {
            curr = curr->next;
        }
        new_word->next = curr->next;
        curr->next = new_word;
    }
}

int is_valid_char(char c) {
    return isalpha(c) || c == '\'' || c == '-';
}

int get_word(char* line, int start, char* word) {
    int end = start;
    while(line[end] && is_valid_char(line[end])) {
        end++;
    }
    int len = end - start;
    if(len > 0) {
        strncpy(word, line+start, len);
        word[len] = '\0';
        return end;
    }
    else {
        return -1;
    }
}

void check_spelling(FILE* dictionary, char* text) {
    word* word_list = NULL;
    char buf[MAX_LINE_LEN];
    int line_no = 0;
    while(fgets(buf, MAX_LINE_LEN, text)) {
        line_no++;
        int i = 0;
        while(buf[i]) {
            while(buf[i] && !is_valid_char(buf[i])) {
                i++;
            }
            if(buf[i]) {
                char word[MAX_WORD_LEN];
                i = get_word(buf, i, word);
                if(i > 0) {
                    int found = 0;
                    fseek(dictionary, 0, SEEK_SET);
                    char dict_word[MAX_WORD_LEN];
                    while(fscanf(dictionary, "%s", dict_word) != EOF) {
                        if(!strcmp(dict_word, word)) {
                            found = 1;
                            break;
                        }
                    }
                    if(!found) {
                        char* new_word = (char*)malloc((strlen(word)+1)*sizeof(char));
                        strcpy(new_word, word);
                        insert_word(&word_list, new_word, line_no);
                    }
                }
            }
        }
    }
    fclose(dictionary);
    
    word* curr = word_list;
    while(curr) {
        printf("%s\t(line %d)\n", curr->str, curr->line_no);
        curr = curr->next;
    }
}

int main(int argc, char** argv) {
    if(argc != 3) {
        printf("Usage: %s dictionary_file text_file\n", argv[0]);
        return 0;
    }
    FILE* dictionary = fopen(argv[1], "r");
    if(!dictionary) {
        printf("Error opening dictionary file: %s\n", argv[1]);
        return -1;
    }
    FILE* text = fopen(argv[2], "r");
    if(!text) {
        printf("Error opening text file: %s\n", argv[2]);
        return -1;
    }
    check_spelling(dictionary, text);
    return 0;
}