//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 10000

typedef struct {
    char *name;
    char *value;
} header;

header http_request(char *request) {
    char *line;
    char *pos;
    header h = {NULL, NULL};
    int count = 0;

    while (count < MAX_SIZE && (line = strtok_r(request, "\r\n", &pos))) {
        if (count == 0) {
            h.name = line;
        } else {
            h.value = line;
            break;
        }
        count++;
    }

    return h;
}

void http_response(header *response, FILE *fp) {
    fprintf(fp, "HTTP/1.1 200 OK\r\n");
    fprintf(fp, "Content-Type: text/html\r\n");
    fprintf(fp, "Content-Length: %d\r\n", strlen(response->value));
    fprintf(fp, "\r\n");
    fprintf(fp, "%s", response->value);
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char request[MAX_SIZE];
    header response;

    fp = fopen("index.html", "r");
    if (!fp) {
        exit(1);
    }

    fread(request, sizeof(char), MAX_SIZE, fp);
    fclose(fp);

    response = http_request(request);

    fp = fopen("index.html", "r");
    http_response(&response, fp);

    fclose(fp);

    return 0;
}