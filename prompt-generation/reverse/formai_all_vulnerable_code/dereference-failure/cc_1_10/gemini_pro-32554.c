//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: active
// Greetings from Planet Xarpti!

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// For our highly advanced encryption algorithms
#include <openssl/md5.h>

// Constants and definitions
#define MAX_XARPTI_WORD_LENGTH 32
#define MAX_XARPTI_SENTENCE_LENGTH 256

// Function prototypes
void translateXarptiWord(char *xarpti_word, char *english_word);
void translateXarptiSentence(char *xarpti_sentence, char *english_sentence);
bool isXarptiWord(char *word);
char *xarptiEncode(char *input);
void print_help();

int main(int argc, char *argv[]) {
    // Greetings to the user
    printf("Welcome to the Xarpti-English Translator, Version 1.0!\n");

    // Parse command-line arguments
    if (argc < 3) {
        print_help();
        return 1;
    }

    // Determine translation mode
    bool translate_to_xarpti = strcmp(argv[1], "-tx") == 0;
    bool translate_to_english = strcmp(argv[1], "-te") == 0;

    if (!translate_to_xarpti && !translate_to_english) {
        print_help();
        return 1;
    }

    // Read the input text
    char *input_text = argv[2];

    // Perform translation
    if (translate_to_xarpti) {
        printf("Translating to Xarpti:\n");
        char *xarpti_text = xarptiEncode(input_text);
        printf("%s\n", xarpti_text);
        free(xarpti_text);
    } else if (translate_to_english) {
        printf("Translating to English:\n");
        char english_text[MAX_XARPTI_SENTENCE_LENGTH + 1];
        translateXarptiSentence(input_text, english_text);
        printf("%s\n", english_text);
    }

    return 0;
}

void translateXarptiWord(char *xarpti_word, char *english_word) {
    // Generate a random suffix
    char suffix[4];
    for (int i = 0; i < 3; i++) {
        suffix[i] = 'a' + rand() % 26;
    }
    suffix[3] = '\0';

    // Construct the English word
    strcpy(english_word, xarpti_word);
    strcat(english_word, suffix);
}

void translateXarptiSentence(char *xarpti_sentence, char *english_sentence) {
    // Tokenize the Xarpti sentence
    char *xarpti_words[MAX_XARPTI_SENTENCE_LENGTH];
    int num_xarpti_words = 0;
    char *token = strtok(xarpti_sentence, " ");
    while (token != NULL) {
        xarpti_words[num_xarpti_words++] = token;
        token = strtok(NULL, " ");
    }

    // Translate each Xarpti word
    for (int i = 0; i < num_xarpti_words; i++) {
        char english_word[MAX_XARPTI_WORD_LENGTH + 1];
        translateXarptiWord(xarpti_words[i], english_word);
        strcat(english_sentence, english_word);
        strcat(english_sentence, " ");
    }

    // Remove the trailing whitespace
    english_sentence[strlen(english_sentence) - 1] = '\0';
}

bool isXarptiWord(char *word) {
    // Check if the word contains any non-alphabetical characters
    for (int i = 0; word[i] != '\0'; i++) {
        if (!isalpha(word[i])) {
            return false;
        }
    }

    // If the word does not contain any vowels, it is not a Xarpti word
    if (strchr(word, 'a') == NULL && strchr(word, 'e') == NULL && strchr(word, 'i') == NULL && strchr(word, 'o') == NULL && strchr(word, 'u') == NULL) {
        return false;
    }

    return true;
}

char *xarptiEncode(char *input) {
    // Convert the input to Xarpti using MD5 encryption
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5((unsigned char *)input, strlen(input), digest);

    // Encode the digest into a Xarpti string
    char *xarpti_text = malloc(2 * MD5_DIGEST_LENGTH + 1);
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(xarpti_text + 2 * i, "%02x", digest[i]);
    }
    xarpti_text[2 * MD5_DIGEST_LENGTH] = '\0';

    return xarpti_text;
}

void print_help() {
    printf("Usage: xarpti-translator [-tx|-te] <text>\n");
    printf("\n");
    printf("Options:\n");
    printf("  -tx: Translate from English to Xarpti\n");
    printf("  -te: Translate from Xarpti to English\n");
    printf("\n");
    printf("Example:\n");
    printf("  xarpti-translator -tx \"Hello World\"\n");
    printf("  xarpti-translator -te \"gJ41F2a5nMh\"\n");
}