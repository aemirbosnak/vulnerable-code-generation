//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: paranoid
// **==============================================================================================================**
// **  Paranoid Typing Speed Test: I'm Watching You! **
// **  In this not-so-humble program, we will put your typing skills to the ultimate test! **
// **  Be warned: this is not for the faint of heart or those prone to paranoia. **
// **==============================================================================================================**

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

// **==============================================================================================================**
// **  Constant Definitions: Don't Try to Change These! **
// **==============================================================================================================**

#define MAX_TEST_TIME 60 // Maximum test time in seconds
#define MIN_WORD_LENGTH 4 // Minimum word length
#define MAX_WORD_LENGTH 20 // Maximum word length
#define MAX_WORDS_PER_TEST 100 // Maximum number of words per test
#define PARANOIA_LEVEL 11 // How paranoid are we? 0 is normal, 10 is extreme

// **==============================================================================================================**
// **  Data Structures: Keep Your Secrets Close! **
// **==============================================================================================================**

typedef struct {
    char *word;
    int length;
} word_t;

typedef struct {
    int num_words;
    word_t *words;
} word_list_t;

// **==============================================================================================================**
// **  Function Prototypes: Don't Trust Anyone! **
// **==============================================================================================================**

void *generate_word_list(void *args);
void *supervise_test(void *args);
void *grade_test(void *args);

// **==============================================================================================================**
// **  Global Variables: Don't Peek! **
// **==============================================================================================================**

static word_list_t word_list;
static int test_time = MAX_TEST_TIME;
static int num_correct_words = 0;
static int num_incorrect_words = 0;
static int num_keystrokes = 0;
static bool test_running = false;

// **==============================================================================================================**
// **  Main Function: Let the Paranoia Begin! **
// **==============================================================================================================**

int main(int argc, char *argv[]) {
    // Initialize the random number generator
    srand(time(NULL));

    // Create threads to generate the word list, supervise the test, and grade the test
    pthread_t word_list_thread, supervisor_thread, grader_thread;
    pthread_create(&word_list_thread, NULL, generate_word_list, NULL);
    pthread_create(&supervisor_thread, NULL, supervise_test, NULL);
    pthread_create(&grader_thread, NULL, grade_test, NULL);

    // Wait for all threads to finish
    pthread_join(word_list_thread, NULL);
    pthread_join(supervisor_thread, NULL);
    pthread_join(grader_thread, NULL);

    // Print the test results
    printf("Your typing speed: %d words per minute\n", (num_correct_words + num_incorrect_words) * 60 / test_time);
    printf("Number of correct words: %d\n", num_correct_words);
    printf("Number of incorrect words: %d\n", num_incorrect_words);
    printf("Number of keystrokes: %d\n", num_keystrokes);

    return 0;
}

// **==============================================================================================================**
// **  Function Definitions: Trust No One! **
// **==============================================================================================================**

// **  Generates a random word list **
void *generate_word_list(void *args) {
    // Create an array to store the words
    word_list.words = malloc(sizeof(word_t) * MAX_WORDS_PER_TEST);
    word_list.num_words = 0;

    // Generate random words
    for (int i = 0; i < MAX_WORDS_PER_TEST; i++) {
        // Determine the length of the word
        int length = MIN_WORD_LENGTH + rand() % (MAX_WORD_LENGTH - MIN_WORD_LENGTH + 1);

        // Generate the word
        word_list.words[i].word = malloc(sizeof(char) * (length + 1));
        for (int j = 0; j < length; j++) {
            word_list.words[i].word[j] = 'a' + rand() % 26;
        }
        word_list.words[i].word[length] = '\0';

        // Increment the number of words
        word_list.num_words++;
    }

    return NULL;
}

// **  Supervises the typing test **
void *supervise_test(void *args) {
    // Start the test timer
    time_t start_time = time(NULL);

    // Print the instructions
    printf("Instructions:\n");
    printf("1. Type the words as they appear on the screen.\n");
    printf("2. Press Enter after each word.\n");
    printf("3. You have %d seconds to complete the test.\n", test_time);

    // Start the test
    test_running = true;

    // Get the user's input
    char input[MAX_WORD_LENGTH + 1];
    while (test_running && time(NULL) - start_time < test_time) {
        scanf("%s", input);

        // Check if the user typed the correct word
        bool correct = false;
        for (int i = 0; i < word_list.num_words; i++) {
            if (strcmp(input, word_list.words[i].word) == 0) {
                // The user typed the correct word
                correct = true;

                // Increment the number of correct words
                num_correct_words++;

                // Increment the number of keystrokes
                num_keystrokes += word_list.words[i].length;

                break;
            }
        }

        // If the user typed the wrong word, increment the number of incorrect words
        if (!correct) {
            num_incorrect_words++;
        }
    }

    // Stop the test
    test_running = false;

    return NULL;
}

// **  Grades the typing test **
void *grade_test(void *args) {
    // Calculate the typing speed in words per minute
    int typing_speed = (num_correct_words + num_incorrect_words) * 60 / test_time;

    // Print the grade
    printf("Your grade: ");
    if (typing_speed >= 100) {
        printf("Excellent!\n");
    } else if (typing_speed >= 80) {
        printf("Good!\n");
    } else if (typing_speed >= 60) {
        printf("Fair!\n");
    } else {
        printf("Needs improvement!\n");
    }

    return NULL;
}