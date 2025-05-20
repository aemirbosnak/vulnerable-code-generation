//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *input_str = NULL;
    int length = 0;

    printf("Enter the text to summarize: ");
    fgets(input_str, 1024, stdin);
    input_str[strcspn(input_str, "\n")] = '\0';

    length = strlen(input_str);

    if (length == 0) {
        printf("No text entered.\n");
        return 0;
    }

    int summary_length = 100;

    char *summary_str = (char *)malloc(summary_length + 1);
    if (summary_str == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    char *token = NULL;
    int token_length = 0;
    int i = 0;

    token = strtok(input_str, " ");

    while (token!= NULL && i < summary_length) {
        summary_str[i] = token[0];
        i++;
        token_length = strlen(token);

        if (token_length > 1) {
            token = strtok(NULL, " ");
        } else {
            token = NULL;
        }
    }

    summary_str[i] = '\0';

    printf("Summary:\n%s\n", summary_str);

    free(summary_str);

    return 0;
}