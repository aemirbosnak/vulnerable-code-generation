//Gemma-7B DATASET v1.0 Category: Email Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct EmailClient {
  char **inbox;
  int inbox_size;
  char **sent_mail;
  int sent_mail_size;
  char **draft;
  int draft_size;
  char **cur_mail;
  int cur_mail_size;
} EmailClient;

EmailClient *email_client_init(int size) {
  EmailClient *client = malloc(sizeof(EmailClient));
  client->inbox = malloc(sizeof(char *) * size);
  client->inbox_size = size;
  client->sent_mail = malloc(sizeof(char *) * size);
  client->sent_mail_size = size;
  client->draft = malloc(sizeof(char *) * size);
  client->draft_size = size;
  client->cur_mail = malloc(sizeof(char *) * MAX_BUFFER_SIZE);
  client->cur_mail_size = MAX_BUFFER_SIZE;

  return client;
}

void email_client_add_inbox(EmailClient *client, char *mail) {
  client->inbox[client->inbox_size++] = mail;
}

void email_client_add_sent_mail(EmailClient *client, char *mail) {
  client->sent_mail[client->sent_mail_size++] = mail;
}

void email_client_add_draft(EmailClient *client, char *mail) {
  client->draft[client->draft_size++] = mail;
}

void email_client_set_cur_mail(EmailClient *client, char *mail) {
  client->cur_mail[client->cur_mail_size++] = mail;
}

int email_client_get_inbox_size(EmailClient *client) {
  return client->inbox_size;
}

int email_client_get_sent_mail_size(EmailClient *client) {
  return client->sent_mail_size;
}

int email_client_get_draft_size(EmailClient *client) {
  return client->draft_size;
}

char *email_client_get_cur_mail(EmailClient *client) {
  return client->cur_mail[0];
}

void email_client_free(EmailClient *client) {
  free(client->inbox);
  free(client->sent_mail);
  free(client->draft);
  free(client->cur_mail);
  free(client);
}

int main() {
  EmailClient *client = email_client_init(10);

  char *mail1 = "This is the first email";
  email_client_add_inbox(client, mail1);

  char *mail2 = "This is the second email";
  email_client_add_inbox(client, mail2);

  char *mail3 = "This is the third email";
  email_client_add_inbox(client, mail3);

  email_client_set_cur_mail(client, mail2);

  printf("%s", email_client_get_cur_mail(client));

  email_client_free(client);

  return 0;
}