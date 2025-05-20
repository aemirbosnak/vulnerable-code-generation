//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the cyberpunk data structure
struct cyberpunk {
    char *name;
    int age;
    char *occupation;
    char *cybernetics;
    char *skills;
};

// Create a new cyberpunk
struct cyberpunk *create_cyberpunk(char *name, int age, char *occupation, char *cybernetics, char *skills) {
    struct cyberpunk *cyber = malloc(sizeof(struct cyberpunk));
    cyber->name = name;
    cyber->age = age;
    cyber->occupation = occupation;
    cyber->cybernetics = cybernetics;
    cyber->skills = skills;
    return cyber;
}

// Print a cyberpunk's data
void print_cyberpunk(struct cyberpunk *cyber) {
    printf("Name: %s\n", cyber->name);
    printf("Age: %d\n", cyber->age);
    printf("Occupation: %s\n", cyber->occupation);
    printf("Cybernetics: %s\n", cyber->cybernetics);
    printf("Skills: %s\n", cyber->skills);
}

// Free a cyberpunk's memory
void free_cyberpunk(struct cyberpunk *cyber) {
    free(cyber->name);
    free(cyber->occupation);
    free(cyber->cybernetics);
    free(cyber->skills);
    free(cyber);
}

int main() {
    // Create a few cyberpunks
    struct cyberpunk *cyber1 = create_cyberpunk("Neo", 30, "Hacker", "Cybernetic eyes and arms", "Hacking, coding, martial arts");
    struct cyberpunk *cyber2 = create_cyberpunk("Trinity", 25, "Courier", "Cybernetic legs and lungs", "Running, shooting, stealth");
    struct cyberpunk *cyber3 = create_cyberpunk("Morpheus", 40, "Mentor", "Cybernetic brain and nervous system", "Philosophy, leadership, martial arts");

    // Print the cyberpunk's data
    print_cyberpunk(cyber1);
    print_cyberpunk(cyber2);
    print_cyberpunk(cyber3);

    // Free the cyberpunk's memory
    free_cyberpunk(cyber1);
    free_cyberpunk(cyber2);
    free_cyberpunk(cyber3);

    return 0;
}