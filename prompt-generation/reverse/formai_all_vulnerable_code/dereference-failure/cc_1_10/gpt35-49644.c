//FormAI DATASET v1.0 Category: Browser Plugin ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define MAX_KEYWORD_LENGTH 50

char* extractUrl(char* input);

int main(int argc, char const *argv[])
{
    char url[MAX_URL_LENGTH];
    char *blockWord;
    int blockWordCount = 0;
    char **blockWords;
    bool blocked = false;

    printf("Enter a URL to visit: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = 0;

    printf("Enter words to block (separated by space, max %d): ", MAX_KEYWORD_LENGTH);
    blockWords = (char**) malloc (MAX_KEYWORD_LENGTH * sizeof(char*));
    blockWord = strtok((char*) argv[1], " ");
    while (blockWord != NULL) {
        if (blockWordCount >= MAX_KEYWORD_LENGTH) {
            printf("Maximum number of keywords reached. Continuing with previous keywords.\n");
            break;
        }
        blockWords[blockWordCount] = blockWord;
        blockWordCount++;
        blockWord = strtok(NULL, " ");
    }

    printf("Checking for blocked words in URL...\n");
    for (int i = 0; i < blockWordCount; i++) {
        if (strstr(url, blockWords[i]) != NULL) {
            printf("WARNING: Blocked word '%s' found in URL.\n", blockWords[i]);
            blocked = true;
        }
    }

    if (blocked) {
        printf("This website is not safe to visit.\n");
    } else {
        printf("This website is safe to visit.\n");
    }

    return 0;
}

char* extractUrl(char* input) {
    char *start = strstr(input, "http");
    if (start == NULL) {
        start = strstr(input, "www");
        if (start == NULL) {
            return NULL;
        } else {
            start = strstr(input, "://");
            if (start != NULL) {
                start += 3;
            } else {
                start = input + 4;
            }
        }
    } else {
        start = strstr(input, "://");
        start += 3;
    }
    char *end = strstr(start, "/");
    if (end == NULL) {
        end = start + strlen(start);
    }
    char *url = (char*) malloc ((end-start+1) * sizeof(char));
    strncpy(url, start, (end-start));
    url[end-start] = '\0';
    return url;
}