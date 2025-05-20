//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The world has crumbled, and the echoes of destruction still linger. But amidst the ruins, a lone survivor seeks solace in the relics of a forgotten era.

typedef struct csv_reader {
    FILE *fp;
    char *line;
    size_t line_len;
    char *fields[1024];
    size_t num_fields;
} csv_reader;

// Open the gates of a CSV wasteland, weary traveler.
csv_reader *csv_open(const char *filename) {
    csv_reader *r = malloc(sizeof(csv_reader));
    if (!r) {
        return NULL;
    }
    r->fp = fopen(filename, "r");
    if (!r->fp) {
        free(r);
        return NULL;
    }
    r->line = NULL;
    r->line_len = 0;
    r->num_fields = 0;
    return r;
}

// Step into the vast expanse of a CSV line, my friend.
char *csv_readline(csv_reader *r) {
    if (!r->fp) {
        return NULL;
    }
    if (r->line) {
        free(r->line);
    }
    r->line_len = 0;
    r->line = NULL;
    size_t len = 0;
    ssize_t nread;
    do {
        nread = getline(&r->line, &len, r->fp);
        if (nread == -1) {
            break;
        }
        r->line_len += nread;
    } while (r->line[r->line_len - 1] != '\n');
    // In the dark corners of the line, shadows lurk.
    if (r->line_len > 0 && r->line[r->line_len - 1] == '\n') {
        r->line_len--;
        r->line[r->line_len] = '\0';
    }
    return r->line;
}

// As you traverse this shattered realm, you must parse the enigmatic CSV fields.
int csv_parse_fields(csv_reader *r) {
    if (!r->line) {
        return -1;
    }
    r->num_fields = 0;
    char *p = r->line;
    while (*p != '\0') {
        if (*p == ',') {
            *p = '\0';
            r->fields[r->num_fields++] = p + 1;
            p++;
        } else {
            p++;
        }
    }
    // In the end, you stand before the gatekeepers of the fields.
    r->fields[r->num_fields++] = p;
    return r->num_fields;
}

// Close the portal to the CSV abyss, weary traveler.
void csv_close(csv_reader *r) {
    if (!r) {
        return;
    }
    if (r->fp) {
        fclose(r->fp);
    }
    if (r->line) {
        free(r->line);
    }
    free(r);
}

int main() {
    // The winds whisper tales of a forgotten time. Let us seek out the remnants of knowledge.
    csv_reader *r = csv_open("survivor_data.csv");
    if (!r) {
        fprintf(stderr, "The gates of the CSV abyss are closed.");
        return 1;
    }
    // With each line, we piece together the fragmented memories of a lost civilization.
    char *line;
    while ((line = csv_readline(r)) != NULL) {
        // The fields hold the echoes of their struggles, the blueprints of their shattered dreams.
        int num_fields = csv_parse_fields(r);
        if (num_fields > 0) {
            // We have stumbled upon a beacon of hope, a glimmer of meaning in the darkness.
            printf("Line: %s\n", line);
            for (int i = 0; i < num_fields; i++) {
                printf("\tField %d: %s\n", i + 1, r->fields[i]);
            }
        }
    }
    csv_close(r);
    return 0;
}