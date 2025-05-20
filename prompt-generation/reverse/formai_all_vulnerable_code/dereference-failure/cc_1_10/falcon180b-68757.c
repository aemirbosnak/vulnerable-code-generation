//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 1000
#define MAX_CONSPIRACY_COMPONENTS 20
#define MAX_CONSPIRATORS 100

typedef struct {
    char name[50];
    int involvement;
} Conspirator;

typedef struct {
    char *description;
    int num_components;
    Conspirator *conspirators;
} Conspiracy;

void generate_conspiracy(Conspiracy *conspiracy) {
    int i;
    int num_components = rand() % MAX_CONSPIRACY_COMPONENTS + 1;

    conspiracy->num_components = num_components;
    conspiracy->conspirators = (Conspirator *) malloc(sizeof(Conspirator) * num_components);

    for (i = 0; i < num_components; i++) {
        strcpy(conspiracy->conspirators[i].name, "Conspirator ");
        sprintf(&conspiracy->conspirators[i].name[strlen(conspiracy->conspirators[i].name)], "%d", i + 1);
        conspiracy->conspirators[i].involvement = rand() % 3;
    }

    strcpy(conspiracy->description, "The ");
    for (i = 0; i < num_components; i++) {
        switch (conspiracy->conspirators[i].involvement) {
            case 0:
                strcat(conspiracy->description, "unwitting ");
                break;
            case 1:
                strcat(conspiracy->description, "coerced ");
                break;
            case 2:
                strcat(conspiracy->description, "willing ");
                break;
        }
        strcat(conspiracy->description, conspiracy->conspirators[i].name);
        if (i < num_components - 1) {
            strcat(conspiracy->description, ", ");
        }
    }
    strcat(conspiracy->description, " Conspiracy");
}

void print_conspiracy(Conspiracy *conspiracy) {
    printf("Conspirators: %s\n", conspiracy->description);
}

int main() {
    srand(time(NULL));

    Conspiracy conspiracy;
    generate_conspiracy(&conspiracy);
    print_conspiracy(&conspiracy);

    return 0;
}