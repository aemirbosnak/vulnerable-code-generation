//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_BAGGAGE 100
#define MAX_TERMINALS 10

typedef struct {
    int id;
    int terminal;
} Baggage;

typedef struct {
    int id;
    Baggage* baggage[MAX_BAGGAGE];
    int num_bags;
} Terminal;

void arrive_at_terminal(Terminal* terminal, Baggage* baggage) {
    if (terminal->num_bags < MAX_BAGGAGE) {
        terminal->baggage[terminal->num_bags++] = baggage;
        printf("Baggage #%d has arrived at Terminal %d.\n", baggage->id, terminal->id);
    } else {
        printf("Terminal %d is at maximum capacity!\n", terminal->id);
    }
    sleep(1);
}

void handle_baggage(Terminal** terminals, int num_terminals, Baggage* baggage) {
    bool handled = false;
    while (!handled) {
        for (int i = 0; i < num_terminals; i++) {
            if (terminals[i]->id == baggage->terminal) {
                arrive_at_terminal(terminals[i], baggage);
                handled = true;
                break;
            }
        }
    }
}

int main() {
    Terminal* terminals[MAX_TERMINALS];
    for (int i = 0; i < MAX_TERMINALS; i++) {
        Terminal* terminal = (Terminal*) malloc(sizeof(Terminal));
        terminal->id = i;
        terminal->num_bags = 0;
        terminals[i] = terminal;
    }

    Baggage* baggage[MAX_BAGGAGE];
    for (int i = 0; i < MAX_BAGGAGE; i++) {
        Baggage* bg = (Baggage*) malloc(sizeof(Baggage));
        bg->id = i + 1;
        bg->terminal = rand() % MAX_TERMINALS;
        baggage[i] = bg;
    }

    // Handle baggage
    for (int i = 0; i < MAX_BAGGAGE; i++) {
        handle_baggage(terminals, MAX_TERMINALS, baggage[i]);
    }

    // Print results
    printf("\nBaggage Report:\n");
    for (int i = 0; i < MAX_TERMINALS; i++) {
        Terminal* terminal = terminals[i];
        printf("Terminal %d: %d bags\n", terminal->id, terminal->num_bags);
        for (int j = 0; j < terminal->num_bags; j++) {
            printf("  > #%d\n", terminal->baggage[j]->id);
            free(terminal->baggage[j]);
        }
        free(terminal);
    }

    return 0;
}