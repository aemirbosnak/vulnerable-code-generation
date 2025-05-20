//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_NAME_LENGTH 50
#define LOVE_SCORE_MIN 0
#define LOVE_SCORE_MAX 1000

// Function to calculate the love score between two names
int calculate_love_score(char *name1, char *name2) {
    int name1_score = 0;
    int name2_score = 0;
    int name_length = 0;

    // Error checking for name1
    if (strlen(name1) > MAX_NAME_LENGTH) {
        perror("Error: Name1 is too long.\n");
        exit(EXIT_FAILURE);
    }
    name_length = strlen(name1);

    for (int i = 0; i < name_length; i++) {
        switch (name1[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                name1_score += 1;
                break;
            default:
                name1_score += name1[i];
        }
    }

    // Error checking for name2
    if (strlen(name2) > MAX_NAME_LENGTH) {
        write(STDERR_FILENO, "Error: Name2 is too long.\n", strlen("Error: Name2 is too long.\n"));
        exit(EXIT_FAILURE);
    }
    name_length = strlen(name2);

    for (int i = 0; i < name_length; i++) {
        switch (name2[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                name2_score += 1;
                break;
            default:
                name2_score += name2[i];
        }
    }

    // Calculate love score
    int love_score = name1_score + name2_score;

    if (love_score < LOVE_SCORE_MIN) {
        printf("Error: Your love score is below the minimum. Check your names.\n");
        exit(EXIT_FAILURE);
    } else if (love_score > LOVE_SCORE_MAX) {
        printf("Error: Your love score is too high. Check your names.\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Your love score is: %d\n", love_score);
    }

    return love_score;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <name1> <name2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int love_score = calculate_love_score(argv[1], argv[2]);

    return 0;
}