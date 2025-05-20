//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alien_dict {
    char **words;
    size_t num_words;
};

struct alien_dict *create_dict(const char *filename) {
    struct alien_dict *dict = malloc(sizeof(struct alien_dict));
    if (!dict) {
        perror("malloc");
        return NULL;
    }

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        free(dict);
        perror("fopen");
        return NULL;
    }

    size_t line_size = 1024;
    char *line = malloc(line_size);
    if (!line) {
        free(dict);
        fclose(fp);
        perror("malloc");
        return NULL;
    }

    dict->num_words = 0;
    while (fgets(line, line_size, fp)) {
        // Remove newline character
        line[strlen(line) - 1] = '\0';

        dict->words = realloc(dict->words, (dict->num_words + 1) * sizeof(char *));
        if (!dict->words) {
            free(dict);
            free(line);
            fclose(fp);
            perror("realloc");
            return NULL;
        }

        dict->words[dict->num_words++] = strdup(line);
    }

    free(line);
    fclose(fp);

    return dict;
}

void free_dict(struct alien_dict *dict) {
    for (size_t i = 0; i < dict->num_words; i++) {
        free(dict->words[i]);
    }
    free(dict->words);
    free(dict);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <alien_dict> <text_to_translate>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct alien_dict *dict = create_dict(argv[1]);
    if (!dict) {
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[2], "r");
    if (!fp) {
        free_dict(dict);
        perror("fopen");
        return EXIT_FAILURE;
    }

    size_t line_size = 1024;
    char *line = malloc(line_size);
    if (!line) {
        free_dict(dict);
        fclose(fp);
        perror("malloc");
        return EXIT_FAILURE;
    }

    while (fgets(line, line_size, fp)) {
        // Remove newline character
        line[strlen(line) - 1] = '\0';

        // Split line into words
        char *words[strlen(line)];
        size_t num_words = 0;
        char *pch = strtok(line, " ");
        while (pch != NULL) {
            words[num_words++] = pch;
            pch = strtok(NULL, " ");
        }

        // Translate each word
        for (size_t i = 0; i < num_words; i++) {
            int found = 0;
            for (size_t j = 0; j < dict->num_words; j++) {
                if (strcmp(words[i], dict->words[j]) == 0) {
                    printf("%s ", dict->words[j]);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("%s ", words[i]);
            }
        }

        printf("\n");
    }

    free(line);
    fclose(fp);
    free_dict(dict);

    return EXIT_SUCCESS;
}