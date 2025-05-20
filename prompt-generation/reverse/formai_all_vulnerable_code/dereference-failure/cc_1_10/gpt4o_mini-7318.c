//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 100
#define MAX_DESCRIPTION 255
#define MAX_DREAMS 50

typedef struct {
    char title[MAX_TITLE];
    char description[MAX_DESCRIPTION];
    int id;
} Dream;

Dream *dreams[MAX_DREAMS];
int dream_count = 0;

void addDream() {
    if (dream_count >= MAX_DREAMS) {
        printf("Dream journal is full!\n");
        return;
    }
    Dream *new_dream = (Dream *)malloc(sizeof(Dream));
    printf("Enter dream title: ");
    scanf(" %[^\n]", new_dream->title);
    printf("Enter dream description: ");
    scanf(" %[^\n]", new_dream->description);
    new_dream->id = dream_count;

    dreams[dream_count++] = new_dream;
    printf("Dream added successfully!\n");
}

void viewDreams() {
    if (dream_count == 0) {
        printf("Dream journal is empty!\n");
        return;
    }
    printf("\n--- Dream Journal ---\n");
    for (int i = 0; i < dream_count; i++) {
        printf("ID: %d\n", dreams[i]->id);
        printf("Title: %s\n", dreams[i]->title);
        printf("Description: %s\n\n", dreams[i]->description);
    }
}

void modifyDream() {
    int id;
    printf("Enter dream ID to modify: ");
    scanf("%d", &id);
    
    if (id < 0 || id >= dream_count) {
        printf("Invalid ID!\n");
        return;
    }
    
    printf("Enter new title: ");
    scanf(" %[^\n]", dreams[id]->title);
    printf("Enter new description: ");
    scanf(" %[^\n]", dreams[id]->description);
    printf("Dream updated successfully!\n");
}

void deleteDream() {
    int id;
    printf("Enter dream ID to delete: ");
    scanf("%d", &id);
    
    if (id < 0 || id >= dream_count) {
        printf("Invalid ID!\n");
        return;
    }

    free(dreams[id]); // Release memory
    for (int i = id; i < dream_count - 1; i++) {
        dreams[i] = dreams[i + 1]; // Shift dreams to fill the gap
    }
    dreams[--dream_count] = NULL; // Nullify the last element
    printf("Dream deleted successfully!\n");
}

void displayMenu() {
    printf("\n--- Dream Journal Menu ---\n");
    printf("1. Add Dream\n");
    printf("2. View Dreams\n");
    printf("3. Modify Dream\n");
    printf("4. Delete Dream\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    do {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addDream(); break;
            case 2: viewDreams(); break;
            case 3: modifyDream(); break;
            case 4: deleteDream(); break;
            case 5: printf("Thank you for using the Dream Journal!\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    
    // Cleanup remaining dreams
    for (int i = 0; i < dream_count; i++) {
        free(dreams[i]);
    }

    return 0;
}