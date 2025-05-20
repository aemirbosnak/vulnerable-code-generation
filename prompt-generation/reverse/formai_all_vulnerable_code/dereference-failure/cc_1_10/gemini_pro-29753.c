//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LISTS 1000
#define MAX_USERS 10000
#define MAX_MESSAGES 100000

typedef struct {
  char *name;
  char **users;
  int num_users;
  char **messages;
  int num_messages;
} mailing_list;

mailing_list lists[MAX_LISTS];
int num_lists = 0;

int user_is_member_of_list(char *user, char *list) {
  int i;
  for (i = 0; i < num_lists; i++) {
    if (strcmp(lists[i].name, list) == 0) {
      int j;
      for (j = 0; j < lists[i].num_users; j++) {
        if (strcmp(lists[i].users[j], user) == 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}

int add_user_to_list(char *user, char *list) {
  int i;
  for (i = 0; i < num_lists; i++) {
    if (strcmp(lists[i].name, list) == 0) {
      lists[i].users = realloc(lists[i].users, (lists[i].num_users + 1) * sizeof(char *));
      lists[i].users[lists[i].num_users++] = strdup(user);
      return 1;
    }
  }
  return 0;
}

int remove_user_from_list(char *user, char *list) {
  int i, j;
  for (i = 0; i < num_lists; i++) {
    if (strcmp(lists[i].name, list) == 0) {
      for (j = 0; j < lists[i].num_users; j++) {
        if (strcmp(lists[i].users[j], user) == 0) {
          free(lists[i].users[j]);
          lists[i].users[j] = lists[i].users[--lists[i].num_users];
          return 1;
        }
      }
    }
  }
  return 0;
}

int add_message_to_list(char *message, char *list) {
  int i;
  for (i = 0; i < num_lists; i++) {
    if (strcmp(lists[i].name, list) == 0) {
      lists[i].messages = realloc(lists[i].messages, (lists[i].num_messages + 1) * sizeof(char *));
      lists[i].messages[lists[i].num_messages++] = strdup(message);
      return 1;
    }
  }
  return 0;
}

int main(int argc, char **argv) {
  if (argc < 4) {
    fprintf(stderr, "Usage: %s <command> <list> <user/message>\n", argv[0]);
    return 1;
  }

  char *command = argv[1];
  char *list = argv[2];
  char *user_or_message = argv[3];

  if (strcmp(command, "add-user") == 0) {
    if (!user_is_member_of_list(user_or_message, list)) {
      add_user_to_list(user_or_message, list);
      printf("User %s added to list %s.\n", user_or_message, list);
    } else {
      printf("User %s is already a member of list %s.\n", user_or_message, list);
    }
  } else if (strcmp(command, "remove-user") == 0) {
    if (user_is_member_of_list(user_or_message, list)) {
      remove_user_from_list(user_or_message, list);
      printf("User %s removed from list %s.\n", user_or_message, list);
    } else {
      printf("User %s is not a member of list %s.\n", user_or_message, list);
    }
  } else if (strcmp(command, "add-message") == 0) {
    add_message_to_list(user_or_message, list);
    printf("Message %s added to list %s.\n", user_or_message, list);
  } else {
    fprintf(stderr, "Unknown command: %s\n", command);
  }

  return 0;
}