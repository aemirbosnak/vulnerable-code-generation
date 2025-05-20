//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define INITIAL_WORD_COUNT 1000

struct key_value_pair {
    char* key;
    int value;
};

struct word_freq_counter {
    struct key_value_pair* pairs;
    int num_pairs;
    int max_pairs;
};

static int cmp(const void* p1, const void* p2) {
    struct key_value_pair* kv1 = (struct key_value_pair*) p1;
    struct key_value_pair* kv2 = (struct key_value_pair*) p2;
    return kv2->value - kv1->value;
}

static struct word_freq_counter* new_word_freq_counter() {
    struct word_freq_counter* counter = malloc(sizeof(struct word_freq_counter));
    counter->pairs = malloc(sizeof(struct key_value_pair) * INITIAL_WORD_COUNT);
    counter->num_pairs = 0;
    counter->max_pairs = INITIAL_WORD_COUNT;
    return counter;
}

static void add_word(struct word_freq_counter* counter, const char* word) {
    if (counter->num_pairs + 1 >= counter->max_pairs) {
        counter->pairs = realloc(counter->pairs, sizeof(struct key_value_pair) * counter->max_pairs * 2);
        counter->max_pairs *= 2;
    }

    char* copy = strdup(word);
    int i = 0;
    while (copy[i]) {
        copy[i] = tolower(copy[i]);
        i++;
    }

    for (int j = 0; j < counter->num_pairs; j++) {
        if (strcmp(copy, counter->pairs[j].key) == 0) {
            counter->pairs[j].value++;
            free(copy);
            return;
        }
    }

    counter->pairs[counter->num_pairs].key = copy;
    counter->pairs[counter->num_pairs].value = 1;
    counter->num_pairs++;
}

static void print_word_freq_counter(struct word_freq_counter* counter) {
    qsort(counter->pairs, counter->num_pairs, sizeof(struct key_value_pair), cmp);
    for (int i = 0; i < counter->num_pairs; i++) {
        printf("%s: %d\n", counter->pairs[i].key, counter->pairs[i].value);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        printf("Unable to open %s\n", filename);
        return 1;
    }

    struct word_freq_counter* counter = new_word_freq_counter();
    char word[MAX_WORD_LENGTH];
    while (fscanf(f, "%s", word) != EOF) {
        add_word(counter, word);
    }

    print_word_freq_counter(counter);

    fclose(f);

    for (int i = 0; i < counter->num_pairs; i++) {
        free(counter->pairs[i].key);
    }
    free(counter->pairs);
    free(counter);

    return 0;
}