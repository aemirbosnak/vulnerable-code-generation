//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_RESUMES 10
#define MAX_LEN 255
#define SKILL_LEN 50

typedef struct {
    char filename[MAX_LEN];
} ResumeFile;

typedef struct {
    char name[MAX_LEN];
    char email[MAX_LEN];
    char skills[5][SKILL_LEN]; // Assume at most 5 skills
    int skill_count;
} ParsedResume;

void *parse_resume(void *arg) {
    ResumeFile *resumeFile = (ResumeFile *)arg;
    ParsedResume *result = malloc(sizeof(ParsedResume));
    
    // Initialize result
    memset(result, 0, sizeof(ParsedResume));
    
    FILE *file = fopen(resumeFile->filename, "r");
    if (!file) {
        perror("File opening failed");
        free(result);
        return NULL;
    }

    char line[MAX_LEN];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Name:") != NULL) {
            sscanf(line, "Name: %[^\n]", result->name);
        } else if (strstr(line, "Email:") != NULL) {
            sscanf(line, "Email: %[^\n]", result->email);
        } else if (strstr(line, "Skills:") != NULL) {
            char *ptr = strtok(line + 7, ","); // Skips "Skills:"
            while (ptr != NULL && result->skill_count < 5) {
                strcpy(result->skills[result->skill_count++], ptr);
                ptr = strtok(NULL, ",");
            }
        }
    }
    
    fclose(file);
    return result;
}

void print_parsed_resume(ParsedResume *resume) {
    printf("Parsed Resume:\n");
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Skills: ");
    for (int i = 0; i < resume->skill_count; i++) {
        printf("%s%s", resume->skills[i], (i == resume->skill_count - 1) ? "\n" : ", ");
    }
}

int main() {
    pthread_t threads[MAX_RESUMES];
    ResumeFile resumes[MAX_RESUMES] = {
        {"resume1.txt"},
        {"resume2.txt"},
        {"resume3.txt"},
        {"resume4.txt"},
        {"resume5.txt"},
        {"resume6.txt"},
        {"resume7.txt"},
        {"resume8.txt"},
        {"resume9.txt"},
        {"resume10.txt"},
    };
    
    for (int i = 0; i < MAX_RESUMES; i++) {
        if (pthread_create(&threads[i], NULL, parse_resume, &resumes[i]) != 0) {
            fprintf(stderr, "Error creating thread for %s\n", resumes[i].filename);
            return 1;
        }
    }

    for (int i = 0; i < MAX_RESUMES; i++) {
        ParsedResume *result;
        pthread_join(threads[i], (void **)&result);
        if (result != NULL) {
            print_parsed_resume(result);
            free(result);
        }
    }

    return 0;
}