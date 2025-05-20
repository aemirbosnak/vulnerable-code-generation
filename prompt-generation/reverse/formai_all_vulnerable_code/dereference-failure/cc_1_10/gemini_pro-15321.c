//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024

char *strip_whitespace(char *str)
{
	char *p = str;
	while (*p) {
		if (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r') {
			p++;
		} else {
			break;
		}
	}
	return p;
}

char *strip_trailing_whitespace(char *str)
{
	char *p = str + strlen(str) - 1;
	while (p >= str) {
		if (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r') {
			p--;
		} else {
			break;
		}
	}
	*(p + 1) = '\0';
	return str;
}

char *str_replace(char *str, const char *old, const char *new)
{
	char *p = str;
	char *q = str;
	char *r = old;
	char *s = new;
	while (*q) {
		if (*p == *r) {
			p++;
			r++;
			if (*r == '\0') {
				while (*s) {
					*p++ = *s++;
				}
				q = p - strlen(old);
				r = old;
				s = new;
			}
		} else {
			*p++ = *q++;
			r = old;
			s = new;
		}
	}
	return str;
}

int main(int argc, char **argv)
{
	char buf[BUFSIZE];
	char *p;
	char *q;
	char *r;
	char *s;

	if (argc != 4) {
		fprintf(stderr, "Usage: %s <string> <old> <new>\n", argv[0]);
		return 1;
	}

	strncpy(buf, argv[1], BUFSIZE - 1);
	buf[BUFSIZE - 1] = '\0';

	p = strip_whitespace(buf);
	q = strip_trailing_whitespace(p);
	r = argv[2];
	s = argv[3];

	str_replace(q, r, s);

	printf("%s\n", q);

	return 0;
}