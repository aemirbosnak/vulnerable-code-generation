//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Define the structure for a diary entry
typedef struct diary_entry {
    char title[100];
    char content[1000];
} diary_entry_t;

int main() {
    diary_entry_t entries[10]; // Array to store diary entries
    int num_entries = 0; // Number of diary entries
    
    // Prompt user for diary entry
    printf("Enter title of diary entry (max 100 characters): ");
    fgets(entries[num_entries].title, sizeof(entries[num_entries].title), stdin);
    
    // Prompt user for diary content
    printf("Enter content of diary entry (max 1000 characters): ");
    fgets(entries[num_entries].content, sizeof(entries[num_entries].content), stdin);
    
    // Add entry to array
    num_entries++;
    
    // Check if there are more entries
    while (1) {
        // Prompt user for diary entry
        printf("Enter title of diary entry (max 100 characters): ");
        fgets(entries[num_entries].title, sizeof(entries[num_entries].title), stdin);
        
        // Prompt user for diary content
        printf("Enter content of diary entry (max 1000 characters): ");
        fgets(entries[num_entries].content, sizeof(entries[num_entries].content), stdin);
        
        // Add entry to array
        num_entries++;
        
        // Check if there are more entries
        if (num_entries >= 10) {
            printf("Maximum entries reached. No more entries can be added.\n");
            break;
        }
    }
    
    // Display all entries
    printf("Diary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].title, entries[i].content);
    }
    
    // Free memory allocated to entries
    for (int i = 0; i < num_entries; i++) {
        free(entries[i].title);
        free(entries[i].content);
    }
    
    return 0;
}