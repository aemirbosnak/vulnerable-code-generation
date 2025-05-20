//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char *word;
	int count;
	struct node *next;
} node;

node *head = NULL;

void add_word(char *word) {
	node *current = head;

	while (current != NULL) {
		if (strcmp(current->word, word) == 0) {
			current->count++;
			return;
		}
		current = current->next;
	}

	node *new_node = malloc(sizeof(node));
	new_node->word = strdup(word);
	new_node->count = 1;
	new_node->next = head;

	head = new_node;
}

void print_words() {
	node *current = head;

	while (current != NULL) {
		printf("%s: %d\n", current->word, current->count);
		current = current->next;
	}
}

int main() {
	char *words[] = {
		"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"
	};
	int num_words = sizeof(words) / sizeof(char *);

	for (int i = 0; i < num_words; i++) {
		add_word(words[i]);
	}

	print_words();

	return 0;
}