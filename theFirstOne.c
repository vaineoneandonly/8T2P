#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 8

int main()
{
    FILE *fptr = {fopen("messages.txt", "r")};

    char buffer[BUFFER_SIZE];

    while (fread(buffer, sizeof(char), BUFFER_SIZE, fptr) != 0)
    {
        printf("%s\n", buffer);
    }

    return 0;
}