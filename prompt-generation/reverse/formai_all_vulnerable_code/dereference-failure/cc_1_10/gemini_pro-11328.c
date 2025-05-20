//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct _SpamFilter {
  char *phrase;
  int count;
} SpamFilter;

typedef struct _SpamDetector {
  SpamFilter *filters;
  int num_filters;
} SpamDetector;

// Function prototypes
SpamDetector *create_spam_detector(void);
void destroy_spam_detector(SpamDetector *detector);
int add_filter(SpamDetector *detector, char *phrase);
int remove_filter(SpamDetector *detector, char *phrase);
int check_spam(SpamDetector *detector, char *message);

// Main function
int main(void) {
  // Create a spam detector
  SpamDetector *detector = create_spam_detector();

  // Add some filters
  add_filter(detector, "free money");
  add_filter(detector, "click here");
  add_filter(detector, "viagra");

  // Check a message for spam
  char *message = "I'm not interested in your free money or your viagra.";
  int is_spam = check_spam(detector, message);

  // Print the result
  if (is_spam) {
    printf("The message is spam.\n");
  } else {
    printf("The message is not spam.\n");
  }

  // Destroy the spam detector
  destroy_spam_detector(detector);

  return 0;
}

// Function definitions
SpamDetector *create_spam_detector(void) {
  SpamDetector *detector = malloc(sizeof(SpamDetector));
  detector->filters = NULL;
  detector->num_filters = 0;
  return detector;
}

void destroy_spam_detector(SpamDetector *detector) {
  for (int i = 0; i < detector->num_filters; i++) {
    free(detector->filters[i].phrase);
  }
  free(detector->filters);
  free(detector);
}

int add_filter(SpamDetector *detector, char *phrase) {
  detector->filters = realloc(detector->filters, (detector->num_filters + 1) * sizeof(SpamFilter));
  detector->filters[detector->num_filters].phrase = strdup(phrase);
  detector->filters[detector->num_filters].count = 0;
  detector->num_filters++;
  return 0;
}

int remove_filter(SpamDetector *detector, char *phrase) {
  for (int i = 0; i < detector->num_filters; i++) {
    if (strcmp(detector->filters[i].phrase, phrase) == 0) {
      for (int j = i + 1; j < detector->num_filters; j++) {
        detector->filters[j - 1] = detector->filters[j];
      }
      detector->num_filters--;
      return 0;
    }
  }
  return -1;
}

int check_spam(SpamDetector *detector, char *message) {
  for (int i = 0; i < detector->num_filters; i++) {
    if (strstr(message, detector->filters[i].phrase) != NULL) {
      detector->filters[i].count++;
      return 1;
    }
  }
  return 0;
}