//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
  char name[50];
  char email[50];
  char address[100];
  char phone_number[20];
  char education[100];
  char skills[200];
  char work_experience[500];
};

void parse_resume(struct resume *r, char *filename) {
  FILE *f = fopen(filename, "r");
  char line[200];

  while (fgets(line, sizeof(line), f)) {
    if (strstr(line, "Name: ")) {
      sscanf(line+6, "%s", r->name);
    } else if (strstr(line, "Email: ")) {
      sscanf(line+7, "%s", r->email);
    } else if (strstr(line, "Address: ")) {
      sscanf(line+9, "%[^\n]", r->address);
    } else if (strstr(line, "Phone Number: ")) {
      sscanf(line+14, "%s", r->phone_number);
    } else if (strstr(line, "Education: ")) {
      sscanf(line+11, "%[^\n]", r->education);
    } else if (strstr(line, "Skills: ")) {
      sscanf(line+8, "%[^\n]", r->skills);
    } else if (strstr(line, "Work Experience: ")) {
      char experience[200];
      while(fgets(line, sizeof(line), f)) {
        if (strstr(line, "End Experience")) {
          break;
        } else {
          strcat(experience, line);
        }
      }
      strcpy(r->work_experience, experience);
    }
  }

  fclose(f);
}

void print_resume(struct resume *r) {
  printf("Name: %s\n", r->name);
  printf("Email: %s\n", r->email);
  printf("Address: %s\n", r->address);
  printf("Phone Number: %s\n", r->phone_number);
  printf("Education: %s\n", r->education);
  printf("Skills: %s\n", r->skills);
  printf("Work Experience: %s\n", r->work_experience);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <resume_file>\n", argv[0]);
    exit(1);
  }

  struct resume r;
  parse_resume(&r, argv[1]);
  print_resume(&r);

  exit(0);
}