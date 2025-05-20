//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Declare a sorcerer structure to hold RAM information
typedef struct Sorcerer {
    char *name;
    int memory_in_use; // Memory used by the sorcerer's spell
    int total_memory;   // Total memory available in the kingdom
} Sorcerer;

// Function to summon RAM information
void summon_ram_info(Sorcerer *sorcerer) {
    FILE *fp;
    char buffer[256];
    
    // Cast the spell to gather information from the memory realm
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to summon RAM info");
        exit(EXIT_FAILURE);
    }

    // Read the total memory available in the kingdom
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (sscanf(buffer, "MemTotal: %d kB", &sorcerer->total_memory) == 1) {
            sorcerer->total_memory /= 1024; // Convert to MB
            break;
        }
    }
    
    fclose(fp);
}

// Function to cast the memory spell
void cast_memory_spell(Sorcerer *sorcerer) {
    printf("Gather around, brave villagers! The Great Sorcerer %s is here to reveal the secrets of the RAM!\n", sorcerer->name);
    
    // The sorcerer conjures up spells to manipulate the memory
    sorcerer->memory_in_use = rand() % sorcerer->total_memory; // Simulate used memory
    
    printf("Total available memory in the kingdom: %d MB\n", sorcerer->total_memory);
    printf("Memory currently in use by the sorcerer: %d MB\n", sorcerer->memory_in_use);
    
    // Summon the memory left for the villagers
    int memory_left = sorcerer->total_memory - sorcerer->memory_in_use;
    printf("Fear not! The remaining memory for the kingdom is: %d MB\n", memory_left);
}

// Function to prepare the mighty sorcerer
void prepare_sorcerer(Sorcerer *sorcerer, const char *name) {
    sorcerer->name = (char *)malloc(strlen(name) + 1);
    strcpy(sorcerer->name, name);
    sorcerer->memory_in_use = 0;
    sorcerer->total_memory = 0;
}

// Function to clean up the sorcerer's magic
void clean_sorcerer(Sorcerer *sorcerer) {
    free(sorcerer->name);
}

int main() {
    // Let us introduce the great sorcerer
    Sorcerer grand_sorcerer;
    prepare_sorcerer(&grand_sorcerer, "Gandalf the Grey");
    
    // Summon RAM information before casting the spell
    summon_ram_info(&grand_sorcerer);
    
    // Cast the memory spell and display grand knowledge
    cast_memory_spell(&grand_sorcerer);

    // Clean up after the sorcerer's magic
    clean_sorcerer(&grand_sorcerer);
    
    return 0;
}