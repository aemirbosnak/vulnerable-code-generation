//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Noble steed structure representing a captured image
typedef struct {
    int id;
    char name[50];
    char type[20]; // e.g., "dragon", "knight", "maiden"
} NobleSteed;

// Function to create a new noble steed
NobleSteed* createNobleSteed(int id, const char* name, const char* type) {
    NobleSteed* steed = (NobleSteed*)malloc(sizeof(NobleSteed));
    steed->id = id;
    strncpy(steed->name, name, sizeof(steed->name) - 1);
    strncpy(steed->type, type, sizeof(steed->type) - 1);
    return steed;
}

// Function to print details of the noble steed
void printNobleSteed(NobleSteed* steed) {
    printf("Behold! A noble steed of type: %s\n", steed->type);
    printf("ID: %d, Name: %s\n", steed->id, steed->name);
}

// Function to classify the noble steed
const char* classifyNobleSteed(NobleSteed* steed) {
    if (strcmp(steed->type, "dragon") == 0) {
        return "A fearsome beast of the skies!";
    } else if (strcmp(steed->type, "knight") == 0) {
        return "A valiant warrior of the realm!";
    } else if (strcmp(steed->type, "maiden") == 0) {
        return "A figure of grace and beauty!";
    } else {
        return "Unknown creature, perhaps a goblin?";
    }
}

// Spell to capture the images of noble steeds
void captureImages() {
    const char* names[] = {"Fang", "Sir Lancelot", "Lady Guinevere", "Smaug", "Gandalf"};
    const char* types[] = {"dragon", "knight", "maiden", "dragon", "wizard"};

    printf("Gathering noble steeds from the realm...\n");
    for (int i = 0; i < 5; i++) {
        NobleSteed* steed = createNobleSteed(i + 1, names[i], types[i]);
        printNobleSteed(steed);
        printf("%s\n\n", classifyNobleSteed(steed));
        free(steed);
    }
}

// The grand ceremony of classification begins
int main() {
    printf("Welcome to the Grand Image Classification of Noble Steeds!\n");
    printf("Hear ye! Hear ye! Let the images be captured and classified!\n");

    // Invocation of the image capturing spell
    captureImages();

    printf("The grand spectacle has concluded! May your roads be paved with glory!\n");
    return 0;
}