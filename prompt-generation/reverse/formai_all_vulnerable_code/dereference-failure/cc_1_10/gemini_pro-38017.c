//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum number of skills and keywords to search for
#define MAX_SKILLS 10
#define MAX_KEYWORDS 10

// Define the structure of a skill
typedef struct skill {
  char *name;
  int level;
} skill;

// Define the structure of a resume
typedef struct resume {
  char *name;
  char *email;
  char *phone;
  char *address;
  char *summary;
  skill skills[MAX_SKILLS];
  int num_skills;
  char *keywords;
} resume;

// Define the function to parse a resume
int parse_resume(char *filename, resume *resume) {
  // Open the resume file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening resume file %s\n", filename);
    return -1;
  }

  // Read the resume header
  char line[1024];
  if (fgets(line, sizeof(line), file) == NULL) {
    fprintf(stderr, "Error reading resume header\n");
    fclose(file);
    return -1;
  }

  // Parse the resume header
  char *name = strtok(line, ",");
  char *email = strtok(NULL, ",");
  char *phone = strtok(NULL, ",");
  char *address = strtok(NULL, "\n");

  // Store the resume header in the resume structure
  resume->name = strdup(name);
  resume->email = strdup(email);
  resume->phone = strdup(phone);
  resume->address = strdup(address);

  // Read the resume summary
  if (fgets(line, sizeof(line), file) == NULL) {
    fprintf(stderr, "Error reading resume summary\n");
    fclose(file);
    return -1;
  }

  // Parse the resume summary
  char *summary = strdup(line);

  // Store the resume summary in the resume structure
  resume->summary = summary;

  // Read the resume skills
  int num_skills = 0;
  while (fgets(line, sizeof(line), file) != NULL) {
    // Parse the resume skill
    char *skill_name = strtok(line, ",");
    char *skill_level = strtok(NULL, "\n");

    // Store the resume skill in the resume structure
    resume->skills[num_skills].name = strdup(skill_name);
    resume->skills[num_skills].level = atoi(skill_level);

    // Increment the number of skills
    num_skills++;
  }

  // Store the number of skills in the resume structure
  resume->num_skills = num_skills;

  // Read the resume keywords
  if (fgets(line, sizeof(line), file) == NULL) {
    fprintf(stderr, "Error reading resume keywords\n");
    fclose(file);
    return -1;
  }

  // Parse the resume keywords
  char *keywords = strdup(line);

  // Store the resume keywords in the resume structure
  resume->keywords = keywords;

  // Close the resume file
  fclose(file);

  return 0;
}

// Define the function to print a resume
void print_resume(resume *resume) {
  // Print the resume header
  printf("Name: %s\n", resume->name);
  printf("Email: %s\n", resume->email);
  printf("Phone: %s\n", resume->phone);
  printf("Address: %s\n", resume->address);

  // Print the resume summary
  printf("Summary: %s\n", resume->summary);

  // Print the resume skills
  printf("Skills:\n");
  for (int i = 0; i < resume->num_skills; i++) {
    printf("  - %s (%d)\n", resume->skills[i].name, resume->skills[i].level);
  }

  // Print the resume keywords
  printf("Keywords: %s\n", resume->keywords);
}

// Define the function to search for a skill in a resume
int search_skill(resume *resume, char *skill_name) {
  // Convert the skill name to lowercase
  char *skill_name_lower = strdup(skill_name);
  for (int i = 0; skill_name_lower[i] != '\0'; i++) {
    skill_name_lower[i] = tolower(skill_name_lower[i]);
  }

  // Search for the skill in the resume
  for (int i = 0; i < resume->num_skills; i++) {
    // Convert the skill name in the resume to lowercase
    char *resume_skill_name_lower = strdup(resume->skills[i].name);
    for (int j = 0; resume_skill_name_lower[j] != '\0'; j++) {
      resume_skill_name_lower[j] = tolower(resume_skill_name_lower[j]);
    }

    // Compare the skill name to the skill name in the resume
    if (strcmp(skill_name_lower, resume_skill_name_lower) == 0) {
      return 1;
    }
  }

  // The skill was not found in the resume
  return 0;
}

// Define the function to search for a keyword in a resume
int search_keyword(resume *resume, char *keyword) {
  // Convert the keyword to lowercase
  char *keyword_lower = strdup(keyword);
  for (int i = 0; keyword_lower[i] != '\0'; i++) {
    keyword_lower[i] = tolower(keyword_lower[i]);
  }

  // Search for the keyword in the resume
  char *keywords = strdup(resume->keywords);
  for (int i = 0; keywords[i] != '\0'; i++) {
    // Convert the keyword in the resume to lowercase
    char *resume_keyword_lower = strdup(&keywords[i]);
    for (int j = 0; resume_keyword_lower[j] != '\0'; j++) {
      resume_keyword_lower[j] = tolower(resume_keyword_lower[j]);
    }

    // Compare the keyword to the keyword in the resume
    if (strcmp(keyword_lower, resume_keyword_lower) == 0) {
      return 1;
    }
  }

  // The keyword was not found in the resume
  return 0;
}

// Define the function to main
int main(int argc, char **argv) {
  // Check the number of arguments
  if (argc < 3) {
    fprintf(stderr, "Usage: %s resume.txt skill keyword\n", argv[0]);
    return -1;
  }

  // Load the resume from the given file
  resume resume;
  if (parse_resume(argv[1], &resume) != 0) {
    return -1;
  }

  // Parse the given skill
  char *skill_name = argv[2];

  // Search for the skill in the resume
  int skill_found = search_skill(&resume, skill_name);

  // Parse the given keyword
  char *keyword = argv[3];

  // Search for the keyword in the resume
  int keyword_found = search_keyword(&resume, keyword);

  // Print the results
  if (skill_found && keyword_found) {
    printf("The resume matches both the skill and keyword\n");
  } else if (skill_found) {
    printf("The resume matches the skill but not the keyword\n");
  } else if (keyword_found) {
    printf("The resume matches the keyword but not the skill\n");
  } else {
    printf("The resume does not match either the skill or the keyword\n");
  }

  // Free the memory allocated for the resume
  free(resume.name);
  free(resume.email);
  free(resume.phone);
  free(resume.address);
  free(resume.summary);
  for (int i = 0; i < resume.num_skills; i++) {
    free(resume.skills[i].name);
  }
  free(resume.keywords);

  return 0;
}