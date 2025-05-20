//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int weight;
} Baggage;

typedef struct {
    Baggage* baggage;
    int size;
} BaggageList;

int main() {
    BaggageList* list = malloc(sizeof(BaggageList));
    list->size = 0;
    list->baggage = NULL;

    BaggageList* newList = malloc(sizeof(BaggageList));
    newList->size = 0;
    newList->baggage = NULL;

    while (1) {
        printf("Enter the name of the baggage : ");
        scanf("%s", list->baggage[list->size].name);
        printf("Enter the weight of the baggage : ");
        scanf("%d", &list->baggage[list->size].weight);
        list->size++;

        if (list->size == 10) {
            printf("Maximum baggage limit reached. Please remove some baggage.\n");
            printf("Current list of baggage: \n");
            for (int i = 0; i < list->size; i++) {
                printf("%s - %d kg\n", list->baggage[i].name, list->baggage[i].weight);
            }
            printf("Do you want to continue (Y/N)? ");
            char input;
            scanf(" %c", &input);
            if (input!= 'Y') {
                break;
            }
        }

        for (int i = 0; i < list->size; i++) {
            Baggage baggage = {.name = list->baggage[i].name,.weight = list->baggage[i].weight };
            newList->size++;
            newList->baggage = realloc(newList->baggage, sizeof(Baggage) * newList->size);
            newList->baggage[newList->size - 1] = baggage;
        }
        printf("Baggage added to the new list. \n");

        for (int i = 0; i < newList->size; i++) {
            printf("Name: %s, Weight: %d kg\n", newList->baggage[i].name, newList->baggage[i].weight);
        }
    }

    free(list->baggage);
    free(list);
    return 0;
}