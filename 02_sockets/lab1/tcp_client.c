#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {

    // cria o socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    // apenas para verificar se foi criado corretamente
    if (client_socket < 0) {
        perror("socket");
        return 1;
    }

    // atribuir o endereço do servidor
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    // realizar a conexão
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("conect");
        close(client_socket);
        return 1;
    }

    // receber uma mensagem do servidor
    char buffer[256];
    memset(buffer, 0, sizeof(buffer));
    ssize_t bytes = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes < 0) {
        perror("recv");
        close(client_socket);
        return 1;
    } 

    // mostrar a mensagem
    printf("Recebido do servidor: %s\n\n", buffer);

    // encerra o socket
    close(client_socket);

    return 0;
}