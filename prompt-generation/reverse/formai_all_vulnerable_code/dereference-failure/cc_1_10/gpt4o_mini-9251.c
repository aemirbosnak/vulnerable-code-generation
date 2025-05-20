//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LoveLetter {
    char message[256];
    struct LoveLetter* left;  // Left child (representing the depth of emotional connection)
    struct LoveLetter* right; // Right child (representing shared memories)
} LoveLetter;

// Function to create a new love letter
LoveLetter* createLoveLetter(const char* msg) {
    LoveLetter* newLetter = (LoveLetter*)malloc(sizeof(LoveLetter));
    strncpy(newLetter->message, msg, sizeof(newLetter->message) - 1);
    newLetter->message[sizeof(newLetter->message) - 1] = '\0'; // Ensuring null-termination
    newLetter->left = NULL;
    newLetter->right = NULL;
    return newLetter;
}

// Function to add a love letter to the tree
LoveLetter* addLoveLetter(LoveLetter* root, const char* msg) {
    if (root == NULL) {
        return createLoveLetter(msg);
    }
    // Simulating the emotional depth with a simple condition
    if (strcmp(msg, root->message) < 0) {
        root->left = addLoveLetter(root->left, msg);  // left for deeper feelings
    } else {
        root->right = addLoveLetter(root->right, msg); // right for bright memories
    }
    return root;
}

// Function to visualize the love letters in-order
void visualizeLoveLetters(LoveLetter* root) {
    if (root != NULL) {
        visualizeLoveLetters(root->left);
        printf("📜 Love Letter: %s\n", root->message);
        visualizeLoveLetters(root->right);
    }
}

// Function to free memory allocated for the love letters
void freeLoveLetters(LoveLetter* root) {
    if (root != NULL) {
        freeLoveLetters(root->left);
        freeLoveLetters(root->right);
        free(root);
    }
}

// Main function
int main() {
    LoveLetter* loveTree = NULL;

    // Seeding the love letters
    loveTree = addLoveLetter(loveTree, "I cherish every moment with you.");
    loveTree = addLoveLetter(loveTree, "You complete my soul.");
    loveTree = addLoveLetter(loveTree, "Our love is a beautiful journey.");
    loveTree = addLoveLetter(loveTree, "Every glance from you lights my heart.");
    loveTree = addLoveLetter(loveTree, "In your arms, I find eternal bliss.");
    loveTree = addLoveLetter(loveTree, "You are my muse, my inspiration.");
    loveTree = addLoveLetter(loveTree, "Together, we dance under the moonlit sky.");
    
    // Visualizing the love letters
    printf("🌹 Visualizing our Love Letters:\n");
    visualizeLoveLetters(loveTree);

    // Freeing memory
    freeLoveLetters(loveTree);
    
    return 0;
}