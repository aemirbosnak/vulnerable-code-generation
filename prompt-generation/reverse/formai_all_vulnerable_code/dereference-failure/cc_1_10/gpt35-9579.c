//FormAI DATASET v1.0 Category: Digital Diary ; Style: relaxed
#include<stdio.h>
#include<string.h>

// function prototypes
void add_entry(char date[], char entry[]);
void view_entries(char date[]);

int main()
{
   char choice[10];
   char date[11];    // max length of date string is 10
   char entry[256];  // max length of diary entry is 255

   do
   {
      printf("\n1. Add Entry\n2. View Entries\n3. Quit\n");
      printf("Enter your choice: ");
      fgets(choice, 10, stdin);
      choice[strcspn(choice, "\n")] = 0; // remove trailing newline

      if(strcmp(choice, "1") == 0)
      {
         printf("Enter today's date (dd/mm/yyyy): ");
         fgets(date, 11, stdin);
         date[strcspn(date, "\n")] = 0; // remove trailing newline

         printf("Enter your entry for today:\n");
         fgets(entry, 256, stdin);
         entry[strcspn(entry, "\n")] = 0; // remove trailing newline

         add_entry(date, entry);
         printf("Entry added successfully!\n");
      }
      else if(strcmp(choice, "2") == 0)
      {
         printf("Enter date to view entries (dd/mm/yyyy): ");
         fgets(date, 11, stdin);
         date[strcspn(date, "\n")] = 0; // remove trailing newline

         view_entries(date);
      }
      else if(strcmp(choice, "3") != 0)
      {
         printf("Invalid choice!\n");
      }

   } while(strcmp(choice, "3") != 0);

   return 0;
}

// function to add entry to diary file
void add_entry(char date[], char entry[])
{
   FILE *fp = fopen("diary.txt", "a"); // open file in append mode
   
   if(fp != NULL)
   {
      fprintf(fp, "%s,%s\n", date, entry);
      fclose(fp);
   }
   else
   {
      printf("Failed to open file!\n");
   }
}

// function to view entries for a specific date
void view_entries(char date[])
{
   FILE *fp = fopen("diary.txt", "r");

   if(fp != NULL)
   {
      char line[268]; // max length of line is 10 (date) + 1 (comma) + 255 (entry) + 1 (newline)

      while(fgets(line, 268, fp) != NULL) // read line by line
      {
         char *d = strtok(line, ",");
         char *e = strtok(NULL, ",");

         if(strcmp(d, date) == 0) // match found
         {
            printf("\n%s\n", e);
         }
      }

      fclose(fp);
   }
   else
   {
      printf("Failed to open file!\n");
   }
}