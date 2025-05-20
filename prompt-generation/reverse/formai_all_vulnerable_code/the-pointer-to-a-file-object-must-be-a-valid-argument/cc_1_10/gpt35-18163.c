//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: rigorous
#include <stdio.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_SCORE 10

typedef struct {
    char name[30];
    char email[50];
    char education[50];
    char skills[100];
    char experience[100];
} Resume;

Resume resumes[MAX_RESUMES];
int num_resumes = 0;

int calculate_score(char* keywords[], int num_keywords, char* text) {
    int score = 0;

    char* ptr = strtok(text, " ");
    while (ptr != NULL) {
        for (int i = 0; i < num_keywords; i++) {
            if (strcmp(ptr, keywords[i]) == 0) {
                score++;
            }
        }
        ptr = strtok(NULL, " ");
    }

    return score;
}

void parse_resume(char* filename) {
    FILE* fp = fopen(filename, "r");

    Resume resume;
    fgets(resume.name, 30, fp);
    fgets(resume.email, 50, fp);
    fgets(resume.education, 50, fp);
    fgets(resume.skills, 100, fp);
    fgets(resume.experience, 100, fp);

    fclose(fp);

    resumes[num_resumes++] = resume;
}

void search_resumes(char* keywords[], int num_keywords) {
    int scores[MAX_RESUMES];

    for (int i = 0; i < num_resumes; i++) {
        Resume resume = resumes[i];
        int edu_score = calculate_score(keywords, num_keywords, resume.education);
        int skills_score = calculate_score(keywords, num_keywords, resume.skills);
        int experience_score = calculate_score(keywords, num_keywords, resume.experience);
        scores[i] = edu_score * 3 + skills_score * 4 + experience_score * 3;
    }

    for (int i = 0; i < num_resumes; i++) {
        for (int j = i + 1; j < num_resumes; j++) {
            if (scores[j] > scores[i]) {
                int temp_score = scores[i];
                scores[i] = scores[j];
                scores[j] = temp_score;

                Resume temp_resume = resumes[i];
                resumes[i] = resumes[j];
                resumes[j] = temp_resume;
            }
        }
    }

    for (int i = 0; i < num_resumes && i < MAX_SCORE; i++) {
        printf("Name: %s\n", resumes[i].name);
        printf("Education: %s\n", resumes[i].education);
        printf("Skills: %s\n", resumes[i].skills);
        printf("Experience: %s\n\n", resumes[i].experience);
    }
}

int main() {
    parse_resume("resume1.txt");
    parse_resume("resume2.txt");
    parse_resume("resume3.txt");

    char* keywords[] = {"C", "Python", "Java", "Web", "Database", "Machine", "Learning"};
    search_resumes(keywords, 7);

    return 0;
}