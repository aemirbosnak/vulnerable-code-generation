//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: portable
#include <stdio.h>
#include <string.h>

typedef struct {
    char* name;
    char* email;
    char* phone;
} Resume;

Resume* read_resume(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char line[100];
    Resume* resume = malloc(sizeof(Resume));
    while (fgets(line, sizeof(line), file)) {
        char* colon = strchr(line, ':');
        if (colon!= NULL) {
            *colon = '\0';
        }
        strcpy(resume->name, line);
        colon = strchr(line, '@');
        if (colon!= NULL) {
            *colon = '\0';
        }
        strcpy(resume->email, line);
        colon = strchr(line, '-');
        if (colon!= NULL) {
            *colon = '\0';
        }
        strcpy(resume->phone, line);
    }
    fclose(file);
    return resume;
}

Resume* parse_resume(const char* resume) {
    Resume* resume_struct = malloc(sizeof(Resume));
    char* colon = strchr(resume, ':');
    if (colon!= NULL) {
        *colon = '\0';
    }
    strcpy(resume_struct->name, resume);
    colon = strchr(resume, '@');
    if (colon!= NULL) {
        *colon = '\0';
    }
    strcpy(resume_struct->email, resume);
    colon = strchr(resume, '-');
    if (colon!= NULL) {
        *colon = '\0';
    }
    strcpy(resume_struct->phone, resume);
    return resume_struct;
}

void print_resume(Resume* resume) {
    printf("%s\n%s\n%s\n", resume->name, resume->email, resume->phone);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    Resume* resume = read_resume(argv[1]);
    if (resume!= NULL) {
        Resume* parsed_resume = parse_resume(resume->name);
        if (parsed_resume!= NULL) {
            print_resume(parsed_resume);
            free(parsed_resume);
            free(resume);
        } else {
            fprintf(stderr, "Error parsing resume\n");
        }
    } else {
        fprintf(stderr, "Error reading resume\n");
    }

    return 0;
}