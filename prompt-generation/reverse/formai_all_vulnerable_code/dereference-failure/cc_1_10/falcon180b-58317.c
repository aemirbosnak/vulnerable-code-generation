//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

//node structure for linked list
typedef struct node {
    char word[MAX_WORD_LENGTH];
    int count;
    struct node* next;
} Node;

//function to add word to linked list
void addWord(Node** head, char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->next = *head;
    *head = newNode;
}

//function to print linked list
void printList(Node* head) {
    while(head!= NULL) {
        printf("%s %d\n", head->word, head->count);
        head = head->next;
    }
}

//function to count words in file
void countWords(FILE* file, Node** head) {
    char word[MAX_WORD_LENGTH];
    char ch;
    int i = 0;
    int inWord = 0;
    while((ch = fgetc(file))!= EOF) {
        if(isalpha(ch)) {
            word[i] = tolower(ch);
            inWord = 1;
        } else if(inWord) {
            word[i] = '\0';
            addWord(head, word);
            inWord = 0;
            i = 0;
        }
    }
    if(inWord) {
        word[i] = '\0';
        addWord(head, word);
    }
}

int main(int argc, char* argv[]) {
    if(argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    FILE* file = fopen(argv[1], "r");
    if(file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    Node* head = NULL;
    countWords(file, &head);
    printList(head);
    fclose(file);
    return 0;
}