//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char input[100];
    int correct = 0, incorrect = 0, total = 0;
    int start_time, end_time;
    double elapsed_time;
    int speed = 0;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Please start typing when you are ready.\n");

    srand(time(NULL));
    int rand_string_length = rand() % 20 + 5; // generate a random string length between 5 and 24
    char *rand_string = malloc(rand_string_length * sizeof(char));
    for (int i = 0; i < rand_string_length; i++) {
        rand_string[i] = rand() % 26 + 'a'; // generate a random string containing only lowercase letters
    }
    printf("Type the following string:\n%s\n", rand_string);

    // start timer
    start_time = clock();

    // get user input
    while (scanf("%s", input)!= EOF) {
        total++;
        if (strcmp(input, rand_string) == 0) {
            correct++;
        } else {
            incorrect++;
        }
    }

    // stop timer
    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // calculate speed
    if (elapsed_time > 0) {
        speed = total / elapsed_time;
    }

    printf("Results:\n");
    printf("Total characters typed: %d\n", total);
    printf("Correct characters typed: %d\n", correct);
    printf("Incorrect characters typed: %d\n", incorrect);
    printf("Typing speed: %d characters per second\n", speed);

    return 0;
}