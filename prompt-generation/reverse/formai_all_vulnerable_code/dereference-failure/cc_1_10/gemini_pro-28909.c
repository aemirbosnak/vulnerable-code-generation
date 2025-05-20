//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

// Linguistic analysis tools, worthy of the great detective
#define WATSON_LEXICON_SIZE 1000
static const char* WATSON_LEXICON[WATSON_LEXICON_SIZE] = {
    "admirable", "affectionate", "agreeable", "amiable", "amusing",
    "bashful", "bewildered", "blissful", "brave", "bright",
    "careful", "charming", "cheerful", "chummy", "clever",
    "cloudy", "comfortable", "compassionate", "considerate", "contented",
    "crazy", "cross", "curious",
    "daffy", "daring", "dashing", "delightful", "determined",
    "disgusted", "distressed", "doubtful", "downhearted", "dull",
    "eager", "easygoing", "ecstatic", "elated", "enchanted",
    "encouraging", "energetic", "enthusiastic", "envious", "excited",
    "faithful", "familiar", "famous", "fanciful", "fascinating",
    "fearful", "festive", "fierce", "fine", "foolish",
    "fortunate", "frank", "friendly", "funny", "furious",
    "gallant", "generous", "gentle", "giddy", "gloomy",
    "goofy", "gorgeous", "graceful", "grateful", "great",
    "handsome", "happy", "harmonious", "healthy", "helpful",
    "hilarious", "homely", "hopeful", "horrible", "hospitable",
    "humble", "humorous", "hungry",
    "ill-tempered", "important", "impossible", "industrious", "intelligent",
    "interesting", "irritated",
    "jealous", "jolly", "joyful", "jubilant", "judicious",
    "kind", "knowledgeable",
    "languid", "lazy", "lively", "lonely", "lovely",
    "lucky", "ludicrous",
    "mad", "magnificent", "majestic", "marvelous", "meek",
    "merry", "miserable", "mistaken", "moody", "mournful",
    "nervous", "nice", "nutty",
    "obedient", "obnoxious", "odd", "old-fashioned", "optimistic",
    "outrageous", "outstanding", "overjoyed", "overwhelmed", "painful",
    "plucky", "poor", "powerful", "prejudiced", "prickly",
    "proud", "prudent",
    "quaint", "quarrelsome", "queer", "quirky",
    "radiant", "rambunctious", "rare", "relieved", "repulsive",
    "rich", "romantic", "rude",
    "sad", "sarcastic", "satisfied", "scared", "scornful",
    "secretive", "selfish", "serious", "shabby", "sharp",
    "shy", "silly", "simple", "skillful", "sleepy",
    "small", "smart", "smiling", "solemn", "sophisticated",
    "sore", "sorry", "splendid", "startled", "stupid",
    "successful", "sulky", "super", "suspicious", "sweet",
    "talented", "tame", "tender", "terrible", "thankful",
    "thoughtful", "thoughtless", "tidy", "timid", "tired",
    "tolerant", "tremendous", "tricky", "trustworthy", "unbearable",
    "uncertain", "uncomfortable", "unfair", "unfortunate", "unfriendly",
    "unhappy", "unhealthy", "unique", "unusual", "upset",
    "uptight", "useless",
    "vain", "victorious", "vigorous", "vivacious", "vulgar",
    "warm", "wealthy", "weary", "wicked", "wild",
    "willing", "wonderful", "worried", "worthless", "wretched",
    "zany", "zealous"
};

// Hash table to store word frequencies
#define HASH_TABLE_SIZE 1000
typedef struct {
    char* word;
    int frequency;
} WordFrequency;
WordFrequency* HASH_TABLE[HASH_TABLE_SIZE];

// Hash function to map words to indices
unsigned int hash(const char* word) {
    unsigned int hash_value = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        hash_value += word[i];
    }
    return hash_value % HASH_TABLE_SIZE;
}

// Insert a word into the hash table
void insert_word(const char* word) {
    unsigned int index = hash(word);
    if (HASH_TABLE[index] == NULL) {
        HASH_TABLE[index] = malloc(sizeof(WordFrequency));
        HASH_TABLE[index]->word = strdup(word);
        HASH_TABLE[index]->frequency = 1;
    } else {
        HASH_TABLE[index]->frequency++;
    }
}

// Get the frequency of a word in the hash table
int get_frequency(const char* word) {
    unsigned int index = hash(word);
    if (HASH_TABLE[index] == NULL) {
        return 0;
    } else {
        return HASH_TABLE[index]->frequency;
    }
}

// Analyze the sentiment of a text
int analyze_sentiment(const char* text) {
    // Count the frequency of positive and negative words
    int positive_count = 0;
    int negative_count = 0;
    char* token = strtok(text, " ");
    while (token != NULL) {
        if (get_frequency(token) > 0) {
            if (strstr(token, "not") != NULL) {
                negative_count++;
            } else {
                positive_count++;
            }
        }
        token = strtok(NULL, " ");
    }

    // Determine the overall sentiment
    int sentiment;
    if (positive_count > negative_count) {
        sentiment = 1;
    } else if (negative_count > positive_count) {
        sentiment = -1;
    } else {
        sentiment = 0;
    }

    // Return the sentiment
    return sentiment;
}

// Main function
int main() {
    // Load the Watson Lexicon into the hash table
    for (int i = 0; i < WATSON_LEXICON_SIZE; i++) {
        insert_word(WATSON_LEXICON[i]);
    }

    // Get the text to be analyzed
    char* text = "The dog barked at the mailman.";

    // Analyze the sentiment of the text
    int sentiment = analyze_sentiment(text);

    // Print the results
    if (sentiment == 1) {
        printf("The text has a positive sentiment.\n");
    } else if (sentiment == -1) {
        printf("The text has a negative sentiment.\n");
    } else {
        printf("The text has a neutral sentiment.\n");
    }

    return 0;
}