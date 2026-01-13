#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(int argc, char *argv[])
{
    const char *peerIp =      {argv[1] };
    int         peerPt   = {atoi(argv[2])};
    const char *data   = argv[3]; 

    struct sockaddr_in peerAddress;
    
    peerAddress.sin_family  = AF_INET;
    peerAddress.sin_port    = htons(peerPt);

    if (inet_pton(AF_INET, peerIp, &(peerAddress.sin_addr)) <= 0)
    {
        printf("error with ip\n");
        return EXIT_FAILURE;
    }
    
    int udpSocket = {socket(AF_INET, SOCK_DGRAM, 0)};
    if (udpSocket < 0)
    {
        printf("couldn't create socket.");
        return EXIT_FAILURE;
    }

    if (sendto(udpSocket,
               data, 
               strlen(data) + 1, 
               0, 
               (struct sockaddr *)&peerAddress, 
               sizeof(peerAddress)) < 0)
    {
        printf("failed to send message\n");
        
        return EXIT_FAILURE;
    }
    
    printf("'%s' succesfully sent to <%s:%d>\n", data, peerIp, peerPt);
    close(udpSocket);
    
    return EXIT_SUCCESS;
}