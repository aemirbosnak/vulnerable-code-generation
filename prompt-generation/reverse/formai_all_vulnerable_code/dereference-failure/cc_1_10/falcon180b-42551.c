//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char input[100];
    int correct = 0;
    int incorrect = 0;
    int total = 0;
    int count = 0;
    int score = 0;
    int wpm = 0;
    time_t start, end;
    double elapsed;

    srand(time(NULL));
    int length = rand() % 10 + 1;
    char *text = (char *)malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        text[i] = rand() % 26 + 'a';
    }
    printf("You will be typing the following:\n%s\n", text);

    time(&start);
    while (1) {
        printf("Enter your input: ");
        fgets(input, sizeof(input), stdin);
        if (strlen(input) == length) {
            if (strcmp(input, text) == 0) {
                correct++;
            } else {
                incorrect++;
            }
            total++;
            count++;
        }

        if (count == 10) {
            break;
        }
    }

    time(&end);
    elapsed = difftime(end, start);

    score = (int)round(60 / elapsed);
    wpm = (int)round(score * total / 5);

    printf("Your final score is %d WPM\n", wpm);

    free(text);
    return 0;
}