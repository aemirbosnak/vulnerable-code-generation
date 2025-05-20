//Falcon2-11B DATASET v1.0 Category: Typing Speed Test ; Style: shape shifting
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_WORD_LEN 100
#define MAX_TEST_LEN 1000

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <test length in words>\n", argv[0]);
        return 1;
    }

    int test_len = atoi(argv[1]);
    int words_typed = 0;
    int total_time = 0;

    char *words[MAX_TEST_LEN];
    char *word_list[MAX_TEST_LEN];

    srand(time(NULL));
    for (int i = 0; i < test_len; i++) {
        words_typed++;
        int word_len = rand() % MAX_WORD_LEN;
        words[i] = (char *) malloc(word_len + 1);
        strcpy(words[i], "This is a random word of length ");
        for (int j = 0; j < word_len; j++) {
            words[i][j] = 'a' + (rand() % 26);
        }
        words[i][word_len] = '\0';
        word_list[i] = strdup(words[i]);
    }

    for (int i = 0; i < test_len; i++) {
        printf("%s\n", words[i]);
        fflush(stdout);

        clock_t start = clock();
        char typed[MAX_WORD_LEN + 1];
        gets(typed);

        clock_t end = clock();
        total_time += end - start;
        total_time /= CLOCKS_PER_SEC;

        if (strcmp(typed, words[i]) == 0) {
            words_typed++;
        }
    }

    printf("Total words typed: %d\n", words_typed);
    printf("Average typing speed (words per second): %.2f\n", words_typed / total_time);

    for (int i = 0; i < test_len; i++) {
        free(word_list[i]);
    }

    return 0;
}