//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _SA_LEXICON_ENTRY {
  char* word;
  int score;
} SA_LEXICON_ENTRY;

typedef struct _SA_LEXICON {
  SA_LEXICON_ENTRY* entries;
  int num_entries;
} SA_LEXICON;

typedef struct _SA_CONTEXT {
  char* text;
  int length;
  int current_position;
} SA_CONTEXT;

typedef struct _SA_RESULT {
  int score;
  char* most_positive_word;
  char* most_negative_word;
} SA_RESULT;

SA_LEXICON* load_lexicon(const char* filename) {
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  SA_LEXICON* lexicon = malloc(sizeof(SA_LEXICON));
  lexicon->num_entries = 0;
  lexicon->entries = NULL;

  char line[1024];
  while (fgets(line, sizeof(line), fp) != NULL) {
    char* word = strtok(line, "\t");
    int score = atoi(strtok(NULL, "\t"));
    SA_LEXICON_ENTRY* entry = malloc(sizeof(SA_LEXICON_ENTRY));
    entry->word = strdup(word);
    entry->score = score;
    lexicon->num_entries++;
    lexicon->entries = realloc(lexicon->entries, lexicon->num_entries * sizeof(SA_LEXICON_ENTRY));
    lexicon->entries[lexicon->num_entries - 1] = *entry;
  }

  fclose(fp);
  return lexicon;
}

void free_lexicon(SA_LEXICON* lexicon) {
  for (int i = 0; i < lexicon->num_entries; i++) {
    free(lexicon->entries[i].word);
  }
  free(lexicon->entries);
  free(lexicon);
}

SA_CONTEXT* create_context(const char* text) {
  SA_CONTEXT* context = malloc(sizeof(SA_CONTEXT));
  context->text = strdup(text);
  context->length = strlen(text);
  context->current_position = 0;
  return context;
}

void free_context(SA_CONTEXT* context) {
  free(context->text);
  free(context);
}

SA_RESULT* analyze_sentiment(SA_CONTEXT* context, SA_LEXICON* lexicon) {
  SA_RESULT* result = malloc(sizeof(SA_RESULT));
  result->score = 0;
  result->most_positive_word = NULL;
  result->most_negative_word = NULL;

  int max_score = 0;
  int min_score = 0;

  while (context->current_position < context->length) {
    char* word = strtok(context->text + context->current_position, " ,.-!?");
    if (word == NULL) {
      break;
    }
    SA_LEXICON_ENTRY* entry = lexicon->entries;
    int found = 0;
    for (int i = 0; i < lexicon->num_entries; i++) {
      if (strcmp(word, entry->word) == 0) {
        result->score += entry->score;
        if (entry->score > max_score) {
          max_score = entry->score;
          result->most_positive_word = word;
        }
        if (entry->score < min_score) {
          min_score = entry->score;
          result->most_negative_word = word;
        }
        found = 1;
        break;
      }
      entry++;
    }
    if (!found) {
      context->current_position++;
      continue;
    }
    context->current_position += strlen(word);
  }

  return result;
}

void free_result(SA_RESULT* result) {
  free(result->most_positive_word);
  free(result->most_negative_word);
  free(result);
}

int main() {
  SA_LEXICON* lexicon = load_lexicon("lexicon.txt");
  SA_CONTEXT* context = create_context("This is a great movie!");
  SA_RESULT* result = analyze_sentiment(context, lexicon);
  printf("Sentiment score: %d\n", result->score);
  printf("Most positive word: %s\n", result->most_positive_word);
  printf("Most negative word: %s\n", result->most_negative_word);
  free_result(result);
  free_context(context);
  free_lexicon(lexicon);
  return 0;
}