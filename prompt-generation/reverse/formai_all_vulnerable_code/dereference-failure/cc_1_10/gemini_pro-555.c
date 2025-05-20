//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

struct node {
	int type;
	char *text;
	struct node *next;
};

struct node *parse_line(char *line)
{
	struct node *root = NULL;
	struct node *tail = NULL;
	struct node *node;
	char *start = line;
	char *end;
	int depth = 0;

	while (*start) {
		if (*start == '(') {
			depth++;
			if (!root) {
				root = malloc(sizeof(struct node));
				root->type = -1;
				root->text = NULL;
				root->next = NULL;
				tail = root;
			} else {
				node = malloc(sizeof(struct node));
				node->type = -1;
				node->text = NULL;
				node->next = NULL;
				tail->next = node;
				tail = tail->next;
			}
		} else if (*start == ')') {
			depth--;
			if (depth == 0)
				tail = NULL;
		} else if (*start == '\'') {
			start++;
			node = malloc(sizeof(struct node));
			node->type = 0;
			end = start;
			while (*end && *end != '\'')
				end++;
			node->text = malloc(end - start + 1);
			strncpy(node->text, start, end - start);
			node->text[end - start] = '\0';
			if (!root) {
				root = node;
				tail = root;
			} else {
				tail->next = node;
				tail = tail->next;
			}
			start = end;
		}
		start++;
	}

	return root;
}

void print_tree(struct node *root, int depth)
{
	int i;

	if (!root)
		return;

	for (i = 0; i < depth; i++)
		printf(" ");

	if (root->type == -1)
		printf("()\n");
	else
		printf("'%s'\n", root->text);

	print_tree(root->next, depth + 1);
}

int main(int argc, char **argv)
{
	struct node *root;

	root = parse_line(argv[1]);
	print_tree(root, 0);

	return 0;
}