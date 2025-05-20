//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: shape shifting
// Welcome to the C Spam Detection System, an ever-changing entity against the tide of spam!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our shape-shifting spam filter, adapting to the ever-changing landscape
typedef struct {
    char** keywords;
    int num_keywords;
    int sensitivity;
} SpamFilter;

// Initialize our filter with a set of keywords and sensitivity level
SpamFilter* init_filter(char** keywords, int num_keywords, int sensitivity) {
    SpamFilter* filter = malloc(sizeof(SpamFilter));
    filter->keywords = keywords;
    filter->num_keywords = num_keywords;
    filter->sensitivity = sensitivity;
    return filter;
}

// Scan a message for spam using our filter
int scan_message(char* message, SpamFilter* filter) {
    int matches = 0;
    for (int i = 0; i < filter->num_keywords; i++) {
        if (strstr(message, filter->keywords[i]) != NULL) {
            matches++;
        }
    }
    return matches >= filter->sensitivity;
}

int main() {

    // Sample message to test our filter on
    char* message = "Dear Sir/Madam, You have won a free cruise to the Bahamas! Click here: www.suspiciouslink.com";

    // Create our spam filter
    SpamFilter* filter = init_filter((char*[]){"free", "cruise", "click"}, 3, 2);

    // Perform the scan
    int is_spam = scan_message(message, filter);

    // Determine if the message is spam
    if (is_spam) {
        printf("Spam detected!\n");
    } else {
        printf("Message is not spam.\n");
    }

    return 0;
}