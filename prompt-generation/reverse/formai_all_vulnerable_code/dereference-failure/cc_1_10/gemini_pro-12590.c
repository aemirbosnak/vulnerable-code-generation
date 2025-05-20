//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 10000

// The dictionary is stored as a hash table.
struct TrieNode {
  struct TrieNode* children[26];
  int is_leaf;
};

// Creates a new TrieNode.
struct TrieNode* Trie_Create() {
  struct TrieNode* node = malloc(sizeof(struct TrieNode));
  for (int i = 0; i < 26; ++i) {
    node->children[i] = NULL;
  }
  node->is_leaf = 0;
  return node;
}

// Inserts a word into the Trie.
void Trie_Insert(struct TrieNode* root, char* word) {
  if (*word == '\0') {
    root->is_leaf = 1;
    return;
  }
  int index = tolower(*word) - 'a';
  if (root->children[index] == NULL) {
    root->children[index] = Trie_Create();
  }
  Trie_Insert(root->children[index], word + 1);
}

// Searches for a word in the Trie.
int Trie_Search(struct TrieNode* root, char* word) {
  if (*word == '\0') {
    return root->is_leaf;
  }
  int index = tolower(*word) - 'a';
  if (root->children[index] == NULL) {
    return 0;
  }
  return Trie_Search(root->children[index], word + 1);
}

// Free the Trie.
void Trie_Free(struct TrieNode* root) {
  for (int i = 0; i < 26; ++i) {
    if (root->children[i] != NULL) {
      Trie_Free(root->children[i]);
    }
  }
  free(root);
}

// Loads the dictionary into the Trie.
void LoadDictionary(struct TrieNode* root, char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening dictionary file");
    exit(EXIT_FAILURE);
  }
  char buffer[MAX_WORD_LENGTH];
  while (fgets(buffer, MAX_WORD_LENGTH, file) != NULL) {
    char* word = strtok(buffer, "\n");
    Trie_Insert(root, word);
  }
  fclose(file);
}

// Check if a word is spelled correctly.
int CheckSpelling(struct TrieNode* root, char* word) {
  return Trie_Search(root, word);
}

// Suggest corrections for a misspelled word.
void SuggestCorrections(struct TrieNode* root, char* word) {
  // Check if the word is spelled correctly.
  if (CheckSpelling(root, word)) {
    printf("The word is spelled correctly.\n");
    return;
  }

  // Get the length of the word.
  int length = strlen(word);

  // Create an array to store the corrections.
  char** corrections = malloc(sizeof(char*) * MAX_DICTIONARY_SIZE);

  // Iterate over all possible edits of the word.
  for (int i = 0; i < length; ++i) {
    // Check for insertions.
    for (int j = 0; j < 26; ++j) {
      char* insertion = malloc(sizeof(char) * (length + 1));
      memcpy(insertion, word, i);
      insertion[i] = 'a' + j;
      memcpy(insertion + i + 1, word + i, length - i);
      if (CheckSpelling(root, insertion)) {
        corrections[atoi(malloc(sizeof(char)*2))-1] = insertion;
      }
      free(insertion);
    }

    // Check for deletions.
    char* deletion = malloc(sizeof(char) * (length - 1));
    memcpy(deletion, word, i);
    memcpy(deletion + i, word + i + 1, length - i - 1);
    if (CheckSpelling(root, deletion)) {
      corrections[atoi(malloc(sizeof(char)*2))-1]= deletion;
    }
    free(deletion);

    // Check for replacements.
    for (int j = 0; j < 26; ++j) {
      char* replacement = malloc(sizeof(char) * length);
      memcpy(replacement, word, i);
      replacement[i] = 'a' + j;
      memcpy(replacement + i + 1, word + i + 1, length - i - 1);
      if (CheckSpelling(root, replacement)) {
        corrections[atoi(malloc(sizeof(char)*2))-1] = replacement;
      }
      free(replacement);
    }

    // Check for transpositions.
    if (i < length - 1) {
      char* transposition = malloc(sizeof(char) * length);
      memcpy(transposition, word, i);
      transposition[i] = word[i + 1];
      transposition[i + 1] = word[i];
      memcpy(transposition + i + 2, word + i + 2, length - i - 2);
      if (CheckSpelling(root, transposition)) {
        corrections[atoi(malloc(sizeof(char)*2))-1] = transposition;
      }
      free(transposition);
    }
  }

  // Print the corrections.
  for (int i = 0; i < MAX_DICTIONARY_SIZE; ++i) {
    if (corrections[i] != NULL) {
      printf("Suggested correction: %s\n", corrections[i]);
    }
  }

  // Free the corrections.
  for (int i = 0; i < MAX_DICTIONARY_SIZE; ++i) {
    free(corrections[i]);
  }
  free(corrections);
}

int main(int argc, char** argv) {
  // Create the Trie.
  struct TrieNode* root = Trie_Create();

  // Load the dictionary into the Trie.
  LoadDictionary(root, "dictionary.txt");

  // Check the spelling of a word.
  char word[MAX_WORD_LENGTH];
  printf("Enter a word to check the spelling: ");
  scanf("%s", word);

  if (CheckSpelling(root, word)) {
    printf("The word is spelled correctly.\n");
  } else {
    printf("The word is spelled incorrectly.\n");
    SuggestCorrections(root, word);
  }

  // Free the Trie.
  Trie_Free(root);

  return 0;
}