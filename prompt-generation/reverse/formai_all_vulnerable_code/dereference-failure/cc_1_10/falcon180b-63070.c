//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int max_chars = 200;
    int num_words = 10;
    char *words[num_words];
    int word_lengths[num_words];
    int total_chars = 0;
    int i;
    double avg_speed;
    double start_time, end_time;

    srand(time(NULL));
    for(i = 0; i < num_words; i++) {
        int length = rand() % max_chars + 5;
        char *word = (char*)malloc(length * sizeof(char));
        int j;
        for(j = 0; j < length; j++) {
            word[j] = rand() % 26 + 'a';
        }
        word[length - 1] = '\0';
        words[i] = word;
        word_lengths[i] = length;
        total_chars += length;
    }

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be typing %d words with a total of %d characters.\n\n", num_words, total_chars);

    start_time = clock();
    for(i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
        fflush(stdout);
        if(i == num_words - 1) {
            printf("\n\nPress Enter to finish...");
        }
    }
    fflush(stdout);
    getchar();

    end_time = clock();
    avg_speed = (double)CLOCKS_PER_SEC / (double)(end_time - start_time);

    printf("\n\nYou finished in %.2f seconds.\n", avg_speed);
    printf("Your average typing speed is %.2f characters per second.\n", avg_speed * total_chars / (double)num_words);

    for(i = 0; i < num_words; i++) {
        free(words[i]);
    }

    return 0;
}