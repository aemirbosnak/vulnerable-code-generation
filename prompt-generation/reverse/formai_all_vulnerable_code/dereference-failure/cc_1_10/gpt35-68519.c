//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Structure to store code-to-morse translation
typedef struct {
    char code;
    char *morse;
} code_morse_t;

// Array to store all code-to-morse translations
code_morse_t code_morse_array[] = {
    {'A', ".-"},
    {'B', "-..."},
    {'C', "-.-."},
    {'D', "-.."},
    {'E', "."},
    {'F', "..-."},
    {'G', "--."},
    {'H', "...."},
    {'I', ".."},
    {'J', ".---"},
    {'K', "-.-"},
    {'L', ".-.."},
    {'M', "--"},
    {'N', "-."},
    {'O', "---"},
    {'P', ".--."},
    {'Q', "--.-"},
    {'R', ".-."},
    {'S', "..."},
    {'T', "-"},
    {'U', "..-"},
    {'V', "...-"},
    {'W', ".--"},
    {'X', "-..-"},
    {'Y', "-.--"},
    {'Z', "--.."},
    {'1', ".----"},
    {'2', "..---"},
    {'3', "...--"},
    {'4', "....-"},
    {'5', "....."},
    {'6', "-...."},
    {'7', "--..."},
    {'8', "---.."},
    {'9', "----."},
    {'0', "-----"}
};

// Function to convert text to Morse code
void *text_to_morse(void *args) {
    char *text = (char *) args; // Get text parameter as char*
    int text_len = strlen(text);
    
    // Store Morse code in a dynamic array of strings
    char **morse_array = malloc(sizeof(char*) * text_len);
    
    for (int i = 0; i < text_len; i++) {
        char text_char = text[i];
        char *morse_char = "";
        
        // Find Morse code corresponding to text character
        for (int j = 0; j < sizeof(code_morse_array)/sizeof(code_morse_t); j++) {
            if (code_morse_array[j].code == text_char) {
                morse_char = code_morse_array[j].morse;
                break;
            }
        }
        
        // Append Morse character to Morse code string
        morse_array[i] = morse_char;
    }
    
    // Return Morse code string array
    return (void *) morse_array;
}

int main() {
    char text[100];
    
    // Get input text from user
    printf("Enter text to convert to Morse code: ");
    fgets(text, 100, stdin);
    text[strcspn(text, "\n")] = 0;
    
    // Create thread for text-to-Morse code conversion
    pthread_t thread;
    pthread_create(&thread, NULL, text_to_morse, (void *) text);
    
    // Wait for thread to finish execution
    void *morse_array;
    pthread_join(thread, &morse_array);
    
    // Print Morse code
    printf("Morse code: ");
    
    int text_len = strlen(text);
    for (int i = 0; i < text_len; i++) {
        char *morse_char = ((char **) morse_array)[i];
        printf("%s ", morse_char);
        free(morse_char); // Free memory allocated for Morse character
    }
    
    // Free memory allocated for Morse code string array
    free(morse_array);
    
    return 0;
}