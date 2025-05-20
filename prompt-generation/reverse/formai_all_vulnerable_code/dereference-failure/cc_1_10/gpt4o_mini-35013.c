//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1024
#define MAX_SUMMARY_LENGTH 256
#define MAX_WORDS 100

// A scribe's quill, assisting in the summation of tales
void craft_summary(char *full_text, char *summary) {
    char *word_list[MAX_WORDS];
    char *word;
    int word_count = 0;

    // Break the full text into words, much like a thoughtful scribe would
    word = strtok(full_text, " ,.-!?");
    while (word != NULL && word_count < MAX_WORDS) {
        word_list[word_count++] = word;
        word = strtok(NULL, " ,.-!?");
    }

    // Gather the first few words for our summary
    summary[0] = '\0'; // Ensuring the summary string is indeed empty
    for (int i = 0; i < word_count && i < 10; i++) { // First ten words shall be sufficient
        strcat(summary, word_list[i]);
        strcat(summary, " ");
    }

    // Ending with a noble period
    strcat(summary, "...");
}

// The bard shall recite the story with grandeur
void recite_story(char *story) {
    printf("Once upon a time, in a realm far and wide,\n");
    printf("%s\n", story);
    printf("Thus ends our tale, worthy listeners.\n");
}

int main() {
    char *kingdom_story = (char *)malloc(MAX_TEXT_LENGTH);
    char summary[MAX_SUMMARY_LENGTH];

    // The tale that is spun as one walks through the forest of words
    printf("Gather 'round, noble folk, and lend me thine ears.\n");
    printf("Pray, enter the epic text of yore (max %d characters):\n", MAX_TEXT_LENGTH - 1);
    fgets(kingdom_story, MAX_TEXT_LENGTH, stdin);
    
    // Remove the newline character if it exists
    size_t len = strlen(kingdom_story);
    if (len > 0 && kingdom_story[len - 1] == '\n') {
        kingdom_story[len - 1] = '\0';
    }

    // A scribe works meticulously to summarize the grand tale
    craft_summary(kingdom_story, summary);

    // And lo, the bard recites the summary of the tale
    printf("\nThe bard hath penned a summary of thine epic:\n");
    printf("%s\n", summary);

    // Release the memory allotted for the tale
    free(kingdom_story);
    
    // Let us conclude with cheer! 
    printf("Rejoice, for the story hath been told and retold!\n");
    return 0;
}