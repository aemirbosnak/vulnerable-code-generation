//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define BUF_SIZE 1024
#define WORD "example"  // The word to count

void rdy(const char *msg) {
    printf("\033[1;34m%s\033[0m\n", msg); // Fancy message print
}

int cntWords(const char *data) {
    regex_t regex;
    int reti, count = 0;

    reti = regcomp(&regex, WORD, REG_ICASE); // Compile regex
    if (reti) {
        rdy("Regex compilation failed!");
        exit(1);
    }

    char *p = (char *)data;
    while (*p) {
        reti = regexec(&regex, p, 0, NULL, 0);
        if (!reti) {
            count++;
            p += strlen(WORD); // Move pointer past the match
        } else {
            p++; // Move to the next character
        }
    }

    regfree(&regex);
    return count;
}

void fetchAndCount(const char *url) {
    rdy("Fetching data...");
    char buffer[BUF_SIZE];
    char *data = (char *)calloc(1, BUF_SIZE);
    
    // Simulating fetching HTML (In real usage, you'd use libcurl or similar)
    snprintf(buffer, BUF_SIZE, "This is an example of the example word appearing multiple times. Example could lead to examples.");
    strcat(data, buffer); 
    
    int count = cntWords(data);
    printf("\033[1;32mThe word '%s' appeared %d times.\033[0m\n", WORD, count);
    
    free(data);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        rdy("Usage: ./plugin <url>");
        return 1;
    }
    
    char *url = argv[1];
    fetchAndCount(url);
    
    return 0;
}