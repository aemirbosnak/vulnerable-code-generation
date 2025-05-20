//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    char* word;
    int count;
    struct Node* next;
} Node;

int hash(char* word) { /*sum ASCII values of word*/
    int hash = 0;
    while(*word) {
        hash += *word;
        word++;
    }
    return hash % 10; /*hash into 10 buckets*/
}

void printResults(Node** hashtable) {
    for(int i = 0; i < 10; i++) {
        Node* curr = hashtable[i];
        printf("Bucket %d:\n", i);
        while(curr != NULL) {
            printf("%s: %d\n", curr->word, curr->count);
            curr = curr->next;
        }
    }
}

void freeList(Node* head) {
    while(head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp->word);
        free(temp);
    }
}

void shift(Node*** hashtable, int oldSize, int newSize) {
    Node** newHash = calloc(newSize, sizeof(Node*));
    for(int i = 0; i < oldSize; i++) {
        Node* curr = (*hashtable)[i];
        while(curr != NULL) { /*rehash old items into new hashtable*/
            int index = hash(curr->word);
            Node* temp = curr->next;
            curr->next = newHash[index];
            newHash[index] = curr;
            curr = temp;
        }
    }
    free(*hashtable);
    *hashtable = newHash;
}

void addWord(Node*** hashtable, char* word) {
    int index = hash(word);
    Node* curr = (*hashtable)[index];
    while(curr != NULL) { /*word already in list*/
        if(strcmp(curr->word, word) == 0) {
            curr->count++;
            return;
        }
        curr = curr->next;
    }
    /*word not found, add to list*/
    Node* newNode = malloc(sizeof(Node));
    newNode->word = malloc((strlen(word)+1)*sizeof(char));
    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->next = (*hashtable)[index];
    (*hashtable)[index] = newNode;
}

int main() {
    Node** hashtable = calloc(10, sizeof(Node*)); /*initialize empty hashtable*/
    int numBuckets = 10;
    char c;
    char* word = calloc(100, sizeof(char));
    int index = 0;
    while((c = getchar()) != EOF) {
        if(isalpha(c)) {
            word[index] = tolower(c);
            index++;
        } else if(index > 0) {
            word[index] = '\0';
            addWord(&hashtable, word);
            index = 0;
            /*resize hashtable if load factor too big*/
            int numItems = 0;
            for(int i = 0; i < numBuckets; i++) {
                Node* curr = hashtable[i];
                while(curr != NULL) {
                    numItems++;
                    curr = curr->next;
                }
            }
            if(numItems > numBuckets*2) {
                int oldSize = numBuckets;
                numBuckets *= 2;
                shift(&hashtable, oldSize, numBuckets);
            } else if(numItems < numBuckets/2) { /*resize hashtable if load factor too small*/
                int oldSize = numBuckets;
                numBuckets /= 2;
                shift(&hashtable, oldSize, numBuckets);
            }
            /*move to next word*/
            memset(word, 0, 100*sizeof(char));
        }
    }
    if(index > 0) { /*last word in file*/
        word[index] = '\0';
        addWord(&hashtable, word);
    }
    printResults(hashtable);
    freeList(hashtable);
    free(word);
    return 0;
}