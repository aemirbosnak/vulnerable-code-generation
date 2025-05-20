//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//structure to hold each parsed resume section
typedef struct {
    char* header; //header of section
    char* content; //content of section
    int weight; //weight assigned to this section
} ResumeSection;

//function to parse the resume and extract relevant sections
ResumeSection* parseResume(char* resumeText, int* numSections) {
    ResumeSection* sections = (ResumeSection*) malloc(sizeof(ResumeSection) * 10);
    int maxSections = 10;
    char* curLine = strtok(resumeText, "\n"); //break resume into lines
    int curSection = -1; //current section index
    while (curLine != NULL) {
        //check for section headers, and assign weight based on importance
        if (strstr(curLine, "Experience") != NULL) {
            curSection++;
            if (curSection >= maxSections) { //resize array if needed
                maxSections *= 2;
                sections = (ResumeSection*) realloc(sections, sizeof(ResumeSection) * maxSections);
            }
            sections[curSection].header = strdup("Experience");
            sections[curSection].weight = 5;
        } else if (strstr(curLine, "Education") != NULL) {
            curSection++;
            if (curSection >= maxSections) { //resize array if needed
                maxSections *= 2;
                sections = (ResumeSection*) realloc(sections, sizeof(ResumeSection) * maxSections);
            }
            sections[curSection].header = strdup("Education");
            sections[curSection].weight = 4;
        } else if (strstr(curLine, "Skills") != NULL) {
            curSection++;
            if (curSection >= maxSections) { //resize array if needed
                maxSections *= 2;
                sections = (ResumeSection*) realloc(sections, sizeof(ResumeSection) * maxSections);
            }
            sections[curSection].header = strdup("Skills");
            sections[curSection].weight = 3;
        } else if (strstr(curLine, "Objective") != NULL) {
            curSection++;
            if (curSection >= maxSections) { //resize array if needed
                maxSections *= 2;
                sections = (ResumeSection*) realloc(sections, sizeof(ResumeSection) * maxSections);
            }
            sections[curSection].header = strdup("Objective");
            sections[curSection].weight = 2;
        } else if (strstr(curLine, "Summary") != NULL) {
            curSection++;
            if (curSection >= maxSections) { //resize array if needed
                maxSections *= 2;
                sections = (ResumeSection*) realloc(sections, sizeof(ResumeSection) * maxSections);
            }
            sections[curSection].header = strdup("Summary");
            sections[curSection].weight = 1;
        //if not a header, then just append line to current section's content
        } else {
            if (curSection >= 0) {
                //allocate memory for content if not already present
                if (sections[curSection].content == NULL) {
                    sections[curSection].content = strdup("");
                }
                //append line to content with a newline character
                sections[curSection].content = (char*) realloc(sections[curSection].content, strlen(sections[curSection].content) + strlen(curLine) + 2);
                strcat(sections[curSection].content, curLine);
                strcat(sections[curSection].content, "\n");
            }
        }
        //get next line from resume
        curLine = strtok(NULL, "\n");
    }
    *numSections = curSection + 1;
    return sections;
}

//function to calculate relevance score for each section based on keywords
void calculateScores(char** keywords, int numKeywords, ResumeSection* sections, int numSections) {
    for (int i = 0; i < numSections; i++) {
        int score = 0;
        char* contentCopy = strdup(sections[i].content); //make copy of content for modification
        //lowercase entire content for case-insensitive matching
        for (int j = 0; j < strlen(contentCopy); j++) {
            contentCopy[j] = tolower(contentCopy[j]);
        }
        //count occurrences of each keyword in content
        for (int j = 0; j < numKeywords; j++) {
            char* curKeyword = keywords[j];
            int curLen = strlen(curKeyword);
            char* curPos = contentCopy;
            while ((curPos = strstr(curPos, curKeyword)) != NULL) {
                if ((curPos == contentCopy || !isalpha(curPos[-1])) && !isalpha(curPos[curLen])) { //only count exact matches
                    score++;
                }
                curPos += curLen;
            }
        }
        sections[i].weight += score; //add keyword score to section weight
        free(contentCopy); //free copy of content
    }
}

int main() {
    char* resume = "John Doe\n123 Main St.\nAnytown, USA 12345\njohndoe@email.com\n\n\
Objective: Seeking a challenging position as a software engineer\n\n\
Summary: Experienced software engineer with skills in C++, Java, and Python\n\n\
Skills:\nC++, Java, Python, Ruby, SQL, Node.js, HTML/CSS\n\n\
Experience:\nSoftware Engineer, XYZ Corp. (2015-present)\n- Developed and maintained software applications in C++, Java, and Python\n- Worked with teams to implement new features and improve performance\n\n\
Education:\nBachelor of Science in Computer Science, XYZ University (2015)\n";

    char* keywords[] = {"C++", "Java", "Python", "Ruby", "SQL", "Node.js", "HTML/CSS"};

    int numSections;
    ResumeSection* sections = parseResume(resume, &numSections);
    calculateScores(keywords, 7, sections, numSections);

    //sort sections by weight in decreasing order
    for (int i = 0; i < numSections; i++) {
        for (int j = i + 1; j < numSections; j++) {
            if (sections[i].weight < sections[j].weight) {
                //swap sections
                ResumeSection temp = sections[i];
                sections[i] = sections[j];
                sections[j] = temp;
            }
        }
    }

    //print out sections in order of relevance
    for (int i = 0; i < numSections; i++) {
        printf("%s:\n%s\n\n", sections[i].header, sections[i].content);
    }

    //free memory allocated for sections
    for (int i = 0; i < numSections; i++) {
        free(sections[i].header);
        free(sections[i].content);
    }
    free(sections);

    return 0;
}