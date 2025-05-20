//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pthread.h>

typedef struct {
    char *sentence;
    int length;
} Sentence;

typedef struct {
    Sentence *sentences;
    int num_sentences;
} Sentences;

typedef struct {
    Sentences *sentences;
    int num_sentences;
    int current_sentence;
    int current_character;
    int errors;
    int correct;
    int wpm;
    int time_elapsed;
} Test;

Sentences *generate_sentences(int num_sentences) {
    Sentences *sentences = malloc(sizeof(Sentences));
    sentences->sentences = malloc(sizeof(Sentence) * num_sentences);
    sentences->num_sentences = num_sentences;

    for (int i = 0; i < num_sentences; i++) {
        int length = rand() % 100 + 1;
        char *sentence = malloc(sizeof(char) * (length + 1));
        for (int j = 0; j < length; j++) {
            sentence[j] = 'a' + rand() % 26;
        }
        sentence[length] = '\0';
        sentences->sentences[i].sentence = sentence;
        sentences->sentences[i].length = length;
    }

    return sentences;
}

Test *create_test(Sentences *sentences) {
    Test *test = malloc(sizeof(Test));
    test->sentences = sentences;
    test->num_sentences = sentences->num_sentences;
    test->current_sentence = 0;
    test->current_character = 0;
    test->errors = 0;
    test->correct = 0;
    test->wpm = 0;
    test->time_elapsed = 0;

    return test;
}

void *typing_loop(void *arg) {
    Test *test = (Test *)arg;

    while (test->current_sentence < test->num_sentences) {
        Sentence sentence = test->sentences->sentences[test->current_sentence];

        char input[sentence.length + 1];
        fgets(input, sentence.length + 1, stdin);

        if (strcmp(input, sentence.sentence) == 0) {
            test->correct++;
        } else {
            test->errors++;
        }

        test->current_sentence++;
        test->current_character = 0;
    }

    return NULL;
}

void *timer_loop(void *arg) {
    Test *test = (Test *)arg;

    time_t start_time = time(NULL);

    while (test->current_sentence < test->num_sentences) {
        time_t current_time = time(NULL);
        test->time_elapsed = current_time - start_time;
    }

    return NULL;
}

void calculate_wpm(Test *test) {
    test->wpm = (test->correct * 60) / test->time_elapsed;
}

void print_results(Test *test) {
    printf("Words per minute: %d\n", test->wpm);
    printf("Errors: %d\n", test->errors);
    printf("Correct: %d\n", test->correct);
}

int main() {
    srand(time(NULL));

    Sentences *sentences = generate_sentences(100);
    Test *test = create_test(sentences);

    pthread_t typing_thread, timer_thread;

    pthread_create(&typing_thread, NULL, typing_loop, test);
    pthread_create(&timer_thread, NULL, timer_loop, test);

    pthread_join(typing_thread, NULL);
    pthread_join(timer_thread, NULL);

    calculate_wpm(test);
    print_results(test);

    for (int i = 0; i < sentences->num_sentences; i++) {
        free(sentences->sentences[i].sentence);
    }
    free(sentences->sentences);
    free(sentences);
    free(test);

    return 0;
}