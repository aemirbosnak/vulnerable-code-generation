//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Shape-shifting metadata extractor example program */

typedef enum {
  JPEG,
  PNG,
  PDF,
  UNKNOWN
} FileType;

typedef struct {
  char* fileName;
  FileType fileType;
  int fileSize;
  char* authorName;
  char* creationDate;
} Metadata;

/* Function to extract metadata from a JPEG file */
Metadata extractJpgMetadata(char* fileName) {
  Metadata jpgMetadata = {0};
  jpgMetadata.fileName = fileName;
  jpgMetadata.fileType = JPEG;
  jpgMetadata.fileSize = 2048;
  jpgMetadata.authorName = "John Doe";
  jpgMetadata.creationDate = "08/18/2021";
  return jpgMetadata;
}

/* Function to extract metadata from a PNG file */
Metadata extractPngMetadata(char* fileName) {
  Metadata pngMetadata = {0};
  pngMetadata.fileName = fileName;
  pngMetadata.fileType = PNG;
  pngMetadata.fileSize = 4096;
  pngMetadata.authorName = "Jane Doe";
  pngMetadata.creationDate = "08/18/2021";
  return pngMetadata;
}

/* Function to extract metadata from a PDF file */
Metadata extractPdfMetadata(char* fileName) {
  Metadata pdfMetadata = {0};
  pdfMetadata.fileName = fileName;
  pdfMetadata.fileType = PDF;
  pdfMetadata.fileSize = 8192;
  pdfMetadata.authorName = "Bob Smith";
  pdfMetadata.creationDate = "08/18/2021";
  return pdfMetadata;
}

/* Function to determine the file type */
FileType determineFileType(char* fileName) {
  char* fileExtension = strrchr(fileName, '.');
  if (fileExtension != NULL) {
    if (strcmp(fileExtension, ".jpg") == 0 ||
        strcmp(fileExtension, ".jpeg") == 0 ||
        strcmp(fileExtension, ".JPG") == 0 ||
        strcmp(fileExtension, ".JPEG") == 0) {
      return JPEG;
    } else if (strcmp(fileExtension, ".png") == 0 ||
               strcmp(fileExtension, ".PNG") == 0) {
      return PNG;
    } else if (strcmp(fileExtension, ".pdf") == 0 ||
               strcmp(fileExtension, ".PDF") == 0) {
      return PDF;
    }
  }
  return UNKNOWN;
}

/* Main function */
int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Usage: %s <file_name>\n", argv[0]);
    return 1;
  }

  char* fileName = argv[1];
  FileType fileType = determineFileType(fileName);

  Metadata metadata = {0};
  switch (fileType) {
    case JPEG:
      metadata = extractJpgMetadata(fileName);
      break;
    case PNG:
      metadata = extractPngMetadata(fileName);
      break;
    case PDF:
      metadata = extractPdfMetadata(fileName);
      break;
    default:
      printf("Unsupported file type\n");
      return 1;
  }

  printf("File name: %s\n", metadata.fileName);
  printf("File type: %d\n", metadata.fileType);
  printf("File size: %d\n", metadata.fileSize);
  printf("Author name: %s\n", metadata.authorName);
  printf("Creation date: %s\n", metadata.creationDate);

  return 0;
}