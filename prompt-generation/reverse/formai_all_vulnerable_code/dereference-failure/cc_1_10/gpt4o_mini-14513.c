//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CV_MAX_LINES 100
#define LINE_LENGTH 256

typedef struct {
    char *name;
    int age;
    char *email;
    char *skills[10];
    int skill_count;
} Resume;

Resume* create_resume() {
    Resume *new_resume = (Resume*)malloc(sizeof(Resume));
    new_resume->name = NULL;
    new_resume->email = NULL;
    new_resume->skill_count = 0;
    new_resume->age = 0;
    return new_resume;
}

void free_resume(Resume *resume) {
    if (resume) {
        free(resume->name);
        free(resume->email);
        for (int i = 0; i < resume->skill_count; i++) {
            free(resume->skills[i]);
        }
        free(resume);
    }
}

void parse_line(Resume *resume, const char *line) {
    if (strstr(line, "Name:") == line) {
        resume->name = strdup(line + 5);
    } else if (strstr(line, "Age:") == line) {
        resume->age = atoi(line + 4);
    } else if (strstr(line, "Email:") == line) {
        resume->email = strdup(line + 6);
    } else if (strstr(line, "Skills:") == line) {
        char *token = strtok((char *)(line + 7), ", ");
        while (token && resume->skill_count < 10) {
            resume->skills[resume->skill_count] = strdup(token);
            resume->skill_count++;
            token = strtok(NULL, ", ");
        }
    }
}

void surreal_resume_display(Resume *resume) {
    if (resume) {
        printf("In the realm of resumes where shadows dance:\n");
        printf("Name: %s", resume->name);
        printf("Age: %d revolutions around the sun\n", resume->age);
        printf("Email: %s, the digital echo of your being\n", resume->email);
        printf("Skills, like petals that float in the breeze:\n");
        for (int i = 0; i < resume->skill_count; i++) {
            printf("- %s\n", resume->skills[i]);
        }
        printf("And thus, the essence of you breathes in typed words.\n");
    } else {
        printf("The void of nonexistence lingers here.\n");
    }
}

int main() {
    char *lines[CV_MAX_LINES];
    char buffer[LINE_LENGTH];
    Resume *my_resume = create_resume();
    int line_count = 0;

    printf("Welcome to the Surreal Resume Parsing Machine!\n");
    printf("Please conjure your resume line by line. Type 'END' to finish.\n");

    while (line_count < CV_MAX_LINES) {
        printf("Enter line %d: ", line_count + 1);
        fgets(buffer, LINE_LENGTH, stdin);
        buffer[strcspn(buffer, "\n")] = 0;  // Remove newline

        if (strcmp(buffer, "END") == 0) {
            break;
        }

        lines[line_count] = strdup(buffer);
        parse_line(my_resume, buffer);
        line_count++;
    }

    surreal_resume_display(my_resume);

    for (int i = 0; i < line_count; i++) {
        free(lines[i]);
    }

    free_resume(my_resume);
    return 0;
}