//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 20

typedef struct {
    char *words[MAX_WORDS];
    int num_words;
} Sentence;

Sentence generate_sentence(int num_words) {
    Sentence result = {0};
    char *words[MAX_WORDS] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    int i;

    srand(time(NULL));
    for (i = 0; i < num_words; i++) {
        result.words[i] = words[rand() % 9];
    }
    result.num_words = num_words;

    return result;
}

void print_sentence(Sentence sentence) {
    int i;

    for (i = 0; i < sentence.num_words; i++) {
        printf("%s ", sentence.words[i]);
    }
    printf("\n");
}

int main() {
    int num_sentences, sentence_length;

    printf("Enter the number of sentences to generate: ");
    scanf("%d", &num_sentences);

    printf("Enter the maximum sentence length: ");
    scanf("%d", &sentence_length);

    int i;
    for (i = 0; i < num_sentences; i++) {
        Sentence sentence = generate_sentence(rand() % (sentence_length + 1));
        print_sentence(sentence);
    }

    return 0;
}