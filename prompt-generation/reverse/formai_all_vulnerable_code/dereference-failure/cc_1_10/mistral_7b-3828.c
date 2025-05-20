//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_WISH_LENGTH 100

void sanitizeWish(char *wish) {
    int i, j;

    for (i = 0; wish[i] != '\0'; i++) {
        for (j = 0; j < 10; j++) {
            if (isdigit(wish[i])) {
                wish[i] = '\0';
                i--;
                break;
            }
        }

        if (wish[i] == ';') {
            wish[i] = '\0';
            for (j = i; wish[j] != '\0'; j++) {
                wish[j] = wish[j + 1];
            }
            i--;
        }
    }

    size_t len = strlen(wish);
    if (len > MAX_WISH_LENGTH) {
        for (i = len; i > MAX_WISH_LENGTH; i--) {
            wish[i - 1] = wish[i];
        }
        wish[MAX_WISH_LENGTH] = '\0';
    }
}

int main() {
    char wish[MAX_WISH_LENGTH];

    printf("Welcome to the Magic Tea Pot!\n");
    printf("Enter your wish: ");
    fgets(wish, sizeof(wish), stdin);

    // Remove newline character from fgets
    size_t len = strlen(wish);
    if (len > 0 && wish[len - 1] == '\n') {
        wish[len - 1] = '\0';
    }

    sanitizeWish(wish);

    printf("Your sanitized wish is: %s\n", wish);

    if (strcmp(wish, "tea") == 0) {
        printf("The Magic Tea Pot grants you a cup of tea.\n");
    } else {
        printf("The Magic Tea Pot doesn't understand your wish.\n");
    }

    return 0;
}