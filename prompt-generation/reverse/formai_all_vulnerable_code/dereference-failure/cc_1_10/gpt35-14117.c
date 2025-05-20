//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* XML node structure */
typedef struct xmlnode {
    char *name;                     /* name of the node */
    char *value;                    /* contents of the node */
    struct xmlnode *siblings;       /* linked list of sibling nodes */
    struct xmlnode *children;       /* linked list of child nodes */
} XMLNode;

/* distributed style XML parser function */
XMLNode* parseXML(char *filename)
{
    FILE *fp;
    char *buffer = NULL;
    long length;

    /* open the file in read mode */
    fp = fopen(filename, "r");
    if (fp == NULL)
        return NULL;

    /* get the length of the file */
    fseek(fp, 0, SEEK_END);
    length = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    /* allocate memory for the buffer */
    buffer = (char *)malloc(length + 1);
    if (buffer == NULL)
        return NULL;

    /* read the file into the buffer */
    if (fread(buffer, 1, length, fp) < length)
        return NULL;
    fclose(fp);

    /* create the root node */
    XMLNode *root = (XMLNode*)malloc(sizeof(XMLNode));
    root->name = NULL;
    root->value = NULL;
    root->siblings = NULL;
    root->children = NULL;

    /* parse the XML */
    char *tagStart, *tagEnd, *textStart, *textEnd;
    char *pos = buffer;
    XMLNode *currentParent = root;
    while ((tagStart = strchr(pos, '<')) != NULL)
    {
        /* check if there is any text between the previous tag and the current tag */
        if (tagStart > pos)
        {
            textStart = pos;
            textEnd = tagStart - 1;
            while (*textStart == ' ') textStart++;
            while (*(textEnd-1) == ' ') textEnd--;
            if (textEnd > textStart)
            {
                XMLNode *textNode = (XMLNode*)malloc(sizeof(XMLNode));
                textNode->name = NULL;
                textNode->value = (char*)malloc(textEnd - textStart + 1);
                strncpy(textNode->value, textStart, textEnd - textStart);
                textNode->value[textEnd - textStart] = '\0';
                textNode->siblings = NULL;
                textNode->children = NULL;

                currentParent->children = textNode;
                currentParent = textNode;
            }
        }

        /* check for end tag */
        if (*(tagStart+1) == '/')
        {
            tagEnd = strchr(tagStart, '>');
            if (tagEnd == NULL)
                return NULL;
            char *tagName = (char*)malloc(tagEnd - tagStart - 1);
            strncpy(tagName, tagStart + 2, tagEnd - tagStart - 2);
            tagName[tagEnd - tagStart - 2] = '\0';
            if (strcmp(currentParent->name, tagName) != 0)
                return NULL;
            currentParent = currentParent->siblings;
            free(tagName);
            pos = tagEnd + 1;
        }
        /* check for start tag */
        else
        {
            tagEnd = strchr(tagStart, '>');
            if (tagEnd == NULL)
                return NULL;
            XMLNode *newNode = (XMLNode*)malloc(sizeof(XMLNode));
            newNode->name = (char*)malloc(tagEnd - tagStart - 1);
            strncpy(newNode->name, tagStart + 1, tagEnd - tagStart - 1);
            newNode->name[tagEnd - tagStart - 1] = '\0';
            newNode->value = NULL;
            newNode->siblings = NULL;
            newNode->children = NULL;

            currentParent->siblings = newNode;
            currentParent = newNode;
            pos = tagEnd + 1;
        }
    }

    free(buffer);
    return root;
}

/* main function */
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    XMLNode *root = parseXML(argv[1]);
    if (root == NULL)
    {
        fprintf(stderr, "Error: failed to parse XML file.\n");
        return 1;
    }

    /* do something with the parsed XML */

    return 0;
}