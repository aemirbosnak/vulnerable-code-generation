//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 100
#define NUM_STRINGS 10

char *happy_strings[NUM_STRINGS] = {
    "Sunshine makes me happy",
    "Rainbows light up my day",
    "Butterflies dance in my heart",
    "Lollipops bring a smile to my face",
    "Roses have happy hues",
    "Daisies brighten up my world",
    "Snowflakes fill me with joy",
    "Unicorns sparkle in my imagination",
    "Raindrops sing a happy tune",
    "Marshmallows are pure delight"
};

void print_string(char *str) {
    printf("%s\n", str);
}

int main() {
    int i, j, score = 0, total_chars = 0, wpm;
    clock_t start_time, end_time;
    char user_input[MAX_LENGTH];

    printf("*************************************************\n");
    printf("* Welcome to the Happy C Typing Speed Test!      *\n");
    printf("* Type the following happy strings as fast as  *\n");
    printf("* you can and press enter after each one.       *\n");
    printf("* Your typing speed will be calculated at the  *\n");
    printf("* end of the test.                             *\n");
    printf("*************************************************\n");

    start_time = clock();

    for (i = 0; i < NUM_STRINGS; i++) {
        printf("\n%s: ", happy_strings[i]);
        fgets(user_input, sizeof(user_input), stdin);
        strncpy(user_input, strtok(user_input, "\n"), sizeof(user_input) - 1);
        total_chars += strlen(happy_strings[i]);

        if (strcasecmp(happy_strings[i], user_input) == 0) {
            score += strlen(happy_strings[i]);
            print_string("Correct!");
        } else {
            print_string("Incorrect. The correct answer was: ");
            print_string(happy_strings[i]);
        }
    }

    end_time = clock();
    wpm = (score * 60) / (end_time - start_time);

    printf("\n\nCongratulations! You completed the test.\n");
    printf("Your typing speed is %d words per minute.\n", wpm);
    printf("Total characters typed: %d\n", total_chars);

    return 0;
}