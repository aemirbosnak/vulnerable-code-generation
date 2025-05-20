//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: invasive
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_frequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int compare_words(const void* a, const void* b) {
    struct word_frequency* word1 = (struct word_frequency*)a;
    struct word_frequency* word2 = (struct word_frequency*)b;

    return strcmp(word1->word, word2->word);
}

void count_words(char* text, struct word_frequency* words, int num_words) {
    char* token;
    char* word = strtok_r(text, " \t\r\n\f\v", &token);

    while(word!= NULL) {
        int i;
        for(i=0; i<num_words; i++) {
            if(strcmp(word, words[i].word) == 0) {
                words[i].frequency++;
                break;
            }
        }

        if(i == num_words) {
            if(num_words >= MAX_WORDS) {
                printf("Error: Maximum number of words reached.\n");
                exit(1);
            }

            strncpy(words[num_words].word, word, MAX_WORD_LENGTH-1);
            words[num_words].word[MAX_WORD_LENGTH-1] = '\0';
            words[num_words].frequency = 1;
            num_words++;
        }

        word = strtok_r(NULL, " \t\r\n\f\v", &token);
    }
}

void print_word_frequencies(struct word_frequency* words, int num_words) {
    qsort(words, num_words, sizeof(struct word_frequency), compare_words);

    printf("Word\tFrequency\n");
    for(int i=0; i<num_words; i++) {
        printf("%s\t%d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    char text[100000];
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    int num_words = 0;
    struct word_frequency words[MAX_WORDS];

    count_words(text, words, num_words);

    printf("Word frequencies:\n");
    print_word_frequencies(words, num_words);

    return 0;
}