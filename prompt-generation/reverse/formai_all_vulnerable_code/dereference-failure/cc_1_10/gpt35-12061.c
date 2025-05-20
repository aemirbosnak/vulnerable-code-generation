//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char* name;
    int experience;
    char* education;
} Applicant;

typedef struct {
    char* key;
    int value;
} Keyword;

int count_keywords(char* resume, Keyword* keywords, int keyword_count) {
    int total = 0;

    for(int i = 0; i < keyword_count; i++) {
        char* keyword = keywords[i].key;
        int count = keywords[i].value;

        char* start = resume;

        while(1) {
            start = strstr(start, keyword);

            if(start == NULL) {
                break;
            }

            total += count;
            start++;
        }
    }

    return total;
}

int main() {
    Applicant* applicants = malloc(sizeof(Applicant) * 3);

    Applicant john_doe = {"John Doe", 5, "Bachelor's Degree in Computer Science"};
    applicants[0] = john_doe;

    Applicant jane_doe = {"Jane Doe", 3, "Master's Degree in Business Administration"};
    applicants[1] = jane_doe;

    Applicant bob_smith = {"Bob Smith", 2, "Associate's Degree in Marketing"};
    applicants[2] = bob_smith;

    Keyword* keywords = malloc(sizeof(Keyword) * 3);

    Keyword c_keyword = {"C", 1};
    keywords[0] = c_keyword;

    Keyword experience_keyword = {"years of experience", 2};
    keywords[1] = experience_keyword;

    Keyword degree_keyword = {"Degree", 3};
    keywords[2] = degree_keyword;

    for(int i = 0; i < 3; i++) {
        printf("Applicant %d:\n", i + 1);
        printf("Name: %s\n", applicants[i].name);
        printf("Experience: %d\n", applicants[i].experience);
        printf("Education: %s\n", applicants[i].education);

        char* education = applicants[i].education;
        int keyword_score = count_keywords(education, keywords, 3);

        printf("Keyword Score: %d\n", keyword_score);
        printf("Total Score: %d\n\n", applicants[i].experience + keyword_score);
    }

    free(applicants);
    free(keywords);

    return 0;
}