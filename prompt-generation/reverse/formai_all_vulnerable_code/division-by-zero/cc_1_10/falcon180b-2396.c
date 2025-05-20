//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

char words[MAX_WORD_LENGTH][MAX_WORDS];
int num_words;

void generate_words() {
    FILE *file;
    char ch;
    int i = 0;
    int word_len = 0;

    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            words[i][word_len++] = ch;
        } else if (word_len > 0) {
            words[i][word_len] = '\0';
            i++;
            word_len = 0;
        }
    }

    fclose(file);
    num_words = i;
}

int main() {
    int i, j;
    int correct_words = 0;
    int incorrect_words = 0;
    int total_words = 0;
    int wpm = 0;
    time_t start_time, end_time;
    
    srand(time(NULL));

    generate_words();

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will have 60 seconds to type as many words as possible.\n");
    printf("Press enter to begin.\n");
    getchar();

    time(&start_time);

    for (i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
        fflush(stdout);
        for (j = 0; j < strlen(words[i]); j++) {
            char ch = toupper(words[i][j]);
            if (ch == getchar()) {
                total_words++;
                if (j == strlen(words[i]) - 1) {
                    correct_words++;
                }
            } else {
                incorrect_words++;
                break;
            }
        }
    }

    time(&end_time);

    wpm = (total_words - incorrect_words) * 60 / (end_time - start_time);

    printf("\nTest complete!\n");
    printf("You typed %d correct words and %d incorrect words.\n", correct_words, incorrect_words);
    printf("Your typing speed is %d words per minute.\n", wpm);

    return 0;
}