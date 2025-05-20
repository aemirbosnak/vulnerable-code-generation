//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A curious and curiouser representation of a C structure, oh my!
typedef struct {
    int a; // Alice's appetite
    int b; // Bob's appetite
    int c; // Curious case of chocolate cravings
} curious_cravings;

// A greedy algorithm to distribute chocolate, hmmm...
curious_cravings distribute_chocolate(int n, int *chocolates) {
    // Initialize curious cravings
    curious_cravings cravings = {0, 0, 0};

    // Alice and Bob get their first chocolates
    cravings.a = chocolates[0];
    cravings.b = chocolates[1];

    // Let's get curious about the rest
    for (int i = 2; i < n; i++) {
        // If Alice's cravings are less than Bob's...
        if (cravings.a < cravings.b) {
            // ...she takes a bite
            cravings.a += chocolates[i];
        } else {
            // Otherwise, it's Bob's turn
            cravings.b += chocolates[i];
        }

        // But what about our curious cravings?
        cravings.c += abs(chocolates[i] - chocolates[i - 1]);
    }

    // Return the curious cravings
    return cravings;
}

// Let's get some curious inputs
int main() {
    // A curious number of chocolates
    int n;
    scanf("%d", &n);

    // An even more curious array of chocolates
    int chocolates[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &chocolates[i]);
    }

    // Distribute the chocolate and satisfy curious cravings
    curious_cravings cravings = distribute_chocolate(n, chocolates);

    // Print the curious results
    printf("Alice's cravings: %d\n", cravings.a);
    printf("Bob's cravings: %d\n", cravings.b);
    printf("Curious cravings: %d\n", cravings.c);

    return 0;
}