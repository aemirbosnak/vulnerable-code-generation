//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MIN_WORD_LENGTH 5
#define MAX_WORD_LENGTH 15
#define MAX_SPEED 200

char *words[MAX_WORDS];
int num_words;
int word_lengths[MAX_WORDS];

int main() {
    srand(time(NULL));

    // Load words into array
    num_words = 0;
    FILE *fp = fopen("words.txt", "r");
    char line[100];
    while (fgets(line, 100, fp)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            if (strlen(word) >= MIN_WORD_LENGTH && strlen(word) <= MAX_WORD_LENGTH) {
                words[num_words] = strdup(word);
                word_lengths[num_words] = strlen(word);
                num_words++;
            }
            word = strtok(NULL, " ");
        }
    }
    fclose(fp);

    // Shuffle words
    for (int i = 0; i < num_words; i++) {
        int j = rand() % num_words;
        char *temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }

    // Test typing speed
    int correct = 0;
    int incorrect = 0;
    int speed = 0;
    int start_time = time(NULL);
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
        fflush(stdout);
        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, words[i]) == 0) {
            correct++;
        } else {
            incorrect++;
        }
        speed += strlen(input);
        if (difftime(time(NULL), start_time) > 60) {
            break;
        }
    }
    speed /= difftime(time(NULL), start_time);

    // Print results
    printf("\nResults:\n");
    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);
    printf("Speed: %d WPM\n", speed);

    return 0;
}