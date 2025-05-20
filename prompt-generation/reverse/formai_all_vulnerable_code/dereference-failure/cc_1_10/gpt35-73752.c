//FormAI DATASET v1.0 Category: Spam Detection System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPAM_WORDS 10
#define MAX_SPAM_MESSAGES 100

char *spam_words[MAX_SPAM_WORDS] = {"money", "offer", "free", "win", "prize", "cash", "discount", "limited", "urgent", "click"};
char *spam_messages[MAX_SPAM_MESSAGES];
int msg_count = 0;

typedef struct spam_detection {
  char message[200];
  int spam_count;
} SpamDetection;

SpamDetection detect_spam_messages() {
  SpamDetection sd;
  sd.spam_count = 0;
  int i, j;
  
  for (i = 0; i < msg_count; i++) {
    char message[200];
    strcpy(message, spam_messages[i]);
    char *word = strtok(message, " \t\n\r");

    while (word != NULL) {
      for (j = 0; j < MAX_SPAM_WORDS; j++) {
        if (strcmp(word, spam_words[j]) == 0) {
          sd.spam_count++;
        }
      }
      
      word = strtok(NULL, " \t\n\r");
    }
  }
  
  strcpy(sd.message, spam_messages[msg_count - 1]);
  return sd;
}

void add_spam_message() {
  char message[200];
  printf("Enter message: ");
  fgets(message, 200, stdin);

  spam_messages[msg_count] = (char *) malloc(sizeof(char) * (strlen(message) + 1));
  strcpy(spam_messages[msg_count], message);
  msg_count++;
}

int main() {
  char choice;

  while (1) {
    printf("1. Add spam message\n");
    printf("2. Detect spam messages\n");
    printf("3. Quit\n");
    printf("Enter choice: ");
    scanf(" %c", &choice);

    switch (choice) {
      case '1':
        add_spam_message();
        break;
      case '2': {
        SpamDetection sd = detect_spam_messages();

        if (sd.spam_count > 0) {
          printf("Spam detected! Message: %s\n", sd.message);
          printf("Spam count: %d\n", sd.spam_count);
        } else {
          printf("No spam detected.\n");
        }
        
        break;
      }

      case '3':
        printf("Quitting spam detection system...\n");
        exit(0);
      default:
        printf("Invalid choice. Try again.\n");
    }
  }

  return 0;
}