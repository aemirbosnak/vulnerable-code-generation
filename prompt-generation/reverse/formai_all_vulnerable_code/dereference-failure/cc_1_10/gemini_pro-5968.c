//GEMINI-pro DATASET v1.0 Category: System administration ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to create a new user
void create_user(char *username, char *password) {
  // Check if the username is valid
  if (!username || strlen(username) == 0) {
    fprintf(stderr, "Invalid username\n");
    exit(1);
  }

  // Check if the password is valid
  if (!password || strlen(password) == 0) {
    fprintf(stderr, "Invalid password\n");
    exit(1);
  }

  // Create the user
  char command[256];
  snprintf(command, sizeof(command), "useradd -m -s /bin/bash %s", username);
  if (system(command) != 0) {
    fprintf(stderr, "Error creating user\n");
    exit(1);
  }

  // Set the password for the user
  snprintf(command, sizeof(command), "passwd %s", username);
  if (system(command) != 0) {
    fprintf(stderr, "Error setting password\n");
    exit(1);
  }
}

// Function to delete a user
void delete_user(char *username) {
  // Check if the username is valid
  if (!username || strlen(username) == 0) {
    fprintf(stderr, "Invalid username\n");
    exit(1);
  }

  // Delete the user
  char command[256];
  snprintf(command, sizeof(command), "userdel -r %s", username);
  if (system(command) != 0) {
    fprintf(stderr, "Error deleting user\n");
    exit(1);
  }
}

// Function to create a new group
void create_group(char *groupname) {
  // Check if the groupname is valid
  if (!groupname || strlen(groupname) == 0) {
    fprintf(stderr, "Invalid groupname\n");
    exit(1);
  }

  // Create the group
  char command[256];
  snprintf(command, sizeof(command), "groupadd %s", groupname);
  if (system(command) != 0) {
    fprintf(stderr, "Error creating group\n");
    exit(1);
  }
}

// Function to delete a group
void delete_group(char *groupname) {
  // Check if the groupname is valid
  if (!groupname || strlen(groupname) == 0) {
    fprintf(stderr, "Invalid groupname\n");
    exit(1);
  }

  // Delete the group
  char command[256];
  snprintf(command, sizeof(command), "groupdel %s", groupname);
  if (system(command) != 0) {
    fprintf(stderr, "Error deleting group\n");
    exit(1);
  }
}

// Function to add a user to a group
void add_user_to_group(char *username, char *groupname) {
  // Check if the username is valid
  if (!username || strlen(username) == 0) {
    fprintf(stderr, "Invalid username\n");
    exit(1);
  }

  // Check if the groupname is valid
  if (!groupname || strlen(groupname) == 0) {
    fprintf(stderr, "Invalid groupname\n");
    exit(1);
  }

  // Add the user to the group
  char command[256];
  snprintf(command, sizeof(command), "usermod -a -G %s %s", groupname, username);
  if (system(command) != 0) {
    fprintf(stderr, "Error adding user to group\n");
    exit(1);
  }
}

// Function to remove a user from a group
void remove_user_from_group(char *username, char *groupname) {
  // Check if the username is valid
  if (!username || strlen(username) == 0) {
    fprintf(stderr, "Invalid username\n");
    exit(1);
  }

  // Check if the groupname is valid
  if (!groupname || strlen(groupname) == 0) {
    fprintf(stderr, "Invalid groupname\n");
    exit(1);
  }

  // Remove the user from the group
  char command[256];
  snprintf(command, sizeof(command), "gpasswd -d %s %s", username, groupname);
  if (system(command) != 0) {
    fprintf(stderr, "Error removing user from group\n");
    exit(1);
  }
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user is root
  if (getuid() != 0) {
    fprintf(stderr, "Error: Must be root to run this program\n");
    exit(1);
  }

  // Parse the command-line arguments
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <command> [arguments]\n", argv[0]);
    exit(1);
  }

  // Get the command
  char *command = argv[1];

  // Get the arguments
  char *args[argc - 1];
  for (int i = 2; i < argc; i++) {
    args[i - 2] = argv[i];
  }

  // Execute the command
  if (strcmp(command, "create_user") == 0) {
    create_user(args[0], args[1]);
  } else if (strcmp(command, "delete_user") == 0) {
    delete_user(args[0]);
  } else if (strcmp(command, "create_group") == 0) {
    create_group(args[0]);
  } else if (strcmp(command, "delete_group") == 0) {
    delete_group(args[0]);
  } else if (strcmp(command, "add_user_to_group") == 0) {
    add_user_to_group(args[0], args[1]);
  } else if (strcmp(command, "remove_user_from_group") == 0) {
    remove_user_from_group(args[0], args[1]);
  } else {
    fprintf(stderr, "Invalid command\n");
    exit(1);
  }

  return 0;
}