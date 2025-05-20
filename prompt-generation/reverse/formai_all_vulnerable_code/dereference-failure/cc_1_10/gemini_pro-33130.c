//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char* name;
    char* description;
    struct node* north;
    struct node* south;
    struct node* east;
    struct node* west;
} node;

node* createNode(char* name, char* description){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->name = (char*)malloc(strlen(name) + 1);
    strcpy(newNode->name, name);
    newNode->description = (char*)malloc(strlen(description) + 1);
    strcpy(newNode->description, description);
    newNode->north = NULL;
    newNode->south = NULL;
    newNode->east = NULL;
    newNode->west = NULL;
    return newNode;
}

void printNode(node* n){
    printf("%s\n", n->name);
    printf("%s\n", n->description);
}

void printDirections(node* n){
    if(n->north != NULL){
        printf("North: %s\n", n->north->name);
    }
    if(n->south != NULL){
        printf("South: %s\n", n->south->name);
    }
    if(n->east != NULL){
        printf("East: %s\n", n->east->name);
    }
    if(n->west != NULL){
        printf("West: %s\n", n->west->name);
    }
}

int main(){
    // Create the nodes
    node* n1 = createNode("Node 1", "This is node 1.");
    node* n2 = createNode("Node 2", "This is node 2.");
    node* n3 = createNode("Node 3", "This is node 3.");
    node* n4 = createNode("Node 4", "This is node 4.");

    // Connect the nodes
    n1->north = n2;
    n2->south = n1;
    n2->east = n3;
    n3->west = n2;
    n3->north = n4;
    n4->south = n3;

    // Start the player in node 1
    node* current = n1;

    // Main game loop
    while(1){
        // Print the current node
        printNode(current);
        // Print the available directions
        printDirections(current);

        // Get the player's input
        char input[20];
        printf("> ");
        scanf("%s", input);

        // Move the player
        if(strcmp(input, "north") == 0){
            if(current->north != NULL){
                current = current->north;
            }
            else{
                printf("You cannot go that way.\n");
            }
        }
        else if(strcmp(input, "south") == 0){
            if(current->south != NULL){
                current = current->south;
            }
            else{
                printf("You cannot go that way.\n");
            }
        }
        else if(strcmp(input, "east") == 0){
            if(current->east != NULL){
                current = current->east;
            }
            else{
                printf("You cannot go that way.\n");
            }
        }
        else if(strcmp(input, "west") == 0){
            if(current->west != NULL){
                current = current->west;
            }
            else{
                printf("You cannot go that way.\n");
            }
        }
        else if(strcmp(input, "quit") == 0){
            break;
        }
    }

    // Free the nodes
    free(n1);
    free(n2);
    free(n3);
    free(n4);

    return 0;
}