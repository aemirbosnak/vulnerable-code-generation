//FormAI DATASET v1.0 Category: Mailing list manager ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee {
   char name[50];
   char email[50];
   char department[50];
   char supervisor[50];
   struct employee* next;
} Employee;

Employee* create_employee(char* name, char* email, char* department, char* supervisor) {
   Employee* emp = (Employee*) malloc(sizeof(Employee));
   strcpy(emp->name, name);
   strcpy(emp->email, email);
   strcpy(emp->department, department);
   strcpy(emp->supervisor, supervisor);
   emp->next = NULL;
   return emp;
}

typedef struct mailinglist {
   Employee* head;
   int size;
} MailingList;

MailingList* create_mailinglist() {
   MailingList* ml = (MailingList*) malloc(sizeof(MailingList));
   ml->head = NULL;
   ml->size = 0;
   return ml;
}

void add_employee(MailingList* ml, Employee* emp) {
   if (ml->head == NULL) {
      ml->head = emp;
   } else {
      emp->next = ml->head;
      ml->head = emp;
   }
   ml->size++;
}

void print_employee(Employee* emp) {
   printf("Name: %s\n", emp->name);
   printf("Email: %s\n", emp->email);
   printf("Department: %s\n", emp->department);
   printf("Supervisor: %s\n", emp->supervisor);
}

void print_mailinglist(MailingList* ml) {
   Employee* curr = ml->head;
   printf("Mailing List:\n");
   while (curr != NULL) {
      print_employee(curr);
      printf("\n");
      curr = curr->next;
   }
}

void delete_employee(MailingList* ml, char* email) {
   if(ml->head == NULL) {
        printf("Mailing list is empty\n");
        return;
   }
   if(strcmp(ml->head->email, email) == 0) {
      Employee* temp = ml->head;
      ml->head = ml->head->next;
      free(temp);
      ml->size--;
      return;
   } else {
      Employee* prev = ml->head;
      Employee* curr = ml->head->next;
      while(curr != NULL) {
         if(strcmp(curr->email, email) == 0) {
            prev->next = curr->next;
            free(curr);
            ml->size--;
            return;
         }
         prev = curr;
         curr = curr->next;
      }
   }
   printf("Employee with email %s not found in mailing list\n", email);
}

void destroy_mailinglist(MailingList* ml) {
   Employee* curr = ml->head;
   Employee* temp;
   while (curr != NULL) {
      temp = curr;
      curr = curr->next;
      free(temp);
   }
   free(ml);
   printf("Mailing list destroyed\n");
}

int main() {
   MailingList* ml = create_mailinglist();

   Employee* emp1 = create_employee("John", "john@abc.com", "IT", "Jane");
   add_employee(ml, emp1);
   Employee* emp2 = create_employee("Sarah", "sarah@abc.com", "HR", "Bob");
   add_employee(ml, emp2);
   Employee* emp3 = create_employee("Mike", "mike@abc.com", "Finance", "Mary");
   add_employee(ml, emp3);

   print_mailinglist(ml);

   delete_employee(ml, "sarah@abc.com");

   print_mailinglist(ml);

   destroy_mailinglist(ml);
   return 0;
}