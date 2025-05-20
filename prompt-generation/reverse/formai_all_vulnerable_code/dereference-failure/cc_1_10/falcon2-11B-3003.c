//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to extract most important sentences from a given text
void extract_sentences(const char* text, int num_sentences, char* result) {
    char* sentence;
    int sentence_length;
    char* token;
    int num_words = 0;
    int num_sentences_found = 0;

    // Tokenize the text into individual words
    token = strtok(text, " ");
    while (token!= NULL) {
        num_words++;
        token = strtok(NULL, " ");
    }

    // Initialize the result array with the first sentence
    result[num_sentences_found] = "";
    sentence = strtok(text, " ");
    while (sentence!= NULL && num_sentences_found < num_sentences) {
        sentence_length = strlen(sentence);
        if (sentence_length > 30) {
            result[num_sentences_found] = sentence;
            num_sentences_found++;
        }
        sentence = strtok(NULL, " ");
    }
}

int main() {
    const char* text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                  "Sed sit amet nibh euismod, pulvinar elit at, pulvinar lorem. "
                  "Aenean nec sollicitudin diam, quis bibendum lorem. "
                  "Pellentesque nec vestibulum orci. Sed euismod ligula vel ipsum "
                  "tincidunt, at condimentum purus ultricies. "
                  "Suspendisse eget risus quam. Morbi ac magna nisi. "
                  "Nunc ornare, mi sit amet volutpat consequat, nunc "
                  "quam convallis neque, ut tincidunt erat nisi sed risus. "
                  "In hac habitasse platea dictumst. Integer euismod ligula "
                  "sit amet arcu rhoncus, ac mattis risus tempor. "
                  "Nunc pretium, odio eu ultrices elementum, neque nunc aliquet "
                  "diam, at sodales erat eros et nisl. "
                  "Sed sit amet nibh euismod, pulvinar elit at, pulvinar lorem. "
                  "Aenean nec sollicitudin diam, quis bibendum lorem. "
                  "Pellentesque nec vestibulum orci. Sed euismod ligula vel ipsum "
                  "tincidunt, at condimentum purus ultricies. "
                  "Suspendisse eget risus quam. Morbi ac magna nisi. "
                  "Nunc ornare, mi sit amet volutpat consequat, nunc "
                  "quam convallis neque, ut tincidunt erat nisi sed risus. "
                  "In hac habitasse platea dictumst. Integer euismod ligula "
                  "sit amet arcu rhoncus, ac mattis risus tempor. "
                  "Nunc pretium, odio eu ultrices elementum, neque nunc aliquet "
                  "diam, at sodales erat eros et nisl.";
    char* result[5];
    int num_sentences = 5;
    extract_sentences(text, num_sentences, result);
    printf("The most important sentences from the text are: ");
    for (int i = 0; i < num_sentences; i++) {
        printf("%s ", result[i]);
    }
    printf("\n");
    return 0;
}