//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTIMENT_LEN 1000
#define MAX_WORDS 1000

// A struct to store the sentiment analysis result.
typedef struct {
    float positive;
    float negative;
    float neutral;
} sentiment_result_t;

// A linked list node to store a word and its sentiment score.
typedef struct {
    char *word;
    float sentiment;
    struct node *next;
} word_node_t;

// A linked list to store all the words and their sentiment scores.
typedef struct {
    word_node_t *head;
    word_node_t *tail;
    int size;
} word_list_t;

// Create a new word list.
word_list_t *new_word_list() {
    word_list_t *list = malloc(sizeof(word_list_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Add a new word to the word list.
void add_word_to_list(word_list_t *list, char *word, float sentiment) {
    word_node_t *new_node = malloc(sizeof(word_node_t));
    new_node->word = strdup(word);
    new_node->sentiment = sentiment;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
}

// Free all the memory allocated by the word list.
void free_word_list(word_list_t *list) {
    word_node_t *current = list->head;
    while (current != NULL) {
        word_node_t *next = current->next;
        free(current->word);
        free(current);
        current = next;
    }

    free(list);
}

// Load the sentiment word list from a file.
word_list_t *load_sentiment_word_list(char *filename) {
    word_list_t *list = new_word_list();

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening sentiment word list file: %s\n", filename);
        return NULL;
    }

    char line[MAX_SENTIMENT_LEN];
    while (fgets(line, sizeof(line), file)) {
        char *word = strtok(line, ",");
        char *sentiment = strtok(NULL, ",");
        float sentiment_score = atof(sentiment);
        add_word_to_list(list, word, sentiment_score);
    }

    fclose(file);

    return list;
}

// Analyze the sentiment of a text.
sentiment_result_t analyze_sentiment(char *text, word_list_t *list) {
    sentiment_result_t result = { 0, 0, 0 };

    char *words[MAX_WORDS];
    int num_words = 0;

    // Tokenize the text into words.
    char *token = strtok(text, " ");
    while (token != NULL) {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }

    // Calculate the sentiment score for each word.
    for (int i = 0; i < num_words; i++) {
        word_node_t *node = list->head;
        while (node != NULL) {
            if (strcmp(words[i], node->word) == 0) {
                result.positive += node->sentiment;
                break;
            }
            node = node->next;
        }

        if (node == NULL) {
            result.neutral += 1;
        }
    }

    float total = result.positive + result.neutral;
    result.positive /= total;
    result.neutral /= total;
    result.negative = 1 - result.positive - result.neutral;

    return result;
}

// Print the sentiment analysis result.
void print_sentiment_result(sentiment_result_t result) {
    printf("Positive: %.2f%%\n", result.positive * 100);
    printf("Neutral: %.2f%%\n", result.neutral * 100);
    printf("Negative: %.2f%%\n", result.negative * 100);
}

int main() {
    // Load the sentiment word list.
    word_list_t *list = load_sentiment_word_list("sentiment_word_list.txt");

    // Get the text to analyze.
    char text[MAX_SENTIMENT_LEN];
    printf("Enter the text to analyze: ");
    fgets(text, sizeof(text), stdin);

    // Analyze the sentiment of the text.
    sentiment_result_t result = analyze_sentiment(text, list);

    // Print the sentiment analysis result.
    print_sentiment_result(result);

    // Free the memory allocated by the word list.
    free_word_list(list);

    return 0;
}