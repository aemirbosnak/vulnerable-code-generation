//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// CAT Dictionary
typedef struct CatWord {
    char* eng;
    char* cat;
    struct CatWord* next;
} CatWord;

CatWord* cat_dictionary = NULL;

void add_cat_word(const char* eng, const char* cat) {
    CatWord* new_word = (CatWord*) malloc(sizeof(CatWord));
    new_word->eng = strdup(eng);
    new_word->cat = strdup(cat);
    new_word->next = cat_dictionary;
    cat_dictionary = new_word;
}

void init_cat_dictionary() {
    add_cat_word("hello", "meow meow");
    add_cat_word("goodbye", "purr purr");
    add_cat_word("how", "mew mew");
    add_cat_word("are", "meow are");
    add_cat_word("you", "you you");
}

int translate_english_to_cat(const char* eng, char* cat, int max_len) {
    CatWord* current = cat_dictionary;
    int len = strlen(eng);
    int i;

    for (i = 0; i < len && current != NULL; i++) {
        if (tolower(eng[i]) == tolower(current->eng[i])) {
            strncat(cat, current->cat, max_len - strlen(cat) - 1);
            if (strlen(cat) >= max_len) {
                return -1;
            }
            strcat(cat, " ");
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        return -1;
    }

    return strlen(cat);
}

int main() {
    init_cat_dictionary();

    char buffer[256];
    char cat_sentence[256];
    int len;

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        sscanf(buffer, "%s", buffer); // remove newline character

        len = translate_english_to_cat(buffer, cat_sentence, sizeof(cat_sentence));
        if (len < 0) {
            printf("Error: Unknown English word: %s\n", buffer);
            continue;
        }

        printf("%s -> %s\n", buffer, cat_sentence);
    }

    return 0;
}