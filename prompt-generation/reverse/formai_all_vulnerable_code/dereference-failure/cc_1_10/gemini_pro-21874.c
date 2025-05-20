//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAILING_LIST_MAX_SIZE 100

typedef struct {
  char *email;
  char *name;
} mailing_list_entry;

mailing_list_entry mailing_list[MAILING_LIST_MAX_SIZE];
int mailing_list_size = 0;

void add_to_mailing_list(char *email, char *name) {
  if (mailing_list_size < MAILING_LIST_MAX_SIZE) {
    mailing_list[mailing_list_size].email = strdup(email);
    mailing_list[mailing_list_size].name = strdup(name);
    mailing_list_size++;
  }
}

void remove_from_mailing_list(char *email) {
  for (int i = 0; i < mailing_list_size; i++) {
    if (strcmp(mailing_list[i].email, email) == 0) {
      free(mailing_list[i].email);
      free(mailing_list[i].name);
      for (int j = i; j < mailing_list_size - 1; j++) {
        mailing_list[j] = mailing_list[j + 1];
      }
      mailing_list_size--;
      break;
    }
  }
}

void send_email(char *subject, char *body) {
  for (int i = 0; i < mailing_list_size; i++) {
    printf("Sending email to %s (%s)\n", mailing_list[i].name, mailing_list[i].email);
    printf("Subject: %s\n", subject);
    printf("Body: %s\n", body);
  }
}

int main() {
  add_to_mailing_list("john@example.com", "John Doe");
  add_to_mailing_list("jane@example.com", "Jane Doe");
  add_to_mailing_list("bob@example.com", "Bob Smith");

  send_email("Hello world", "This is a test email.");

  remove_from_mailing_list("bob@example.com");

  send_email("Goodbye", "This is a goodbye email.");

  return 0;
}