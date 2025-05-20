//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word {
    char text[MAX_WORD_LENGTH];
    int length;
};

void init_words(struct word *words) {
    FILE *f = fopen("words.txt", "r");
    char line[MAX_WORD_LENGTH];
    int count = 0;

    while (fgets(line, MAX_WORD_LENGTH, f)!= NULL) {
        strcpy(words[count].text, line);
        words[count].length = strlen(line);
        count++;
    }

    fclose(f);
}

int main() {
    struct word words[MAX_WORDS];
    int num_words = 0;
    int index = 0;
    int correct_words = 0;
    int incorrect_words = 0;
    double speed = 0;
    double accuracy = 0;
    char input[MAX_WORD_LENGTH];
    int len;
    int i;

    init_words(words);
    num_words = count_words(words);

    srand(time(NULL));
    for (i = 0; i < num_words; i++) {
        index = rand() % num_words;
        printf("%s\n", words[index].text);
        fflush(stdout);
        fgets(input, MAX_WORD_LENGTH, stdin);
        len = strlen(input);
        if (len == words[index].length && strcmp(input, words[index].text) == 0) {
            correct_words++;
        } else {
            incorrect_words++;
        }
    }

    speed = (double)count_chars(words) / (5.0 * num_words);
    accuracy = (double)correct_words / num_words;

    printf("You typed %d words, %d of which were correct.\n", num_words, correct_words);
    printf("Your speed was %.2f WPM and your accuracy was %.2f%%\n", speed, accuracy * 100);

    return 0;
}

int count_words(struct word *words) {
    int count = 0;
    while (words[count].text[0]!= '\0') {
        count++;
    }
    return count;
}

int count_chars(struct word *words) {
    int count = 0;
    int i;
    for (i = 0; i < count_words(words); i++) {
        count += words[i].length;
    }
    return count;
}