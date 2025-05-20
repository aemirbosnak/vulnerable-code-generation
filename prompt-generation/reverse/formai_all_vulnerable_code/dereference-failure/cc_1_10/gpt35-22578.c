//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_TREE_HT 50
#define MAX_CHAR 256

// Nodes in Huffman Code Tree
struct Huffman_Node {
    char data;
    unsigned freq;
    struct Huffman_Node *left, *right;
};

// PriorityQueue Node
struct PQueue_Node {
   struct Huffman_Node *data;
   unsigned priority;
   struct PQueue_Node *next;
};

// Create a Huffman Node
struct Huffman_Node* newHuffmanNode(char data, unsigned freq) {
    struct Huffman_Node* node = 
                (struct Huffman_Node*) malloc(sizeof(struct Huffman_Node));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// Create Priority Queue Node
struct PQueue_Node* newPQueueNode(struct Huffman_Node* data, unsigned priority) {
    struct PQueue_Node* temp = 
         (struct PQueue_Node*)malloc(sizeof(struct PQueue_Node));
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}

// Function to check if the Queue is empty or not
int isQueueEmpty(struct PQueue_Node** head)
{
    return (*head) == NULL;
}

// Add a node based on priority - Higher priority nodes are added first
void enqueue(struct PQueue_Node** head, struct Huffman_Node* data, unsigned priority) {
    struct PQueue_Node* start = (*head);
    struct PQueue_Node* temp = newPQueueNode(data, priority);
 
    if ((*head)->priority > priority) {
        temp->next = *head;
        (*head) = temp;
    } else {
        while (start->next != NULL && start->next->priority < priority) {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
}

// Remove the node with the lowest priority
struct Huffman_Node* dequeue(struct PQueue_Node** head) {
    struct PQueue_Node* temp = *head;
    struct Huffman_Node* data;
    if (isQueueEmpty(head)) {
        return NULL;
    } else {
        data = (*head)->data;
        (*head) = (*head)->next;
        free(temp);
        return data;
    }
}

// Check if a node is a Leaf Node
int isLeaf(struct Huffman_Node* node) {
    return !(node->left) && !(node->right);
}

// Print the Huffman Code of a character
void printCharHuffmanCode(struct Huffman_Node* root, char str[], int top) {
    if (root->left) {
        str[top] = '0';
        printCharHuffmanCode(root->left, str, top + 1);
    }
    if (root->right) {
        str[top] = '1';
        printCharHuffmanCode(root->right, str, top + 1);
    }
    if (isLeaf(root)) {
        printf(" %c | %5d | ",root->data,root->freq);
        int i;
        for (i = 0; i < top; i++) {
            printf("%c", str[i]);
        }
        printf("\n");
    }
}

// Generate Huffman Code Tree
void generateHuffmanCodeTree(char data[], int freq[], int size) {
    struct Huffman_Node *left, *right, *top;
 
    struct PQueue_Node* head = NULL;
 
    for (int i = 0; i < size; ++i) {
        enqueue(&head, newHuffmanNode(data[i], freq[i]), freq[i]);
    }

    while (!isQueueEmpty(&head)) {
        left = dequeue(&head);
        right = dequeue(&head);
 
        top = newHuffmanNode('$', left->freq + right->freq);
 
        top->left = left;
        top->right = right;
 
        enqueue(&head, top, top->freq);
    }

    char str[MAX_TREE_HT];
    printf("\n\nCharacter | Freq | Huffman Code\n");
    printCharHuffmanCode(dequeue(&head), str, 0);
}

// Driver program to test above functions
int main() {
 
    char charArr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freqArr[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(charArr) / sizeof(char);
 
    printf("Huffman Coding Provided in C \n");
    printf("------------------------------\n");
    generateHuffmanCodeTree(charArr, freqArr, size);
 
    return 0;
}