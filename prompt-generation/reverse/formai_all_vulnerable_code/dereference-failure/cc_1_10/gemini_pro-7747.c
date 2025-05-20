//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char *name;
	char *value;
	struct node *next;
} node;

typedef struct {
	node *head;
	node *tail;
} list;

void list_init(list *l) {
	l->head = l->tail = NULL;
}

void list_add(list *l, char *name, char *value) {
	node *n = malloc(sizeof(node));
	n->name = name;
	n->value = value;
	n->next = NULL;
	if (l->tail) {
		l->tail->next = n;
	} else {
		l->head = n;
	}
	l->tail = n;
}

void list_free(list *l) {
	node *n = l->head;
	while (n) {
		node *next = n->next;
		free(n->name);
		free(n->value);
		free(n);
		n = next;
	}
}

void html_beautify(char *html) {
	list l;
	list_init(&l);
	char *name = NULL;
	char *value = NULL;
	int in_tag = 0;
	int in_value = 0;
	for (char *p = html; *p; p++) {
		switch (*p) {
		case '<':
			in_tag = 1;
			break;
		case '>':
			in_tag = 0;
			if (value) {
				list_add(&l, name, value);
				free(name);
				free(value);
			}
			name = value = NULL;
			break;
		case '"':
		case '\'':
			if (!in_value) {
				in_value = 1;
				value = p + 1;
			} else if (value[strlen(value)-1] == *p) {
				in_value = 0;
			}
			break;
		case ' ':
		case '\t':
		case '\n':
		case '\r':
			if (!in_tag && !in_value) {
				break;
			}
		default:
			if (!name) {
				name = p;
			} else if (!in_value) {
				*p = ' ';
			}
		}
	}
	list_free(&l);
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <html>\n", argv[0]);
		return 1;
	}
	char *html = argv[1];
	html_beautify(html);
	printf("%s", html);
	return 0;
}