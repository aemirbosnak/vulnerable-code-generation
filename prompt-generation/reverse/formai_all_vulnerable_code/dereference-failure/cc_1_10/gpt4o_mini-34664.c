//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a text file and return its content
char* read_file(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }
    
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *content = malloc(length + 1);
    if (!content) {
        perror("Could not allocate memory");
        fclose(file);
        return NULL;
    }

    fread(content, 1, length, file);
    content[length] = '\0';
    fclose(file);
    
    return content;
}

// Function to perform sentiment analysis and return a score
int analyze_sentiment(const char* text) {
    const char* positive_words[] = {"good", "great", "happy", "fantastic", "love", NULL};
    const char* negative_words[] = {"bad", "terrible", "sad", "horrible", "hate", NULL};

    int score = 0;
    char *word = strtok(strdup(text), " ,.!?;\n");
    
    while (word) {
        for (int i = 0; positive_words[i] != NULL; i++) {
            if (strcasecmp(word, positive_words[i]) == 0) {
                score++;
                break;
            }
        }
        for (int i = 0; negative_words[i] != NULL; i++) {
            if (strcasecmp(word, negative_words[i]) == 0) {
                score--;
                break;
            }
        }
        word = strtok(NULL, " ,.!?;\n");
    }

    return score;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *content = read_file(argv[1]);
    if (!content) {
        return EXIT_FAILURE;
    }

    int score = analyze_sentiment(content);
    free(content);

    if (score > 0) {
        printf("Overall Sentiment: Positive (Score: %d)\n", score);
    } else if (score < 0) {
        printf("Overall Sentiment: Negative (Score: %d)\n", score);
    } else {
        printf("Overall Sentiment: Neutral (Score: %d)\n", score);
    }

    return EXIT_SUCCESS;
}