//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RUSTED_STRINGS 1024  // Max length of rusty strings
#define CORRODED_PTRS 1024  // Max number of corroded pointers

typedef struct {
    char *str;
    int length;
} RustyString;

typedef struct {
    RustyString **strings;
    int size;
} CorrodedPtrs;

CorrodedPtrs *create_corrupted_pointers() {
    CorrodedPtrs *ptrs = malloc(sizeof(CorrodedPtrs));
    ptrs->strings = malloc(sizeof(RustyString *) * CORRODED_PTRS);
    ptrs->size = 0;
    return ptrs;
}

void destroy_corrupted_pointers(CorrodedPtrs *ptrs) {
    for (int i = 0; i < ptrs->size; i++) {
        free(ptrs->strings[i]->str);
        free(ptrs->strings[i]);
    }
    free(ptrs->strings);
    free(ptrs);
}

RustyString *create_rusty_string(const char *str) {
    RustyString *string = malloc(sizeof(RustyString));
    string->length = strlen(str);
    string->str = malloc(string->length + 1);
    strcpy(string->str, str);
    return string;
}

void destroy_rusty_string(RustyString *string) {
    free(string->str);
    free(string);
}

void add_to_corrupted_pointers(CorrodedPtrs *ptrs, RustyString *string) {
    ptrs->strings[ptrs->size++] = string;
}

void print_corrupted_pointers(CorrodedPtrs *ptrs) {
    for (int i = 0; i < ptrs->size; i++) {
        printf("%s\n", ptrs->strings[i]->str);
    }
}

void mutate_rusty_string(RustyString *string) {
    for (int i = 0; i < string->length; i++) {
        if (rand() % 2 == 0) {
            string->str[i] = rand() % 26 + 'a';  // Replace with random lowercase letter
        } else {
            string->str[i] = rand() % 26 + 'A';  // Replace with random uppercase letter
        }
    }
}

int main() {
    CorrodedPtrs *ptrs = create_corrupted_pointers();

    char *raw_strings[] = {
        "We are survivors from the nuclear war.",
        "We will rebuild our world.",
        "We will find a way to survive.",
        "We will never give up hope.",
        "We will protect our children."
    };

    for (int i = 0; i < 5; i++) {
        RustyString *string = create_rusty_string(raw_strings[i]);
        mutate_rusty_string(string);
        add_to_corrupted_pointers(ptrs, string);
    }

    printf("Corrupted strings:\n");
    print_corrupted_pointers(ptrs);

    destroy_corrupted_pointers(ptrs);

    return 0;
}