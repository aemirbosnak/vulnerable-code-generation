//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <pwd.h>

#define MAX_LINE_LENGTH 1024
#define MAX_MAIL_LENGTH 100000

struct mail {
  char *sender;
  char *recipient;
  char *date;
  char *time;
  char *subject;
  char *body;
  struct mail *next;
};

struct mailing_list {
  char *name;
  char *description;
  char *owner;
  struct mail *first_mail;
  struct mail *last_mail;
  struct mailing_list *next;
};

struct user {
  char *username;
  char *password;
  struct mailing_list *first_mailing_list;
  struct mailing_list *last_mailing_list;
  struct user *next;
};

struct system {
  struct user *first_user;
  struct user *last_user;
  struct mailing_list *first_mailing_list;
  struct mailing_list *last_mailing_list;
};

struct system *system_create() {
  struct system *system = malloc(sizeof(struct system));
  system->first_user = NULL;
  system->last_user = NULL;
  system->first_mailing_list = NULL;
  system->last_mailing_list = NULL;
  return system;
}

void system_destroy(struct system *system) {
  // TODO: Free all the memory allocated by the system.
  free(system);
}

struct user *user_create(char *username, char *password) {
  struct user *user = malloc(sizeof(struct user));
  user->username = strdup(username);
  user->password = strdup(password);
  user->first_mailing_list = NULL;
  user->last_mailing_list = NULL;
  return user;
}

void user_destroy(struct user *user) {
  // TODO: Free all the memory allocated by the user.
  free(user->username);
  free(user->password);
  free(user);
}

struct mailing_list *mailing_list_create(char *name, char *description, char *owner) {
  struct mailing_list *mailing_list = malloc(sizeof(struct mailing_list));
  mailing_list->name = strdup(name);
  mailing_list->description = strdup(description);
  mailing_list->owner = strdup(owner);
  mailing_list->first_mail = NULL;
  mailing_list->last_mail = NULL;
  return mailing_list;
}

void mailing_list_destroy(struct mailing_list *mailing_list) {
  // TODO: Free all the memory allocated by the mailing list.
  free(mailing_list->name);
  free(mailing_list->description);
  free(mailing_list->owner);
  free(mailing_list);
}

struct mail *mail_create(char *sender, char *recipient, char *date, char *time, char *subject, char *body) {
  struct mail *mail = malloc(sizeof(struct mail));
  mail->sender = strdup(sender);
  mail->recipient = strdup(recipient);
  mail->date = strdup(date);
  mail->time = strdup(time);
  mail->subject = strdup(subject);
  mail->body = strdup(body);
  mail->next = NULL;
  return mail;
}

void mail_destroy(struct mail *mail) {
  // TODO: Free all the memory allocated by the mail.
  free(mail->sender);
  free(mail->recipient);
  free(mail->date);
  free(mail->time);
  free(mail->subject);
  free(mail->body);
  free(mail);
}

int main(int argc, char **argv) {
  // Create the system.
  struct system *system = system_create();

  // Create a user.
  struct user *user = user_create("alice", "password");

  // Create a mailing list.
  struct mailing_list *mailing_list = mailing_list_create("friends", "A mailing list for my friends.", "alice");

  // Send a mail.
  struct mail *mail = mail_create("alice", "bob", "2023-03-08", "13:37:42", "Hello, world!", "This is a test email.");

  // Link the mail to the mailing list.
  mailing_list->last_mail = mail;
  if (mailing_list->first_mail == NULL) {
    mailing_list->first_mail = mail;
  }

  // Link the mailing list to the user.
  user->last_mailing_list = mailing_list;
  if (user->first_mailing_list == NULL) {
    user->first_mailing_list = mailing_list;
  }

  // Add the user to the system.
  system->last_user = user;
  if (system->first_user == NULL) {
    system->first_user = user;
  }

  // Print the mail.
  printf("From: %s\n", mail->sender);
  printf("To: %s\n", mail->recipient);
  printf("Date: %s\n", mail->date);
  printf("Time: %s\n", mail->time);
  printf("Subject: %s\n", mail->subject);
  printf("Body: %s\n", mail->body);

  // Destroy the mail, mailing list, user, and system.
  mail_destroy(mail);
  mailing_list_destroy(mailing_list);
  user_destroy(user);
  system_destroy(system);

  return 0;
}