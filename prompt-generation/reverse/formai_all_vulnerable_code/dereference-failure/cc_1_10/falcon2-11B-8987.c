//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a haunted house environment
void create_haunted_house(char* name, int size) {
    int i;
    char* house[size];

    // Create the haunted house environment
    for (i = 0; i < size; i++) {
        house[i] = (char*) malloc(size * sizeof(char));
        strcpy(house[i], " ");
    }

    // Print the haunted house environment
    printf("%s is a %dx%dx%dx%d haunted house with %d rooms\n", name, size, size, size, size, size);
    printf("The first room is in the ");
    for (i = 0; i < size; i++) {
        printf("%s ", house[i]);
    }
    printf("corner.\n");
    printf("The second room is in the ");
    for (i = 0; i < size; i++) {
        printf("%s ", house[i]);
    }
    printf("corner.\n");
    printf("The third room is in the ");
    for (i = 0; i < size; i++) {
        printf("%s ", house[i]);
    }
    printf("corner.\n");
    printf("The fourth room is in the ");
    for (i = 0; i < size; i++) {
        printf("%s ", house[i]);
    }
    printf("corner.\n");
    printf("The fifth room is in the ");
    for (i = 0; i < size; i++) {
        printf("%s ", house[i]);
    }
    printf("corner.\n");
}

int main() {
    // Create a haunted house environment
    char* name = "Haunted House";
    int size = 5;
    create_haunted_house(name, size);

    return 0;
}