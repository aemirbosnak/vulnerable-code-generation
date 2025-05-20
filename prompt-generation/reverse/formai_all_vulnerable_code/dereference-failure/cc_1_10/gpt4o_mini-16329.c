//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_BAGS 10

typedef struct {
    int id;
    char *owner;
} Bag;

typedef struct {
    Bag *bags[MAX_BAGS];
    int count;
} BaggageHandler;

void initBaggageHandler(BaggageHandler *handler) {
    handler->count = 0;
}

void addBag(BaggageHandler *handler, int id, const char *owner) {
    if (handler->count < MAX_BAGS) {
        Bag *newBag = malloc(sizeof(Bag));
        newBag->id = id;
        newBag->owner = (char*) owner;
        handler->bags[handler->count++] = newBag;
    } else {
        printf("Alas! No more bags can be added, the baggage carousel doth overflow.\n");
    }
}

void removeBag(BaggageHandler *handler, int id) {
    for (int i = 0; i < handler->count; i++) {
        if (handler->bags[i]->id == id) {
            printf("Oh radiant Juliet! Thy bag with ID %d has departed.\n", id);
            free(handler->bags[i]);
            handler->bags[i] = handler->bags[handler->count - 1];
            handler->count--;
            return;
        }
    }
    printf("Wherefore art thou, my sweet bag with ID %d? Alas, I cannot find thee!\n", id);
}

void showBags(BaggageHandler *handler) {
    printf("Behold, the bags that remain:\n");
    for (int i = 0; i < handler->count; i++) {
        printf("Bag ID: %d, Owned By: %s\n", handler->bags[i]->id, handler->bags[i]->owner);
    }
}

void simulateBaggageHandling() {
    BaggageHandler handler;
    initBaggageHandler(&handler);

    addBag(&handler, 1, "Romeo");
    sleep(1);
    addBag(&handler, 2, "Juliet");
    sleep(1);
    addBag(&handler, 3, "Mercutio");
    sleep(1);
    addBag(&handler, 4, "Benvolio");
    sleep(1);

    showBags(&handler);
    printf("A tragedy unfolds!\n");
    sleep(1);

    removeBag(&handler, 2);  // Juliet's bag departs tragically
    showBags(&handler);
    sleep(1);

    removeBag(&handler, 1);  // Romeo follows suite
    showBags(&handler);
    sleep(1);

    printf("Fear not, for though our lovers be estranged, their memories linger.\n");
    sleep(1);
    
    // Cleaning up remaining bags
    while (handler.count > 0) {
        removeBag(&handler, handler.bags[0]->id);
    }
}

int main() {
    printf("Welcome to the tragic Baggage Handling System of Verona Airport!\n");
    simulateBaggageHandling();
    printf("Thus ends our tale of loss and love in the realm of baggage.\n");
    return 0;
}