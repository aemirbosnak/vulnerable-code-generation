//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TAG_LEN 100

typedef struct node {
	char *tag;
	struct node *child;
	struct node *sibling;
} node;

node *parse_xml(char *xml) {
	node *root = malloc(sizeof(node));
	root->tag = malloc(MAX_TAG_LEN);
	root->child = NULL;
	root->sibling = NULL;
	
	char *start = xml;
	char *end = xml;
	
	while (*end != '\0') {
		if (*end == '<') {
			start = end + 1;
			end = start;
			while (*end != '>') {
				end++;
			}
			
			strncpy(root->tag, start, end - start);
			root->tag[end - start] = '\0';
			
			if (*start == '/') {
				return root;
			}
			
			root->child = parse_xml(end + 1);
			
			while (*end != '\0' && *end != '<') {
				end++;
			}
			
			if (*end == '<') {
				root->sibling = parse_xml(end);
			}
		}
		
		end++;
	}
	
	return root;
}

void print_xml(node *root) {
	printf("<%s>", root->tag);
	
	if (root->child != NULL) {
		print_xml(root->child);
	}
	
	if (root->sibling != NULL) {
		print_xml(root->sibling);
	}
	
	printf("</%s>", root->tag);
}

int main() {
	char *xml = "<root><child1>text1</child1><child2>text2</child2></root>";
	node *root = parse_xml(xml);
	print_xml(root);
	return 0;
}