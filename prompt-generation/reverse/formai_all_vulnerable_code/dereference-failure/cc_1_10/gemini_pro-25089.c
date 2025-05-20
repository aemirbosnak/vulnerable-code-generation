//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The Adventure of the Memory Leak

int main() {
    // Watson, the housekeeper, is always keeping track of the manor's finances.
    int *finances = (int *)malloc(sizeof(int));
    *finances = 1000;

    // But Watson is a forgetful soul, and sometimes he forgets to free the memory he has allocated.
    // Moriarty, the criminal mastermind, takes advantage of this and exploits the memory leak.

    // Moriarty creates a list of fake expenses to trick Watson into spending the manor's money.
    char **expenses = (char **)calloc(100, sizeof(char *));
    for (int i = 0; i < 100; i++) {
        expenses[i] = (char *)malloc(100);
        sprintf(expenses[i], "Expense %d", i);
    }

    // Moriarty then tricks Watson into processing the fake expenses, one by one.
    for (int i = 0; i < 100; i++) {
        printf("%s\n", expenses[i]);
    }

    // Watson, still oblivious to the leak, continues to diligently manage the manor's finances.
    *finances -= 100;

    // As Moriarty's plan unfolds, Watson realizes that the manor's finances are dwindling.
    printf("My dear Watson, it appears that our finances have taken a hit.\n");

    // Holmes, the detective, arrives to investigate the case and quickly uncovers the memory leak.
    printf("Ah, Watson, it seems you have been the victim of a cunning ploy. Moriarty has exploited the memory leak to trick you into spending the manor's money.\n");

    // Holmes frees the memory that was leaked and restores the manor's finances.
    for (int i = 0; i < 100; i++) {
        free(expenses[i]);
    }
    free(expenses);
    free(finances);

    // Holmes then warns Watson to be more careful in the future and to always free the memory he allocates.
    printf("Watson, you must always be vigilant in managing the manor's finances. Remember, a memory leak can be a dangerous thing.\n");

    // Watson, grateful for Holmes' help, vows to be more careful in the future.
    printf("Thank you, Holmes. I will be sure to be more diligent in managing the manor's finances.\n");

    return 0;
}