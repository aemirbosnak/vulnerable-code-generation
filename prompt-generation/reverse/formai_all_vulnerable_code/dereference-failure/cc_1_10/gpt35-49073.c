//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_SIZE 100
#define MAX_RESUME_ENTRIES 50
#define MAX_COMPANY_KEYWORDS 100

// Struct for storing company keyword data
typedef struct {
    char keyword[MAX_STRING_SIZE];
    int weight;
} CompanyKeyword;

// Struct for storing resume entries
typedef struct {
    char category[MAX_STRING_SIZE];
    char entry[MAX_STRING_SIZE];
} ResumeEntry;

// Function for reading company keyword data from file
void read_company_keywords(CompanyKeyword *keywords, int *num_keywords) {
    FILE *fp = fopen("company_keywords.txt", "r");

    char buffer[MAX_STRING_SIZE];
    *num_keywords = 0;

    while (fgets(buffer, MAX_STRING_SIZE, fp)) {
        char *token = strtok(buffer, ",");
        strncpy(keywords[*num_keywords].keyword, token, MAX_STRING_SIZE);

        token = strtok(NULL, ",");
        keywords[*num_keywords].weight = atoi(token);

        (*num_keywords)++;
    }

    fclose(fp);
}

int main() {
    // Read company keywords from file
    CompanyKeyword company_keywords[MAX_COMPANY_KEYWORDS];
    int num_company_keywords;
    read_company_keywords(company_keywords, &num_company_keywords);

    // Initialize resume entries
    ResumeEntry resume_entries[MAX_RESUME_ENTRIES];
    int num_resume_entries = 0;

    // Simulate reading resume entries from file
    char sample_resume[MAX_RESUME_ENTRIES][MAX_STRING_SIZE] = {
        "Education,University of XYZ",
        "Experience,Software Engineer,ABC Company",
        "Skills,C++,Java,Python",
        "Experience,Intern,XYZ Company",
        "Education,M.S. in Computer Science,XYZ University"
    };

    // Parse resume entries from sample data
    for (int i = 0; i < MAX_RESUME_ENTRIES; i++) {
        char *category = strtok(sample_resume[i], ",");
        char *entry = strtok(NULL, ",");

        // Ignore entries with empty categories or entries
        if (category && entry) {
            strncpy(resume_entries[num_resume_entries].category, category, MAX_STRING_SIZE);
            strncpy(resume_entries[num_resume_entries].entry, entry, MAX_STRING_SIZE);

            num_resume_entries++;
        }
    }

    // Analyze resume entries for company keywords
    int total_weight = 0;
    for (int i = 0; i < num_resume_entries; i++) {
        for (int j = 0; j < num_company_keywords; j++) {
            if (strstr(resume_entries[i].entry, company_keywords[j].keyword)) {
                total_weight += company_keywords[j].weight;
            }
        }
    }

    // Print overall score based on company keyword matches
    printf("Overall Resume Score: %d\n", total_weight);

    return 0;
}