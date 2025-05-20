//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: grateful
#include <stdio.h>

#define MAX_RESUME_SIZE 1000000 /* Maximum resume size assumed to be 1 MB */
#define MAX_LINE_SIZE 1024 /* Maximum line size of the resume assumed to be 1 KB */
#define MAX_TAG_SIZE 256 /* Maximum tag size assumed to be 256 bytes */
#define MAX_BASE_TAGS 5 /* Maximum base tags for a resume (Name, Email, Phone, Education, Experience) */
#define MAX_LANGUAGES 5 /* Maximum number of programming languages a candidate can list */
#define MAX_SKILLS 10 /* Maximum number of skills a candidate can list */

/* Base tags for a resume */
char base_tags[MAX_BASE_TAGS][MAX_TAG_SIZE] = {"Name", "Email", "Phone", "Education", "Experience"};

/* Programming languages and their respective proficiency level */
struct programming_language {
    char name[MAX_TAG_SIZE];
    char proficiency[MAX_TAG_SIZE];
} languages[MAX_LANGUAGES];

/* Skills and their respective proficiency level */
struct skill {
    char name[MAX_TAG_SIZE];
    char proficiency[MAX_TAG_SIZE];
} skills[MAX_SKILLS];

/* Structure to hold all the extracted information from a resume */
struct candidate_info {
    char name[MAX_TAG_SIZE];
    char email[MAX_TAG_SIZE];
    char phone[MAX_TAG_SIZE];
    char education[MAX_LINE_SIZE];
    char experience[MAX_LINE_SIZE];
    struct programming_language languages[MAX_LANGUAGES];
    struct skill skills[MAX_SKILLS];
} candidate;

/* Function to extract information from a line */
void extract_line_info(char* line) {
    /* Loop through all the base tags to extract their values */
    for (int i = 0; i < MAX_BASE_TAGS; i++) {
        if (strstr(line, base_tags[i])) {
            char* value = strchr(line, ':') + 2;
            switch(i) {
                case 0:
                    strcpy(candidate.name, value);
                    break;
                case 1:
                    strcpy(candidate.email, value);
                    break;
                case 2:
                    strcpy(candidate.phone, value);
                    break;
                case 3:
                    strcpy(candidate.education, value);
                    break;
                case 4:
                    strcpy(candidate.experience, value);
                    break;
            }
        }
    }
    /* Loop through all the language tags to extract their values */
    for (int i = 0; i < MAX_LANGUAGES; i++) {
        char language_tag[MAX_TAG_SIZE];
        sprintf(language_tag, "Language %d", i+1);
        if (strstr(line, language_tag)) {
            char* language_name = strchr(line, ':') + 2;
            char* proficiency_level = strchr(language_name, '-') + 2;
            strncpy(candidate.languages[i].name, language_name, strchr(language_name, '-') - language_name - 1);
            strcpy(candidate.languages[i].proficiency, proficiency_level);
        }
    }
    /* Loop through all the skill tags to extract their values */
    for (int i = 0; i < MAX_SKILLS; i++) {
        char skill_tag[MAX_TAG_SIZE];
        sprintf(skill_tag, "Skill %d", i+1);
        if (strstr(line, skill_tag)) {
            char* skill_name = strchr(line, ':') + 2;
            char* proficiency_level = strchr(skill_name, '-') + 2;
            strncpy(candidate.skills[i].name, skill_name, strchr(skill_name, '-') - skill_name - 1);
            strcpy(candidate.skills[i].proficiency, proficiency_level);
        }
    }
}

/* Function to parse the resume */
void parse_resume(char* resume) {
    FILE* fp;
    char line[MAX_LINE_SIZE];

    /* Open the resume for reading */
    fp = fopen(resume, "r");
    if (fp == NULL) {
        printf("Error: Unable to open the resume file.");
        exit(1);
    }

    /* Loop through all the lines in the resume */
    while (fgets(line, MAX_LINE_SIZE, fp)) {
        extract_line_info(line);
    }

    /* Close the file */
    fclose(fp);
}

int main() {
    printf("Enter the path of the resume file: ");
    char resume[MAX_RESUME_SIZE];
    fgets(resume, MAX_RESUME_SIZE, stdin);
    strtok(resume, "\n"); /* Remove the trailing newline character */
    parse_resume(resume);
    
    /* Print the candidate information */
    printf("\nCandidate Name: %s\n", candidate.name);
    printf("Email: %s\n", candidate.email);
    printf("Phone: %s\n", candidate.phone);
    printf("Education: %s\n", candidate.education);
    printf("Experience: %s\n", candidate.experience);
    printf("Languages:\n");
    for (int i = 0; i < MAX_LANGUAGES; i++) {
        if (strlen(candidate.languages[i].name) > 0) {
            printf("%s (%s)\n", candidate.languages[i].name, candidate.languages[i].proficiency);
        }
    }
    printf("Skills:\n");
    for (int i = 0; i < MAX_SKILLS; i++) {
        if (strlen(candidate.skills[i].name) > 0) {
            printf("%s (%s)\n", candidate.skills[i].name, candidate.skills[i].proficiency);
        }
    }
    return 0;
}