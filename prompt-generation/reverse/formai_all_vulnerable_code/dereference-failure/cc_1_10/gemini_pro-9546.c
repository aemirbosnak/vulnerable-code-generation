//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove all punctuation from a string
char *remove_punctuation(char *str) {
  int i, j;
  char *new_str = malloc(strlen(str) + 1);
  for (i = 0, j = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      new_str[j++] = str[i];
    } else if (str[i] >= 'A' && str[i] <= 'Z') {
      new_str[j++] = str[i];
    } else if (str[i] == ' ') {
      new_str[j++] = str[i];
    }
  }
  new_str[j] = '\0';
  return new_str;
}

// Function to count the number of occurrences of a substring in a string
int count_substring(char *str, char *substr) {
  int count = 0;
  int i, j;
  int len_str = strlen(str);
  int len_substr = strlen(substr);
  for (i = 0; i <= len_str - len_substr; i++) {
    for (j = 0; j < len_substr; j++) {
      if (str[i + j] != substr[j]) {
        break;
      }
    }
    if (j == len_substr) {
      count++;
    }
  }
  return count;
}

// Function to parse a resume and extract the skills
char **parse_resume(char *resume) {
  char *skills[] = {"C", "C++", "Java", "Python", "HTML", "CSS", "JavaScript", "SQL", "NoSQL", "Git"};
  int num_skills = sizeof(skills) / sizeof(skills[0]);
  char **skill_list = malloc(num_skills * sizeof(char *));
  int i;
  for (i = 0; i < num_skills; i++) {
    skill_list[i] = malloc(strlen(skills[i]) + 1);
    strcpy(skill_list[i], skills[i]);
  }
  char *clean_resume = remove_punctuation(resume);
  for (i = 0; i < num_skills; i++) {
    skill_list[i] = realloc(skill_list[i], strlen(clean_resume) + 1);
    strcpy(skill_list[i], clean_resume);
    skill_list[i] = strstr(skill_list[i], skills[i]);
    if (skill_list[i] == NULL) {
      skill_list[i][0] = '\0';
    }
  }
  return skill_list;
}

// Function to print the skills extracted from a resume
void print_skills(char **skill_list) {
  int i;
  int num_skills = sizeof(skill_list) / sizeof(skill_list[0]);
  for (i = 0; i < num_skills; i++) {
    if (skill_list[i][0] != '\0') {
      printf("%s\n", skill_list[i]);
    }
  }
}

int main() {
  char *resume = "I am a software engineer with 5 years of experience in C, C++, Java, and Python. I have also worked with HTML, CSS, JavaScript, SQL, and NoSQL. I am proficient in Git and have experience with Agile development methodologies.";
  char **skill_list = parse_resume(resume);
  printf("Skills:\n");
  print_skills(skill_list);
  return 0;
}