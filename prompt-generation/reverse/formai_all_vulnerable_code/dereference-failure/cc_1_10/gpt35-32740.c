//FormAI DATASET v1.0 Category: Spell checking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DEFAULT_DICT "dictionary.txt"
#define MAX_WORD_LEN 50
#define MAX_BUFFER_LEN 1024

typedef struct node {
    char word[MAX_WORD_LEN];
    struct node *next;
} node_t;

int load_dictionary(const char *dict_path, node_t **dict_h) {
    FILE *fp = fopen(dict_path, "r");
    if (!fp) {
        fprintf(stderr, "Failed to load dictionary %s\n", dict_path);
        return -1;
    }

    char buffer[MAX_BUFFER_LEN] = {0};
    while (fgets(buffer, MAX_BUFFER_LEN, fp)) {
        if (buffer[0] == '\n' || buffer[0] == '#' || buffer[0] == ';') {
            continue; // Skip empty lines or comments
        }

        size_t len = strlen(buffer);
        if (buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0'; // Remove newline character
        }

        node_t *node = malloc(sizeof(node_t));
        if (!node) {
            fprintf(stderr, "Failed to allocate memory for word %s\n", buffer);
            return -1;
        }

        strncpy(node->word, buffer, MAX_WORD_LEN);
        node->next = NULL;

        if (!(*dict_h)) {
            *dict_h = node;
        }
        else {
            node_t *cur = *dict_h;
            while (cur) {
                if (strcmp(cur->word, node->word) == 0) {
                    free(node);
                    break;
                }
                else if (!cur->next) {
                    cur->next = node;
                    break;
                }
                cur = cur->next;
            }
        }
    }

    fclose(fp);

    return 0;
}

void free_dictionary(node_t **dict_h) {
    while (*dict_h) {
        node_t *node = *dict_h;
        *dict_h = (*dict_h)->next;
        free(node);
    }
}

int check_word(node_t *dict_h, const char *word) {
    node_t *cur = dict_h;
    while (cur) {
        if (strcmp(cur->word, word) == 0) {
            return 0;
        }
        cur = cur->next;
    }
    return -1;
}

void to_lower_case(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [text_file] [dictionary_path (optional, default=%s)]\n", argv[0], DEFAULT_DICT);
        return -1;
    }

    const char *dict_path = DEFAULT_DICT;
    if (argc == 3) {
        dict_path = argv[2];
    }

    node_t *dict_h = NULL;
    if (load_dictionary(dict_path, &dict_h) == -1) {
        free_dictionary(&dict_h);
        return -1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        fprintf(stderr, "Failed to open file %s\n", argv[1]);
        free_dictionary(&dict_h);
        return -1;
    }

    char buffer[MAX_BUFFER_LEN] = {0};
    int line_num = 1;
    while (fgets(buffer, MAX_BUFFER_LEN, fp)) {
        char *word = strtok(buffer, " \n\r\t");
        while (word) {
            to_lower_case(word);
            if (check_word(dict_h, word) == -1) {
                printf("Line %d: %s\n", line_num, word);
            }
            word = strtok(NULL, " \n\r\t");
        }
        line_num++;
    }

    fclose(fp);
    free_dictionary(&dict_h);

    return 0;
}