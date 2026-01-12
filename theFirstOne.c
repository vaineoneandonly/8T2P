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

int *getLineCharCount(FILE *fptr)
{
    int l = {getLines(fptr)};

    for (int i = 0; i < l; ++i)
    {
        
    }
}

int main()
{
    FILE *fptr = {fopen("messages.txt", "r")};
    //readN(fptr);
    //readLine(fptr);

    printf("%d\n%d\n", getFileSize(fptr), getLines(fptr));
    return 0;
}