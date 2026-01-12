#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 100

char buffer[BUFFER_SIZE];

void readN(FILE *fptr)
{
    //fread reads n bytes.
    while (fread(buffer, sizeof(char), BUFFER_SIZE, fptr) != 0)
    {
        printf("%s\n", buffer);
    }
}

char *readLine(FILE *fptr)
{
    //fgets gets a string of n characters, or gets a string until it finds an end of line.
    while(fgets(buffer, BUFFER_SIZE, fptr))
    {
        printf("%s", buffer);
    }

}

int getFileSize(FILE *fptr)
{
    fseek(fptr, 0, SEEK_END);
    int s = {ftell(fptr)};
    rewind(fptr);
    
    return s;
}

int getLines(FILE *fptr)
{
    int lc = {0};

    char c;
    while (c != EOF)
    {
        c = fgetc(fptr);
        if (c == '\n') ++lc;
    }

    rewind(fptr);

    return lc;
}

int getLineCharCount(FILE *fptr)
{
    int cc = {0};
    
    char c;
    while (c != '\n')
    {
        ++cc;
    }

    return cc;
}

int *glcc(FILE *fptr)
{
    int l = {getLines(fptr)};

    int lineCharCount[l];

    for (int i = 0; i < l; ++i)
    {
        
    }
}

int main()
{
    FILE *fptr = {fopen("messages.txt", "r")};
    //readLine(fptr);

    int l = {getLines(fptr)};

    int *charsPerLine = {malloc(sizeof(int) * l)};

    char c;
    int n = {0};
    int i = {0};
    while ((c = fgetc(fptr)) != EOF)
    {
        if (c == '\n')
        {
            charsPerLine[i] = n;
            printf("line %d done with %d chars\n", i+1, n);
            ++i;
            n = 0;
        }
        else
        {
            ++n;
        }
    }

    for (int i = 0; i < 7; ++i)
    {
        printf("%d - ", charsPerLine[i]);
    }

    fclose(fptr);
    return 0;
}
