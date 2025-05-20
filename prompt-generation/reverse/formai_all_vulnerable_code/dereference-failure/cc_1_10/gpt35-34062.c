//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENT_NAME_LEN 20
#define MAX_ELEMENT_SYM_LEN 3
#define MAX_ELEMENT_DATA_LEN 5

struct Element {
   int atomic_number;
   char symbol[MAX_ELEMENT_SYM_LEN];
   char name[MAX_ELEMENT_NAME_LEN];
   float atomic_mass;
   int period;
   int group;
};

void display_table(struct Element table[], int size);
void display_element(struct Element element);
int quiz_question(struct Element element);

int main() {
   struct Element PeriodicTable[118];

   FILE *file;
   char *line = NULL;
   size_t len = 0;
   ssize_t read;
   int table_index = 0;

   file = fopen("PeriodicTable.txt", "r");
   if (file == NULL) {
      printf("Unable to open file 'PeriodicTable.txt'\n");
      return 1;
   }

   while ((read = getline(&line, &len, file)) != -1) {
      char *token;
      char *rest = line;
      int data_index = 0;
      struct Element element;

      while ((token = strtok_r(rest, ",", &rest))) {
         switch (data_index) {
            case 0: element.atomic_number = atoi(token);
                    break;
            case 1: strncpy(element.symbol, token, sizeof(element.symbol)-1);
                    break;
            case 2: strncpy(element.name, token, sizeof(element.name)-1);
                    break;
            case 3: element.atomic_mass = atof(token);
                    break;
            case 4: element.period = atoi(token);
                    break;
            case 5: element.group = atoi(token);
                    break;
         }
         data_index++;
      }

      PeriodicTable[table_index] = element;
      table_index++;
   }

   fclose(file);
   if (line) free(line);

   display_table(PeriodicTable, 118);
   printf("\n\nLet's test your knowledge of the Periodic Table!\n\n");
   printf("I will give you an element and you give me its atomic number.\n");
   printf("Type '-1' to quit.\n\n");

   int num_correct = 0;
   int num_attempts = 0;
   int quit = 0;
   while (!quit) {
      int index = rand() % 118;
      struct Element element = PeriodicTable[index];

      int answer = quiz_question(element);
      if (answer == -1) {
         quit = 1;
         continue;
      }

      if (answer == element.atomic_number) {
         printf("Correct! The atomic number of %s is %d\n", element.name, element.atomic_number);
         num_correct++;
      }
      else {
         printf("Incorrect. The atomic number of %s is %d\n", element.name, element.atomic_number);
      }

      num_attempts++;
   }

   printf("\n\nYou got %d out of %d correct!\n", num_correct, num_attempts);

   return 0;
}

void display_table(struct Element table[], int size) {
   for (int i = 0; i < size; i++) {
      display_element(table[i]);
   }
}

void display_element(struct Element element) {
   printf("%s (%s): atomic number %d, atomic mass %4.2f, period %d, group %d\n", element.name, element.symbol, element.atomic_number, element.atomic_mass, element.period, element.group);
}

int quiz_question(struct Element element) {
   printf("\nWhat is the atomic number of %s? ", element.name);

   char answer[MAX_ELEMENT_DATA_LEN];
   fgets(answer, sizeof(answer), stdin);

   if (strcmp(answer, "-1\n") == 0) {
      return -1;
   }

   return atoi(answer);
}