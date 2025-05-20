//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: multivariable
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mailing_list {
	char **emails;
	size_t size;
	size_t capacity;
};

void print_error(const char *message)
{
	fprintf(stderr, "%s: %s\n", message, strerror(errno));
	exit(EXIT_FAILURE);
}

void mailing_list_init(struct mailing_list *list)
{
	list->emails = NULL;
	list->size = 0;
	list->capacity = 0;
}

void mailing_list_destroy(struct mailing_list *list)
{
	for (size_t i = 0; i < list->size; i++) {
		free(list->emails[i]);
	}
	free(list->emails);
}

int mailing_list_add(struct mailing_list *list, const char *email)
{
	if ((email = strdup(email)) == NULL) {
		return -1;
	}
	if (list->size >= list->capacity) {
		size_t new_capacity = list->capacity ? list->capacity * 2 : 16;
		char **new_emails = realloc(list->emails, new_capacity * sizeof(*list->emails));
		if (new_emails == NULL) {
			free((char *)email);
			return -1;
		}
		list->emails = new_emails;
		list->capacity = new_capacity;
	}
	list->emails[list->size++] = email;
	return 0;
}

int mailing_list_remove(struct mailing_list *list, const char *email)
{
	for (size_t i = 0; i < list->size; i++) {
		if (strcmp(list->emails[i], email) == 0) {
			free(list->emails[i]);
			list->size--;
			list->emails[i] = list->emails[list->size];
			return 0;
		}
	}
	return -1;
}

int mailing_list_save(const struct mailing_list *list, const char *filename)
{
	FILE *fp = fopen(filename, "w");
	if (fp == NULL) {
		return -1;
	}
	for (size_t i = 0; i < list->size; i++) {
		if (fprintf(fp, "%s\n", list->emails[i]) < 0) {
			fclose(fp);
			return -1;
		}
	}
	fclose(fp);
	return 0;
}

int mailing_list_load(struct mailing_list *list, const char *filename)
{
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		return -1;
	}
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	while ((nread = getline(&line, &len, fp)) != -1) {
		line[nread - 1] = '\0';  // remove newline
		if (mailing_list_add(list, line) < 0) {
			free(line);
			fclose(fp);
			return -1;
		}
	}
	free(line);
	fclose(fp);
	return 0;
}

int main(int argc, char **argv)
{
	struct mailing_list list;
	mailing_list_init(&list);
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-a") == 0) {
			if (mailing_list_add(&list, argv[++i]) < 0) {
				print_error("mailing_list_add");
			}
		} else if (strcmp(argv[i], "-r") == 0) {
			if (mailing_list_remove(&list, argv[++i]) < 0) {
				print_error("mailing_list_remove");
			}
		} else if (strcmp(argv[i], "-s") == 0) {
			if (mailing_list_save(&list, argv[++i]) < 0) {
				print_error("mailing_list_save");
			}
		} else if (strcmp(argv[i], "-l") == 0) {
			if (mailing_list_load(&list, argv[++i]) < 0) {
				print_error("mailing_list_load");
			}
		} else {
			fprintf(stderr, "usage: %s [-a email] [-r email] [-s file] [-l file]\n", argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	for (size_t i = 0; i < list.size; i++) {
		printf("%s\n", list.emails[i]);
	}
	mailing_list_destroy(&list);
	return EXIT_SUCCESS;
}