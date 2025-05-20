//FormAI DATASET v1.0 Category: Spell checking ; Style: innovative
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 100 // maximum length of a word in the dictionary

struct node { // declares a trie node
    struct node* children[26]; // 26 letters of the English alphabet
    int is_end_of_word; // determines if the node represents the end of a valid word
};

struct node* create_node() { // create a new trie node
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->is_end_of_word = 0;
    for(int i=0; i<26; i++) {
        n->children[i] = NULL;
    }
    return n;
}

void insert_word(struct node* root, char* word) { // inserts a word into the trie
    int length = strlen(word);
    struct node* current_node = root;

    for(int i=0; i<length; i++) {
        int index = tolower(word[i]) - 'a';
        if(current_node->children[index] == NULL) {
            current_node->children[index] = create_node();
        }
        current_node = current_node->children[index];
    }
    current_node->is_end_of_word = 1;
}

int is_word_spelled_correctly(struct node* root, char* word) { // check if a word is spelled correctly
    int length = strlen(word);
    struct node* current_node = root;

    for(int i=0; i<length; i++) {
        int index = tolower(word[i]) - 'a';
        if(current_node->children[index] == NULL) {
            return 0;
        }
        current_node = current_node->children[index];
    }

    if(current_node->is_end_of_word == 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    FILE* dictionary_file = fopen("dictionary.txt", "r"); // open dictionary file
    if(dictionary_file == NULL) { // check if file was opened successfully
        printf("Unable to open dictionary file!");
        return 0;
    }

    struct node* dictionary_trie = create_node(); // create a new trie to store the dictionary words
    char word[MAX_WORD_SIZE];
    while(fscanf(dictionary_file, "%s", word) == 1) { // read each word from the dictionary file
        insert_word(dictionary_trie, word); // insert the word into the trie
    }
    fclose(dictionary_file); // close the dictionary file

    printf("Enter a sentence: "); // prompt for input
    char sentence[MAX_WORD_SIZE];
    fgets(sentence, sizeof(sentence), stdin); // read the user input

    char* word_start = sentence;
    int index = 0;
    int sentence_length = strlen(sentence);

    while(index < sentence_length) { // iterate through each character in the input sentence
        char current_char = sentence[index];
        if(current_char == ' ' || current_char == '\n' || current_char == '\0') { // if the current character marks the end of a word
            char current_word[MAX_WORD_SIZE];
            int length = index - (word_start - sentence); // calculate the length of the current word
            strncpy(current_word, word_start, length); // copy the current word into a new buffer
            current_word[length] = '\0'; // append null terminator to the end of the buffer

            if(!is_word_spelled_correctly(dictionary_trie, current_word)) { // if the current word is not in the dictionary
                printf("Did you mean: %s?\n", current_word); // suggest the closest matching word from the dictionary
            }

            word_start = sentence + index + 1; // move the word start pointer to the beginning of the next word
        }
        index++;
    }

    return 0;
}