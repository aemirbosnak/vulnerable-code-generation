//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

typedef struct {
    char *str;
    int len;
} string_t;

typedef struct {
    char **strs;
    int num_strs;
} spam_list_t;

// Load a list of spam words from a file
spam_list_t *load_spam_list(const char *filename) {
    FILE *fp;
    char line[MAX_STR_LEN];
    spam_list_t *spam_list = malloc(sizeof(spam_list_t));
    if (!spam_list) {
        return NULL; // Error allocating memory
    }

    fp = fopen(filename, "r");
    if (!fp) {
        free(spam_list);
        return NULL; // Error opening file
    }

    // Read each line from the file and add it to the list
    spam_list->strs = malloc(sizeof(char *) * 10); // Start with a small list and grow as needed
    spam_list->num_strs = 0;
    while (fgets(line, MAX_STR_LEN, fp) != NULL) {
        line[strlen(line) - 1] = '\0'; // Remove newline character
        spam_list->strs[spam_list->num_strs] = strdup(line);
        spam_list->num_strs++;

        // Reallocate the list if necessary
        if (spam_list->num_strs >= 10 * (spam_list->num_strs / 10)) {
            spam_list->strs = realloc(spam_list->strs, sizeof(char *) * 10 * (spam_list->num_strs / 10));
        }
    }

    fclose(fp);

    return spam_list;
}

// Free the memory allocated for a spam list
void free_spam_list(spam_list_t *spam_list) {
    for (int i = 0; i < spam_list->num_strs; i++) {
        free(spam_list->strs[i]);
    }
    free(spam_list->strs);
    free(spam_list);
}

// Check if a string is spam
int is_spam(const char *str, spam_list_t *spam_list) {
    for (int i = 0; i < spam_list->num_strs; i++) {
        if (strstr(str, spam_list->strs[i]) != NULL) {
            return 1; // Found a spam word
        }
    }

    return 0; // No spam words found
}

// Find all spam messages in a file
int find_spam_messages(const char *filename, spam_list_t *spam_list) {
    FILE *fp;
    char line[MAX_STR_LEN];
    int num_spam_messages = 0;

    fp = fopen(filename, "r");
    if (!fp) {
        return -1; // Error opening file
    }

    // Read each line from the file and check if it is spam
    while (fgets(line, MAX_STR_LEN, fp) != NULL) {
        line[strlen(line) - 1] = '\0'; // Remove newline character
        if (is_spam(line, spam_list)) {
            num_spam_messages++;
        }
    }

    fclose(fp);

    return num_spam_messages;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <spam_list_file> <input_file>\n", argv[0]);
        return 1;
    }

    // Load the spam list
    spam_list_t *spam_list = load_spam_list(argv[1]);
    if (!spam_list) {
        printf("Error loading spam list from file '%s'\n", argv[1]);
        return 1;
    }

    // Find all spam messages in the input file
    int num_spam_messages = find_spam_messages(argv[2], spam_list);
    if (num_spam_messages == -1) {
        printf("Error opening input file '%s'\n", argv[2]);
        return 1;
    }

    // Print the number of spam messages found
    printf("%d spam messages found in file '%s'\n", num_spam_messages, argv[2]);

    // Free the memory allocated for the spam list
    free_spam_list(spam_list);

    return 0;
}