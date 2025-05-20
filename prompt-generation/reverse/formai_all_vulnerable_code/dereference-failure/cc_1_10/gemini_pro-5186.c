//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NESTING_LEVEL 10

typedef struct {
    char *name;
    int nesting_level;
    int start_line;
    int end_line;
} tag_t;

typedef struct {
    char *html;
    int length;
    int capacity;
} html_t;

static void print_error(char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

static void print_usage(void) {
    fprintf(stderr, "Usage: htmlbeautifier <input_file> <output_file>\n");
    exit(EXIT_FAILURE);
}

static char *read_file(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        print_error("Could not open file");
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(length + 1);
    if (!buffer) {
        print_error("Could not allocate memory");
    }

    fread(buffer, 1, length, file);
    fclose(file);

    buffer[length] = '\0';

    return buffer;
}

static void write_file(char *filename, char *html) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        print_error("Could not open file");
    }

    fwrite(html, 1, strlen(html), file);
    fclose(file);
}

static html_t *new_html(void) {
    html_t *html = malloc(sizeof(html_t));
    if (!html) {
        print_error("Could not allocate memory");
    }

    html->html = malloc(MAX_LINE_LENGTH);
    if (!html->html) {
        print_error("Could not allocate memory");
    }

    html->length = 0;
    html->capacity = MAX_LINE_LENGTH;

    return html;
}

static void free_html(html_t *html) {
    free(html->html);
    free(html);
}

static void append_html(html_t *html, char *string) {
    int length = strlen(string);
    if (html->length + length >= html->capacity) {
        html->capacity *= 2;
        html->html = realloc(html->html, html->capacity);
        if (!html->html) {
            print_error("Could not allocate memory");
        }
    }

    memcpy(html->html + html->length, string, length);
    html->length += length;
}

static tag_t *new_tag(char *name, int nesting_level, int start_line, int end_line) {
    tag_t *tag = malloc(sizeof(tag_t));
    if (!tag) {
        print_error("Could not allocate memory");
    }

    tag->name = strdup(name);
    tag->nesting_level = nesting_level;
    tag->start_line = start_line;
    tag->end_line = end_line;

    return tag;
}

static void free_tag(tag_t *tag) {
    free(tag->name);
    free(tag);
}

static tag_t *find_open_tag(tag_t **tags, int nesting_level, int line_number) {
    for (int i = 0; i < nesting_level; i++) {
        if (tags[i]->nesting_level == nesting_level && tags[i]->end_line == -1) {
            return tags[i];
        }
    }

    return NULL;
}

static void close_tags(html_t *html, tag_t **tags, int nesting_level, int line_number) {
    while (nesting_level--) {
        tag_t *tag = find_open_tag(tags, nesting_level, line_number);
        if (!tag) {
            break;
        }

        append_html(html, "</");
        append_html(html, tag->name);
        append_html(html, ">\n");

        tag->end_line = line_number;
    }
}

static void beautify_html(html_t *html, tag_t **tags, int nesting_level, int line_number) {
    char *line = strtok(html->html, "\n");
    while (line) {
        if (nesting_level) {
            append_html(html, " ");
        }

        int tag_start = strcspn(line, "<");
        if (line[tag_start] == '<') {
            int tag_end = strcspn(line + tag_start + 1, ">");
            char *tag_name = strndup(line + tag_start + 1, tag_end);

            if (line[tag_start + 1] == '/') {
                close_tags(html, tags, nesting_level, line_number);

                tag_t *tag = find_open_tag(tags, nesting_level, line_number);
                if (!tag) {
                    print_error("Unmatched closing tag");
                }

                append_html(html, "</");
                append_html(html, tag->name);
                append_html(html, ">\n");

                tag->end_line = line_number;
            } else {
                tag_t *tag = new_tag(tag_name, nesting_level, line_number, -1);
                tags[nesting_level] = tag;

                append_html(html, "<");
                append_html(html, tag->name);
                append_html(html, ">\n");

                nesting_level++;
            }

            free(tag_name);
        } else {
            append_html(html, line);
            append_html(html, "\n");
        }

        line = strtok(NULL, "\n");
        line_number++;
    }

    close_tags(html, tags, nesting_level, line_number);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        print_usage();
    }

    char *input_filename = argv[1];
    char *output_filename = argv[2];

    char *html = read_file(input_filename);
    html_t *beautified_html = new_html();

    tag_t *tags[MAX_NESTING_LEVEL];
    for (int i = 0; i < MAX_NESTING_LEVEL; i++) {
        tags[i] = NULL;
    }

    int nesting_level = 0;
    int line_number = 1;

    beautify_html(beautified_html, tags, nesting_level, line_number);

    write_file(output_filename, beautified_html->html);

    free_html(beautified_html);

    for (int i = 0; i < MAX_NESTING_LEVEL; i++) {
        if (tags[i]) {
            free_tag(tags[i]);
        }
    }

    free(html);

    return EXIT_SUCCESS;
}