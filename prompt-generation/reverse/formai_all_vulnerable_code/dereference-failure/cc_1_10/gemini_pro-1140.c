//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to store the resume data
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *experience;
    char *education;
} resume_t;

// Function to parse a line of text and extract the name
char *parse_name(char *line) {
    char *name = NULL;
    char *start = strstr(line, "Name:");
    if (start) {
        start += 5; // Skip "Name:"
        while (*start && !isspace(*start)) {
            start++;
        }
        while (*start && isspace(*start)) {
            start++;
        }
        char *end = start;
        while (*end && !isspace(*end)) {
            end++;
        }
        name = strndup(start, end - start);
    }
    return name;
}

// Function to parse a line of text and extract the email
char *parse_email(char *line) {
    char *email = NULL;
    char *start = strstr(line, "Email:");
    if (start) {
        start += 6; // Skip "Email:"
        while (*start && !isspace(*start)) {
            start++;
        }
        while (*start && isspace(*start)) {
            start++;
        }
        char *end = start;
        while (*end && !isspace(*end)) {
            end++;
        }
        email = strndup(start, end - start);
    }
    return email;
}

// Function to parse a line of text and extract the phone
char *parse_phone(char *line) {
    char *phone = NULL;
    char *start = strstr(line, "Phone:");
    if (start) {
        start += 6; // Skip "Phone:"
        while (*start && !isspace(*start)) {
            start++;
        }
        while (*start && isspace(*start)) {
            start++;
        }
        char *end = start;
        while (*end && !isspace(*end)) {
            end++;
        }
        phone = strndup(start, end - start);
    }
    return phone;
}

// Function to parse a line of text and extract the address
char *parse_address(char *line) {
    char *address = NULL;
    char *start = strstr(line, "Address:");
    if (start) {
        start += 8; // Skip "Address:"
        while (*start && !isspace(*start)) {
            start++;
        }
        while (*start && isspace(*start)) {
            start++;
        }
        char *end = start;
        while (*end && !isspace(*end)) {
            end++;
        }
        address = strndup(start, end - start);
    }
    return address;
}

// Function to parse a line of text and extract the skills
char *parse_skills(char *line) {
    char *skills = NULL;
    char *start = strstr(line, "Skills:");
    if (start) {
        start += 7; // Skip "Skills:"
        while (*start && !isspace(*start)) {
            start++;
        }
        while (*start && isspace(*start)) {
            start++;
        }
        char *end = start;
        while (*end && !isspace(*end)) {
            end++;
        }
        skills = strndup(start, end - start);
    }
    return skills;
}

// Function to parse a line of text and extract the experience
char *parse_experience(char *line) {
    char *experience = NULL;
    char *start = strstr(line, "Experience:");
    if (start) {
        start += 11; // Skip "Experience:"
        while (*start && !isspace(*start)) {
            start++;
        }
        while (*start && isspace(*start)) {
            start++;
        }
        char *end = start;
        while (*end && !isspace(*end)) {
            end++;
        }
        experience = strndup(start, end - start);
    }
    return experience;
}

// Function to parse a line of text and extract the education
char *parse_education(char *line) {
    char *education = NULL;
    char *start = strstr(line, "Education:");
    if (start) {
        start += 10; // Skip "Education:"
        while (*start && !isspace(*start)) {
            start++;
        }
        while (*start && isspace(*start)) {
            start++;
        }
        char *end = start;
        while (*end && !isspace(*end)) {
            end++;
        }
        education = strndup(start, end - start);
    }
    return education;
}

// Function to parse a resume file
resume_t *parse_resume(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        return NULL;
    }

    resume_t *resume = malloc(sizeof(resume_t));
    resume->name = NULL;
    resume->email = NULL;
    resume->phone = NULL;
    resume->address = NULL;
    resume->skills = NULL;
    resume->experience = NULL;
    resume->education = NULL;

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        char *name = parse_name(line);
        if (name) {
            resume->name = name;
        }

        char *email = parse_email(line);
        if (email) {
            resume->email = email;
        }

        char *phone = parse_phone(line);
        if (phone) {
            resume->phone = phone;
        }

        char *address = parse_address(line);
        if (address) {
            resume->address = address;
        }

        char *skills = parse_skills(line);
        if (skills) {
            resume->skills = skills;
        }

        char *experience = parse_experience(line);
        if (experience) {
            resume->experience = experience;
        }

        char *education = parse_education(line);
        if (education) {
            resume->education = education;
        }
    }

    fclose(fp);

    return resume;
}

// Function to print a resume
void print_resume(resume_t *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);
}

// Main function
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    resume_t *resume = parse_resume(argv[1]);
    if (!resume) {
        fprintf(stderr, "Error parsing resume file\n");
        return EXIT_FAILURE;
    }

    print_resume(resume);

    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->address);
    free(resume->skills);
    free(resume->experience);
    free(resume->education);
    free(resume);

    return EXIT_SUCCESS;
}