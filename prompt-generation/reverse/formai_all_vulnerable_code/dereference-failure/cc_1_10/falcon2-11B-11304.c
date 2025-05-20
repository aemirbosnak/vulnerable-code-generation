//Falcon2-11B DATASET v1.0 Category: Metadata Extractor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <libgen.h>
#include <libgen.h>

typedef struct {
    char* name;
    char* version;
} Package;

void print_package(Package* pkg) {
    printf("%s %s\n", pkg->name, pkg->version);
}

int main(int argc, char** argv) {
    Package pkg;

    char* filename = strdup(argv[1]);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    char buffer[4096];
    while (fgets(buffer, sizeof(buffer), file)!= NULL) {
        char* line = strtok(buffer, "\n");
        char* version = strtok(NULL, "\n");

        if (line == NULL || version == NULL) {
            continue;
        }

        strncpy(pkg.name, line, strlen(line));
        strncpy(pkg.version, version, strlen(version));
        break;
    }

    fclose(file);

    print_package(&pkg);

    return 0;
}