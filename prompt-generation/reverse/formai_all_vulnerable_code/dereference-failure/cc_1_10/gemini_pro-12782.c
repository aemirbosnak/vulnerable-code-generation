//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFSIZE 1024
#define STRSIZE 256

typedef struct {
    char *name;
    char *value;
} QStat;

// Stdin Buffer
char *buf;

// Qstats array
QStat *stats;

// Global statistic indices
int nstats;
int dstats;

// Time helpers
static time_t gstart;
static double gtotal;

// (re)Allocate QStats
int allocstats(int n)
{
    QStat *tmp;
    int i;

    tmp = realloc(stats, n * sizeof(QStat));
    if (tmp == NULL)
        return -1;
    stats = tmp;

    for (i = dstats; i < n; i++) {
        stats[i].name = malloc(STRSIZE);
        stats[i].value = malloc(STRSIZE);
        if (stats[i].name == NULL || stats[i].value == NULL) {
            free(stats[i].name);
            free(stats[i].value);
            stats[i].name = NULL;
            stats[i].value = NULL;
            return -1;
        }
    }
    dstats = n;
    return 0;
}

// Read a line from stdin
char *readln()
{
    char *p = buf;
    char c;

    while (1) {
        c = getchar();
        if (c == EOF)
            return NULL;
        if (c == '\n')
            break;
        *p++ = c;
    }
    *p = '\0';
    return buf;
}

// Split a line into name/value pair
int split(char *line, char **name, char **value)
{
    char *p = line;

    while (*p && *p != '=' && *p != ' ')
        p++;
    if (*p == '\0')
        return -1;
    *p++ = '\0';
    *name = line;
    *value = p;
    while (*p && *p != '\n')
        p++;
    if (*p)
        *p = '\0';
    return 0;
}

// Add a QStat
int addqstat(char *name, char *value)
{
    int i;

    for (i = 0; i < nstats; i++) {
        if (strcmp(stats[i].name, name) == 0) {
            free(stats[i].value);
            stats[i].value = strdup(value);
            if (stats[i].value == NULL)
                return -1;
            return 0;
        }
    }
    if (allocstats(nstats + 1) == -1)
        return -1;
    stats[nstats].name = strdup(name);
    stats[nstats].value = strdup(value);
    if (stats[nstats].name == NULL || stats[nstats].value == NULL) {
        free(stats[nstats].name);
        free(stats[nstats].value);
        return -1;
    }
    nstats++;
    return 0;
}

// Parse QStats
int parsestats()
{
    char *line;
    char *name;
    char *value;

    while ((line = readln()) != NULL) {
        if (split(line, &name, &value) == -1)
            continue;
        if (addqstat(name, value) == -1) {
            free(line);
            return -1;
        }
    }

    return 0;
}

// Print QStats
void printstats()
{
    int i;

    for (i = 0; i < nstats; i++)
        printf("%s=%s\n", stats[i].name, stats[i].value);
}

// Main
int main()
{
    buf = malloc(BUFSIZE);
    if (buf == NULL)
        return -1;
    
    gstart = time(NULL);
    gtotal = 0.0;
    
    if (parsestats() == -1)
        return -1;

    printstats();

    return 0;
}