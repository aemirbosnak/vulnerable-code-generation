//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_WORD_LEN 50
#define MAX_TIME 60

struct word {
    char str[MAX_WORD_LEN];
    int len;
};

struct word words[MAX_WORDS];
int num_words;

void add_word(char* str) {
    if (num_words >= MAX_WORDS) {
        printf("Error: max number of words reached\n");
        exit(1);
    }
    strncpy(words[num_words].str, str, MAX_WORD_LEN);
    words[num_words].len = strlen(str);
    num_words++;
}

int main() {
    srand(time(NULL));
    int i;
    for (i = 0; i < num_words; i++) {
        int j;
        for (j = 0; j < words[i].len; j++) {
            printf("*");
        }
        printf("\n");
    }
    int score = 0;
    int time_left = MAX_TIME;
    char input[MAX_WORD_LEN];
    while (time_left > 0) {
        int len = rand() % MAX_WORD_LEN + 1;
        int word_index = rand() % num_words;
        strncpy(input, words[word_index].str, MAX_WORD_LEN);
        input[len] = '\0';
        printf("Type the following word within %d seconds: %s\n", time_left, input);
        fgets(input, MAX_WORD_LEN, stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, words[word_index].str) == 0) {
            score++;
        }
        time_left--;
    }
    printf("Your score is %d out of %d\n", score, num_words);
    return 0;
}