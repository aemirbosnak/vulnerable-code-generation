//FormAI DATASET v1.0 Category: Digital Diary ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int choice;
   char entry[200];
   char date[20];
   time_t t = time(NULL);
   struct tm tm = *localtime(&t);

   printf("\n*********************************************\n");
   printf("Welcome to your digital diary\n");
   printf("*********************************************\n\n");

   while (1) {
      printf("Enter 1 to enter a new entry into your diary\n");
      printf("Enter 2 to view your previous diary entries\n");
      printf("Enter 3 to exit\n");

      scanf("%d", &choice);

      if (choice == 1) {
         printf("\nPlease enter today's date (dd-mm-yyyy): ");
         scanf("%s", date);
         printf("\nEnter your diary entry for today: ");
         scanf(" %[^\n]s", entry);

         FILE *fp;
         fp = fopen("diary.txt", "a");
         fprintf(fp, "%d-%d-%d\n%s\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, entry);
         fclose(fp);

         printf("\nDiary entry added successfully!\n\n");
      } else if (choice == 2) {
         FILE *fp;
         fp = fopen("diary.txt", "r");
         
         if (fp == NULL) {
            printf("\nNo entries found.\n");
         } else {
            char ch;
            printf("\nYour previous diary entries:\n\n");
            while (!feof(fp)) {
               ch = fgetc(fp);
               printf("%c", ch);
            }
            printf("\n");
            fclose(fp);
         }
      } else if (choice == 3) {
         printf("\nThank you for using your digital diary. Goodbye.\n\n");
         break;
      } else {
         printf("\nInvalid choice. Please try again.\n\n");
      }
   }

   return 0;
}