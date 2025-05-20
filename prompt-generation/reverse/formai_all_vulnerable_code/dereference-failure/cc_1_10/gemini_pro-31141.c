//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 50
#define MAX_BODY_LEN 2000
#define MAX_ATTACHMENTS 10

struct attachment {
  char *filename;
  size_t size;
  char *mime_type;
};

struct email {
  char *from;
  char *to;
  char *subject;
  char *body;
  struct attachment *attachments;
  int num_attachments;
};

struct email *create_email(char *from, char *to, char *subject, char *body) {
  struct email *email = malloc(sizeof(struct email));
  email->from = strdup(from);
  email->to = strdup(to);
  email->subject = strdup(subject);
  email->body = strdup(body);
  email->attachments = NULL;
  email->num_attachments = 0;

  return email;
}

void free_email(struct email *email) {
  free(email->from);
  free(email->to);
  free(email->subject);
  free(email->body);
  for (int i = 0; i < email->num_attachments; i++) {
    free(email->attachments[i].filename);
    free(email->attachments[i].mime_type);
  }
  free(email->attachments);
  free(email);
}

int add_attachment(struct email *email, char *filename, size_t size, char *mime_type) {
  if (email->num_attachments >= MAX_ATTACHMENTS) {
    return -1;
  }

  struct attachment *attachment = malloc(sizeof(struct attachment));
  attachment->filename = strdup(filename);
  attachment->size = size;
  attachment->mime_type = strdup(mime_type);

  email->attachments[email->num_attachments] = *attachment;
  email->num_attachments++;

  return 0;
}

int send_email(struct email *email) {
  // TODO: Implement email sending logic
  return 0;
}

int main() {
  struct email *email = create_email("from@example.com", "to@example.com", "Subject", "Body");

  add_attachment(email, "filename.txt", 100, "text/plain");

  send_email(email);

  free_email(email);

  return 0;
}