//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
    char name[50];
    char email[50];
    char education[100];
    char experience[500];
    int num_skills;
    char **skills;
};

int parse_resume(char *filename, struct resume *r) {
    FILE *fp;
    char line[500];
    char *token;
    int i;

    fp = fopen(filename, "r");

    if (!fp) {
        printf("Error: could not open file.\n");
        return -1;
    }

    fgets(line, 500, fp);

    // Parse name from first line
    token = strtok(line, ",");
    strcpy(r->name, token);

    // Parse email from second line
    fgets(line, 500, fp);
    token = strtok(line, ",");
    strcpy(r->email, token);

    // Parse education from third line
    fgets(line, 500, fp);
    token = strtok(line, ",");
    strcpy(r->education, token);

    // Parse experience from fourth line
    fgets(line, 500, fp);
    token = strtok(line, ",");
    strcpy(r->experience, token);

    // Parse skills from fifth line
    fgets(line, 500, fp);
    token = strtok(line, ",");
    r->num_skills = atoi(token);

    r->skills = malloc(r->num_skills * sizeof(char *));
    for (i = 0; i < r->num_skills; i++) {
        fgets(line, 500, fp);
        token = strtok(line, ",");
        r->skills[i] = malloc(strlen(token) + 1);
        strcpy(r->skills[i], token);
    }

    fclose(fp);

    return 0;
}

void print_resume(struct resume r) {
    int i;

    printf("Resume for %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Education: %s\n", r.education);
    printf("Experience: %s\n", r.experience);
    printf("Skills: ");
    for (i = 0; i < r.num_skills; i++) {
        printf("%s", r.skills[i]);
        if (i < r.num_skills - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int main() {
    struct resume r;
    int i, ret;

    ret = parse_resume("resume.txt", &r);

    if (ret < 0) {
        return -1;
    }

    print_resume(r);

    // Free memory
    for (i = 0; i < r.num_skills; i++) {
        free(r.skills[i]);
    }
    free(r.skills);

    return 0;
}