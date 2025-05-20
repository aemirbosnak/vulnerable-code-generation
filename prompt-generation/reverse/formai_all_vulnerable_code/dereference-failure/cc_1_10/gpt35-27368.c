//FormAI DATASET v1.0 Category: Word Count Tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000

typedef struct word_count {
    char *word;
    int count;
} word_count;

word_count *init_dict(int size);
unsigned long hasher(char *str);
void insert(word_count *dict, char *word, int size);
void print_dict(word_count *dict, int size);
int get_word_count(word_count *dict, char *word, int size);

int main() {
    char text[MAX_STR_LEN];
    const char separator[] = " \n\t,.;:-?!()\"'";
    word_count *dict = init_dict(101); // arbitrary prime number for size
    
    // get input text
    printf("Enter text: ");
    fgets(text, MAX_STR_LEN, stdin);
    
    // tokenize input and add to dictionary
    char *token = strtok(text, separator);
    while(token != NULL) {
        insert(dict, token, 101);
        token = strtok(NULL, separator);
    }

    // print word count
    printf("\nWord Count\n");
    print_dict(dict, 101);

    // get count of specific word
    char word[MAX_STR_LEN];
    printf("\nEnter a word to get count: ");
    fgets(word, MAX_STR_LEN, stdin);
    word[strcspn(word, "\n")] = 0; // remove newline character from input
    printf("%s: %d", word, get_word_count(dict, word, 101));

    // free memory
    for(int i = 0; i < 101; i++) {
        free(dict[i].word);
    }
    free(dict);

    return 0;
}

word_count *init_dict(int size) {
    word_count *dict = (word_count *)malloc(size * sizeof(word_count));
    for(int i = 0; i < size; i++) {
        dict[i].word = NULL;
        dict[i].count = 0;
    }
    return dict;
}

unsigned long hasher(char *str) {
    unsigned long hash = 5381;
    int c;

    while((c = *str++) != '\0') {
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

void insert(word_count *dict, char *word, int size) {
    unsigned long hash = hasher(word);
    int index = hash % size;

    // check if word already exists in dictionary
    if(dict[index].word != NULL && strcmp(dict[index].word, word) == 0) {
        dict[index].count++;
    }
    // handle collisions using linear probing
    else {
        for(int i = 1; i < size; i++) {
            int new_index = (index + i) % size;
            if(dict[new_index].word == NULL) {
                dict[new_index].word = (char *)malloc((strlen(word) + 1) * sizeof(char));
                strcpy(dict[new_index].word, word);
                dict[new_index].count++;
                break;
            }
            else if(strcmp(dict[new_index].word, word) == 0) {
                dict[new_index].count++;
                break;
            }
        }
    }
}

void print_dict(word_count *dict, int size) {
    for(int i = 0; i < size; i++) {
        if(dict[i].word != NULL) {
            printf("%s: %d\n", dict[i].word, dict[i].count);
        }
    }
}

int get_word_count(word_count *dict, char *word, int size) {
    unsigned long hash = hasher(word);
    int index = hash % size;

    // check if word exists in dictionary
    if(dict[index].word != NULL && strcmp(dict[index].word, word) == 0) {
        return dict[index].count;
    }
    // handle collisions using linear probing
    else {
        for(int i = 1; i < size; i++) {
            int new_index = (index + i) % size;
            if(dict[new_index].word == NULL) {
                return 0;
            }
            else if(strcmp(dict[new_index].word, word) == 0) {
                return dict[new_index].count;
            }
        }
    }
    return 0;
}