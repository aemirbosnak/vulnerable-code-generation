//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_resume(char **resume, int index)
{
    if (index >= (*resume) - 1)
    {
        return;
    }

    switch ((*resume)[index])
    {
        case 'H':
            printf("Header found at index %d\n", index);
            break;
        case 'P':
            printf("Profile found at index %d\n", index);
            break;
        case 'E':
            printf("Education found at index %d\n", index);
            break;
        case 'W':
            printf("Work experience found at index %d\n", index);
            break;
        default:
            parse_resume(resume, index + 1);
    }

    parse_resume(resume, index + 1);
}

int main()
{
    char *resume = "John Doe\n"
                     "123 Main St.\n"
                     "New York, NY 10001\n"
                     "(123) 456-7890\n"
                     "john.doe@gmail.com\n"
                     "\n"
                     "Profile\n"
                     "Highly motivated and experienced professional with a strong background in software engineering.\n"
                     "\n"
                     "Education\n"
                     "Bachelor of Science in Computer Science, University of California, Berkeley\n"
                     "\n"
                     "Work Experience\n"
                     "Software Engineer, Google Inc., Mountain View, CA\n"
                     "2018-2022\n"
                     "Designed and developed software applications for a variety of clients.\n"
                     "\n"
                     "Junior Software Engineer, ACME Corp., New York, NY\n"
                     "2016-2018\n"
                     "Assisted in the design and development of software applications.\n";

    parse_resume(&resume, 0);

    return 0;
}