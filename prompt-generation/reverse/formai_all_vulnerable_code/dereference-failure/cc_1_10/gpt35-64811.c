//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Declare and initialize semaphore
#include <semaphore.h>

sem_t sem;

// Define an enum to represent each alien character
enum AlienChar {
    BLART,
    FLIP,
    TACK,
    TORK,
    ZOOP,
};

// Define a struct to represent an alien word
struct AlienWord {
    enum AlienChar *chars;
    int length;
};

// Define an array of strings to hold translations
char *translations[] = {
    "Hello",
    "Greetings",
    "Goodbye",
    "Farewell",
    "Thank you",
};

// Define a function to translate an AlienWord
char *translate(struct AlienWord *word) {
    int i;
    char *result = malloc((word->length + 1) * sizeof(char));

    // Convert each alien character to a letter in the translation
    for (i = 0; i < word->length; i++) {
        switch (word->chars[i]) {
            case BLART:
                strcat(result, "H");
                break;
            case FLIP:
                strcat(result, "E");
                break;
            case TACK:
                strcat(result, "L");
                break;
            case TORK:
                strcat(result, "O");
                break;
            case ZOOP:
                strcat(result, " ");
                break;
            default:
                break;
        }
    }

    return result;
}

// Define a function to generate a random AlienWord
struct AlienWord *generateWord() {
    int i, length = rand() % 10 + 1;
    struct AlienWord *word = malloc(sizeof(struct AlienWord));
    word->chars = malloc(length * sizeof(enum AlienChar));
    word->length = length;

    // Generate random characters for the word
    for (i = 0; i < length; i++) {
        word->chars[i] = rand() % 5;
    }

    return word;
}

// Define the translator function
void translator() {
    while (1) {
        // Wait for a word to be available
        sem_wait(&sem);

        // Generate a random delay up to 1 second
        int delay = rand() % 1000000;
        usleep(delay);

        // Translate the word and print the result
        struct AlienWord *word = generateWord();
        char *translation = translate(word);
        printf("%s: %s\n", translation, translations[rand() % 5]);

        // Free memory allocated for the word and translation
        free(word->chars);
        free(word);
        free(translation);
    }
}

// Define the main function
int main() {
    // Initialize the semaphore
    sem_init(&sem, 0, 0);

    // Create a new process to run the translator
    if (fork() == 0) {
        translator();
    }

    // Read input from the user and signal the semaphore
    char input[100];
    while (1) {
        printf("Enter an alien word: ");
        fgets(input, sizeof(input), stdin);

        // Parse the input and create a new AlienWord struct
        struct AlienWord *word = malloc(sizeof(struct AlienWord));
        int i = 0;
        char *token = strtok(input, " ");
        while (token != NULL) {
            enum AlienChar character;
            switch (token[0]) {
                case 'B':
                    character = BLART;
                    break;
                case 'F':
                    character = FLIP;
                    break;
                case 'T':
                    character = TACK;
                    break;
                case 'O':
                    character = TORK;
                    break;
                case 'Z':
                    character = ZOOP;
                    break;
                default:
                    printf("Invalid character \"%c\"\n", token[0]);
                    break;
            }
            word->chars[i] = character;
            i++;
            token = strtok(NULL, " ");
        }
        word->length = i;

        // Signal the semaphore to indicate that a word is available
        sem_post(&sem);

        // Free memory allocated for the AlienWord
        free(word->chars);
        free(word);
    }

    // Destroy the semaphore
    sem_destroy(&sem);

    return 0;
}