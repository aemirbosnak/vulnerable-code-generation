//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a player structure
typedef struct player {
    char name[20];
    int score;
    struct player *left;
    struct player *right;
} player;

// Create a new player
player *create_player(char *name, int score) {
    player *new_player = malloc(sizeof(player));
    strcpy(new_player->name, name);
    new_player->score = score;
    new_player->left = NULL;
    new_player->right = NULL;
    return new_player;
}

// Insert a player into a binary search tree
player *insert_player(player *root, player *new_player) {
    if (root == NULL) {
        return new_player;
    } else if (strcmp(new_player->name, root->name) < 0) {
        root->left = insert_player(root->left, new_player);
    } else if (strcmp(new_player->name, root->name) > 0) {
        root->right = insert_player(root->right, new_player);
    }
    return root;
}

// Find a player in a binary search tree
player *find_player(player *root, char *name) {
    if (root == NULL) {
        return NULL;
    } else if (strcmp(name, root->name) == 0) {
        return root;
    } else if (strcmp(name, root->name) < 0) {
        return find_player(root->left, name);
    } else if (strcmp(name, root->name) > 0) {
        return find_player(root->right, name);
    }
    return NULL;
}

// Print a binary search tree
void print_tree(player *root) {
    if (root != NULL) {
        print_tree(root->left);
        printf("%s (%d)\n", root->name, root->score);
        print_tree(root->right);
    }
}

// Main function
int main() {
    // Create the root of the binary search tree
    player *root = NULL;

    // Insert some players into the binary search tree
    root = insert_player(root, create_player("Alice", 100));
    root = insert_player(root, create_player("Bob", 200));
    root = insert_player(root, create_player("Charlie", 300));
    root = insert_player(root, create_player("Dave", 400));
    root = insert_player(root, create_player("Eve", 500));

    // Print the binary search tree
    print_tree(root);

    // Find a player in the binary search tree
    player *found_player = find_player(root, "Dave");
    if (found_player != NULL) {
        printf("Found player: %s (%d)\n", found_player->name, found_player->score);
    } else {
        printf("Player not found.\n");
    }

    return 0;
}