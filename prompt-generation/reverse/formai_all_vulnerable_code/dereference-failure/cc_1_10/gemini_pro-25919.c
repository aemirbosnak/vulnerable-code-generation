//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store information about a potential spam message
typedef struct {
  char *sender;
  char *receiver;
  char *subject;
  char *body;
  int score;
} message_t;

// Define a function to initialize a new message struct
message_t *init_message(char *sender, char *receiver, char *subject, char *body) {
  message_t *msg = malloc(sizeof(message_t));
  msg->sender = malloc(strlen(sender) + 1);
  strcpy(msg->sender, sender);
  msg->receiver = malloc(strlen(receiver) + 1);
  strcpy(msg->receiver, receiver);
  msg->subject = malloc(strlen(subject) + 1);
  strcpy(msg->subject, subject);
  msg->body = malloc(strlen(body) + 1);
  strcpy(msg->body, body);
  msg->score = 0;
  return msg;
}

// Define a function to free the memory allocated for a message struct
void free_message(message_t *msg) {
  free(msg->sender);
  free(msg->receiver);
  free(msg->subject);
  free(msg->body);
  free(msg);
}

// Define a function to calculate the spam score of a message
int calculate_spam_score(message_t *msg) {
  int score = 0;

  // Check the sender's email address
  if (strstr(msg->sender, "spam") != NULL) {
    score += 10;
  }

  // Check the receiver's email address
  if (strstr(msg->receiver, "spam") != NULL) {
    score += 5;
  }

  // Check the subject line
  if (strstr(msg->subject, "spam") != NULL) {
    score += 10;
  }

  // Check the body of the message
  if (strstr(msg->body, "spam") != NULL) {
    score += 10;
  }

  // Check for other spammy keywords
  if (strstr(msg->body, "free") != NULL) {
    score += 5;
  }

  if (strstr(msg->body, "offer") != NULL) {
    score += 5;
  }

  if (strstr(msg->body, "click here") != NULL) {
    score += 5;
  }

  return score;
}

// Define a function to classify a message as spam or not spam
int classify_message(message_t *msg) {
  int score = calculate_spam_score(msg);

  if (score >= 50) {
    return 1;  // Spam
  } else {
    return 0;  // Not spam
  }
}

// Define a function to test the spam detection system
void test_spam_detection_system() {
  // Create a few test messages
  message_t *msg1 = init_message("spam@example.com", "user@example.com", "Spam", "This is a spam message.");
  message_t *msg2 = init_message("user@example.com", "user2@example.com", "Not spam", "This is not a spam message.");
  message_t *msg3 = init_message("spam@example.com", "user3@example.com", "Free offer", "Click here to get your free offer!");

  // Classify the test messages
  int result1 = classify_message(msg1);
  int result2 = classify_message(msg2);
  int result3 = classify_message(msg3);

  // Print the results
  printf("Message 1: %s\n", result1 ? "Spam" : "Not spam");
  printf("Message 2: %s\n", result2 ? "Spam" : "Not spam");
  printf("Message 3: %s\n", result3 ? "Spam" : "Not spam");

  // Free the memory allocated for the test messages
  free_message(msg1);
  free_message(msg2);
  free_message(msg3);
}

// Define the main function
int main() {
  // Test the spam detection system
  test_spam_detection_system();

  return 0;
}