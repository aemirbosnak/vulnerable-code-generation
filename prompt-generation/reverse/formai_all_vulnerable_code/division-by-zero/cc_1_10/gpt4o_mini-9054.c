//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEXT_LENGTH 512
#define TIME_LIMIT 60

void display_instructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a passage to type.\n");
    printf("The test lasts for %d seconds.\n", TIME_LIMIT);
    printf("Try to make it with the fewest errors possible!\n\n");
}

void get_random_text(char *text) {
    const char *sample_texts[] = {
        "The quick brown fox jumps over the lazy dog.",
        "To be or not to be, that is the question.",
        "All that glitters is not gold.",
        "In the middle of difficulty lies opportunity.",
        "A journey of a thousand miles begins with a single step.",
        "It does not matter how slowly you go as long as you do not stop."
    };

    srand(time(NULL));
    int random_index = rand() % (sizeof(sample_texts) / sizeof(sample_texts[0]));
    strcpy(text, sample_texts[random_index]);
}

void countdown(int seconds) {
    printf("Starting in:\n");
    for (int i = seconds; i > 0; i--) {
        printf("%d...\n", i);
        sleep(1);
    }
    printf("Go!\n");
}

int calculate_speed(int characters_typed, int seconds_elapsed) {
    return (characters_typed / 5) * 60 / seconds_elapsed; // WPM calculation
}

int main() {
    char text[MAX_TEXT_LENGTH];
    char user_input[MAX_TEXT_LENGTH];
    int characters_typed = 0;
    time_t start_time, end_time;

    display_instructions();
    get_random_text(text);

    printf("Type the following text:\n\n");
    printf("\"%s\"\n\n", text);
    
    countdown(5);

    start_time = time(NULL);

    printf("Start typing now:\n");
    fgets(user_input, MAX_TEXT_LENGTH, stdin);

    end_time = time(NULL);
    int seconds_elapsed = difftime(end_time, start_time);
    if(seconds_elapsed > TIME_LIMIT) {
        printf("Time's up! You exceeded the time limit of %d seconds.\n", TIME_LIMIT);
    } else {
        characters_typed = strlen(user_input);
        if (strcmp(user_input, text) == 0) {
            printf("Perfect match! You typed it accurately.\n");
        } else {
            printf("There were some errors in what you typed.\n");
        }
    }

    int typing_speed = calculate_speed(characters_typed, seconds_elapsed);
    printf("Typing speed: %d words per minute.\n", typing_speed);
    
    return 0;
}