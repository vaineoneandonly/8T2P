#include <stdio.h>
#include <stdlib.h>

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

void readLine(FILE *fptr)
{
    //fgets gets a string of n characters, or gets a string until it finds an end of line.
    while(fgets(buffer, BUFFER_SIZE, fptr))
    {
        printf("%s", buffer);
    }

}

int main()
{
    FILE *fptr = {fopen("messages.txt", "r")};
    //readN(fptr);
    readLine(fptr);

    return 0;
}