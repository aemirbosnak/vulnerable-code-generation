//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main()
{
  system("/bin/clear");

  printf("Enter the haunted house number:");
  int house_num = atoi(getenv("HOUSE_NUMBER"));

  switch (house_num)
  {
    case 1:
      printf("You have entered the Haunted House of the Crumbling Manor.\n");
      break;
    case 2:
      printf("You have entered the Haunted House of the Bleeding Nun.\n");
      break;
    case 3:
      printf("You have entered the Haunted House of the Twisted Spirit.\n");
      break;
    default:
      printf("Invalid haunted house number.\n");
  }

  printf("Would you like to enter the house? (Y/N): ");
  char answer = getchar();

  if (answer == 'Y')
  {
    printf("You have entered the haunted house.\n");

    // Create a spooky atmosphere
    int i = 0;
    for (i = 0; i < 10; i++)
    {
      printf("%c", rand() % 200);
    }

    // Play some creepy music
    system("/usr/bin/play -n 0 /path/to/spooky.mp3");

    // Have a ghostly encounter
    printf("Suddenly, you hear a voice... \n");
    printf("The air is thick with the smell of burning flesh... \n");
    printf("You feel a cold hand brush against your skin... \n");

    printf("Do you want to flee the haunted house? (Y/N): ");
    answer = getchar();

    if (answer == 'Y')
    {
      printf("You flee the haunted house and run away.\n");
    }
    else
    {
      printf("The ghostly hand wraps you in its grip... \n");
      printf("The end.\n");
    }
  }
  else
  {
    printf("You have chosen to stay away from the haunted house.\n");
  }

  return 0;
}