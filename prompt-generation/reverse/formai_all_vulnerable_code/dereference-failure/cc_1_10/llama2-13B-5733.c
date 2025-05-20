//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100
#define MIN_LENGTH 5

// Define a structure to hold a happy message
typedef struct {
    char *message;
    int length;
} happy_message_t;

// Function to generate a happy message
happy_message_t *generate_happy_message(void) {
    // Generate a random length between MIN_LENGTH and MAX_LENGTH
    int length = rand() % (MAX_LENGTH - MIN_LENGTH) + MIN_LENGTH;

    // Allocate memory for the message
    char *message = malloc(length * sizeof(char));

    // Fill the message with random words
    for (int i = 0; i < length; i++) {
        message[i] = rand() % 26 + 'a';
    }

    // Create a happy_message_t struct and return it
    happy_message_t *happy_msg = (happy_message_t *) malloc(sizeof(happy_message_t));
    happy_msg->message = message;
    happy_msg->length = length;
    return happy_msg;
}

// Function to print a happy message
void print_happy_message(happy_message_t *happy_msg) {
    printf("%s\n", happy_msg->message);
}

int main(void) {
    // Generate a happy message
    happy_message_t *happy_msg = generate_happy_message();

    // Print the happy message
    print_happy_message(happy_msg);

    // Free the memory allocated for the message
    free(happy_msg->message);
    free(happy_msg);

    return 0;
}