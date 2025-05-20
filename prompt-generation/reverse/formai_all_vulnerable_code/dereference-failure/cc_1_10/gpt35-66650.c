//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

char* get_word(char* input, int start_index) {
    int i;
    char* word = malloc(sizeof(char));
    for (i = start_index; i < strlen(input) && input[i] != ' '; i++) {
        word = realloc(word, (i - start_index + 1) * sizeof(char));
        *(word + i - start_index) = input[i];
    }
    *(word + i - start_index) = '\0';
    return word;
}

char* translate(char* input) {
    char* output = malloc(sizeof(char));
    int i = 0, j = 0;
    while (i < strlen(input)) {
        char* word = get_word(input, i);
        if (strcmp(word, "meow") == 0) {
            output = realloc(output, (j + 2) * sizeof(char));
            strcat(output, "C");
            j++;
        } else if (strcmp(word, "purr") == 0) {
            output = realloc(output, (j + 2) * sizeof(char));
            strcat(output, "++");
            j += 2;
        } else if (strcmp(word, "hiss") == 0) {
            output = realloc(output, (j + 2) * sizeof(char));
            strcat(output, "int");
            j += 3;
        } else if (strcmp(word, "scratch") == 0) {
            output = realloc(output, (j + 3) * sizeof(char));
            strcat(output, "<<=");
            j += 2;
        } else if (strcmp(word, "lick") == 0) {
            output = realloc(output, (j + 2) * sizeof(char));
            strcat(output, "->");
            j += 2;
        }
        i += strlen(word) + 1;
        free(word);
    }
    return output;
}

int main() {
    char input[100];
    printf("Enter sentence in Cat Language:\n");
    fgets(input, 100, stdin);
    printf("In C:\n%s\n", translate(input));
    return 0;
}