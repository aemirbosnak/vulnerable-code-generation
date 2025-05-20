//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_SIZE 100

// Custom user input sanitizer function
int is_input_safe(char *input) {
    int i, found_special_char = 0;
    const char *special_chars = ";:\"'()<>{}\\|`~^%$#@";

    for (i = 0; input[i] != '\0'; i++) {
        if (strchr(special_chars, input[i]) != NULL) {
            found_special_char = 1;
            break;
        }
    }

    if (found_special_char) {
        printf("Curiouser and curiouser! Input contains special characters.\n");
        free(input);
        return 0;
    }

    return 1;
}

int main() {
    char user_input[MAX_INPUT_SIZE];
    char *safe_input = NULL;

    printf("Hello there, curious traveler! I'd be delighted to hear your story. Please type it below, but beware!\n");
    printf("I have a curious little friend here who might try to inject some special characters into your story!\n");
    printf("If you succeed in telling a safe story, I will share it with the world!\n");
    printf("Ready? Go on, tell me your story:\n");

    fgets(user_input, MAX_INPUT_SIZE, stdin);

    if (strchr(user_input, '\n') != NULL) {
        user_input[strcspn(user_input, "\n")] = '\0';
    }

    if (is_input_safe(user_input)) {
        safe_input = (char *) malloc(strlen(user_input) + 1);
        strcpy(safe_input, user_input);
        printf("Bravo! Your story is safe to share with the world!\n");
        printf("Here it is:\n%s\n", safe_input);
        free(safe_input);
    } else {
        printf("Oh dear! It seems your story contained some special characters.\n");
        printf("I'm sorry, but I cannot share that with the world.\n");
    }

    return 0;
}