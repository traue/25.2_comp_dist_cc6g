#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {

    char server_message[256] = "Você chegou ao servidor! Congrats!";

    // criação do socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // atribui um endereço ao servidor
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    listen(server_socket, 5);

    int client_socket = accept(server_socket, NULL, NULL);

    // envia a mensagem ao cliente:
    send(client_socket, server_message, sizeof(server_message), 0);

    // fecha o socket
    close(server_socket);

    return 0;
}