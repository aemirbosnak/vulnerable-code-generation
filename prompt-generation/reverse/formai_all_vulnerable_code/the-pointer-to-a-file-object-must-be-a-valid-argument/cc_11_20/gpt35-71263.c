//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   char text[1000];
   int posWords = 0, negWords = 0, count = 0;
   FILE *fp = fopen("positive_words.txt", "r");
   char ch;

   while ((ch = fgetc(fp)) != EOF)
   {
      if (ch == '\n')
         posWords++;
   }

   fclose(fp);

   fp = fopen("negative_words.txt", "r");

   while ((ch = fgetc(fp)) != EOF)
   {
      if (ch == '\n')
         negWords++;
   }

   fclose(fp);

   printf("Enter your text: ");
   fgets(text, 1000, stdin);

   char delim[] = " ";
   char *ptr = strtok(text, delim);

   while (ptr != NULL)
   {
      fp = fopen("positive_words.txt", "r");

      for (int i = 0; i < posWords; i++)
      {
         char word[100];
         fgets(word, 100, fp);
         word[strlen(word) - 1] = '\0';

         if (strcasecmp(word, ptr) == 0)
         {
            count++;
            break;
         }
      }

      fclose(fp);

      fp = fopen("negative_words.txt", "r");

      for (int i = 0; i < negWords; i++)
      {
         char word[100];
         fgets(word, 100, fp);
         word[strlen(word) - 1] = '\0';

         if (strcasecmp(word, ptr) == 0)
         {
            count--;
            break;
         }
      }

      fclose(fp);
      ptr = strtok(NULL, delim);
   }

   printf("\nThe sentiment score of your text is %d.", count);

   if (count > 0)
   {
      printf(" The text has a positive sentiment.\n");
   }
   else if (count < 0)
   {
      printf(" The text has a negative sentiment.\n");
   }
   else
   {
      printf(" The text has a neutral sentiment.\n");
   }

   return 0;
}