// Server side C program to demonstrate Socket
// programming
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080


int main(int argc, char const* argv[])
{
    int server_fd;
    struct sockaddr_in address;


    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM , 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    //Set the socket to accept on port 8080
    int opt = 1;
    if ( setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) != 0){
        perror("socket to 8080 failed");
        exit(EXIT_FAILURE);
    }

    //Bind the socket together
    if (bind(server_fd, (struct sockaddr*)&address ,sizeof(address) ) != 0){
        perror("sbind failed");
        exit(EXIT_FAILURE);
    }

    //Next, listen on the socket

}