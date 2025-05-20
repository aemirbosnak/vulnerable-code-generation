//MISTRAL-7B DATASET v1.0 Category: Spam Detection System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define MAX_WORDS 10000
#define WORD_LEN 50
#define FILE_NAME "spam_words.txt"

typedef struct {
    char word[WORD_LEN];
    bool is_spam;
} Word;

Word words[MAX_WORDS];
int num_words = 0;

void load_words() {
    int fd = open(FILE_NAME, O_RDONLY);
    char line[1024];

    if (fd < 0) {
        perror("Error opening file");
        return;
    }

    while (fgets(line, sizeof(line), fd) != NULL) {
        int i = 0;
        char *token = strtok(line, " ");

        while (token != NULL) {
            strncpy(words[num_words].word, token, WORD_LEN);
            words[num_words].is_spam = false;
            num_words++;

            if (num_words >= MAX_WORDS) {
                printf("Error: too many words\n");
                exit(1);
            }

            token = strtok(NULL, " ");
        }
    }

    close(fd);
}

bool is_spam(char *message, int len) {
    int i;
    bool found_spam_word = false;

    for (i = 0; i < num_words; i++) {
        if (strstr(message, words[i].word) != NULL) {
            words[i].is_spam = true;
            found_spam_word = true;
            break;
        }
    }

    if (found_spam_word) {
        return true;
    }

    int num_caps = 0;
    for (i = 0; i < len; i++) {
        if (isupper(message[i])) {
            num_caps++;
        }
    }

    if (num_caps > (len * 0.1)) {
        return true;
    }

    return false;
}

int main() {
    load_words();

    char message[1024];
    int len;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    len = strlen(message);

    if (message[len - 1] == '\n') {
        message[len - 1] = '\0';
        len--;
    }

    if (is_spam(message, len)) {
        printf("This message is spam!\n");
    } else {
        printf("This message is not spam.\n");
    }

    return 0;
}