//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

struct node {
   char *word;
   struct node *next;
};

struct node *head = NULL;

void insert(char *word) {
   struct node *new_node = (struct node *)malloc(sizeof(struct node));
   new_node->word = word;
   new_node->next = head;
   head = new_node;
}

int find(char *word) {
   struct node *current = head;
   while (current != NULL) {
      if (strcmp(current->word, word) == 0) {
         return 1;
      }
      current = current->next;
   }
   return 0;
}

void print_list() {
   struct node *current = head;
   while (current != NULL) {
      printf("%s\n", current->word);
      current = current->next;
   }
}

int main() {
   char *words[] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
   for (int i = 0; i < 9; i++) {
      insert(words[i]);
   }

   char *word = "fox";
   if (find(word)) {
      printf("%s is in the list.\n", word);
   } else {
      printf("%s is not in the list.\n", word);
   }

   print_list();

   return 0;
}