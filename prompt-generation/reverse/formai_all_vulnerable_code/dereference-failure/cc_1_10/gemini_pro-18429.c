//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom string manipulation functions
char *str_append(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char *newstr = malloc(len1 + len2 + 1);
    strcpy(newstr, s1);
    strcpy(newstr + len1, s2);
    newstr[len1 + len2] = '\0';
    return newstr;
}

char *str_reverse(char *s) {
    int len = strlen(s);
    char *newstr = malloc(len + 1);
    int i;
    for (i = 0; i < len; i++) {
        newstr[i] = s[len - i - 1];
    }
    newstr[len] = '\0';
    return newstr;
}

// A creative example - a function that generates a random sentence
char *generate_sentence() {
    // Arrays of words
    char *subjects[] = {"The cat", "The dog", "The bird", "The boy", "The girl"};
    char *verbs[] = {"ran", "jumped", "flew", "played", "slept"};
    char *objects[] = {"over the fence", "on the bed", "in the tree", "with a ball", "under the table"};

    // Generate random indices for each array
    int subject_idx = rand() % 5;
    int verb_idx = rand() % 5;
    int object_idx = rand() % 5;

    // Concatenate the words into a sentence
    char *sentence = str_append(str_append(subjects[subject_idx], " "), verbs[verb_idx]);
    sentence = str_append(sentence, " ");
    sentence = str_append(sentence, objects[object_idx]);
    sentence = str_append(sentence, ".");

    return sentence;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate 10 random sentences
    int i;
    for (i = 0; i < 10; i++) {
        char *sentence = generate_sentence();
        printf("%s\n", sentence);
        free(sentence);
    }

    return 0;
}