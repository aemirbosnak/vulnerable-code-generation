//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    unsigned int start;
    unsigned int end;
    unsigned int size;
    unsigned int flags;
} section;

typedef struct {
    unsigned int start;
    unsigned int end;
    unsigned int size;
    unsigned int flags;
    unsigned int num_sections;
    section *sections;
} segment;

typedef struct {
    unsigned int start;
    unsigned int end;
    unsigned int size;
    unsigned int flags;
    unsigned int num_segments;
    segment *segments;
} image;

image *parse_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    image *image = malloc(sizeof(image));
    if (image == NULL) {
        fprintf(stderr, "Error allocating memory for image\n");
        fclose(fp);
        return NULL;
    }

    image->start = 0;
    image->end = 0;
    image->size = 0;
    image->flags = 0;
    image->num_segments = 0;
    image->segments = NULL;

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while ((nread = getline(&line, &len, fp)) != -1) {
        if (nread == 0) {
            continue;
        }

        char *name = strtok(line, " ");
        unsigned int start = strtoul(strtok(NULL, " "), NULL, 16);
        unsigned int end = strtoul(strtok(NULL, " "), NULL, 16);
        unsigned int size = end - start + 1;
        unsigned int flags = strtoul(strtok(NULL, " "), NULL, 16);

        if (strcmp(name, "SEGMENT") == 0) {
            segment *segment = malloc(sizeof(segment));
            if (segment == NULL) {
                fprintf(stderr, "Error allocating memory for segment\n");
                free(image);
                return NULL;
            }

            segment->start = start;
            segment->end = end;
            segment->size = size;
            segment->flags = flags;
            segment->num_sections = 0;
            segment->sections = NULL;

            if (image->num_segments == 0) {
                image->segments = malloc(sizeof(segment));
                if (image->segments == NULL) {
                    fprintf(stderr, "Error allocating memory for image segments\n");
                    free(segment);
                    free(image);
                    return NULL;
                }
            } else {
                image->segments = realloc(image->segments, (image->num_segments + 1) * sizeof(segment));
                if (image->segments == NULL) {
                    fprintf(stderr, "Error reallocating memory for image segments\n");
                    free(segment);
                    free(image);
                    return NULL;
                }
            }

            image->segments[image->num_segments] = *segment;
            image->num_segments++;
        } else if (strcmp(name, "SECTION") == 0) {
            section *section = malloc(sizeof(section));
            if (section == NULL) {
                fprintf(stderr, "Error allocating memory for section\n");
                free(image);
                return NULL;
            }

            section->name = strdup(name);
            section->start = start;
            section->end = end;
            section->size = size;
            section->flags = flags;

            if (image->segments[image->num_segments - 1].num_sections == 0) {
                image->segments[image->num_segments - 1].sections = malloc(sizeof(section));
                if (image->segments[image->num_segments - 1].sections == NULL) {
                    fprintf(stderr, "Error allocating memory for segment sections\n");
                    free(section);
                    free(image);
                    return NULL;
                }
            } else {
                image->segments[image->num_segments - 1].sections = realloc(image->segments[image->num_segments - 1].sections, (image->segments[image->num_segments - 1].num_sections + 1) * sizeof(section));
                if (image->segments[image->num_segments - 1].sections == NULL) {
                    fprintf(stderr, "Error reallocating memory for segment sections\n");
                    free(section);
                    free(image);
                    return NULL;
                }
            }

            image->segments[image->num_segments - 1].sections[image->segments[image->num_segments - 1].num_sections] = *section;
            image->segments[image->num_segments - 1].num_sections++;
        }
    }

    fclose(fp);
    return image;
}

void free_image(image *image) {
    for (unsigned int i = 0; i < image->num_segments; i++) {
        for (unsigned int j = 0; j < image->segments[i].num_sections; j++) {
            free(image->segments[i].sections[j].name);
        }
        free(image->segments[i].sections);
    }
    free(image->segments);
    free(image);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    image *image = parse_image(argv[1]);
    if (image == NULL) {
        fprintf(stderr, "Error parsing image\n");
        return 1;
    }

    // TODO: Optimize the image

    free_image(image);
    return 0;
}