//FormAI DATASET v1.0 Category: Data structures visualization ; Style: curious
// Welcome to the World of C Data Structures Visualization!
// In this program, we will create a linked list of animals
// and display them in a fun and interactive way!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Define a node structure for our linked list
typedef struct AnimalNode {
    char name[32];
    char animalType[32];
    struct AnimalNode* next;
} AnimalNode;

// Function to create a new animal node
AnimalNode* createAnimalNode(char* name, char* animalType) {
    AnimalNode* newNode = (AnimalNode*)malloc(sizeof(AnimalNode));
    strcpy(newNode->name, name);
    strcpy(newNode->animalType, animalType);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new animal node at the end of the list
AnimalNode* insertAnimalNode(AnimalNode* head, AnimalNode* newNode) {
    if (head == NULL) {
        head = newNode;
    } else {
        AnimalNode* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    return head;
}

// Function to print the linked list of animals
void printAnimalList(AnimalNode* head) {
    AnimalNode* curr = head;
    while (curr != NULL) {
        printf("%s the %s\n", curr->name, curr->animalType);
        curr = curr->next;
    }
}

int main() {
    // Create some initial animals for our linked list
    AnimalNode* lionNode = createAnimalNode("Simba", "lion");
    AnimalNode* tigerNode = createAnimalNode("Tony", "tiger");
    AnimalNode* bearNode = createAnimalNode("Yogi", "bear");
    AnimalNode* elephantNode = createAnimalNode("Dumbo", "elephant");
    
    // Insert the initial animals into the linked list
    AnimalNode* head = NULL;
    head = insertAnimalNode(head, lionNode);
    head = insertAnimalNode(head, tigerNode);
    head = insertAnimalNode(head, bearNode);
    head = insertAnimalNode(head, elephantNode);
    
    // Print the initial list of animals
    printf("\n--- Initial List of Animals ---\n");
    printAnimalList(head);
    
    // Let's add some more animals to our list!
    AnimalNode* giraffeNode = createAnimalNode("Melman", "giraffe");
    AnimalNode* kangarooNode = createAnimalNode("Kang", "kangaroo");
    AnimalNode* zebraNode = createAnimalNode("Marty", "zebra");
    AnimalNode* hippoNode = createAnimalNode("Gloria", "hippo");
    
    // Insert the new animals into the linked list
    head = insertAnimalNode(head, giraffeNode);
    head = insertAnimalNode(head, kangarooNode);
    head = insertAnimalNode(head, zebraNode);
    head = insertAnimalNode(head, hippoNode);
    
    // Clear the console screen
    system("clear");
    
    // Now let's print the list of animals with some fun animations!
    printf("\n--- List of Animals ---\n");
    while (1) {
        // Move the cursor to the top left corner of the screen
        printf("\033[0;0H");
        
        // Loop over the list of animals and print each one with a different color and animation
        AnimalNode* curr = head;
        int color = 0;
        while (curr != NULL) {
            // Set the color of the text
            switch (color) {
                case 0:
                    printf("\033[0;31m"); // red
                    break;
                case 1:
                    printf("\033[0;32m"); // green
                    break;
                case 2:
                    printf("\033[0;33m"); // yellow
                    break;
                case 3:
                    printf("\033[0;34m"); // blue
                    break;
                case 4:
                    printf("\033[0;35m"); // magenta
                    break;
                case 5:
                    printf("\033[0;36m"); // cyan
                    break;
            }
            
            // Print the animal name with an animation
            int i;
            for (i = 0; i < 10; i++) {
                printf("%s ", curr->name);
                fflush(stdout);
                usleep(100000);
                printf("\b \b");
                fflush(stdout);
                usleep(100000);
            }
            
            // Move to the next line and reset the color
            printf("\033[0m\n");
            curr = curr->next;
            color = (color + 1) % 6;
        }
        
        // Wait for a short time before printing the list again
        usleep(500000);
    }
    
    return 0;
}