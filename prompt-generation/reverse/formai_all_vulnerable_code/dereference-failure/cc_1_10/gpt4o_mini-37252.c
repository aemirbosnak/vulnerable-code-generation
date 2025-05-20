//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    else if (b <= a && b <= c) return b;
    else return c;
}

// Function to compute the Levenshtein distance
int levenshtein(const char *s, const char *t) {
    int len_s = strlen(s);
    int len_t = strlen(t);
    int **d = (int **)malloc((len_s + 1) * sizeof(int *));
    
    for (int i = 0; i <= len_s; i++) {
        d[i] = (int *)malloc((len_t + 1) * sizeof(int));
    }

    for (int i = 0; i <= len_s; i++) {
        d[i][0] = i; // cost of deletion
    }
    for (int j = 0; j <= len_t; j++) {
        d[0][j] = j; // cost of insertion
    }

    for (int i = 1; i <= len_s; i++) {
        for (int j = 1; j <= len_t; j++) {
            int cost = (s[i - 1] == t[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,      // deletion
                          d[i][j - 1] + 1,      // insertion
                          d[i - 1][j - 1] + cost); // substitution
        }
    }

    int result = d[len_s][len_t];

    for (int i = 0; i <= len_s; i++) {
        free(d[i]);
    }
    free(d);
    return result;
}

// Function to get user input and calculate Levenshtein distance
void compareProducts() {
    char product1[100];
    char product2[100];
    
    printf("Enter the name of the first product: ");
    fgets(product1, sizeof(product1), stdin);
    product1[strcspn(product1, "\n")] = 0; // Remove newline character

    printf("Enter the name of the second product: ");
    fgets(product2, sizeof(product2), stdin);
    product2[strcspn(product2, "\n")] = 0; // Remove newline character

    int distance = levenshtein(product1, product2);
    printf("The Levenshtein distance between '%s' and '%s' is: %d\n", product1, product2, distance);
}

int main() {
    printf("Welcome to the Product Similarity Checker!\n");
    printf("This program calculates the Levenshtein distance between two product names.\n\n");

    char continueInput;
    do {
        compareProducts();
        printf("\nDo you want to compare another pair of products? (y/n): ");
        scanf(" %c", &continueInput);
        getchar(); // clear the newline character from buffer
    } while (continueInput == 'y' || continueInput == 'Y');

    printf("Thank you for using the Product Similarity Checker!\n");
    return 0;
}