//FormAI DATASET v1.0 Category: Binary search trees ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
    } else if (data < ((*root)->data)) {
        insert(&((*root)->left), data);
    } else {
        insert(&((*root)->right), data);
    }
}

int search(Node* root, int data) {
    if (root == NULL) {
        return 0;
    } else if (root->data == data) {
        return 1;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

void printTree(Node* root) {
    if (root != NULL) {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}

void playGame() {
    int numGuesses = 0;
    int numToGuess;
    Node* root = NULL;
    
    // Generate BST of random numbers from 1-100
    srand(time(NULL));
    for (int i = 0; i < 50; i++) {
        int num = (rand() % 100) + 1;
        insert(&root, num);
    }
    printf("I'm thinking of a number between 1-100. Can you guess what it is?\n");

    // Player has up to 10 guesses
    while (numGuesses < 10) {
        int guess;
        scanf("%d", &guess);
        if (search(root, guess)) {
            printf("Congratulations, you guessed the number in %d tries!\n", numGuesses+1);
            return;
        } else {
            printf("Incorrect! Guess again.\n");
            numGuesses++;
        }
    }
    printf("Sorry, you ran out of guesses. The number was %d.\n", numToGuess);
}

int main() {
    char playAgain = 'y';
    while (playAgain == 'y') {
        playGame();
        printf("Would you like to play again? (y/n)\n");
        scanf(" %c", &playAgain);
    }
    printf("Goodbye!\n");
    return 0;
}