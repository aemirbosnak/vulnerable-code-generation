//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 256

typedef struct resume_data {
  char *name;
  char *email;
  char *phone;
  char *address;
  char *summary;
} resume_data_t;

void parse_resume(resume_data_t *data) {
  FILE *fp;
  char buffer[MAX_NAME_LENGTH];
  int name_length;
  char *name;
  char *email;
  char *phone;
  char *address;
  char *summary;

  fp = fopen("resume.txt", "r");
  if (fp == NULL) {
    return;
  }

  // Get the name
  name_length = fgets(buffer, MAX_NAME_LENGTH, fp);
  name = strdup(buffer);

  // Get the email
  fgets(buffer, MAX_NAME_LENGTH, fp);
  email = strdup(buffer);

  // Get the phone
  fgets(buffer, MAX_NAME_LENGTH, fp);
  phone = strdup(buffer);

  // Get the address
  fgets(buffer, MAX_NAME_LENGTH, fp);
  address = strdup(buffer);

  // Get the summary
  fgets(buffer, MAX_NAME_LENGTH, fp);
  summary = strdup(buffer);

  data->name = name;
  data->email = email;
  data->phone = phone;
  data->address = address;
  data->summary = summary;

  fclose(fp);
}

int main() {
  resume_data_t data;
  parse_resume(&data);

  printf("Name: %s\n", data.name);
  printf("Email: %s\n", data.email);
  printf("Phone: %s\n", data.phone);
  printf("Address: %s\n", data.address);
  printf("Summary: %s\n", data.summary);

  return 0;
}