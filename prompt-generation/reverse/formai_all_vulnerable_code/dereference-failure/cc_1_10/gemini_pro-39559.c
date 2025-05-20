//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: post-apocalyptic
// In the desolate wasteland, amidst the ruins of an ancient citadel, a lone survivor embarks on a perilous quest to count the echoes of words amidst the silence.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A weathered tome, its pages inscribed with the remnants of countless tales
typedef struct word_node_t {
    char *word;
    int count;
    struct word_node_t *next;
} word_node_t;

// A ragged lexicon, where words are scavenged and catalogued
typedef struct word_list_t {
    word_node_t *head;
    int size;
} word_list_t;

// Initializes the lexicon, a beacon in the barren wasteland of memory
word_list_t *create_list() {
    word_list_t *list = malloc(sizeof(word_list_t));
    list->head = NULL;
    list->size = 0;
    return list;
}

// Adds a word to the lexicon, a whisper echoing through the silence
void add_word(word_list_t *list, char *word) {
    word_node_t *node = list->head;

    // Traverse the lexicon, seeking refuge among its brethren words
    while (node != NULL) {
        // If the word has been uttered before, increment its count, a testament to its enduring presence
        if (strcmp(node->word, word) == 0) {
            node->count++;
            return;
        }
        node = node->next;
    }

    // If the word is new, grant it a place within the lexicon, an echo reverberating in the void
    node = malloc(sizeof(word_node_t));
    node->word = strdup(word);
    node->count = 1;
    node->next = list->head;
    list->head = node;
    list->size++;
}

// Counts the words in a desolate text, a testament to the voices that once filled the air
int count_words(word_list_t *list, char *text) {
    char *word;
    int word_count = 0;

    // Tokenize the text, each word a fragile fragment of memory
    word = strtok(text, " .,:;?!");
    while (word != NULL) {
        // Convert the word to lowercase, a unifying echo in the face of chaos
        for (int i = 0; word[i] != '\0'; i++) {
            word[i] = tolower(word[i]);
        }

        // Add the word to the lexicon, a testament to its resilience
        add_word(list, word);
        word_count++;

        // Seek the next word, a beacon in the sea of desolation
        word = strtok(NULL, " .,:;?!");
    }

    return word_count;
}

// Prints the lexicon, a testament to the echoes that linger in the wasteland
void print_list(word_list_t *list) {
    word_node_t *node = list->head;

    printf("\nIn the annals of the wasteland, these echoes linger:\n");
    printf("------------------------------------------\n");
    while (node != NULL) {
        printf("%s: %d\n", node->word, node->count);
        node = node->next;
    }
}

// Frees the lexicon, its echoes fading into the desolate void
void destroy_list(word_list_t *list) {
    word_node_t *node = list->head;

    while (node != NULL) {
        word_node_t *next = node->next;
        free(node->word);
        free(node);
        node = next;
    }

    free(list);
}

int main() {
    // A salvaged text, a whisper carried by the radioactive wind
    char text[] = "In the ruins of a shattered world, a lone survivor wanders, haunted by echoes of a forgotten past."
                  " Amidst the rubble, they scavenge for remnants of knowledge, their voices echoing through the silence."
                  " Each word, a spark igniting memories, a testament to the resilience of the human spirit.";

    // Initialize the lexicon, a sanctuary for the echoes of language
    word_list_t *list = create_list();

    // Count the words, a measure of the echoes that still reverberate
    int word_count = count_words(list, text);
    printf("\nAmidst the desolation, %d echoes cling to existence.\n", word_count);

    // Print the lexicon, a testament to the enduring power of words
    print_list(list);

    // Release the lexicon, its echoes fading into the void
    destroy_list(list);

    return 0;
}