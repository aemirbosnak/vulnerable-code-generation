//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define struct for resume details
typedef struct{
  char *name;
  char *email;
  char *phone;
  char *experience;
  char *education;
  char *skills;
} Resume;

// function to parse and store resume details
Resume parseResume(char *resumeText){
  Resume parsedResume;
  // split resume text by new lines
  char *token = strtok(resumeText, "\n");
  while(token != NULL){
    // extract name, email, and phone
    if(strstr(token, "Name:") != NULL){
      parsedResume.name = token + strlen("Name: ");
    } else if(strstr(token, "Email:") != NULL){
      parsedResume.email = token + strlen("Email: ");
    } else if(strstr(token, "Phone:") != NULL){
      parsedResume.phone = token + strlen("Phone: ");
    }
    // extract experience
    else if(strstr(token, "Experience:") != NULL){
      parsedResume.experience = token + strlen("Experience: ");
    }
    // extract education
    else if(strstr(token, "Education:") != NULL){
      parsedResume.education = token + strlen("Education: ");
    }
    // extract skills
    else if(strstr(token, "Skills:") != NULL){
      parsedResume.skills = token + strlen("Skills: ");
    }
    token = strtok(NULL, "\n");
  }
  return parsedResume;
}

int main(){
  // example resume text
  char *resumeText = "Name: John Doe\nEmail: johndoe@email.com\nPhone: 123-456-7890\nExperience: Professionally trained as a software engineer with experience in Java, Python, and C++\nEducation: Bachelor's degree in Computer Science\nSkills: Agile development, software testing, and UI design\n";
  // parse resume details
  Resume myResume = parseResume(resumeText);
  // print resume details
  printf("Name: %s\n", myResume.name);
  printf("Email: %s\n", myResume.email);
  printf("Phone: %s\n", myResume.phone);
  printf("Experience: %s\n", myResume.experience);
  printf("Education: %s\n", myResume.education);
  printf("Skills: %s\n", myResume.skills);

  return 0;
}