//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000

typedef struct {
    char *word;
    int count;
} word_count_pair;

int compare_word_count_pairs(const void *a, const void *b) {
    const word_count_pair *aa = (const word_count_pair *)a;
    const word_count_pair *bb = (const word_count_pair *)b;
    return strcmp(aa->word, bb->word);
}

int main() {
    char *text = "In the realm of tranquility, where thoughts gently sway, there dwells an ethereal entity of serenity: the Word Frequency Counter. It gracefully traverses the vast expanse of a given text, seeking to unveil the secrets of language's symphony. With each step, it counts the words, its movements akin to a gentle dance upon the keys of harmony. Through its meticulous observations, it reveals the heartbeat of communication, the ebb and flow of ideas encapsulated within human expression. Its purpose is not to judge or criticize, but to simply observe and count, providing insights into the fabric of language. As it delves deeper into the text, it paints a vivid tapestry of word frequencies, a reflection of the author's thoughts, emotions, and experiences. It doesn't seek to impose its own interpretations, but rather to serve as a humble guide, offering a path to understanding. Like a silent observer in a bustling marketplace, it captures the essence of each word's presence, its frequency a reflection of its significance in the writer's mind. The Word Frequency Counter stands as a testament to the power of observation, a gentle reminder that even in the chaos of language, there is an underlying order waiting to be discovered.";

    // Tokenize the text into words
    char *words[MAX_WORDS];
    int num_words = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }

    // Count the frequency of each word
    word_count_pair word_counts[MAX_WORDS];
    int num_word_counts = 0;
    for (int i = 0; i < num_words; i++) {
        int found = 0;
        for (int j = 0; j < num_word_counts; j++) {
            if (strcmp(words[i], word_counts[j].word) == 0) {
                word_counts[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            word_counts[num_word_counts].word = words[i];
            word_counts[num_word_counts].count = 1;
            num_word_counts++;
        }
    }

    // Sort the word counts in alphabetical order
    qsort(word_counts, num_word_counts, sizeof(word_count_pair), compare_word_count_pairs);

    // Print the word counts
    for (int i = 0; i < num_word_counts; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}