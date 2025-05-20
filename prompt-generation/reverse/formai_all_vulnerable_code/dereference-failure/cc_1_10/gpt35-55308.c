//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

// Morse code struct
typedef struct morse_code {
  char letter;
  char *code;
} morse_code;

// Array of Morse code mappings
morse_code m_codes[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
    {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
    {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
    {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."}, {'0', "-----"}, {'1', ".----"},
    {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."},
    {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},
};

// Function to convert letter to Morse code
char *letter_to_morse(char letter) {
  for(int i = 0; i < sizeof(m_codes)/sizeof(morse_code); i++) {
      if (toupper(m_codes[i].letter) == toupper(letter)) {
          return m_codes[i].code;
      }
  }
  return "";
}

// Thread function for converting text to Morse code
void *text_to_morse(void *input) {
    char *text = (char*) input;
    char *result = malloc(strlen(text) * 5 + 1); // Allocate some space for the result
    
    // Loop through each character in the input and convert to Morse code
    for (int i = 0; i < strlen(text); i++) {
        char letter = text[i];
        if (isspace(letter)) {
            strcat(result, "| "); // Add a space between words
        } else {
            char *morse = letter_to_morse(letter);
            if (strlen(morse) > 0) {
                strcat(result, morse); // Add Morse code equivalent
                strcat(result, " "); // Add a space between letters
            }
        }
    }
    
    // Return the resulting Morse code
    pthread_exit(result);
}

int main(int argc, char *argv[]) {
    // Get the input text from the command line arguments
    char *input_text = argv[1];
    
    // Split the input into an array of words for parallel processing
    char *words[50];
    char *delimiter = " ";
    char *word = strtok(input_text, delimiter);
    int word_idx = 0;
    while (word != NULL) {
        words[word_idx] = word;
        word_idx++;
        word = strtok(NULL, delimiter);
    }
    
    // Initialize the threads
    pthread_t threads[50];
    int rc;
    void *thread_result[50];
    
    // Start a thread for each word in the input
    for (int i = 0; i < word_idx; i++) {
        rc = pthread_create(&threads[i], NULL, text_to_morse, (void *) words[i]);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    
    // Wait for all threads to finish and collect the return values
    for (int i = 0; i < word_idx; i++) {
        rc = pthread_join(threads[i], &thread_result[i]);
        if (rc) {
            printf("ERROR; return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }
    
    // Print out the resulting Morse code
    printf("Morse code:\n");
    for (int i = 0; i < word_idx; i++) {
        printf("%s", (char*) thread_result[i]);
    }
    printf("\n");
    
    // Exit the program
    pthread_exit(NULL);
}