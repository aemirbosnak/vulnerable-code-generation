//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: Linus Torvalds
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000

typedef struct {
	char *word;
	int count;
} word_count_t;

int compare_words(const void *a, const void *b)
{
	return strcmp(((word_count_t *)a)->word, ((word_count_t *)b)->word);
}

int main(int argc, char *argv[])
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *word;
	word_count_t words[MAX_WORDS];
	int word_count = 0;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return EXIT_FAILURE;
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "Error opening file: %s\n", strerror(errno));
		return EXIT_FAILURE;
	}

	while ((read = getline(&line, &len, fp)) != -1) {
		word = strtok(line, " \t\n");
		while (word != NULL) {
			int i;

			for (i = 0; i < word_count; i++) {
				if (strcmp(word, words[i].word) == 0) {
					words[i].count++;
					break;
				}
			}

			if (i == word_count) {
				if (word_count == MAX_WORDS) {
					fprintf(stderr, "Error: Too many words.\n");
					return EXIT_FAILURE;
				}

				words[word_count].word = strdup(word);
				words[word_count].count = 1;
				word_count++;
			}

			word = strtok(NULL, " \t\n");
		}
	}

	qsort(words, word_count, sizeof(word_count_t), compare_words);

	for (int i = 0; i < word_count; i++) {
		printf("%s: %d\n", words[i].word, words[i].count);
	}

	fclose(fp);
	free(line);

	return EXIT_SUCCESS;
}