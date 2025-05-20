//FormAI DATASET v1.0 Category: String manipulation ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
  char str1[100], str2[100];
  int choice, length, result;
  char *tempStr1, *tempStr2;

  do
  {
    printf("\n");
    printf("Choose an option:\n");
    printf("\t1. Concatenate\n");
    printf("\t2. Reverse\n");
    printf("\t3. Compare\n");
    printf("\t4. Quit\n");
    printf("\tEnter choice: ");

    scanf("%d", &choice);

    switch (choice)
    {
      case 1:
        printf("\nEnter string 1: ");
        scanf("%s", str1);
        printf("Enter string 2: ");
        scanf("%s", str2);
        tempStr1 = (char*)malloc(strlen(str1) + strlen(str2) + 1);
        strcpy(tempStr1, str1);
        strcat(tempStr1, str2);
        printf("\nConcatenated string: %s\n", tempStr1);
        free(tempStr1);
        break;
      case 2:
        printf("\nEnter a string: ");
        scanf("%s", str1);
        tempStr1 = (char*)malloc(strlen(str1) + 1);
        strcpy(tempStr1, str1);
        length = strlen(tempStr1);
        for (int i = 0; i < length/2; i++)
        {
          char temp = tempStr1[i];
          tempStr1[i] = tempStr1[length - i - 1];
          tempStr1[length - i - 1] = temp;
        }
        printf("\nReversed string: %s\n", tempStr1);
        free(tempStr1);
        break;
      case 3:
        printf("\nEnter string 1: ");
        scanf("%s", str1);
        printf("Enter string 2: ");
        scanf("%s", str2);
        tempStr1 = (char*)malloc(strlen(str1) + 1);
        strcpy(tempStr1, str1);
        tempStr2 = (char*)malloc(strlen(str2) + 1);
        strcpy(tempStr2, str2);
        result = strcmp(tempStr1, tempStr2);
        if (result == 0)
        {
          printf("\nStrings are equal\n");
        }
        else
        {
          printf("\nStrings are not equal\n");
        }
        free(tempStr1);
        free(tempStr2);
        break;
      case 4:
        printf("\nGoodbye!\n");
        break;
      default:
        printf("\nInvalid choice. Try again.\n");
        break;
    }
  } while (choice != 4);

  return 0;
}