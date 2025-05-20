//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_SIZE 10000
#define MAX_KEYWORD_SIZE 50
#define MAX_MATCHES 5

// Struct to represent a keyword and its weightage
typedef struct Keyword {
    char* word;
    int weightage;
} Keyword;

// Struct to represent a resume with its matching scores
typedef struct Resume {
    char* content;
    int scores[MAX_MATCHES];
} Resume;

// Function to read a file and return its content as a string
char* read_file(char* filename) {
    FILE* fp;
    char* content = calloc(MAX_RESUME_SIZE, sizeof(char));

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to read file: %s\n", filename);
        exit(1);
    }

    while(!feof(fp)) {
        strcat(content, fgets(content+strlen(content), MAX_RESUME_SIZE-strlen(content)-1, fp));
    }

    fclose(fp);
    return content;
}

// Function to get the total weightage of a set of keywords found in a given text
int get_total_weightage(char* text, Keyword* keywords, int n) {
    int total_weightage = 0;

    char* token = strtok(text, " ,.-"); // tokenizing on whitespace, comma, hyphen, and period
    while (token != NULL) {
        for (int i = 0; i < n; i++) {
            if (strcmp(token, keywords[i].word) == 0) {
                total_weightage += keywords[i].weightage;
            }
        }
        token = strtok(NULL, " ,.-");
    }

    return total_weightage;
}

// Function to find the top n matching resumes based on a set of keywords
Resume* find_matching_resumes(char** resumes, int num_resumes, Keyword* keywords, int num_keywords, int n) {
    Resume* matched_resumes = calloc(num_resumes, sizeof(Resume));
    int resume_scores[num_resumes]; // array to store scores of each resume

    for (int i = 0; i < num_resumes; i++) {
        matched_resumes[i].content = resumes[i];
        // getting the total weightage of all keywords found in the resume
        int total_weightage = get_total_weightage(resumes[i], keywords, num_keywords);
        resume_scores[i] = total_weightage;
        // initializing scores array of matched_resume struct with -1
        for (int j = 0; j < n; j++) {
            matched_resumes[i].scores[j] = -1;
        }
    }

    // sorting resume_scores in descending order and updating the matched_resumes struct accordingly
    for (int i = 0; i < num_resumes-1; i++) {
        for (int j = i+1; j < num_resumes; j++) {
            if (resume_scores[j] > resume_scores[i]) {
                int temp = resume_scores[i];
                resume_scores[i] = resume_scores[j];
                resume_scores[j] = temp;
                Resume temp_resume = matched_resumes[i];
                matched_resumes[i] = matched_resumes[j];
                matched_resumes[j] = temp_resume;
            }
        }
    }

    // finding top n matching resumes
    for (int i = 0; i < n; i++) {
        int max_score = resume_scores[i];
        for (int j = 0; j < num_resumes; j++) {
            if (matched_resumes[j].scores[i] == -1 && resume_scores[j] == max_score) {
                matched_resumes[j].scores[i] = max_score;
                break;
            }
        }
    }

    return matched_resumes;
}

int main() {
    // list of resumes to parse
    char* resumes[] = {"resume1.txt", "resume2.txt", "resume3.txt", "resume4.txt", "resume5.txt"};
    int num_resumes = sizeof(resumes) / sizeof(char*);

    // list of keywords and their weightages
    Keyword keywords[] = {{"C", 5}, {"Java", 4}, {"Python", 3}, {"SQL", 2}, {"JavaScript", 1}};
    int num_keywords = sizeof(keywords) / sizeof(Keyword);

    Resume* matched_resumes = find_matching_resumes(resumes, num_resumes, keywords, num_keywords, 3);

    // printing the results
    printf("Top 3 matching resumes:\n");
    for (int i = 0; i < 3; i++) {
        printf("Resume %d:\n", i+1);
        printf("Content: %s\n", matched_resumes[i].content);
        printf("Matching Scores: ");
        for (int j = 0; j < MAX_MATCHES; j++) {
            if (matched_resumes[i].scores[j] != -1) {
                printf("%d ", matched_resumes[i].scores[j]);
            }
        }
        printf("\n\n");
    }

    return 0;
}