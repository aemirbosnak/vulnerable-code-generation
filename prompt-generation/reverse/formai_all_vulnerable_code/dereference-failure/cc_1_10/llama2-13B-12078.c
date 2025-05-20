//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GRATITUDE 100
#define MIN_GRATITUDE 1

typedef struct {
    int amount;
    char message[50];
} gratitude_t;

void add_gratitude(gratitude_t *gratitudes, int amount, char *message) {
    gratitude_t new_gratitude;
    new_gratitude.amount = amount;
    strcpy(new_gratitude.message, message);
    if (gratitudes == NULL) {
        gratitudes = (gratitude_t *)malloc(sizeof(gratitude_t));
        *gratitudes = new_gratitude;
    } else {
        gratitudes = (gratitude_t *)realloc(gratitudes, (gratitudes->amount + 1) * sizeof(gratitude_t));
        gratitudes[gratitudes->amount] = new_gratitude;
    }
    gratitudes->amount++;
}

void print_gratitudes(gratitude_t *gratitudes) {
    int i;
    for (i = 0; i < gratitudes->amount; i++) {
        printf("%d. %s\n", i + 1, gratitudes[i].message);
    }
}

int main() {
    gratitude_t *gratitudes = NULL;

    // Add some gratitudes
    add_gratitude(&gratitudes, 5, "First gratitude");
    add_gratitude(&gratitudes, 10, "Second gratitude");
    add_gratitude(&gratitudes, 20, "Third gratitude");

    // Print all gratitudes
    print_gratitudes(gratitudes);

    // Free memory
    free(gratitudes);

    return 0;
}