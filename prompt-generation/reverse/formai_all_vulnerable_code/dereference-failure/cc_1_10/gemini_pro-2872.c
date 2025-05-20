//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
	char* name;
	struct node* next;
	struct node* prev;
} node_t;

typedef struct directory {
	char* name;
	struct directory* parent;
	struct node* children;
} directory_t;

typedef struct file {
	char* name;
	char* contents;
	size_t size;
} file_t;

typedef struct file_system {
	struct directory* root;
} file_system_t;

void fs_init(file_system_t* fs) {
	fs->root = malloc(sizeof(directory_t));
	fs->root->name = "/";
	fs->root->parent = NULL;
	fs->root->children = NULL;
}

void fs_destroy(file_system_t* fs) {
	// TODO: Free all allocated memory
}

directory_t* fs_mkdir(file_system_t* fs, directory_t* parent, char* name) {
	if (parent == NULL) {
		parent = fs->root;
	}

	node_t* new_node = malloc(sizeof(node_t));
	new_node->name = strdup(name);
	new_node->next = parent->children;
	new_node->prev = NULL;

	if (parent->children != NULL) {
		parent->children->prev = new_node;
	}

	parent->children = new_node;

	directory_t* new_dir = malloc(sizeof(directory_t));
	new_dir->name = strdup(name);
	new_dir->parent = parent;
	new_dir->children = NULL;

	return new_dir;
}

file_t* fs_create_file(file_system_t* fs, directory_t* parent, char* name, char* contents, size_t size) {
	if (parent == NULL) {
		parent = fs->root;
	}

	node_t* new_node = malloc(sizeof(node_t));
	new_node->name = strdup(name);
	new_node->next = parent->children;
	new_node->prev = NULL;

	if (parent->children != NULL) {
		parent->children->prev = new_node;
	}

	parent->children = new_node;

	file_t* new_file = malloc(sizeof(file_t));
	new_file->name = strdup(name);
	new_file->contents = strdup(contents);
	new_file->size = size;

	return new_file;
}

void fs_print_tree(file_system_t* fs, directory_t* dir, int depth) {
	for (int i = 0; i < depth; i++) {
		printf("  ");
	}
	printf("%s\n", dir->name);

	node_t* child = dir->children;
	while (child != NULL) {
		if (child->next != NULL) {
			fs_print_tree(fs, child->next, depth + 1);
		} else {
			fs_print_tree(fs, child, depth + 1);
		}
		child = child->next;
	}
}

int main() {
	file_system_t fs;
	fs_init(&fs);

	directory_t* home = fs_mkdir(&fs, NULL, "home");
	directory_t* bin = fs_mkdir(&fs, home, "bin");
	directory_t* documents = fs_mkdir(&fs, home, "documents");

	file_t* hello_world = fs_create_file(&fs, bin, "hello_world.c", "printf(\"Hello, world!\\n\");", 20);
	file_t* readme = fs_create_file(&fs, documents, "README.md", "# Welcome to my home directory\n\nThis is a simple file system simulation program written in C.", 80);

	fs_print_tree(&fs, fs.root, 0);

	fs_destroy(&fs);
	return 0;
}