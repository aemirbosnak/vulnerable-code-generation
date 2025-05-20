//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define WORDS_COUNT 10
#define WORD_LENGTH 30
#define BUFFER_SIZE 4096

const char *post_apocalyptic_words[WORDS_COUNT] = {
    "Scavenged through the ruins of a forgotten city.",
    "Survived another raid from the marauders.",
    "Gathered precious supplies from the remains of the old world.",
    "Maintained the shelter, protecting us from the harsh elements.",
    "Reclaimed the land, sowing the seeds of hope.",
    "Faced the mutated beasts, securing our food source.",
    "Constructed new tools from salvaged parts.",
    "Encountered a fellow survivor, forming an alliance.",
    "Defended against a horde of raiders, fortifying our position.",
    "Experienced the joy of rebuilding, one step at a time."
};

void print_random_word(const char **words, int words_count) {
    int random_index = rand() % words_count;
    printf("%s\n", words[random_index]);
}

int main() {
    srand(time(NULL));
    char input_buffer[BUFFER_SIZE];
    int words_typed = 0;
    double start_time, end_time, elapsed_time;

    printf("Welcome survivor, prepare for the typing test in this post-apocalyptic world.\n");

    start_time = time(NULL);

    while (words_typed < WORDS_COUNT) {
        print_random_word(post_apocalyptic_words, WORDS_COUNT);
        fgets(input_buffer, BUFFER_SIZE, stdin);
        input_buffer[strcspn(input_buffer, "\n")] = '\0';
        strcpy(input_buffer, strtok(input_buffer, " "));

        if (strcmp(input_buffer, post_apocalyptic_words[words_typed]) == 0) {
            words_typed++;
            printf("Correct: %d/%d\n", words_typed, WORDS_COUNT);
        } else {
            printf("Incorrect: %s, please try again.\n", input_buffer);
        }
        memset(input_buffer, 0, BUFFER_SIZE);
    }

    end_time = time(NULL);
    elapsed_time = end_time - start_time;

    printf("Congratulations survivor, you've completed the typing test in %.2f seconds!\n", elapsed_time);

    return 0;
}