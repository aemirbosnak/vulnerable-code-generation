//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Character {
    char name[50];
    int age;
    char role[50];
    struct Character* next;
} Character;

Character* createCharacter(const char* name, int age, const char* role) {
    Character* newCharacter = (Character*)malloc(sizeof(Character));
    strcpy(newCharacter->name, name);
    newCharacter->age = age;
    strcpy(newCharacter->role, role);
    newCharacter->next = NULL;
    return newCharacter;
}

void addCharacter(Character** head, const char* name, int age, const char* role) {
    Character* newCharacter = createCharacter(name, age, role);
    newCharacter->next = *head;
    *head = newCharacter;
    printf("Added character: %s, Age: %d, Role: %s\n", name, age, role);
}

void displayCharacters(Character* head) {
    if (head == NULL) {
        printf("No characters in the story.\n");
        return;
    }
    printf("Characters in the story:\n");
    Character* current = head;
    while (current != NULL) {
        printf("Name: %s, Age: %d, Role: %s\n", current->name, current->age, current->role);
        current = current->next;
    }
}

Character* searchCharacter(Character* head, const char* name) {
    Character* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void deleteCharacter(Character** head, const char* name) {
    Character* current = *head;
    Character* previous = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Character '%s' not found.\n", name);
        return;
    }

    if (previous == NULL) {
        *head = current->next; // Deleting the head
    } else {
        previous->next = current->next; // Bypass the current node
    }
    free(current);
    printf("Deleted character: %s\n", name);
}

void cleanUp(Character* head) {
    Character* current = head;
    Character* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Character* story = NULL;
    int choice;
    char name[50];
    int age;
    char role[50];

    do {
        printf("\nCharacter Story Management\n");
        printf("1. Add Character\n");
        printf("2. Display Characters\n");
        printf("3. Search Character\n");
        printf("4. Delete Character\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                printf("Enter role: ");
                scanf("%s", role);
                addCharacter(&story, name, age, role);
                break;
            case 2:
                displayCharacters(story);
                break;
            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                Character* found = searchCharacter(story, name);
                if (found) {
                    printf("Found Character: Name: %s, Age: %d, Role: %s\n", found->name, found->age, found->role);
                } else {
                    printf("Character '%s' not found.\n", name);
                }
                break;
            case 4:
                printf("Enter name to delete: ");
                scanf("%s", name);
                deleteCharacter(&story, name);
                break;
            case 5:
                cleanUp(story);
                printf("Exiting the character management system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 5);
    
    return 0;
}