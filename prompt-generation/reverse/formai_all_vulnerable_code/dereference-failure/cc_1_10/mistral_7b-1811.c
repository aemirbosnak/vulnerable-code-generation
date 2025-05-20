//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert a string to lowercase
void str_to_lower(char *str) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

// Function to count the occurrences of a word in a string
int count_word(char *str, char *word) {
    int count = 0;
    char *token = strtok(str, " ");

    while (token != NULL) {
        str_to_lower(token);
        str_to_lower(word);

        if (strcmp(token, word) == 0) {
            count++;
        }

        token = strtok(NULL, " ");
    }

    return count;
}

// Function to read a text file and count the occurrences of a given word
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file> <word>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char buffer[1024];
    int total_count = 0;
    char *word = argv[2];

    while (fgets(buffer, sizeof(buffer), file)) {
        int count = count_word(buffer, word);
        total_count += count;
    }

    fclose(file);

    printf("The word '%s' occurs %d times in the file '%s'\n", word, total_count, argv[1]);

    return 0;
}