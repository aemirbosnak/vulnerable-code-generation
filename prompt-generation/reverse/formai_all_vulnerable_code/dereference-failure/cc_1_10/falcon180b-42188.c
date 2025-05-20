//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word {
    char *word;
    int length;
};

void generate_words(struct word *words, int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        words[i].word = malloc(MAX_WORD_LENGTH * sizeof(char));
        words[i].length = rand() % MAX_WORD_LENGTH + 1;
        int j;
        for (j = 0; j < words[i].length; j++) {
            words[i].word[j] = rand() % 26 + 'a';
        }
        words[i].word[words[i].length] = '\0';
    }
}

int main() {
    srand(time(NULL));
    int num_words;
    printf("Enter the number of words: ");
    scanf("%d", &num_words);
    if (num_words > MAX_WORDS) {
        printf("Error: Number of words is too large.\n");
        return 1;
    }
    struct word words[num_words];
    generate_words(words, num_words);
    int score = 0;
    int i;
    for (i = 0; i < num_words; i++) {
        printf("Word %d: %s\n", i+1, words[i].word);
        int j;
        for (j = 0; j < words[i].length; j++) {
            char ch = getchar();
            if (ch!= words[i].word[j]) {
                score--;
                break;
            }
        }
    }
    printf("Your score is: %d\n", score);
    return 0;
}