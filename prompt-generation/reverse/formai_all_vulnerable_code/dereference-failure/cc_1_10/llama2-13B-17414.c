//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 32

// Define a structure to hold the text data
typedef struct {
    char *text;
    int len;
} text_data_t;

// Function to read text from the user
text_data_t read_text() {
    int i, j;
    text_data_t data;

    printf("Enter a line of text ( Press Enter to end): ");
    data.text = malloc(MAX_LINE_LENGTH);
    data.len = 0;

    while (1) {
        scanf("%s", data.text + data.len);
        if (data.len >= MAX_LINE_LENGTH - 1) {
            break;
        }
        if (data.text[data.len - 1] == '\n') {
            break;
        }
        data.len++;
    }

    return data;
}

// Function to process the text data
void process_text(text_data_t data) {
    int i, j, k;
    char word[MAX_WORD_LENGTH];
    char *p;

    // Iterate through the text lines
    for (i = 0; data.text[i] != '\0'; i++) {
        if (data.text[i] == '\n') {
            // Iterate through the words in the line
            for (j = 0; j < i; j++) {
                if (data.text[j] == ' ' && data.text[i] != ' ') {
                    // Found a word!
                    p = word;
                    for (k = j + 1; data.text[k] != ' ' && k < i; k++) {
                        *p++ = data.text[k];
                    }
                    *p = '\0';

                    // Do something with the word
                    printf("Word: %s\n", word);
                }
            }
        }
    }
}

int main() {
    text_data_t data = read_text();
    process_text(data);
    return 0;
}