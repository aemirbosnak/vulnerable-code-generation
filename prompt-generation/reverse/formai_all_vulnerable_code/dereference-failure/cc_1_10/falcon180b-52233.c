//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordFrequency;

typedef struct {
    char *word;
    char *translation;
} TranslationPair;

typedef struct {
    TranslationPair *pairs;
    int count;
} TranslationTable;

void initializeTable(TranslationTable *table) {
    table->pairs = malloc(sizeof(TranslationPair) * MAX_TOKENS);
    table->count = 0;
}

void addTranslationPair(TranslationTable *table, char *english, char *french) {
    TranslationPair pair;
    pair.word = strdup(english);
    pair.translation = strdup(french);
    table->pairs[table->count++] = pair;
}

char *translateWord(TranslationTable *table, char *word) {
    int i;
    for (i = 0; i < table->count; i++) {
        if (strcmp(table->pairs[i].word, word) == 0) {
            return table->pairs[i].translation;
        }
    }
    return NULL;
}

void translateSentence(TranslationTable *table, char *sentence) {
    char *token;
    char *translatedToken;
    int i, j;
    for (i = 0, j = 0; i < strlen(sentence); i++) {
        if (isspace(sentence[i])) {
            token = malloc(sizeof(char) * (j + 1));
            strncpy(token, sentence + i - j, j);
            token[j] = '\0';
            translatedToken = translateWord(table, token);
            printf("%s ", translatedToken? translatedToken : "unknown");
            j = 0;
        } else if (j < MAX_WORD_LENGTH) {
            sentence[i] = tolower(sentence[i]);
            j++;
        }
    }
    printf("\n");
}

int main() {
    TranslationTable table;
    initializeTable(&table);
    addTranslationPair(&table, "cat", "chat");
    addTranslationPair(&table, "dog", "chien");
    addTranslationPair(&table, "hello", "bonjour");
    addTranslationPair(&table, "world", "monde");
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence to translate: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    translateSentence(&table, sentence);
    return 0;
}