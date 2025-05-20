//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

// Structure definition for resume
typedef struct {
   char *name;
   int age;
   char *email;
   char *phone;
   char *address;
} Resume;

// Function prototype
Resume *parseResume(char *filename);

int main() {
   // Initialize the filename string
   char *filename = "resume.txt";
   
   // Parse the resume
   Resume *resume = parseResume(filename);
   
   // Print the parsed resume
   printf("Name:%s\n", resume->name);
   printf("Age: %d\n", resume->age);
   printf("Email: %s\n", resume->email);
   printf("Phone: %s\n", resume->phone);
   printf("Address: %s\n", resume->address);
   
   return 0;
}

Resume *parseResume(char *filename) {
   // Open the resume file
   FILE *fp = fopen(filename, "r");
   
   // Create a Resume structure
   Resume *resume = malloc(sizeof(Resume));
   
   // Initialize variables for parsing
   char line[100];
   char *token;
   
   // Read each line of the file and parse the information
   while(fgets(line, 100, fp)) {
      // Remove newline character from each line
      line[strcspn(line, "\n")] = '\0';
      
      // Parse the information based on the line
      if(strncmp(line, "Name:", 5) == 0) {
         // Get the name token
         token = strtok(line+6, " ");
         
         // Allocate space for the name and copy it into the Resume structure
         resume->name = malloc(sizeof(char)*(strlen(token)+1));
         strcpy(resume->name, token);
      }
      
      if(strncmp(line, "Age:", 4) == 0) {
         // Get the age token
         token = strtok(line+5, " ");
         
         // Convert the token to an integer and store it in the Resume structure
         resume->age = atoi(token);
 
      }
      
      if(strncmp(line, "Email:", 6) == 0) {
         // Get the email token
         token = strtok(line+7, " ");

         // Allocate space for the email and copy it into the Resume structure
         resume->email = malloc(sizeof(char)*(strlen(token)+1));
         strcpy(resume->email, token);
  
      }
      
      if(strncmp(line, "Phone:", 6) == 0) {
         // Get the phone token
         token = strtok(line+7, " ");
         
         // Allocate space for the phone number and copy it into the Resume structure
         resume->phone = malloc(sizeof(char)*(strlen(token)+1));
         strcpy(resume->phone, token);

      }
      
      if(strncmp(line, "Address:", 8) == 0) {
         // Get the address token
         token = strtok(line+9, " ");
         
         // Allocate space for the address and copy it into the Resume structure
         resume->address = malloc(sizeof(char)*(strlen(token)+1));
         strcpy(resume->address, token);
         
         // Loop to get the rest of the address
         while(token = strtok(NULL, " ")) {
            // Concatenate the rest of the address onto the existing address
            resume->address = realloc(resume->address, sizeof(char)*(strlen(resume->address)+strlen(token)+2));
            strcat(resume->address, " ");
            strcat(resume->address, token);
         }
      }
   }
   
   // Close the file and return the parsed Resume structure
   fclose(fp);
   return resume;
}