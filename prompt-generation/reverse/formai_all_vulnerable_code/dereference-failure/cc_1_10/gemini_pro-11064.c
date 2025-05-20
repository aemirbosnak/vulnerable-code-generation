//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifdef __unix__
#include <sys/time.h>
#endif

int main(int argc, char **argv)
{
    time_t t;
    srand((unsigned) time(&t));
    char *spam_headers[] = {
        "X-Spam-Score: 0.9",
        "X-Spam-Status: Yes",
        "Subject: Free Viagra",
        "From: nigerian_prince@scam.com"
    };
    char *legitimate_headers[] = {
        "X-Spam-Score: 0.0",
        "X-Spam-Status: No",
        "Subject: Meeting Reminder",
        "From: boss@company.com"
    };
    char *headers;
    int num_headers = 4;
    int i;
    int is_spam = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <headers>\n", argv[0]);
        return EXIT_FAILURE;
    }

    headers = argv[1];

    for (i = 0; i < num_headers; i++) {
        if (strstr(headers, spam_headers[i]) != NULL) {
            is_spam = 1;
        }
    }

    if (strstr(headers, legitimate_headers[1]) != NULL) {
        is_spam = 0;
    }

    if (is_spam) {
        printf("This email is spam.\n");
    } else {
        printf("This email is legitimate.\n");
    }

    return EXIT_SUCCESS;
}