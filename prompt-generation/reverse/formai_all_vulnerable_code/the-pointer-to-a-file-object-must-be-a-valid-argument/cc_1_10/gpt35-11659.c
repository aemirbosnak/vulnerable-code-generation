//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  char *email;
  char *phone;
  char *address;
  char *skills;
  char *work_history;
} applicant;

void parse_resume(char *filename, applicant *app) {
  FILE *file = fopen(filename, "r");
  char line[100];
 
  while(fgets(line, sizeof(line), file)) {
    if(strstr(line, "Name:")) {
      strtok(line, ":");
      app->name = strdup(strtok(NULL, "\n"));
    }
    if(strstr(line, "Email:")) {
      strtok(line, ":");
      app->email = strdup(strtok(NULL, "\n"));
    }
    if(strstr(line, "Phone:")) {
      strtok(line, ":");
      app->phone = strdup(strtok(NULL, "\n"));
    }
    if(strstr(line, "Address:")) {
      strtok(line, ":");
      app->address = strdup(strtok(NULL, "\n"));
    }
    if(strstr(line, "Skills:")) {
      strtok(line, ":");
      app->skills = strdup(strtok(NULL, "\n"));
    }
    if(strstr(line, "Work History:")) {
      app->work_history = strdup("");
      while(fgets(line, sizeof(line), file)) {
        if(strlen(line) == 1) break;
        char *temp = malloc(strlen(app->work_history) + strlen(line) + 1);
        strcpy(temp, app->work_history);
        strcat(temp, line);
        free(app->work_history);
        app->work_history = temp;
      }
    }
  }
  fclose(file);
}

int main() {
  char *resume_file = "resume.txt";
  applicant my_applicant;
  parse_resume(resume_file, &my_applicant);
  
  printf("Name: %s\n", my_applicant.name);
  printf("Email: %s\n", my_applicant.email);
  printf("Phone: %s\n", my_applicant.phone);
  printf("Address: %s\n", my_applicant.address);
  printf("Skills: %s\n", my_applicant.skills);
  printf("Work History: %s\n", my_applicant.work_history);
  
  free(my_applicant.name);
  free(my_applicant.email);
  free(my_applicant.phone);
  free(my_applicant.address);
  free(my_applicant.skills);
  free(my_applicant.work_history);
  
  return 0;
}