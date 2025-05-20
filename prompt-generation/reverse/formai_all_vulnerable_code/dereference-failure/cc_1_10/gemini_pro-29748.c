//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Structure to hold the text and its length
typedef struct {
    char *text;
    int length;
} TextData;

// Mutex to protect the shared text data
pthread_mutex_t text_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to count the number of words in a text
int count_words(TextData *data) {
    int word_count = 0;
    int in_word = 0;

    for (int i = 0; i < data->length; i++) {
        if (data->text[i] != ' ' && data->text[i] != '\n' && data->text[i] != '\t') {
            if (!in_word) {
                word_count++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
    }

    return word_count;
}

// Function to count the number of lines in a text
int count_lines(TextData *data) {
    int line_count = 0;

    for (int i = 0; i < data->length; i++) {
        if (data->text[i] == '\n') {
            line_count++;
        }
    }

    return line_count;
}

// Function to count the number of characters in a text
int count_characters(TextData *data) {
    return data->length;
}

// Thread function to process a portion of the text
void *process_text(void *arg) {
    // Get the text data
    TextData *data = (TextData *)arg;

    // Acquire the mutex lock
    pthread_mutex_lock(&text_mutex);

    // Process the text
    int word_count = count_words(data);
    int line_count = count_lines(data);
    int character_count = count_characters(data);

    // Release the mutex lock
    pthread_mutex_unlock(&text_mutex);

    // Print the results
    printf("Word count: %d\n", word_count);
    printf("Line count: %d\n", line_count);
    printf("Character count: %d\n", character_count);

    return NULL;
}

int main() {
    // Get the text from the user
    char *text;
    printf("Enter the text: ");
    scanf("%[^\n]%*c", &text);

    // Create a text data structure
    TextData data;
    data.text = text;
    data.length = strlen(text);

    // Create a thread to process the text
    pthread_t thread;
    pthread_create(&thread, NULL, process_text, &data);

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    // Free the allocated memory
    free(text);

    return 0;
}