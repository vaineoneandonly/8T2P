#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct mySocket
{
    struct sockaddr_un name;
    int number;
    size_t size;
} mySocket;

mySocket *createMySocket(char *newName)
{
    mySocket *newSocket = {malloc(sizeof(mySocket))};

    newSocket -> number = socket(PF_LOCAL, SOCK_DGRAM, 0); 
    
    newSocket -> name.sun_family = AF_LOCAL; 

    strncpy(newSocket -> name.sun_path, newName, sizeof(newSocket -> name.sun_path));
    newSocket -> name.sun_path[sizeof(newSocket -> name.sun_path) - 1] = '\0';

    newSocket -> size = (offsetof(struct sockaddr_un, sun_path) + strlen(newSocket -> name.sun_path));

    return newSocket;
}

void printSocketData(mySocket *s)
{
    printf("name: %s\naddress: %d\nsize: %d", s -> name.sun_path, s -> number, (int)(s -> size));
}


int main(void)
{
    mySocket *s1 = createMySocket("asdljadjlhsa");
    printSocketData(s1);
    printf("%d\n", 23);
}