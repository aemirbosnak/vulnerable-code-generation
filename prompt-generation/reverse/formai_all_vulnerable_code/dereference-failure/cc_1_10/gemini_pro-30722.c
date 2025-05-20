//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: light-weight
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

struct dir_entry {
	char* name;
	size_t size;
	struct dir_entry* next;
};

void add_entry(struct dir_entry** head, char* name, size_t size) {
	struct dir_entry* new_entry = malloc(sizeof(struct dir_entry));
	if (!new_entry) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	new_entry->name = strdup(name);
	if (!new_entry->name) {
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	new_entry->size = size;
	new_entry->next = *head;
	*head = new_entry;
}

void print_entries(struct dir_entry* head) {
	while (head) {
		printf("%-20s %lu\n", head->name, head->size);
		head = head->next;
	}
}

void free_entries(struct dir_entry* head) {
	while (head) {
		struct dir_entry* next = head->next;
		free(head->name);
		free(head);
		head = next;
	}
}

int main(int argc, char** argv) {
	struct dir_entry* head = NULL;

	char* path = argv[1] ? argv[1] : ".";
	DIR* dir = opendir(path);
	if (!dir) {
		perror("opendir");
		exit(EXIT_FAILURE);
	}

	struct dirent* entry;
	while ((entry = readdir(dir))) {
		if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) {
			continue;
		}
		char* full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
		if (!full_path) {
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		sprintf(full_path, "%s/%s", path, entry->d_name);
		struct stat st;
		if (lstat(full_path, &st) == -1) {
			perror("lstat");
			exit(EXIT_FAILURE);
		}
		if (S_ISDIR(st.st_mode)) {
			add_entry(&head, entry->d_name, 0);
		} else {
			add_entry(&head, entry->d_name, st.st_size);
		}
		free(full_path);
	}
	closedir(dir);

	print_entries(head);
	free_entries(head);

	return EXIT_SUCCESS;
}