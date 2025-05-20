//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024

static char *
str_reverse(const char *s)
{
	char *buf = malloc(strlen(s) + 1);
	char *p = buf;

	while (*s)
		*p++ = *s--;

	*p = '\0';
	return buf;
}

static char *
str_replace(const char *s, const char *old, const char *new)
{
	char *buf = malloc(strlen(s) + strlen(new) + 1);
	char *p = buf;

	while (*s) {
		if (strncmp(s, old, strlen(old)) == 0) {
			strcpy(p, new);
			p += strlen(new);
			s += strlen(old);
		} else {
			*p++ = *s++;
		}
	}

	*p = '\0';
	return buf;
}

static int
str_split(const char *s, char **words, int max)
{
	int i = 0;

	while (i < max && *s) {
		while (*s && isspace(*s))
			s++;

		if (*s) {
			words[i++] = strdup(s);

			while (*s && !isspace(*s))
				s++;
		}
	}

	return i;
}

int
main(int argc, char **argv)
{
	char buf[BUFSIZE];
	char *words[10];
	int i;

	printf("Enter a string: ");
	fgets(buf, BUFSIZE, stdin);

	printf("The reversed string is: %s\n", str_reverse(buf));

	printf("Replace all occurrences of 'the' with 'a': %s\n",
	       str_replace(buf, "the", "a"));

	i = str_split(buf, words, 10);
	printf("The split words are:\n");
	for (i = 0; i < i; i++)
		printf("  %s\n", words[i]);

	return 0;
}