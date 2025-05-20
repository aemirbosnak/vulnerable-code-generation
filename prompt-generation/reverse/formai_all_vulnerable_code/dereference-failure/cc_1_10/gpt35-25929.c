//FormAI DATASET v1.0 Category: Banking Record System ; Style: careful
#include<stdio.h>
#include<stdlib.h>

struct banking_record {
   int account_number;
   char name[50];
   float balance;
};

void add_record(struct banking_record*);
void edit_record(struct banking_record*);
void delete_record(struct banking_record*);
void display_record(struct banking_record*);

int main() {
   int choice;
   struct banking_record *record = (struct banking_record*)malloc(sizeof(struct banking_record));
   while(1) {
      printf("\n------------------------------\n");
      printf("         BANK RECORDS         \n");
      printf("------------------------------\n\n");
      printf("1. Add Record\n");
      printf("2. Edit Record\n");
      printf("3. Delete Record\n");
      printf("4. Display Records\n");
      printf("5. Exit\n\n");
      printf("Enter your choice (1-5): ");
      scanf("%d",&choice);
      switch(choice) {
         case 1:
            add_record(record);
            break;
         case 2:
            edit_record(record);
            break;
         case 3:
            delete_record(record);
            break;
         case 4:
            display_record(record);
            break;
         case 5:
            free(record);
            exit(0);
         default:
            printf("Invalid Choice!\n");
      }
   }
   return 0;
}

void add_record(struct banking_record *record) {
   printf("\nAdd Record\n\n");
   printf("Enter Account Number: ");
   scanf("%d", &record->account_number);
   printf("Enter Name: ");
   scanf("%s", record->name);
   printf("Enter Balance: ");
   scanf("%f", &record->balance);
   printf("\nRecord Added Successfully!\n");
   return;
}

void edit_record(struct banking_record *record) {
   int account_number,i;
   printf("\nEdit Record\n\n");
   printf("Enter Account Number: ");
   scanf("%d",&account_number);
   for(i=0;i<1;i++) {
      if((record+i)->account_number==account_number) {
         printf("\n********************\n");
         printf("ACCOUNT NUMBER: %d", (record+i)->account_number);
         printf("\nNAME: %s", (record+i)->name);
         printf("\nBALANCE: %f", (record+i)->balance);
         printf("\n********************\n\n");
         printf("Enter New Account Number: ");
         scanf("%d",&(record+i)->account_number);
         printf("Enter New Name: ");
         scanf("%s",(record+i)->name);
         printf("Enter New Balance: ");
         scanf("%f",&(record+i)->balance);
         printf("\nRecord Edited Successfully!\n");
         return;
      }
   }
   printf("\nRecord Not Found!\n");
   return;
}

void delete_record(struct banking_record *record) {
   int account_number,i;
   printf("\nDelete Record\n\n");
   printf("Enter Account Number: ");
   scanf("%d",&account_number);
   for(i=0;i<1;i++) {
      if((record+i)->account_number==account_number) {
         (record+i)->account_number=0;
         (record+i)->name[0]='\0';
         (record+i)->balance=0;
         printf("\nRecord Deleted Successfully!\n");
         return;
      }
   }
   printf("\nRecord Not Found!\n");
   return;
}

void display_record(struct banking_record *record) {
   int i;
   printf("\nDisplay Records\n\n");
   printf("ACCOUNT NUMBER\tNAME\t\tBALANCE\n");
   for(i=0;i<1;i++) {
      printf("%d\t\t%s\t\t%f\n", (record+i)->account_number, (record+i)->name, (record+i)->balance);
   }
   return;
}