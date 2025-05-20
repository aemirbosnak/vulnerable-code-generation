//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;

struct virus {
	uint32 magic;
	uint32 size;
	uint8 *data;
};

struct virus *load_virus(const char *filename) {
	FILE *fp;
	struct virus *v;

	fp = fopen(filename, "rb");
	if (fp == NULL)
		return NULL;

	v = malloc(sizeof(*v));
	if (v == NULL) {
		fclose(fp);
		return NULL;
	}

	fread(&v->magic, sizeof(v->magic), 1, fp);
	fread(&v->size, sizeof(v->size), 1, fp);
	v->data = malloc(v->size);
	if (v->data == NULL) {
		fclose(fp);
		free(v);
		return NULL;
	}

	fread(v->data, 1, v->size, fp);
	fclose(fp);

	return v;
}

void free_virus(struct virus *v) {
	free(v->data);
	free(v);
}

int scan_file(const char *filename, struct virus *v) {
	FILE *fp;
	uint8 buffer[4096];
	int i, j;

	fp = fopen(filename, "rb");
	if (fp == NULL)
		return -1;

	while (fread(buffer, 1, sizeof(buffer), fp) > 0) {
		for (i = 0; i < sizeof(buffer) - v->size; i++) {
			for (j = 0; j < v->size; j++) {
				if (buffer[i + j] != v->data[j])
					break;
			}

			if (j == v->size)
				return 1;
		}
	}

	fclose(fp);

	return 0;
}

int main(int argc, char **argv) {
	struct virus *v;
	int i, infected = 0;

	if (argc < 3) {
		fprintf(stderr, "Usage: %s <virus> <files>\n", argv[0]);
		return EXIT_FAILURE;
	}

	v = load_virus(argv[1]);
	if (v == NULL) {
		fprintf(stderr, "Error: could not load virus\n");
		return EXIT_FAILURE;
	}

	for (i = 2; i < argc; i++) {
		if (scan_file(argv[i], v) == 1) {
			printf("%s: infected\n", argv[i]);
			infected++;
		}
	}

	free_virus(v);

	if (infected == 0)
		printf("No viruses found\n");

	return EXIT_SUCCESS;
}