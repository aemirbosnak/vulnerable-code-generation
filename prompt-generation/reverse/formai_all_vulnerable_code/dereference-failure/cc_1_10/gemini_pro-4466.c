//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
    ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
    ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....",
    "-....", "--...", "---..", "----.", "-----", " "
};

// Thread data structure
typedef struct {
    char *text;
    char *morse_code;
    int index;
} thread_data;

// Thread function
void *convert_to_morse(void *arg) {
    thread_data *data = (thread_data *)arg;

    // Convert the character to morse code
    data->morse_code = morse_table[data->text[data->index] - 'a'];

    // Return the morse code
    return data->morse_code;
}

int main(int argc, char **argv) {
    // Check if the user provided a text
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    // Create the thread pool
    pthread_t threads[strlen(argv[1])];

    // Create the thread data
    thread_data data[strlen(argv[1])];

    // Create the threads
    for (int i = 0; i < strlen(argv[1]); i++) {
        data[i].text = argv[1];
        data[i].index = i;
        pthread_create(&threads[i], NULL, convert_to_morse, &data[i]);
    }

    // Join the threads
    for (int i = 0; i < strlen(argv[1]); i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the morse code
    for (int i = 0; i < strlen(argv[1]); i++) {
        printf("%s", data[i].morse_code);
    }

    // Free the memory
    for (int i = 0; i < strlen(argv[1]); i++) {
        free(data[i].morse_code);
    }

    return 0;
}