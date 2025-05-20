//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Define a struct to hold a single sentence
typedef struct sentence {
    char *text; // Text of the sentence
    int len; // Length of the text
} sentence;

// Function to generate a random sentence
sentence generate_sentence(void) {
    int word_count = rand() % 5 + 1;
    sentence s;
    s.text = malloc(word_count * sizeof(char));
    s.len = word_count;
    for (int i = 0; i < word_count; i++) {
        s.text[i] = 'a' + (rand() % 26); // Generate a random word
    }
    return s;
}

// Function to print a sentence in a funky font
void print_funky(sentence s) {
    int i = 0;
    while (i < s.len) {
        if (i % 2 == 0) {
            printf(" %c", s.text[i]);
        } else {
            printf("%c", s.text[i]);
        }
        i++;
    }
}

int main() {
    sentence s1 = generate_sentence();
    sentence s2 = generate_sentence();
    sentence s3 = generate_sentence();

    // Print the sentences in a funky font
    print_funky(s1);
    print_funky(s2);
    print_funky(s3);

    // Wait for the user to press a key
    getchar();

    return 0;
}