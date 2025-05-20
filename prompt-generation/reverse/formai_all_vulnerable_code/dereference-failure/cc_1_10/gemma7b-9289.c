//Gemma-7B DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10

typedef struct Password {
  char *name;
  char *password;
} Password;

int main()
{
  Password passwords[MAX_PASSWORDS];
  int i = 0;

  for (; i < MAX_PASSWORDS; i++)
  {
    passwords[i].name = malloc(20);
    passwords[i].password = malloc(20);
  }

  passwords[0].name = "Bob";
  passwords[0].password = "I have a strong password, but I'm not telling you.";

  passwords[1].name = "Alice";
  passwords[1].password = "My password is so secret, it can't be cracked.";

  passwords[2].name = "Tom";
  passwords[2].password = "I'm not even going to try to remember this password.";

  passwords[3].name = "Jane";
  passwords[3].password = "I'm using a really long password, but it's not very secure.";

  passwords[4].name = "Jack";
  passwords[4].password = "I'm using a password that is easy to remember, but not secure.";

  passwords[5].name = "Mary";
  passwords[5].password = "I'm using a password that is too simple, but I'm not lazy.";

  passwords[6].name = "Peter";
  passwords[6].password = "I'm using a password that is full of exclamation marks!!!";

  passwords[7].name = "Susan";
  passwords[7].password = "I'm using a password that is based on my favorite song.";

  passwords[8].name = "John";
  passwords[8].password = "I'm using a password that is as strong as a brick wall.";

  passwords[9].name = "Lisa";
  passwords[9].password = "I'm using a password that is so unique, it can't be cracked.";

  for (i = 0; i < MAX_PASSWORDS; i++)
  {
    printf("%s's password is: %s\n", passwords[i].name, passwords[i].password);
  }

  return 0;
}