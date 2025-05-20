//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a spam email
typedef struct {
  char* subject;
  char* body;
  int score;
} SpamEmail;

// Create a new spam email
SpamEmail* new_spam_email(char* subject, char* body) {
  SpamEmail* email = malloc(sizeof(SpamEmail));
  email->subject = strdup(subject);
  email->body = strdup(body);
  email->score = 0;
  return email;
}

// Free the memory allocated for a spam email
void free_spam_email(SpamEmail* email) {
  free(email->subject);
  free(email->body);
  free(email);
}

// Calculate the spam score for an email
int calculate_spam_score(SpamEmail* email) {
  int score = 0;

  // Check for common spam keywords
  char* keywords[] = {"free", "win", "click", "money", "offer"};
  for (int i = 0; i < 5; i++) {
    if (strstr(email->subject, keywords[i]) != NULL) {
      score += 10;
    }
    if (strstr(email->body, keywords[i]) != NULL) {
      score += 5;
    }
  }

  // Check for excessive use of exclamation marks
  int exclamation_count = 0;
  for (int i = 0; i < strlen(email->subject); i++) {
    if (email->subject[i] == '!') {
      exclamation_count++;
    }
  }
  for (int i = 0; i < strlen(email->body); i++) {
    if (email->body[i] == '!') {
      exclamation_count++;
    }
  }
  if (exclamation_count > 5) {
    score += 5;
  }

  // Check for suspicious links
  char* suspicious_links[] = {"http://www.example.com", "http://www.example.net", "http://www.example.org"};
  for (int i = 0; i < 3; i++) {
    if (strstr(email->body, suspicious_links[i]) != NULL) {
      score += 10;
    }
  }

  // Check for sender reputation
  char* sender = "unknown";
  if (strstr(email->subject, "sender@example.com") != NULL) {
    sender = "sender@example.com";
  }
  if (strstr(email->subject, "sender@example.net") != NULL) {
    sender = "sender@example.net";
  }
  if (strstr(email->subject, "sender@example.org") != NULL) {
    sender = "sender@example.org";
  }
  if (strcmp(sender, "known_spammer") == 0) {
    score += 20;
  }

  return score;
}

// Print the spam score for an email
void print_spam_score(SpamEmail* email) {
  printf("Email subject: %s\n", email->subject);
  printf("Email body: %s\n", email->body);
  printf("Spam score: %d\n", email->score);
}

// Main function
int main() {
  // Create a new spam email
  SpamEmail* email = new_spam_email("Free money!", "Click here to win!");

  // Calculate the spam score for the email
  int score = calculate_spam_score(email);

  // Print the spam score for the email
  print_spam_score(email);

  // Free the memory allocated for the email
  free_spam_email(email);

  return 0;
}