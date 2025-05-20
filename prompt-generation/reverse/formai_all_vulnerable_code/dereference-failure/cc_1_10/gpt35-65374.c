//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WORDS "hello world, this is a typing speed test program designed by a chatbot to test your typing speed and accuracy!"

int main() {
    int i, count = 0, correct = 0;
    float time_taken;
    char input[10000], **words, c;

    // allocate memory for words array
    words = malloc(sizeof(char*) * 100);
    for(i = 0; i < 100; i++) {
        words[i] = malloc(sizeof(char) * 50);
    }

    // copy words to words array
    i = 0;
    char* token = strtok(WORDS, " ");
    while(token) {
        strcpy(words[i++], token);
        token = strtok(NULL, " ");
    }

    printf("*** Welcome to the Typing Speed Test! ***\n\n");
    printf("Type the following text as fast as you can and press enter:\n\n");

    // print words
    for(i = 0; i < 20; i++) {
        printf("%s ", words[i]);
    }
    printf("\n\n");

    // start timer
    clock_t start = clock();

    // read user input
    i = 0;
    while((c = getchar()) != '\n') {
        if(c == ' ') {
            count++;
            if(strcmp(input, words[i]) == 0) {
                correct++;
            }
            i++;
            strcpy(input, "");
        } else {
            strncat(input, &c, 1);
        }
    }

    // stop timer
    clock_t end = clock();

    // calculate time taken
    time_taken = (float)(end - start) / CLOCKS_PER_SEC;

    // print results
    printf("\n\nYou typed %d words in %.2f seconds.\n", count, time_taken);
    printf("Your typing speed is %.2f words per minute.\n", (float)count / time_taken * 60);
    printf("Your accuracy is %.2f%%.\n", (float)correct / count * 100);

    // free memory
    for(i = 0; i < 100; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}