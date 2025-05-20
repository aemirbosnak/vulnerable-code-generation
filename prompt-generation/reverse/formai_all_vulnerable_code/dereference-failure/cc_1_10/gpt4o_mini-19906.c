//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 256
#define MAX_KEYWORDS 10
#define MAX_KEYWORD_LENGTH 20
#define MAX_MESSAGES 100

typedef struct {
    char** keywords;
    int keyword_count;
} SpamFilter;

void initializeSpamFilter(SpamFilter* filter) {
    filter->keywords = (char**) malloc(MAX_KEYWORDS * sizeof(char*));
    for (int i = 0; i < MAX_KEYWORDS; i++) {
        filter->keywords[i] = (char*) malloc(MAX_KEYWORD_LENGTH * sizeof(char));
    }
    filter->keyword_count = 0;
}

void addKeyword(SpamFilter* filter, const char* keyword) {
    if (filter->keyword_count < MAX_KEYWORDS) {
        strcpy(filter->keywords[filter->keyword_count], keyword);
        filter->keyword_count++;
    }
}

int isSpam(SpamFilter* filter, const char* message) {
    for (int i = 0; i < filter->keyword_count; i++) {
        if (strstr(message, filter->keywords[i]) != NULL) {
            return 1; // Spam found
        }
    }
    return 0; // No spam
}

void freeSpamFilter(SpamFilter* filter) {
    for (int i = 0; i < MAX_KEYWORDS; i++) {
        free(filter->keywords[i]);
    }
    free(filter->keywords);
}

void processMessages(const char* input_filename, const char* output_filename, SpamFilter* filter) {
    FILE* input_file = fopen(input_filename, "r");
    FILE* output_file = fopen(output_filename, "w");
    
    if (input_file == NULL || output_file == NULL) {
        fprintf(stderr, "Error opening files.\n");
        return;
    }

    char message[MAX_MESSAGE_LENGTH];
    while (fgets(message, sizeof(message), input_file)) {
        if (isSpam(filter, message)) {
            fprintf(output_file, "SPAM: %s", message);
        } else {
            fprintf(output_file, "NOT SPAM: %s", message);
        }
    }

    fclose(input_file);
    fclose(output_file);
}

void printUsage() {
    printf("Usage: ./spam_detector <input_file> <output_file>\n");
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printUsage();
        return 1;
    }

    const char* input_file = argv[1];
    const char* output_file = argv[2];

    SpamFilter filter;
    initializeSpamFilter(&filter);

    // Define spam keywords
    addKeyword(&filter, "buy now");
    addKeyword(&filter, "click here");
    addKeyword(&filter, "limited offer");
    addKeyword(&filter, "free");
    addKeyword(&filter, "winner");
    addKeyword(&filter, "urgent");
    addKeyword(&filter, "risk-free");
    addKeyword(&filter, "money back");
    addKeyword(&filter, "act now");
    addKeyword(&filter, "exclusive deal");

    // Process messages from file
    processMessages(input_file, output_file, &filter);

    // Cleanup
    freeSpamFilter(&filter);

    printf("Spam detection complete. Results written to %s\n", output_file);
    return 0;
}