//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define global variables
#define MAX_LINE_LEN 1000
#define MAX_FIELD_LEN 100
#define MAX_FIELDS 10

char *field_names[MAX_FIELDS] = {"name", "education", "experience", "skills", "date of birth"};

struct resume {
    char name[MAX_FIELD_LEN];
    char education[MAX_FIELD_LEN];
    char experience[MAX_FIELD_LEN];
    char skills[MAX_FIELD_LEN];
    char dob[MAX_FIELD_LEN];
};

/**
 * This function reads a line from the file and splits it into fields
 * based on the delimiter.
 *
 * @param line the line to be read
 * @param fields the array where fields will be stored
 * @param delimiter the delimiter to use for splitting the line
 * @return the number of fields
 */
int get_fields(char *line, char **fields, char *delimiter) {
    int num_fields = 0;
    char *token = strtok(line, delimiter);
    while (token != NULL) {
        fields[num_fields++] = token;
        token = strtok(NULL, delimiter);
    }
    return num_fields;
}

/**
 * This function reads the resume file, extracts the fields and creates a struct
 * for each resume.
 *
 * @param resume_file the file containing the resumes
 * @param num_resumes a pointer to store the number of resumes
 * @return an array of resume structs
 */
struct resume* parse_resumes(char *resume_file, int *num_resumes) {
    FILE *file = fopen(resume_file, "r");
    if (file == NULL) {
        printf("Unable to open file %s\n", resume_file);
        exit(1);
    }

    // read the first line of the file to get field names
    char line[MAX_LINE_LEN];
    fgets(line, MAX_LINE_LEN, file);
    char *fields[MAX_FIELDS];
    int num_fields = get_fields(line, fields, ",");

    // validate the field names
    for (int i = 0; i < num_fields; i++) {
        if (strcmp(fields[i], field_names[i]) != 0) {
            printf("Invalid field name %s at position %d\n", fields[i], i+1);
            exit(1);
        }
    }

    // count the number of resumes in the file
    int count = 0;
    while (fgets(line, MAX_LINE_LEN, file) != NULL) {
        count++;
    }
    *num_resumes = count;

    // allocate memory for the resumes
    struct resume *resumes = malloc(sizeof(struct resume) * count);

    // read the resumes from the file
    fseek(file, 0, SEEK_SET);
    fgets(line, MAX_LINE_LEN, file); // skip the header row
    for (int i = 0; i < count; i++) {
        fgets(line, MAX_LINE_LEN, file);
        char *fields[MAX_FIELDS];
        num_fields = get_fields(line, fields, ",");
        if (num_fields != num_resumes) {
            printf("Invalid number of fields in line %d\n", i+2);
            exit(1);
        }
        strcpy(resumes[i].name, fields[0]);
        strcpy(resumes[i].education, fields[1]);
        strcpy(resumes[i].experience, fields[2]);
        strcpy(resumes[i].skills, fields[3]);
        strcpy(resumes[i].dob, fields[4]);
    }

    fclose(file);
    return resumes;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        exit(1);
    }

    int num_resumes;
    struct resume *resumes = parse_resumes(argv[1], &num_resumes);

    printf("Found %d resumes:\n", num_resumes);
    for (int i = 0; i < num_resumes; i++) {
        printf("Resume %d:\n", i+1);
        printf("  Name: %s\n", resumes[i].name);
        printf("  Education: %s\n", resumes[i].education);
        printf("  Experience: %s\n", resumes[i].experience);
        printf("  Skills: %s\n", resumes[i].skills);
        printf("  Date of Birth: %s\n", resumes[i].dob);
        printf("\n");
    }

    free(resumes);
    return 0;
}