//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CHARS 1024
#define NUM_WORDS 20
#define NUM_LINES 5
#define TIMEOUT 60

pthread_mutex_t lock;
pthread_cond_t cond;

char* words[NUM_WORDS] = {"hello", "world", "programming", "type", "speed", "test", "happiness", "love", "freedom", "success", "future", "technology", "innovation", "dream", "play", "learn", "joy", "peace", "kindness", "smile"};

char* lines[NUM_LINES] = {
    "The quick brown fox jumps over the lazy dog.",
    "Jackdaws love my big sphinx of quartz.",
    "How vexingly quick daft zebras jump!",
    "Pack my box with five dozen liquor jugs.",
    "My ex pub quiz crowd gave joyful thanks."
};

int score = 0;
char typed[MAX_CHARS];
int curr_line = 0;
int curr_word = 0;
int chars_typed = 0;
int word_count = 0;
int time_elapsed = 0;

void init() {
    srand(time(NULL));
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);
}

void cleanup() {
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);
}

void print_score() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Your typing speed test score:\n");
    printf("Time elapsed: %ds\n", time_elapsed);
    printf("Words per minute: %d\n", score);
}

void* timer_thread(void* arg) {
    for (;time_elapsed<TIMEOUT;time_elapsed++) {
        sleep(1);
        if (time_elapsed == TIMEOUT) {
            pthread_cond_signal(&cond);
        }
    }
    return NULL;
}

void* input_thread(void* arg) {
    struct termios old_t;
    struct termios new_t;
    tcgetattr(STDIN_FILENO, &old_t);
    new_t = old_t;
    new_t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_t);

    while(time_elapsed < TIMEOUT) {
        char c = getchar();
        if (c >= 32 && c <= 126 && chars_typed < MAX_CHARS-1) {
            typed[chars_typed++] = c;
            if (c == ' ') {
                char* curr_word_str = words[curr_word];
                int curr_word_len = strlen(curr_word_str);
                if (strncmp(typed+(chars_typed-curr_word_len-1), curr_word_str, curr_word_len) == 0) {
                    word_count++;
                    curr_word = rand() % NUM_WORDS;
                    curr_line = rand() % NUM_LINES;
                    chars_typed = 0;
                }
            }
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &old_t);
    pthread_cond_signal(&cond);
    return NULL;
}

void print_line(char* line) {
    printf("%s", line);
    fflush(stdout);
    pthread_mutex_unlock(&lock);
}

void typing_test() {
    pthread_t timer, input;
    pthread_create(&timer, NULL, &timer_thread, NULL);
    pthread_create(&input, NULL, &input_thread, NULL);

    curr_word = rand() % NUM_WORDS;
    curr_line = rand() % NUM_LINES;

    while (time_elapsed < TIMEOUT) {
        pthread_mutex_lock(&lock);
        print_line(lines[curr_line]);
        pthread_cond_wait(&cond, &lock);
        print_score();
    }

    pthread_join(timer, NULL);
    pthread_join(input, NULL);
}

int main() {
    init();
    typing_test();
    cleanup();
    return 0;
}