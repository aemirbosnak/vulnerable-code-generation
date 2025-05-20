//FormAI DATASET v1.0 Category: File handling ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *fp;
   char ch, fileName[20];
   int choice, count = 0, i;
   printf("Enter a file name: ");
   gets(fileName);
   fp = fopen(fileName, "a+");

   if (fp == NULL)
   {
       printf("File does not exist.\n");
       exit(1);
   }

   printf("\n1. Write to the file");
   printf("\n2. Read the file");
   printf("\n3. Exit");
   printf("\nEnter your choice: ");
   scanf("%d", &choice);

   switch(choice)
   {
       case 1:
            while ((ch = getchar()) != EOF)
		    {
			    putc(ch, fp);
		    }
		    printf("File written successfully!\n");
		    break;
		case 2: 
		    ch = fgetc(fp);
		    while(ch != EOF)
		    {
			    count++;
			    printf("%c", ch);
			    ch = fgetc(fp);
		    }
		    if(count == 0)
		    {
                printf("File is empty.\n");
		    }
		    break;
		case 3:
		    exit(0);
		default:
		    printf("Invalid choice.\n");
   }
   fclose(fp);
   return 0;
}