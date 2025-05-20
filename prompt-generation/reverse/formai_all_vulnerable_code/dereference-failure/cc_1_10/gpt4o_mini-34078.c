//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

void burn_chars(char *str, char *burned) {
    // Function to eliminate unwanted chars
    char *result = (char *)malloc(strlen(str) + 1);
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!strchr(burned, str[i])) {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    strcpy(str, result);
    free(result);
}

void salvage_sentence(char *sentence) {
    // Function to salvage a sentence by turning it into uppercase
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] >= 'a' && sentence[i] <= 'z') {
            sentence[i] -= 32; // Convert to uppercase
        }
    }
}

void forge_weapon_names(char *base_name, const char *suffixes[], int num_suffixes) {
    // Function to create unique weapon names from base names
    printf("Forging weapons...\n");
    char final_name[MAX_SIZE];
    for (int i = 0; i < num_suffixes; i++) {
        snprintf(final_name, sizeof(final_name), "%s %s", base_name, suffixes[i]);
        printf("Constructed: %s\n", final_name);
    }
}

void print_salvaged_words(char *salvaged) {
    // Display the salvaged words
    printf("Salvaged words: %s\n", salvaged);
}

int main() {
    char original_sentence[MAX_SIZE] = "The war has stripped our world, leaving only remnants.";
    char burned_chars_set[] = " ,.";
    char weapon_base_name[MAX_SIZE] = "Rusty Blade";

    printf("Original Sentence: %s\n", original_sentence);

    // Burn unwanted characters
    burn_chars(original_sentence, burned_chars_set);
    printf("After burning characters: %s\n", original_sentence);

    // Salvage the sentence
    salvage_sentence(original_sentence);
    printf("After salvaging sentence: %s\n", original_sentence);

    // Forge unique weapon names
    const char *weapon_suffixes[] = {
        "of Desolation", 
        "of the Fallen", 
        "of the Reckoning", 
        "of Lost Hope"
    };

    forge_weapon_names(weapon_base_name, weapon_suffixes, sizeof(weapon_suffixes) / sizeof(weapon_suffixes[0]));

    // Construct salvaged words
    char salvaged_words[MAX_SIZE];
    snprintf(salvaged_words, sizeof(salvaged_words), "Mutation, Fragment, Survival, Ruin");
    print_salvaged_words(salvaged_words);

    return EXIT_SUCCESS;
}