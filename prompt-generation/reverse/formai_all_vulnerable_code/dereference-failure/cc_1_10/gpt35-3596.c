//FormAI DATASET v1.0 Category: Digital Diary ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure for individual diary entries
struct DiaryEntry {
   char date[50];
   char entry[500];
};

void addEntry(struct DiaryEntry* entries, int size) {
   fflush(stdin);
   printf("Please enter the entry for today:\n");
   fgets(entries[size].entry, sizeof(entries[size].entry), stdin);
   time_t t = time(NULL);
   struct tm tm = *localtime(&t);
   sprintf(entries[size].date, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
   printf("Entry added successfully! Press enter to continue.\n");
   getchar();
}

void viewEntry(struct DiaryEntry* entries, int size) {
   printf("Please enter the date you would like to view (DD-MM-YYYY):\n");
   char date[50];
   scanf("%s", date);
   for (int i = 0; i < size; i++) {
       if (strcmp(entries[i].date, date) == 0) {
           printf("\n");
           printf("%s\n", entries[i].entry);
           printf("\n");
           break;
       }
   }
   printf("Press enter to continue.\n");
   getchar();
}

void viewAllEntries(struct DiaryEntry* entries, int size) {
    if(size == 0){
        printf("No entries yet! Press enter to continue.\n");
        getchar();
        return;
    }
   printf("List of all diary entries:\n");
   for (int i = 0; i < size; i++) {
       printf("\n%s\n", entries[i].date);
       printf("%s\n", entries[i].entry);
   }
   printf("\n");
   printf("Press enter to continue.\n");
   getchar();
}

void saveToFile(struct DiaryEntry* entries, int size){
    if(size == 0){
        printf("No entries yet! Press enter to continue.\n");
        getchar();
        return;
    }
    FILE *fptr;
    fptr = fopen("diary_entries.txt", "w"); // Opening in write mode
    if (fptr == NULL){
        printf("Error opening file! Press enter to continue.\n");
    }
    else{
        for (int i = 0; i < size; i++) {
           fprintf(fptr,"\n%s\n", entries[i].date);
           fprintf(fptr,"%s\n", entries[i].entry);
        }
        printf("File saved successfully! Press enter to continue.\n");
        fclose(fptr);
    }
    getchar();
}

void readFromFile(struct DiaryEntry* entries, int* size){
   FILE *fptr;
   fptr = fopen("diary_entries.txt", "r"); // Opening in read mode
   if (fptr == NULL){
       printf("Error opening file! Press enter to continue.\n");
   }
   else{
        int i = 0;
        while (!feof(fptr)){
            fgets(entries[*size + i].date, 50, fptr);
            fgets(entries[*size + i].entry, 500, fptr);
            i += 1;
        }
        *size += i-1;
        printf("File read successfully! Press enter to continue.\n");
        fclose(fptr);
   }
   getchar();
}

void clearEntry(struct DiaryEntry* entries, int* size) {
    printf("Please enter the date you would like to clear (DD-MM-YYYY):\n");
    char date[50];
    scanf("%s", date);
    int i;
    for (i = 0; i < *size; i++){
        if (strcmp(entries[i].date, date) == 0){
            break;
        }
    }
    if(i == *size){
        printf("Entry not found. Press enter to continue.\n");
    }
    else{
        for (int j = i; j < *size-1; j++){
            entries[j] = entries[j+1];
        }
        printf("Entry cleared successfully! Press enter to continue.\n");
        *size -= 1;;
    }
    fflush(stdin);
    getchar();
}

int main() {
   struct DiaryEntry entries[100];
   int size = 0;

   while (1) {
      system("clear"); //clearing screen
      printf("Welcome to your digital diary! What would you like to do?\n");
      printf("1. Add a new entry\n");
      printf("2. View an existing entry\n");
      printf("3. View all entries\n");
      printf("4. Save entries to file\n");
      printf("5. Read entries from file\n");
      printf("6. Delete an entry\n");
      printf("7. Exit\n");
      fflush(stdin);
      int choice;
      printf("\nEnter your choice (1-7): ");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            addEntry(entries, size);
            size++;
            break;
         case 2:
            viewEntry(entries, size);
            break;
         case 3:
            viewAllEntries(entries, size);
            break;
         case 4:
            saveToFile(entries, size);
            break;
         case 5:
            readFromFile(entries, &size);
            break;
         case 6:
            clearEntry(entries, &size);
            break;
         case 7:
            printf("Thank you for using the digital diary. Press enter to exit.\n");
            getchar();
            return 0;
         default:
            printf("Invalid choice. Press enter to continue.\n");
            getchar();
            break;
      }
   }

   return 0;
}