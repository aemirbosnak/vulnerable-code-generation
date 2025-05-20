//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char c;
	char *m;
} code_t;

code_t codes[] = {
	{ 'A', ".-" },
	{ 'B', "-..." },
	{ 'C', "-.-." },
	{ 'D', "-.." },
	{ 'E', "." },
	{ 'F', "..-." },
	{ 'G', "--." },
	{ 'H', "...." },
	{ 'I', ".." },
	{ 'J', ".---" },
	{ 'K', "-.-" },
	{ 'L', ".-.." },
	{ 'M', "--" },
	{ 'N', "-." },
	{ 'O', "---" },
	{ 'P', ".--." },
	{ 'Q', "--.-" },
	{ 'R', ".-" },
	{ 'S', "..." },
	{ 'T', "-" },
	{ 'U', "..- -" },
	{ 'V', "...-" },
	{ 'W', ".--" },
	{ 'X', "-..- -" },
	{ 'Y', "-.--" },
	{ 'Z', "--.." },
	{ '0', "-----" },
	{ '1', ".----" },
	{ '2', "..---" },
	{ '3', "...--" },
	{ '4', "....-" },
	{ '5', "....." },
	{ '6', "-...." },
	{ '7', "--..." },
	{ '8', "---.." },
	{ '9', "----." },
	{ ' ', " " },
};

char *to_morse(char c) {
	for (int i = 0; i < sizeof(codes) / sizeof(code_t); i++) {
		if (codes[i].c == c) {
			return codes[i].m;
		}
	}
	return NULL;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <text>\n", argv[0]);
		return 1;
	}

	char *text = argv[1];
	for (int i = 0; i < strlen(text); i++) {
		char *morse = to_morse(text[i]);
		if (morse) {
			printf("%s ", morse);
		}
	}
	printf("\n");

	return 0;
}