//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to destroy a string (simulate a desolate wasteland)
void destroy_string(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = ' '; // wipe out the string like the world was wiped out
    }
}

// Function to concatenate two strings (like people joining forces in the apocalypse)
char* concat_strings(char *dest, const char *src) {
    strcat(dest, src); 
    return dest;
}

// Function to reverse a string (reflecting the backward nature of survival)
void reverse_string(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to convert string to uppercase (as if shouting in the silence of the ruins)
void to_uppercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

// Function to simulate survival in a wasteland by merging two 'survivor' strings
char* survive_in_wasteland(char *name1, char *name2) {
    // Calculate needed memory
    int len1 = strlen(name1);
    int len2 = strlen(name2);
    char *survivor = malloc(len1 + len2 + 2); // +1 for space, +1 for null terminator
    if (!survivor) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    
    strcpy(survivor, name1);
    strcat(survivor, " ");
    strcat(survivor, name2);
    
    return survivor;
}

int main() {
    // The names of survivors on their quest
    char name1[50];
    char name2[50];

    printf("In the ashes of a fallen civilization, the names of the survivors endure...\n");
    printf("Enter the name of the first survivor: ");
    fgets(name1, sizeof(name1), stdin);
    strtok(name1, "\n"); // Remove newline character

    printf("Enter the name of the second survivor: ");
    fgets(name2, sizeof(name2), stdin);
    strtok(name2, "\n"); // Remove newline character

    // Show the names before manipulation
    printf("Survivors' names: %s, %s\n", name1, name2);

    // Give a warning if they need to be combined for emotional support
    char *survivor = survive_in_wasteland(name1, name2);
    printf("Together, their new name will be: %s\n", survivor);

    // In the silence, they want to shout their names to warn off dangers
    to_uppercase(survivor);
    printf("SHOUTING! NEW NAME OF SURVIVOR: %s\n", survivor);

    // Destroy unnecessary parts of the name in a symbolic act of letting go
    destroy_string(survivor);
    printf("After destruction, what's left? : '%s'\n", survivor);

    // Restore the name by concatenating them back with remnants of hope
    printf("Restoring the names...\n");
    concat_strings(survivor, name1);
    strcat(survivor, " ");
    concat_strings(survivor, name2);
    printf("Restored names: %s\n", survivor);

    // Reflect on their journey by reversing the restored name
    reverse_string(survivor);
    printf("In reflection, reversed names: %s\n", survivor);
    
    // Free the allocated survivor string
    free(survivor);

    return 0;
}