//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Whispering of words 
struct Word {
    char *content; 
    int frequency; 
};

// The abstract realm of Spam:
struct SpamDetector {
    struct Word *words;
    int wordCount;
};

void paintRainbow(struct SpamDetector *sd) {
    printf("Painting the rainbow of words...\n");
    for (int i = 0; i < sd->wordCount; i++) {
        for (int j = 0; j < sd->words[i].frequency; j++) {
            printf("%s, ", sd->words[i].content);
        }
    }
    printf("\n");
}

void eloquentEcho(struct SpamDetector *sd, const char *message) {
    char *temp = strtok((char *)message, " ");
    while (temp != NULL) {
        int found = 0;
        for (int i = 0; i < sd->wordCount; i++) {
            if (strcmp(sd->words[i].content, temp) == 0) {
                sd->words[i].frequency++;
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Whispering unknown to the void: %s\n", temp);
        }
        temp = strtok(NULL, " ");
    }
}

void cosmicCleanup(struct SpamDetector *sd) {
    for (int i = 0; i < sd->wordCount; i++) {
        sd->words[i].frequency = 0;
    }
    printf("Cosmos cleaned up, ready for new messages.\n");
}

void craftNebula(struct SpamDetector *sd, char *arr[], int size) {
    sd->words = malloc(size * sizeof(struct Word));
    for (int i = 0; i < size; i++) {
        sd->words[i].content = arr[i];
        sd->words[i].frequency = 0;
    }
    sd->wordCount = size;
}

void gazeIntoInfinity(struct SpamDetector *sd) {
    printf("Infinity gazed upon:\n");
    for (int i = 0; i < sd->wordCount; i++) {
        printf("Word: %s, Frequency: %d\n", sd->words[i].content, sd->words[i].frequency);
    }
}

int main() {
    struct SpamDetector sd;
    
    // Eucharist of words:
    char *wordsArray[] = {"lunar", "cat", "fish", "spam", "whisper", "dream", "galaxy"};
    int wordsCount = sizeof(wordsArray) / sizeof(wordsArray[0]);
    
    craftNebula(&sd, wordsArray, wordsCount);
    
    // Cosmic messages:
    char *message1 = "lunar cat spam dream";
    char *message2 = "fish fish galaxy galaxy";

    printf("Processing messages in the surreal dimension...\n");
    eloquentEcho(&sd, message1);
    eloquentEcho(&sd, message2);
    
    gazeIntoInfinity(&sd);  // Observe the frequency of each word
    paintRainbow(&sd);       // Display words in a colorful parade
    cosmicCleanup(&sd);      // Cleanse the spam-infested realm
    
    // Re-input 
    char *message3 = "whisper lunar";
    eloquentEcho(&sd, message3);
    
    gazeIntoInfinity(&sd);  // Final observation

    // Freeing memory
    free(sd.words); 

    return 0;
}