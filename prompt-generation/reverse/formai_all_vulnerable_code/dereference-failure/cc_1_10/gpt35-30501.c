//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_MESSAGE_LENGTH 100 // Maximum length of the input message
#define MAX_MORSE_LENGTH 400 // Maximum length of the output string

// Morse code lookup table
const char* MorseCodeTable[] =
{
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
    "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..",
    "----.", "-----"
};

// Global variables
char* InputMessage; // Input message
char* OutputMorseCode; // Morse code equivalent of the input message
int DoneProcessing = 0; // Flag to indicate if the processing is done

// Function declarations
void* TextToMorseCode(void* thread_arg);
void* PrintMorseCode(void* thread_arg);

int main(int argc, char* argv[])
{
    // Allocate memory for input and output strings
    InputMessage = (char*)malloc(MAX_MESSAGE_LENGTH * sizeof(char));
    OutputMorseCode = (char*)malloc(MAX_MORSE_LENGTH * sizeof(char));

    // Read input message from user
    printf("Enter the message to convert to Morse code: ");
    fgets(InputMessage, MAX_MESSAGE_LENGTH, stdin);
    InputMessage[strcspn(InputMessage, "\n")] = 0; // Remove newline character

    // Initialize the threads
    pthread_t tid[2];
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    // Create the threads
    pthread_create(&tid[0], &attr, TextToMorseCode, NULL);
    pthread_create(&tid[1], &attr, PrintMorseCode, NULL);

    // Wait for the threads to finish
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    // Free memory
    free(InputMessage);
    free(OutputMorseCode);

    return 0;
}

// Function to convert the input message to Morse code
void* TextToMorseCode(void* thread_arg)
{
    // Iterate over each character in the input message
    for (int i = 0; i < strlen(InputMessage); i++)
    {
        char ch = toupper(InputMessage[i]); // Convert to upper case
        int index;

        // Determine the Morse code index of the character
        if (ch >= 'A' && ch <= 'Z')
        {
            index = ch - 'A';
        }
        else if (ch >= '0' && ch <= '9')
        {
            index = ch - '0' + 26;
        }
        else
        {
            continue; // Ignore non-alphanumeric characters
        }

        // Add the Morse code equivalent of the character to the output string
        strcat(OutputMorseCode, MorseCodeTable[index]);
        strcat(OutputMorseCode, " ");
    }

    DoneProcessing = 1;

    pthread_exit(NULL);
}

// Function to print the Morse code
void* PrintMorseCode(void* thread_arg)
{
    // Wait for the processing to finish
    while (!DoneProcessing)
    {
        usleep(100); // Sleep for 100 microseconds
    }

    // Print the Morse code
    printf("Morse code equivalent: %s\n", OutputMorseCode);

    pthread_exit(NULL);
}