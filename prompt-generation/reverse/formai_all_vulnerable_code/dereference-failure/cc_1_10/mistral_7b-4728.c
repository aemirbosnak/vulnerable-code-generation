//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define NUM_FIELDS 5
typedef struct {
    char ip[20];
    char method[10];
    char url[256];
    int status_code;
    int content_length;
} log_entry_t;

int main(int argc, char **argv) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token[NUM_FIELDS];
    log_entry_t *log_data;
    int i, method_count[128] = {0};

    if ((fp = fopen("access.log", "r")) == NULL) {
        perror("Error opening file");
        exit(1);
    }

    log_data = calloc(1, sizeof(log_entry_t));

    while (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%[^ ]%s%s%s%d%d", log_data->ip, log_data->method, log_data->url,
               &log_data->status_code, &log_data->content_length);

        for (i = 0; i < strlen(log_data->method); i++) {
            method_count[(int)toupper((unsigned char)log_data->method[i])]++;
        }
    }

    fclose(fp);
    free(log_data);

    printf("Access Log Analysis Report\n");
    printf("--------------------------\n");
    printf("Method\tCount\n");
    printf("--------------------------\n");

    for (i = 0; i < 128; i++) {
        if (isalpha(i)) {
            printf("%c\t%d\n", i, method_count[i]);
        }
    }

    return 0;
}