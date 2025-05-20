//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A bag of tricks to keep naughty URLs out of our sight
static const char *baddies[] = {
    "http://www.example.com/naughty",
    "https://www.example.com/naughty",
    "ftp://www.example.com/naughty",
    "file:///etc/passwd",
    "javascript:alert('naughty!')",
};

// A magical function to check if a URL is naughty
static int is_naughty(const char *url) {
    for (int i = 0; i < sizeof(baddies) / sizeof(baddies[0]); i++) {
        if (strstr(url, baddies[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

// The main event: a URL sanitizer that's a riddle wrapped in a mystery
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    const char *url = argv[1];

    // Let's play a guessing game: is our URL naughty or nice?
    int naughty = is_naughty(url);

    // Time for a little deception: let's obfuscate the naughty parts
    char *sanitized = malloc(strlen(url) + 1);
    strcpy(sanitized, url);
    for (int i = 0; i < sizeof(baddies) / sizeof(baddies[0]); i++) {
        char *naughty_part = strstr(sanitized, baddies[i]);
        if (naughty_part != NULL) {
            memset(naughty_part, '*', strlen(baddies[i]));
        }
    }

    // The grand reveal: is our URL still naughty?
    naughty = is_naughty(sanitized);

    // And now, the punchline: let's expose the truth
    if (naughty) {
        printf("Naughty URL detected: %s\n", url);
    } else {
        printf("Sanitized URL: %s\n", sanitized);
    }

    free(sanitized);
    return 0;
}