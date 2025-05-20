//FormAI DATASET v1.0 Category: Digital Diary ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct DiaryEntry {
   char* date;
   char* content;
} DiaryEntry;

void printEntry(DiaryEntry entry) {
   printf("Date: %s\n", entry.date);
   printf("Content: %s\n", entry.content);
   printf("------------------------------------------------\n");
}

void addEntry(DiaryEntry* entries, int* numEntries) {
   char date[11];
   char content[100];

   printf("Enter today's date in the format 'dd/mm/yyyy':\n");
   scanf("%s", date);
   printf("Enter your entry for today (100 characters max):\n");
   scanf("%s", content);

   entries[*numEntries].date = date;
   entries[*numEntries].content = content;

   (*numEntries)++;
}

void shapeShift(DiaryEntry* entries, int numEntries) {
   srand(time(NULL));
   int randIndex1 = rand() % numEntries;
   int randIndex2 = rand() % numEntries;

   DiaryEntry tempEntry = entries[randIndex1];
   entries[randIndex1] = entries[randIndex2];
   entries[randIndex2] = tempEntry;

   printf("Your diary entries have been shape shifted!\n");
}

int main() {
   DiaryEntry entries[100];
   int numEntries = 0;
   int userInput = 0;

   while (userInput != 4) {
      printf("*******************DIGITAL DIARY********************\n");
      printf("1. Add diary entry\n");
      printf("2. View diary entries\n");
      printf("3. Shape shift diary entries\n");
      printf("4. Exit\n");
      printf("****************************************************\n");
      scanf("%d", &userInput);

      switch (userInput) {
         case 1:
            addEntry(entries, &numEntries);
            break;

         case 2:
            for (int i = 0; i < numEntries; i++) {
               printEntry(entries[i]);
            }
            break;

         case 3:
            shapeShift(entries, numEntries);
            break;

         case 4:
            printf("Exiting digital diary...\n");
            break;

         default:
            printf("Invalid input, please try again.\n");
            break;
      }
   }

   return 0;
}