//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_POEMS 10
#define MAX_WORDS 20

typedef struct {
    char *words[MAX_WORDS];
    int num_words;
} Poem;

void generate_poem(Poem *poem) {
    char *adjectives[] = {"beautiful", "lovely", "amazing", "stunning", "gorgeous"};
    char *nouns[] = {"rose", "sunset", "ocean", "sky", "eyes"};
    char *verbs[] = {"shines", "glows", "sparkles", "dances", "sings"};
    char *articles[] = {"the", "a"};

    srand(time(0));

    for (int i = 0; i < MAX_WORDS; i++) {
        poem->words[i] = malloc(sizeof(char) * 20);
        if (i == 0) {
            strcpy(poem->words[i], articles[rand() % 2]);
        } else if (i % 2 == 0) {
            strcpy(poem->words[i], adjectives[rand() % 5]);
        } else {
            strcpy(poem->words[i], nouns[rand() % 5]);
        }
    }

    poem->num_words = MAX_WORDS;
}

void print_poem(Poem *poem) {
    for (int i = 0; i < poem->num_words; i++) {
        printf("%s ", poem->words[i]);
    }
    printf("\n");
}

int main() {
    Poem *poems[MAX_POEMS];

    for (int i = 0; i < MAX_POEMS; i++) {
        poems[i] = malloc(sizeof(Poem));
        generate_poem(poems[i]);
    }

    for (int i = 0; i < MAX_POEMS; i++) {
        print_poem(poems[i]);
    }

    for (int i = 0; i < MAX_POEMS; i++) {
        for (int j = 0; j < poems[i]->num_words; j++) {
            free(poems[i]->words[j]);
        }
        free(poems[i]);
    }

    return 0;
}