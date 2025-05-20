//FormAI DATASET v1.0 Category: Spam Detection System ; Style: recursive
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEVELS 1000

typedef struct Node {
  bool isEndOfWord;
  struct Node* child[26];
} Node;

Node* createNode() {
  Node* node = (Node*)malloc(sizeof(Node));
  node->isEndOfWord = false;

  for (int i = 0; i < 26; i++) {
    node->child[i] = NULL;
  }

  return node;
}

void insertWord(Node* root, const char* word) {
  int len = strlen(word);
  Node* cur = root;

  for (int i = 0; i < len; i++) {
    int c = (int)word[i] - 'a';
    if (cur->child[c] == NULL) {
      cur->child[c] = createNode();
    }

    cur = cur->child[c];
  }

  cur->isEndOfWord = true;
}

bool isSpam(Node* root, const char* message, int curIdx, int level,
            int levelCount[]) {
  if (curIdx == strlen(message)) {
    return false;
  }

  if (level == MAX_LEVELS) {
    return true;
  }

  int c = (int)message[curIdx] - 'a';

  if (root->child[c] == NULL) {
    return false;
  }

  levelCount[level]++;
  if (root->child[c]->isEndOfWord && levelCount[level] == 2) {
    return true;
  }

  bool curLevelSpam = isSpam(root->child[c], message, curIdx + 1, level + 1,
                              levelCount);

  if (curLevelSpam) {
    return true;
  }

  for (int i = 0; i < 26; i++) {
    if (root->child[i] != NULL) {
      bool nextLevelSpam = isSpam(root->child[i], message, curIdx, level + 1,
                                   levelCount);

      if (nextLevelSpam) {
        return true;
      }
    }
  }

  return false;
}

bool isSpamMessage(Node* root, const char* message) {
  int levelCount[MAX_LEVELS];
  memset(levelCount, 0, sizeof(levelCount));

  return isSpam(root, message, 0, 0, levelCount);
}

int main() {
  Node* root = createNode();

  insertWord(root, "buy");
  insertWord(root, "sale");
  insertWord(root, "discount");
  insertWord(root, "cheap");

  const char* message1 = "Buy now and get 50% discount!";
  bool isSpam1 = isSpamMessage(root, message1);

  const char* message2 = "I am selling my car for a cheap price.";
  bool isSpam2 = isSpamMessage(root, message2);

  const char* message3 = "Hello World!";
  bool isSpam3 = isSpamMessage(root, message3);

  printf("%s is spam: %s\n", message1, isSpam1 ? "true" : "false");
  printf("%s is spam: %s\n", message2, isSpam2 ? "true" : "false");
  printf("%s is spam: %s\n", message3, isSpam3 ? "true" : "false");

  return 0;
}