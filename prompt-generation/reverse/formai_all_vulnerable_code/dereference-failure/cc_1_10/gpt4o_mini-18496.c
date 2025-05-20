//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LEN 256
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

void clear_screen() {
    // Clear the screen with a hackish terminal command
    printf("\033[H\033[J");
}

void print_intro() {
    printf("====================================\n");
    printf("    Cyberpunk Levenshtein Engine    \n");
    printf("====================================\n");
    printf("Welcome, netrunner. Let's calculate the distance.\n");
    printf("Enter two strings, and we will see how far apart they are in the matrix.\n");
}

int levenshtein_distance(const char *s1, const char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    int **distance = (int **)malloc((len1 + 1) * sizeof(int *));
    
    for (size_t i = 0; i <= len1; i++) {
        distance[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    for (size_t i = 0; i <= len1; i++) {
        distance[i][0] = i;
    }
    for (size_t j = 0; j <= len2; j++) {
        distance[0][j] = j;
    }

    for (size_t i = 1; i <= len1; i++) {
        for (size_t j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            distance[i][j] = MIN(MIN(distance[i - 1][j] + 1,
                                       distance[i][j - 1] + 1),
                                 distance[i - 1][j - 1] + cost);
        }
    }

    int result = distance[len1][len2];

    for (size_t i = 0; i <= len1; i++) {
        free(distance[i]);
    }
    free(distance);
    
    return result;
}

void get_input(char *input1, char *input2) {
    printf("Enter the first string (max 255 characters, dimmed): ");
    fgets(input1, MAX_LEN, stdin);
    input1[strcspn(input1, "\n")] = 0; // Remove newline

    printf("Enter the second string (max 255 characters, risky): ");
    fgets(input2, MAX_LEN, stdin);
    input2[strcspn(input2, "\n")] = 0; // Remove newline
}

void display_result(int distance) {
    printf("The Levenshtein distance is: %d\n", distance);
    printf("In the neon-lit abyss, the distance between your strings is profound.\n");
}

int main() {
    clear_screen();
    print_intro();

    char input1[MAX_LEN];
    char input2[MAX_LEN];

    get_input(input1, input2);

    int distance = levenshtein_distance(input1, input2);
    display_result(distance);

    printf("====================================\n");
    printf("Thank you, netrunner. Stay vigilant in the matrix.\n");
    return 0;
}