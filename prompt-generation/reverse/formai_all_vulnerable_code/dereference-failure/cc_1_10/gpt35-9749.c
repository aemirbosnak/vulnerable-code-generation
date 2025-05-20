//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: multi-threaded
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

// Define the Morse code as a lookup table
char *morse[37] = {
    ".-",   // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--..", // Z
    "-----",    // 0
    ".----",    // 1
    "..---",    // 2
    "...--",    // 3
    "....-",    // 4
    ".....",    // 5
    "-....",    // 6
    "--...",    // 7
    "---..",    // 8
    "----.",    // 9
    "--..--",   // ,
    "/.",       // Space
};

// Mutex to avoid print collision between threads
pthread_mutex_t lock;

// Function to convert a character to its corresponding Morse code string
char *char_to_morse(char c)
{
    // Check if the character is a number or a letter
    if (c >= '0' && c <= '9')
    {
        return morse[c - '0' + 26];
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return morse[c - 'A'];
    }
    else if (c == ' ')
    {
        return morse[36];
    }
    else
    {
        return "";
    }
}

// Thread function to convert a string to Morse code
void *string_to_morse(void *arg)
{
    // Lock the mutex to avoid collision between threads
    pthread_mutex_lock(&lock);

    // Get the string to be converted from the argument
    char *string = (char *)arg;

    // Convert each character in the string to its corresponding Morse code string
    for (int i = 0; i < strlen(string); i++)
    {
        // Print the Morse code string for the current character
        printf("%s ", char_to_morse(string[i]));
        
        // Sleep for a short time to simulate a longer conversion process
        usleep(100000);
    }

    // Release the mutex lock when finished
    pthread_mutex_unlock(&lock);

    // Exit the thread
    pthread_exit(NULL);
}

// Main function
int main(int argc, char **argv)
{
    // Initialize the mutex lock
    pthread_mutex_init(&lock, NULL);

    // Get the input string from the command line arguments
    char *input_string = argv[1];

    // Calculate the length of the input string
    int input_length = strlen(input_string);

    // Initialize an array of threads for each character in the input string
    pthread_t threads[input_length];

    // Create a new thread for each character in the input string
    for (int i = 0; i < input_length; i++)
    {
        // Create the new thread and pass in the string containing only the current character
        pthread_create(&threads[i], NULL, string_to_morse, (void *)&input_string[i]);

        // Sleep for a short time to simulate a longer conversion process
        usleep(100000);
    }

    // Wait for all threads to finish before continuing
    for (int i = 0; i < input_length; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex lock
    pthread_mutex_destroy(&lock);

    // Exit the program
    return 0;
}