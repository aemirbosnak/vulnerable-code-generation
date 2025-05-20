//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PUNKERS 10
#define NAME_LEN 20
#define MAX_GEAR 5

typedef enum {
    GUN,
    TECH,
    ARMOR,
    DRUG,
    GADGET
} GearType;

typedef struct {
    GearType type;
    char name[NAME_LEN];
    int level;
} Gear;

typedef struct {
    char name[NAME_LEN];
    int streetCred;
    Gear *gear[MAX_GEAR];
    int gearCount;
} Punk;

void addGear(Punk *punk, GearType type, const char *name, int level) {
    if (punk->gearCount < MAX_GEAR) {
        punk->gear[punk->gearCount] = (Gear *)malloc(sizeof(Gear));
        punk->gear[punk->gearCount]->type = type;
        strncpy(punk->gear[punk->gearCount]->name, name, NAME_LEN);
        punk->gear[punk->gearCount]->level = level;
        punk->gearCount++;
    } else {
        printf("Gear limit reached for %s!\n", punk->name);
    }
}

void removeGear(Punk *punk, int index) {
    if (index < punk->gearCount && index >= 0) {
        free(punk->gear[index]);
        for (int i = index; i < punk->gearCount - 1; i++) {
            punk->gear[i] = punk->gear[i + 1];
        }
        punk->gearCount--;
        punk->gear[punk->gearCount] = NULL; // Nullify last pointer
    } else {
        printf("Invalid gear index for %s!\n", punk->name);
    }
}

void printPunkInfo(Punk *punk) {
    printf("Punk Name: %s\n", punk->name);
    printf("Street Cred: %d\n", punk->streetCred);
    printf("Gears:\n");
    for (int i = 0; i < punk->gearCount; i++) {
        printf("  %d. [%s] %s (Level %d)\n", i + 1, 
               punk->gear[i]->type == GUN ? "Gun" : punk->gear[i]->type == TECH ? "Tech" :
               punk->gear[i]->type == ARMOR ? "Armor" : punk->gear[i]->type == DRUG ? "Drug" : "Gadget",
               punk->gear[i]->name, punk->gear[i]->level);
    }
    printf("\n");
}

int main() {
    Punk *punkers[MAX_PUNKERS];
    int punkCount = 0;

    // Populate punks
    while (punkCount < MAX_PUNKERS) {
        punkers[punkCount] = (Punk *)malloc(sizeof(Punk));
        snprintf(punkers[punkCount]->name, NAME_LEN, "Punkster_%d", punkCount + 1);
        punkers[punkCount]->streetCred = rand() % 100;
        punkers[punkCount]->gearCount = 0;

        // Add random gears
        addGear(punkers[punkCount], GUN, "Plasma Pistol", rand() % 5 + 1);
        addGear(punkers[punkCount], TECH, "Holo-Scanner", rand() % 5 + 1);
        punkCount++;
    }

    // Print all punk info
    for (int i = 0; i < punkCount; i++) {
        printPunkInfo(punkers[i]);
    }

    // Example of removing gear and releasing memory
    printf("Removing gear from first punk...\n");
    removeGear(punkers[0], 0); // Remove first gear
    printPunkInfo(punkers[0]);

    // Cleanup memory before exiting
    for (int i = 0; i < punkCount; i++) {
        for (int j = 0; j < punkers[i]->gearCount; j++) {
            free(punkers[i]->gear[j]);
        }
        free(punkers[i]);
    }

    return 0;
}