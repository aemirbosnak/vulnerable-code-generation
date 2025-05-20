//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct TrieNode {
    struct TrieNode *children[26];
    bool isWord;
} TrieNode;

TrieNode *createTrieNode() {
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    memset(node->children, 0, sizeof(node->children));
    node->isWord = false;
    return node;
}

void insertWord(TrieNode *root, const char *word) {
    if (!word || !*word) {
        return;
    }

    TrieNode *node = root;
    while (*word) {
        char c = tolower(*word++);
        if (!node->children[c - 'a']) {
            node->children[c - 'a'] = createTrieNode();
        }
        node = node->children[c - 'a'];
    }
    node->isWord = true;
}

bool searchWord(TrieNode *root, const char *word) {
    if (!word || !*word) {
        return false;
    }

    TrieNode *node = root;
    while (*word) {
        char c = tolower(*word++);
        if (!node->children[c - 'a']) {
            return false;
        }
        node = node->children[c - 'a'];
    }
    return node->isWord;
}

void freeTrie(TrieNode *root) {
    if (!root) {
        return;
    }

    for (int i = 0; i < 26; i++) {
        freeTrie(root->children[i]);
    }
    free(root);
}

void spellCheckFile(TrieNode *root, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("fopen");
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp)) {
        char *word = strtok(buffer, " \t\n\r.,;:?!\"\'[](){}");
        while (word) {
            if (!searchWord(root, word)) {
                printf("%s: %s\n", filename, word);
            }
            word = strtok(NULL, " \t\n\r.,;:?!\"\'[](){}");
        }
    }

    fclose(fp);
}

void spellCheckDirectory(TrieNode *root, const char *dirname) {
    DIR *dir = opendir(dirname);
    if (!dir) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir))) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) {
            continue;
        }

        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);
        struct stat statbuf;
        if (stat(path, &statbuf) < 0) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            spellCheckDirectory(root, path);
        } else if (S_ISREG(statbuf.st_mode)) {
            spellCheckFile(root, path);
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    TrieNode *root = createTrieNode();
    FILE *fp = fopen("words.txt", "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp)) {
        char *word = strtok(buffer, "\n\r");
        insertWord(root, word);
    }

    fclose(fp);

    spellCheckDirectory(root, argv[1]);

    freeTrie(root);

    return 0;
}