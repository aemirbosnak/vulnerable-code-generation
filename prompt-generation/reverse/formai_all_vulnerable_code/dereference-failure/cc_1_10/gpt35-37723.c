//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000
#define MAXWORDS 100

char* resumeText = 
"Mary Jane\n\
A software developer with 5 years of experience in developing web applications using Java and Ruby on Rails. Holds a Bachelor's degree in Computer Science. Proficient in agile methodologies and possesses excellent communication skills.\n\
Skills: Java, Ruby on Rails, HTML, CSS, JavaScript, Agile\n\
Experience: \n\
- Developer at XYZ Corp, Jan 2018-present\n\
  - Developed and maintained web applications using Java\n\
  - Participated in scrum meetings and followed agile practices\n\
- Developer at ABC Inc, May 2016-Dec 2017\n\
  - Developed RESTful APIs using Ruby on Rails\n\
  - Collaborated with cross-functional teams to deliver high-quality software\n\
Education: \n\
Bachelor of Science in Computer Science, XYZ University, May 2016\n";

char*
getWord(char* line, int wordIndex)
{
    int i, start, end;
    char* word = (char*) malloc(MAXLINE * sizeof(char));
    start = end = -1;
    for(i = 0; i<strlen(line); i++) {
        if(line[i] == ' ') {
            if(start != -1 && end == -1) {
                end = i;
                strncpy(word, &line[start], end-start);
                word[end-start] = '\0';
                if(wordIndex == 0) {
                    return word;
                }
                wordIndex--;
                start = -1;
            }
        } else {
            if(start == -1) {
                start = i;
            }
        }
    }
    if(start != -1 && end == -1) {
        strncpy(word, &line[start], i-start);
        word[i-start] = '\0';
        if(wordIndex == 0) {
            return word;
        }
    }
    return NULL;
}

void
parseResume(char* resumeText)
{
    char* ptr;
    char* line;
    char* word;
    char* words[MAXWORDS];
    int numWords, i, j, match;

    ptr = resumeText;
    while(*ptr != '\0') {
        numWords = 0;
        line = (char*) malloc(MAXLINE * sizeof(char));
        while(*ptr != '\n' && *ptr != '\0') {
            line[numWords] = *ptr;
            numWords++;
            ptr++;
        }
        line[numWords] = '\0';
        if(numWords > 0) {
            printf("%s:\n", line);
            for(i = 0; i<numWords; i++) {
                word = getWord(line, i);
                if(word != NULL) {
                    match = 0;
                    for(j = 0; j<i; j++) {
                        if(strcmp(words[j], word) == 0) {
                            match = 1;
                        }
                    }
                    if(match == 0) {
                        words[i] = word;
                        printf("%s\n", word);
                    }
                }
            }
        }
        ptr++;
        free(line);
    }
}

int
main(void)
{
    parseResume(resumeText);
    return 0;
}