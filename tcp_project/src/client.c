#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {

    int sock;

    struct sockaddr_in server_addr;

    char buffer[BUFFER_SIZE] = {0};

    char *message = "Hello from client";

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET,
        "127.0.0.1",
        &server_addr.sin_addr) <= 0) {

        perror("Invalid address");
        close(sock);
        exit(EXIT_FAILURE);
    }

    if(connect(sock,
        (struct sockaddr *)&server_addr,
        sizeof(server_addr)) < 0) {

        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    send(sock, message, strlen(message), 0);

    recv(sock, buffer, BUFFER_SIZE, 0);

    printf("Server says: %s\n", buffer);

    close(sock);

    return 0;
}
