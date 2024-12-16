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
    int server_fd, new_socket;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    ssize_t valread;
    char buffer[1024] = { 0 };
    char* hello = "Hello from server";


    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM , 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }


    //Set the socket to accept on port 8080
    int opt = 8080;
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
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    //Accept input from the socket
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address,&addrlen))< 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    valread = read(new_socket, buffer, 1024 - 1); // subtract 1 for the null
                              // terminator at the end

    printf("%s\n", buffer);
    //send(new_socket, hello, strlen(hello), 0);
    //printf("Hello message sent\n");

}