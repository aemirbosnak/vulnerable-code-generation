//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

// Define a node in the trie data structure
typedef struct TrieNode {
  struct TrieNode *children[26]; // Array of pointers to child nodes
  int is_word; // Flag to indicate if this node represents a complete word
} TrieNode;

// Create a new trie node
TrieNode *create_trie_node() {
  TrieNode *node = malloc(sizeof(TrieNode));
  for (int i = 0; i < 26; i++) {
    node->children[i] = NULL;
  }
  node->is_word = 0;
  return node;
}

// Insert a word into the trie
void insert_word(TrieNode *root, char *word) {
  TrieNode *current = root;
  int length = strlen(word);

  for (int i = 0; i < length; i++) {
    int index = word[i] - 'a';
    if (current->children[index] == NULL) {
      current->children[index] = create_trie_node();
    }
    current = current->children[index];
  }

  current->is_word = 1;
}

// Load a dictionary of words into the trie
void load_dictionary(TrieNode *root, char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening dictionary file\n");
    return;
  }

  char word[MAX_WORD_LENGTH];
  while (fscanf(file, "%s", word) != EOF) {
    insert_word(root, word);
  }

  fclose(file);
}

// Calculate the edit distance between two strings
int edit_distance(char *str1, char *str2) {
  int len1 = strlen(str1);
  int len2 = strlen(str2);

  int matrix[len1 + 1][len2 + 1];

  // Initialize the first row and column of the matrix with edit distances
  for (int i = 0; i <= len1; i++) {
    matrix[i][0] = i;
  }
  for (int j = 0; j <= len2; j++) {
    matrix[0][j] = j;
  }

  // Calculate the edit distance matrix
  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      // If the characters match, no edit is required
      if (str1[i - 1] == str2[j - 1]) {
        matrix[i][j] = matrix[i - 1][j - 1];
      } else {
        // Otherwise, the edit distance is the minimum of the three possible operations:
        // insertion, deletion, or substitution
        matrix[i][j] = fmin(fmin(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + 1);
      }
    }
  }

  return matrix[len1][len2];
}

// Find the closest word in the dictionary to the given word
char *find_closest_word(TrieNode *root, char *word) {
  // Use a priority queue to keep track of the closest words
  typedef struct {
    char *word;
    int distance;
  } WordDistancePair;
  WordDistancePair queue[MAX_WORDS];
  int queue_size = 0;

  // Insert the given word into the queue
  WordDistancePair initial_pair = {word, 0};
  queue[queue_size++] = initial_pair;

  // While the queue is not empty, explore the trie
  while (queue_size > 0) {
    // Get the word with the smallest edit distance from the queue
    WordDistancePair current_pair = queue[0];
    for (int i = 1; i < queue_size; i++) {
      if (queue[i].distance < current_pair.distance) {
        current_pair = queue[i];
      }
    }

    // Remove the word from the queue
    for (int i = 0; i < queue_size - 1; i++) {
      queue[i] = queue[i + 1];
    }
    queue_size--;

    // If the word is in the dictionary, return it
    TrieNode *current = root;
    int length = strlen(current_pair.word);
    for (int i = 0; i < length; i++) {
      int index = current_pair.word[i] - 'a';
      if (current->children[index] == NULL) {
        break;
      }
      current = current->children[index];
    }

    if (current->is_word) {
      return current_pair.word;
    }

    // Otherwise, explore the child nodes of the current node
    for (int i = 0; i < 26; i++) {
      if (current->children[i] != NULL) {
        char new_word[MAX_WORD_LENGTH];
        strcpy(new_word, current_pair.word);
        new_word[length] = 'a' + i;
        new_word[length + 1] = '\0';

        WordDistancePair new_pair = {new_word, current_pair.distance + 1};
        queue[queue_size++] = new_pair;
      }
    }
  }

  // If no word was found in the dictionary, return NULL
  return NULL;
}

int main() {
  // Create the root node of the trie
  TrieNode *root = create_trie_node();

  // Load the dictionary into the trie
  load_dictionary(root, "dictionary.txt");

  // Get the word to be checked from the user
  char word[MAX_WORD_LENGTH];
  printf("Enter a word to be checked: ");
  scanf("%s", word);

  // Find the closest word in the dictionary to the given word
  char *closest_word = find_closest_word(root, word);

  // Print the closest word
  if (closest_word != NULL) {
    printf("The closest word in the dictionary to '%s' is '%s'\n", word, closest_word);
  } else {
    printf("No word in the dictionary is close to '%s'\n", word);
  }

  return 0;
}