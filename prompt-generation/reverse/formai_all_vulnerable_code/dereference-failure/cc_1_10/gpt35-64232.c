//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_SKILLS_LENGTH 100
#define MAX_EXPERIENCE_LENGTH 100

// Structure representing a candidate
typedef struct {
   char name[MAX_NAME_LENGTH];
   char email[MAX_EMAIL_LENGTH];
   char skills[MAX_SKILLS_LENGTH];
   char experience[MAX_EXPERIENCE_LENGTH];
} Candidate;

// Function to parse a candidate's information from a resume and store it in the struct
void parse_resume(char* resume, Candidate* candidate) {
   // Code to parse the resume and extract the candidate's name, email, skills, and experience
   // Here, we will just assign some random values to demonstrate the storage in the struct
   strcpy(candidate->name, "John Doe");
   strcpy(candidate->email, "john.doe@example.com");
   strcpy(candidate->skills, "C, Java, Python");
   strcpy(candidate->experience, "3 years of programming experience");
}

int main() {
   // Create an array of candidate structures to store information about all candidates
   Candidate candidates[10];

   // Read resumes of 10 candidates from files
   for(int i = 0; i < 10; i++) {
      char resume_file_name[50];
      sprintf(resume_file_name, "resume_%d.txt", i+1);
      
      // Open the resume file and read its contents into a string
      FILE* resume_file = fopen(resume_file_name, "r");
      if(!resume_file) {
         printf("Error: Could not read resume file %s\n", resume_file_name);
         exit(1);
      }
      fseek(resume_file, 0, SEEK_END);
      long file_size = ftell(resume_file);
      fseek(resume_file, 0, SEEK_SET);
      char* resume = (char*)malloc(file_size + 1);
      fread(resume, 1, file_size, resume_file);
      resume[file_size] = '\0';
      
      // Parse the resume and store the information in the candidate struct
      parse_resume(resume, &candidates[i]);
      
      // Close the resume file
      fclose(resume_file);
   }

   // Print the information about all candidates
   for(int i = 0; i < 10; i++) {
      printf("\nCandidate %d:\n", i+1);
      printf("Name: %s\n", candidates[i].name);
      printf("Email: %s\n", candidates[i].email);
      printf("Skills: %s\n", candidates[i].skills);
      printf("Experience: %s\n", candidates[i].experience);
   }

   return 0;
}