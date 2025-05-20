//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
	if (argc != 3) {
		printf("Usage:\n");
		printf("\t%s <string1> <string2>\n", argv[0]);
		return 1;
	}

	const char* str1 = argv[1];
	const char* str2 = argv[2];

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int** table = malloc(sizeof(int*) * (len1 + 1));
	for (int i = 0; i <= len1; i++) {
		table[i] = malloc(sizeof(int) * (len2 + 1));
		for (int j = 0; j <= len2; j++) {
			table[i][j] = 0;
		}
	}

	for (int i = 1; i <= len1; i++) {
		table[i][0] = i;
	}

	for (int j = 1; j <= len2; j++) {
		table[0][j] = j;
	}

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			int cost = (str1[i - 1] != str2[j - 1]) ? 1 : 0;
			table[i][j] = min(min(table[i - 1][j] + 1, table[i][j - 1] + 1), table[i - 1][j - 1] + cost);
		}
	}

	printf("Levenshtein distance between \"%s\" and \"%s\": %d\n", str1, str2, table[len1][len2]);

	for (int i = 0; i <= len1; i++) {
		free(table[i]);
	}
	free(table);

	return 0;
}

int min(int a, int b)
{
	return (a < b) ? a : b;
}