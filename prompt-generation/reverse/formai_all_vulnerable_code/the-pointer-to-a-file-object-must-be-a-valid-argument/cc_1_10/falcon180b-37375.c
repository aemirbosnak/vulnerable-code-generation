//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 50
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

Word words[MAX_WORDS];
int num_words;

void load_words(const char* filename) {
    FILE* file = fopen(filename, "r");
    char line[MAX_WORD_LENGTH];
    int i = 0;
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words in file.\n");
            exit(1);
        }
        words[i].length = strlen(line);
        strcpy(words[i].word, line);
        i++;
    }
    num_words = i;
    fclose(file);
}

int main() {
    char input[MAX_WORD_LENGTH];
    int correct = 0, incorrect = 0, total = 0;
    int start_time, end_time;
    double elapsed;

    srand(time(NULL));
    for (int i = 0; i < num_words; i++) {
        int len = rand() % words[i].length + 1;
        strncpy(input, words[i].word, len);
        input[len] = '\0';
    }

    load_words("words.txt");

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given %d words to type.\n", num_words);
    printf("Press ENTER to begin...\n");
    getchar();

    start_time = clock();
    for (int i = 0; i < num_words; i++) {
        printf("%s\n", words[i].word);
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, words[i].word) == 0) {
            correct++;
        } else {
            incorrect++;
        }
        total++;
    }
    end_time = clock();
    elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nTest complete!\n");
    printf("You typed %d words correctly.\n", correct);
    printf("You typed %d words incorrectly.\n", incorrect);
    printf("Your typing speed is %.2f words per minute.\n", (double)total / elapsed);

    return 0;
}