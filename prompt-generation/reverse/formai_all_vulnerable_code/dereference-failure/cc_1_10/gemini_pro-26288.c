//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct word {
    char *str;
    int len;
};

struct test {
    struct word *words;
    int num_words;
    int start_time;
    int end_time;
};

struct word *generate_words(int num_words) {
    struct word *words = malloc(num_words * sizeof(struct word));
    for (int i = 0; i < num_words; i++) {
        int len = rand() % 10 + 1;
        char *str = malloc(len + 1);
        for (int j = 0; j < len; j++) {
            str[j] = 'a' + rand() % 26;
        }
        str[len] = '\0';
        words[i] = (struct word){.str = str, .len = len};
    }
    return words;
}

struct test *create_test(int num_words) {
    struct test *test = malloc(sizeof(struct test));
    test->words = generate_words(num_words);
    test->num_words = num_words;
    test->start_time = time(NULL);
    test->end_time = 0;
    return test;
}

void destroy_test(struct test *test) {
    for (int i = 0; i < test->num_words; i++) {
        free(test->words[i].str);
    }
    free(test->words);
    free(test);
}

void start_test(struct test *test) {
    test->start_time = time(NULL);
}

void end_test(struct test *test) {
    test->end_time = time(NULL);
}

int calculate_wpm(struct test *test) {
    int num_words = test->num_words;
    int time_seconds = test->end_time - test->start_time;
    int wpm = num_words / time_seconds * 60;
    return wpm;
}

void print_results(struct test *test) {
    int wpm = calculate_wpm(test);
    printf("Words per minute: %d\n", wpm);
}

int main() {
    int num_words = 100;
    struct test *test = create_test(num_words);
    start_test(test);
    // Type the words here
    end_test(test);
    print_results(test);
    destroy_test(test);
    return 0;
}