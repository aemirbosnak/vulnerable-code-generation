//FormAI DATASET v1.0 Category: Database Indexing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define struct for node in the indexed list
typedef struct ListNode {
    char* data;
    struct ListNode* next;
} ListNode;

// define struct for index
typedef struct Index {
    char key;
    ListNode* head;
} Index;

// function to create a new node
ListNode* newNode(char* data) {
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));
    node->data = (char*) malloc(strlen(data) + 1); // allocate memory for the string
    strcpy(node->data, data); // copy the string
    node->next = NULL;
    return node;
}

// function to insert a node at the beginning of a linked list
ListNode* insert(ListNode* head, char* data) {
    ListNode* node = newNode(data);
    node->next = head;
    head = node;
    return head;
}

// function to create a new index
Index* newIndex(char key) {
    Index* index = (Index*) malloc(sizeof(Index));
    index->key = key;
    index->head = NULL;
    return index;
}

// function to find the index node for a given key
Index* findIndex(Index* indexes, int numIndexes, char key) {
    int i;
    for (i = 0; i < numIndexes; i++) {
        if (indexes[i].key == key) {
            return &indexes[i];
        }
    }
    return NULL;
}

int main() {
    // create some sample data to insert
    char* data[] = {
        "apple",
        "banana",
        "cherry",
        "date",
        "elderberry",
        "fig",
        "grape",
        "honeydew",
        "indian gooseberry",
        "jujube",
        "kiwi",
        "lemon",
        "mango",
        "nectarine",
        "orange",
        "peach",
        "quince",
        "raspberry",
        "strawberry",
        "tangerine",
        "ugli fruit",
        "vanilla",
        "watermelon",
        "xigua",
        "yellow watermelon",
        "zucchini"
    };

    // create an array of index nodes for each letter of the alphabet
    Index indexes[26];
    int i;
    for (i = 0; i < 26; i++) {
        indexes[i] = *newIndex('a' + i);
    }

    // insert each item into the corresponding index node
    int numData = sizeof(data) / sizeof(char*);
    for (i = 0; i < numData; i++) {
        char firstLetter = data[i][0];
        Index* index = findIndex(indexes, 26, firstLetter);
        if (index != NULL) {
            index->head = insert(index->head, data[i]);
        }
    }

    // print out each index node and its linked list
    for (i = 0; i < 26; i++) {
        Index index = indexes[i];
        if (index.head != NULL) {
            printf("%c:\n", index.key);
            ListNode* current = index.head;
            while (current != NULL) {
                printf("- %s\n", current->data);
                current = current->next;
            }
            printf("\n");
        }
    }

    return 0;
}