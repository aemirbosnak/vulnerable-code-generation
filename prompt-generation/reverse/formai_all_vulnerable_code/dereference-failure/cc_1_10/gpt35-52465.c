//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Define a linked list struct (note: the frequency of the word, or data, is stored in the node)
typedef struct node {
    char *word;
    int frequency;
    struct node *next;
} Node;

// Function declarations
Node* createNode(char *word, int frequency);
void insert(Node **head, char *word);
void printList(Node *head);
void sortList(Node **head);
void swapNodes(Node **head, Node *node1, Node *node2);
char* removePunctuation(char *word);
char* toLowerCase(char *word);

int main() {
    char sentence[1000];

    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);

    // Tokenize the sentence into words
    char *word = strtok(sentence, " \n");

    // Create head of linked list
    Node *head = createNode(word, 1);

    // Loop through the rest of the sentence and insert any new words into the linked list
    while (word != NULL) {
        // Remove punctuation and convert to lowercase
        word = removePunctuation(word);
        word = toLowerCase(word);

        // If word already exists in linked list, increment its frequency
        Node *current = head;
        while (current != NULL) {
            if (strcmp(current->word, word) == 0) {
                current->frequency++;
                break;
            }
            current = current->next;
        }

        // If word does not exist in linked list, create new node and insert it
        if (current == NULL) {
            insert(&head, word);
        }

        // Get next word
        word = strtok(NULL, " \n");
    }

    // Sort the linked list in descending order of frequency
    sortList(&head);

    // Print the word frequency table
    printf("Word frequency:\n");
    printList(head);

    return 0;
}

// Create a new node with given word and frequency
Node* createNode(char *word, int frequency) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->word = word;
    newNode->frequency = frequency;
    newNode->next = NULL;
    return newNode;
}

// Insert a new node with given word into linked list
void insert(Node **head, char *word) {
    Node *newNode = createNode(word, 1);
    newNode->next = *head;
    *head = newNode;
}

// Print the word frequency table
void printList(Node *head) {
    printf("%-15s%s\n", "Word", "Frequency");
    printf("----------------------\n");
    while (head != NULL) {
        printf("%-15s%d\n", head->word, head->frequency);
        head = head->next;
    }
}

// Sort the linked list in descending order of frequency (using bubble sort algorithm)
void sortList(Node **head) {
    int swapped;
    Node *current;
    Node *last = NULL;

    // Check if list is empty or has only one node
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    do {
        swapped = 0;
        current = *head;
        while (current->next != last) {
            if (current->frequency < current->next->frequency) {
                swapNodes(head, current, current->next);
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

// Swap the positions of two nodes in the linked list
void swapNodes(Node **head, Node *node1, Node *node2) {
    Node *prevNode1 = NULL;
    Node *prevNode2 = NULL;
    Node *current = *head;

    // Find the previous nodes of the two nodes to be swapped
    while (current != NULL) {
        if (current->next == node1) {
            prevNode1 = current;
        }
        if (current->next == node2) {
            prevNode2 = current;
        }
        current = current->next;
    }

    // If node1 is not the head of the linked list, then update the next pointer of its previous node
    if (prevNode1 != NULL) {
        prevNode1->next = node2;
    }
    // Else, node1 is the head of the linked list, so update the head pointer
    else {
        *head = node2;
    }

    // If node2 is not the head of the linked list, then update the next pointer of its previous node
    if (prevNode2 != NULL) {
        prevNode2->next = node1;
    }
    // Else, node2 is the head of the linked list, so update the head pointer
    else {
        *head = node1;
    }

    // Swap the next pointers of the two nodes
    Node *temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
}

// Remove punctuation from a given word
char* removePunctuation(char *word) {
    int i, j;
    for (i = 0, j = 0; i < strlen(word); i++) {
        if (isalpha(word[i])) {
            word[j] = word[i];
            j++;
        }
    }
    word[j] = '\0';
    return word;
}

// Convert given word to lowercase
char* toLowerCase(char *word) {
    int i;
    for (i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
    return word;
}