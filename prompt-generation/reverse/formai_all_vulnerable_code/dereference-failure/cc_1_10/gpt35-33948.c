//FormAI DATASET v1.0 Category: Spam Detection System ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER_SIZE 4096                 // Max input buffer size
#define SPAM_THRESHOLD 0.05              // Define spam threshold probability
#define MAX_WORD_COUNT 500               // Maximum number of words in a message
#define WORD_LENGTH_LIMIT 50             // Maximum length of a word
#define MAX_SPAM_TAG_LENGTH 50           // Maximum length of a spam tag

// Define spam probability struct to hold probability values
typedef struct spam_probability {
    double overallProbability;
    double wordProbability[MAX_WORD_COUNT];
    int wordCount;
} SPAM_PROBABILITY;

// Function to clean up input message
char* clean_up_message(char *message) {
    char *cleanMessage = (char*)malloc(BUFFER_SIZE);
    char *tempMessage = (char*)malloc(BUFFER_SIZE);
    char *token;

    memset(tempMessage, 0, BUFFER_SIZE);
    strcpy(tempMessage, message);        // Copy message to temporary string

    // Removing punctuations and converting to lower case
    for(int i = 0; i < strlen(tempMessage); i++) {
        if(((tempMessage[i] >= 'a') && (tempMessage[i] <= 'z')) ||
           ((tempMessage[i] >= 'A') && (tempMessage[i] <= 'Z'))) {
            cleanMessage[strlen(cleanMessage)] = tolower(tempMessage[i]);
        }
    }

    // Tokenizing and re-constructing message
    token = strtok(cleanMessage, " ");
    memset(cleanMessage, 0, BUFFER_SIZE);

    while(token != NULL) {
        strcat(cleanMessage, token);
        strcat(cleanMessage, " ");
        token = strtok(NULL, " ");
    }

    free(tempMessage);
    return cleanMessage;
}

// Function to calculate word probability
double calculate_word_probability(char *word, char **spamWords, int spamWordCount,
                                   char **hamWords, int hamWordCount) {
    double probability = 0;
    double spamCount = 0, hamCount = 0;

    // Count the total number of spam and ham occurrences for given word
    for(int i = 0; i < spamWordCount; i++) {
        if(strcmp(word, spamWords[i]) == 0) {
            spamCount++;
        }
    }

    for(int i = 0; i < hamWordCount; i++) {
        if(strcmp(word, hamWords[i]) == 0) {
            hamCount++;
        }
    }

    // Calculate probability
    if((spamCount + hamCount) > 0) {
        probability = (spamCount / (double) spamWordCount) /
                      ((spamCount / (double) spamWordCount) + (hamCount / (double) hamWordCount));
    }

    return probability;
}

// Function to calculate overall spam probability of a message
SPAM_PROBABILITY calculate_spam_probability(char *message, char **spamWords, int spamWordCount,
                                             char **hamWords, int hamWordCount) {
    char **words = (char**)malloc(sizeof(char*) * MAX_WORD_COUNT);
    char *token;
    double probability = 1;
    int wordCount = 0;
    SPAM_PROBABILITY spamProbability;

    // Clean up message and tokenize it
    message = clean_up_message(message);

    token = strtok(message, " ");

    while(token != NULL) {
        words[wordCount] = (char*)malloc(WORD_LENGTH_LIMIT);
        strcpy(words[wordCount], token);
        wordCount++;
        token = strtok(NULL, " ");
    }

    spamProbability.wordCount = wordCount;

    // Calculate word probabilities and overall probability
    for(int i = 0; i < wordCount; i++) {
        spamProbability.wordProbability[i] = calculate_word_probability(words[i], spamWords, spamWordCount,
                                                                            hamWords, hamWordCount);
        probability *= (1 - spamProbability.wordProbability[i]);
    }

    spamProbability.overallProbability = 1 - probability;

    // Clean up memory and return probability struct
    for(int i = 0; i < wordCount; i++) {
        free(words[i]);
    }

    free(words);
    free(message);

    return spamProbability;
}

// Function to check spam probability against threshold and tag message
char* tag_spam_messages(char *message, char **spamWords, int spamWordCount,
                        char **hamWords, int hamWordCount, char *spamTag) {
    SPAM_PROBABILITY probability = calculate_spam_probability(message, spamWords, spamWordCount,
                                                               hamWords, hamWordCount);
    char *taggedMessage = (char*)malloc(BUFFER_SIZE);

    // Add spam tag to detected spam messages
    if(probability.overallProbability >= SPAM_THRESHOLD) {
        sprintf(taggedMessage, "%s %s", message, spamTag);
    } else {
        strcpy(taggedMessage, message);
    }

    return taggedMessage;
}

int main() {
    // Initialize spam and ham word arrays
    char *spamWords[] = {"buy", "cheap", "free", "viagra", "enlarge", "giveaway", "prize", "win", "cash"};
    char *hamWords[] = {"hello", "world", "read", "this", "information", "and", "learn", "new", "things"};

    char *spamMessage1 = "Buy two get one free! Limited time offer.";
    char *spamMessage2 = "You have been selected to receive a cash prize of $10,000!";
    char *hamMessage1 = "Hello World! How are you doing today?";
    char *hamMessage2 = "Read this message to learn new information.";

    char *taggedMessage;

    // Tag spam messages with spam tag
    taggedMessage = tag_spam_messages(spamMessage1, spamWords, (sizeof(spamWords)/sizeof(char*)),
                                      hamWords, (sizeof(hamWords)/sizeof(char*)), "[SPAM]");
    printf("%s\n", taggedMessage);
    free(taggedMessage);

    taggedMessage = tag_spam_messages(spamMessage2, spamWords, (sizeof(spamWords)/sizeof(char*)),
                                      hamWords, (sizeof(hamWords)/sizeof(char*)), "[SPAM]");
    printf("%s\n", taggedMessage);
    free(taggedMessage);

    // Leave ham messages untagged
    taggedMessage = tag_spam_messages(hamMessage1, spamWords, (sizeof(spamWords)/sizeof(char*)),
                                      hamWords, (sizeof(hamWords)/sizeof(char*)), "[SPAM]");
    printf("%s\n", taggedMessage);
    free(taggedMessage);

    taggedMessage = tag_spam_messages(hamMessage2, spamWords, (sizeof(spamWords)/sizeof(char*)),
                                      hamWords, (sizeof(hamWords)/sizeof(char*)), "[SPAM]");
    printf("%s\n", taggedMessage);
    free(taggedMessage);

    return 0;
}