//FormAI DATASET v1.0 Category: Spell checking ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct Node {
    char* word;
    struct Node* next;
} Node;

Node* createNode(char* word) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->word = (char*) malloc(strlen(word) + 1);
    strcpy(node->word, word);
    node->next = NULL;
    return node;
}

void insert(Node** head, char* word) {
    Node* newNode = createNode(word);
    newNode->next = *head;
    *head = newNode;
}

bool search(Node* head, char* word) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0)
            return true;
        current = current->next;
    }
    return false;
}

void printList(Node* head) {
    Node* current = head;
    printf("Misspelled words: ");
    while (current != NULL) {
        printf("%s ", current->word);
        current = current->next;
    }
    printf("\n");
}

int main() {
    char dictionary[100][15] = {"hello", "world", "programming", "computer", "science", "engineer", "mathematics", "physics", 
                                "chemistry", "biology", "history", "geography", "literature", "art", "music", "film", "politics", 
                                "economics", "business", "finance", "medicine", "law", "philosophy", "psychology", "sociology", 
                                "anthropology", "linguistics", "architecture", "environment", "energy"};
    Node* misspelledWords = NULL;
    bool isMultiplayer = false;
    int numberOfPlayers = 1;
    printf("Welcome to the Spell Checking Game!\n");
    while (true) {
        printf("Do you want to play the Multiplayer mode? (Y/N): ");
        char choice[2];
        fgets(choice, 2, stdin);
        if (tolower(choice[0]) == 'y') {
            isMultiplayer = true;
            printf("Enter the number of players (2-4): ");
            scanf("%d", &numberOfPlayers);
            getchar(); // remove the newline character
            printf("The game will start with %d players.\n", numberOfPlayers);
            break;
        } else if (tolower(choice[0]) == 'n') {
            printf("The game will start with one player.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    int score[numberOfPlayers];
    for (int i = 0; i < numberOfPlayers; i++) {
        score[i] = 0;
    }
    while (true) {
        char input[100];
        printf("Enter a sentence: ");
        fgets(input, 100, stdin);
        char* word = strtok(input, " ,.?!-\n");
        while (word != NULL) {
            bool isCorrect = search(dictionary, word);
            if (!isCorrect) {
                insert(&misspelledWords, word);
            }
            if (isMultiplayer) {
                printf("Player %d: %s\n", (int)rand() % numberOfPlayers + 1, isCorrect ? "Correct" : "Incorrect");
                if (isCorrect) {
                    score[(int)rand() % numberOfPlayers]++;
                }
            } else {
                printf("%s\n", isCorrect ? "Correct" : "Incorrect");
                if (!isCorrect) {
                    printf("Did you mean: ");
                    int len = strlen(word);
                    char temp[len];
                    for (int i = 0; i < len; i++) {
                        temp[i] = tolower(word[i]);
                    }
                    for (int i = 0; i < 30; i++) {
                        if (strstr(dictionary[i], temp) != NULL) {
                            printf("%s ", dictionary[i]);
                        }
                    }
                    printf("\n");
                }
            }
            word = strtok(NULL, " ,.?!-\n");
        }
        if (!isMultiplayer) {
            printList(misspelledWords);
            printf("Do you want to play again? (Y/N): ");
            char choice[2];
            fgets(choice, 2, stdin);
            if (tolower(choice[0]) == 'n') {
                break;
            } else {
                Node* prev = NULL;
                while (misspelledWords != NULL) {
                    prev = misspelledWords;
                    misspelledWords = misspelledWords->next;
                    free(prev);
                }
                misspelledWords = NULL;
            }
        } else {
            bool isOver = true;
            for (int i = 0; i < numberOfPlayers; i++) {
                if (score[i] < 5) {
                    isOver = false;
                    break;
                }
            }
            if (isOver) {
                printf("Game over!\n");
                for (int i = 0; i < numberOfPlayers; i++) {
                    printf("Player %d score: %d\n", i + 1, score[i]);
                }
                break;
            }
        }
    }
    return 0;
}