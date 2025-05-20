//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

// Configuration structure to define the behavior of the checksum calculator
typedef struct {
    char *inputFilePath;
    char *outputFilePath;
    int checksumType; // 1 for SUM, 2 for XOR
} Config;

// Function prototypes
void printHelp();
int calculateChecksum(unsigned char *data, size_t length, int checksumType);
void readFile(const char *filePath, unsigned char *buffer, size_t *length);
void saveChecksumToFile(const char *outputFilePath, int checksum);

int main(int argc, char *argv[]) {
    Config config = {NULL, NULL, 1}; // Default to SUM checksum
    unsigned char buffer[MAX_BUFFER_SIZE];
    size_t dataLength = 0;
    int checksum;

    // Parse command line arguments
    if (argc < 2) {
        printHelp();
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--input") == 0) {
            if (i + 1 < argc) {
                config.inputFilePath = argv[i + 1];
                i++;
            } else {
                fprintf(stderr, "Error: Missing input file path\n");
                return EXIT_FAILURE;
            }
        } else if (strcmp(argv[i], "--output") == 0) {
            if (i + 1 < argc) {
                config.outputFilePath = argv[i + 1];
                i++;
            } else {
                fprintf(stderr, "Error: Missing output file path\n");
                return EXIT_FAILURE;
            }
        } else if (strcmp(argv[i], "--type") == 0) {
            if (i + 1 < argc) {
                config.checksumType = atoi(argv[i + 1]);
                if (config.checksumType < 1 || config.checksumType > 2) {
                    fprintf(stderr, "Error: Invalid checksum type. Use 1 for SUM or 2 for XOR\n");
                    return EXIT_FAILURE;
                }
                i++;
            } else {
                fprintf(stderr, "Error: Missing checksum type value\n");
                return EXIT_FAILURE;
            }
        } else if (strcmp(argv[i], "--help") == 0) {
            printHelp();
            return EXIT_SUCCESS;
        } else {
            fprintf(stderr, "Error: Unknown argument '%s'\n", argv[i]);
            return EXIT_FAILURE;
        }
    }

    // Read the input file
    readFile(config.inputFilePath, buffer, &dataLength);
    
    // Calculate checksum
    checksum = calculateChecksum(buffer, dataLength, config.checksumType);
    
    // Save checksum to output file, or print to console if no output file specified
    if (config.outputFilePath) {
        saveChecksumToFile(config.outputFilePath, checksum);
        printf("Checksum saved to %s\n", config.outputFilePath);
    } else {
        printf("Checksum: %d\n", checksum);
    }

    return EXIT_SUCCESS;
}

void printHelp() {
    printf("Checksum Calculator\n");
    printf("Usage:\n");
    printf("  checksum --input <file_path> [--output <file_path>] [--type <1|2>] [--help]\n");
    printf("Options:\n");
    printf("  --input   Specify the input file path (required)\n");
    printf("  --output  Specify the output file path (optional)\n");
    printf("  --type    Specify checksum type (1 for SUM, 2 for XOR, default is 1)\n");
    printf("  --help    Show this help message\n");
}

int calculateChecksum(unsigned char *data, size_t length, int checksumType) {
    int checksum = (checksumType == 1) ? 0 : 255; // SUM defaults to 0, XOR to 255

    for (size_t i = 0; i < length; i++) {
        if (checksumType == 1) {
            checksum += data[i]; // SUM
        } else {
            checksum ^= data[i]; // XOR
        }
    }
    
    return checksum;
}

void readFile(const char *filePath, unsigned char *buffer, size_t *length) {
    FILE *file = fopen(filePath, "rb");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filePath);
        exit(EXIT_FAILURE);
    }

    *length = fread(buffer, sizeof(unsigned char), MAX_BUFFER_SIZE, file);
    fclose(file);
}

void saveChecksumToFile(const char *outputFilePath, int checksum) {
    FILE *file = fopen(outputFilePath, "w");
    if (!file) {
        fprintf(stderr, "Error: Could not open output file %s for writing\n", outputFilePath);
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Checksum: %d\n", checksum);
    fclose(file);
}