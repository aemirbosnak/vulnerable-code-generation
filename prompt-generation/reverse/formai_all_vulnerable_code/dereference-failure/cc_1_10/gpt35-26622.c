//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

int main()
{
  char resume[1000]; // Assuming that your resume is not longer than 1000 characters
  printf("Please enter your resume.\n");
  fgets(resume, 1000, stdin); // Reading in the user's input

  char name[100], email[100], phone[100];
  int years_of_experience;
  // Initializing variables for the user's name, email, phone, and years of experience

  char* name_start;
  char* name_end;
  // Declaring pointers to locate the start and the end of the user's name in the resume

  char* email_start;
  char* email_end;
  // Declaring pointers to locate the start and the end of the user's email in the resume

  char* phone_start;
  char* phone_end;
  // Declaring pointers to locate the start and the end of the user's phone number in the resume

  char* experience_start;
  char* experience_end;
  // Declaring pointers to locate the start and the end of the user's years of experience in the resume

  name_start = strstr(resume, "Name: ") + strlen("Name: ");
  name_end = strstr(name_start, "\n") - 1;

  email_start = strstr(resume, "Email: ") + strlen("Email: ");
  email_end = strstr(email_start, "\n") - 1;

  phone_start = strstr(resume, "Phone: ") + strlen("Phone: ");
  phone_end = strstr(phone_start, "\n") - 1;

  experience_start = strstr(resume, "Years of experience: ") + strlen("Years of experience: ");
  experience_end = strstr(experience_start, "\n") - 1;

  strncpy(name, name_start, name_end - name_start + 1); //Copying the user's name to the 'name' variable
  name[name_end - name_start + 1] = '\0'; //Adding a null terminator to the end of the name string

  strncpy(email, email_start, email_end - email_start + 1); //Copying the user's email to the 'email' variable
  email[email_end - email_start + 1] = '\0'; //Adding a null terminator to the end of the email string

  strncpy(phone, phone_start, phone_end - phone_start + 1); //Copying the user's phone number to the 'phone' variable
  phone[phone_end - phone_start + 1] = '\0'; //Adding a null terminator to the end of the phone string

  years_of_experience = atoi(experience_start); //Converting the user's years of experience from a string to an integer

  printf("Name: %s\n", name);
  printf("Email: %s\n", email);
  printf("Phone: %s\n", phone);
  printf("Years of Experience: %d\n", years_of_experience);

  return 0;
}