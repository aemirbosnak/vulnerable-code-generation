//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the resume struct
typedef struct resume {
  char *name;
  char *email;
  char *phone;
  char *skills;
  char *education;
  char *experience;
} Resume;

// Declare the parsing function
Resume *parse_resume(char *filename);

// Main function
int main() {
  
  char *filename = "resume.txt";
  
  Resume *resume = parse_resume(filename);
  
  if (resume == NULL) {
    printf("Error parsing resume.\n");
    return 1;
  }
  
  // Print the resume
  printf("Name: %s\n", resume->name);
  printf("Email: %s\n", resume->email);
  printf("Phone: %s\n", resume->phone);
  printf("Skills: %s\n", resume->skills);
  printf("Education: %s\n", resume->education);
  printf("Experience: %s\n", resume->experience);
  
  // Free the resume
  free(resume);
  return 0;
}

// Parsing function
Resume *parse_resume(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }
  
  // Allocate memory for the resume
  Resume *resume = malloc(sizeof(Resume));
  if (resume == NULL) {
    fclose(file);
    return NULL;
  }
  
  // Read the name
  char *name = malloc(100);
  if (name == NULL) {
    fclose(file);
    free(resume);
    return NULL;
  }
  fscanf(file, "%s\n", name);
  resume->name = name;
  
  // Read the email
  char *email = malloc(100);
  if (email == NULL) {
    fclose(file);
    free(resume);
    free(name);
    return NULL;
  }
  fscanf(file, "%s\n", email);
  resume->email = email;
  
  // Read the phone
  char *phone = malloc(100);
  if (phone == NULL) {
    fclose(file);
    free(resume);
    free(name);
    free(email);
    return NULL;
  }
  fscanf(file, "%s\n", phone);
  resume->phone = phone;
  
  // Read the skills
  char *skills = malloc(1000);
  if (skills == NULL) {
    fclose(file);
    free(resume);
    free(name);
    free(email);
    free(phone);
    return NULL;
  }
  fscanf(file, "%[^\n]\n", skills);
  resume->skills = skills;
  
  // Read the education
  char *education = malloc(1000);
  if (education == NULL) {
    fclose(file);
    free(resume);
    free(name);
    free(email);
    free(phone);
    free(skills);
    return NULL;
  }
  fscanf(file, "%[^\n]\n", education);
  resume->education = education;
  
  // Read the experience
  char *experience = malloc(1000);
  if (experience == NULL) {
    fclose(file);
    free(resume);
    free(name);
    free(email);
    free(phone);
    free(skills);
    free(education);
    return NULL;
  }
  fscanf(file, "%[^\n]\n", experience);
  resume->experience = experience;
  
  // Close the file
  fclose(file);
  
  // Return the resume
  return resume;
}