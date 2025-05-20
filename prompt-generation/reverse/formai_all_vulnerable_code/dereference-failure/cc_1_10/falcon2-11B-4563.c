//Falcon2-11B DATASET v1.0 Category: Metadata Extractor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <getopt.h>

#define MAX_LINES 1000

void extract_metadata(char* input_file, char* output_file) {
    FILE* input = fopen(input_file, "r");
    FILE* output = fopen(output_file, "w");

    char line[MAX_LINES];
    size_t num_lines = 0;

    while (fgets(line, sizeof(line), input)!= NULL) {
        if (strlen(line) == 0)
            continue;

        if (strncmp(line, "#", 1) == 0) {
            fprintf(output, "#%s\n", line);
            continue;
        }

        if (strncmp(line, "!", 1) == 0) {
            fprintf(output, "!%s\n", line);
            continue;
        }

        fprintf(output, "%s\n", line);
        num_lines++;
    }

    fclose(input);
    fclose(output);

    printf("Number of lines extracted: %zu\n", num_lines);
}

int main(int argc, char* argv[]) {
    char input_file[MAX_LINES];
    char output_file[MAX_LINES];

    while (1) {
        static struct option long_options[] = {
            {"input", required_argument, NULL, 'i'},
            {"output", required_argument, NULL, 'o'},
            {"help", no_argument, NULL, 'h'},
            {NULL, 0, NULL, 0}
        };

        int option_index = 0;
        int c = getopt_long(argc, argv, "hi:o:", long_options, &option_index);

        if (c == -1)
            break;

        switch (c) {
            case 'i':
                strcpy(input_file, optarg);
                break;
            case 'o':
                strcpy(output_file, optarg);
                break;
            case 'h':
                printf("Usage: %s [options]\n"
                       "  -i, --input <file>   Input file\n"
                       "  -o, --output <file>  Output file\n",
                       argv[0]);
                return 0;
            default:
                printf("Invalid option: %c\n", c);
                return 1;
        }
    }

    if (optind >= argc) {
        printf("Error: No input file specified\n");
        return 1;
    }

    if (optind + 1 >= argc) {
        printf("Error: No output file specified\n");
        return 1;
    }

    extract_metadata(argv[optind], argv[optind + 1]);

    return 0;
}