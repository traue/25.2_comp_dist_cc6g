# Projeto Chat Socket

Neste projeto usaremos o socket com TCP junto com o select() para criar um pequeno sistema de envio de mensagens de clientes para o servidor


## Objetivos

 - Servidor deve aceitar multipas conexões usando o select()
 - Cliente deve ler automaticamente o input do usuário (stdin) e o socket deverá enviar corretamente a mensagem ao servidor
 - Servidor deverá identificar clientes desconectados


## Estrutura

 - `chat_server.c`: servidor multi clientes
 - `chat_client.c`: cliente interativo
 - `Makefile`: compilação execução do server e do client e 


## Como compilar

Para o servidor:

```bash
make run-server
```

Para o client:

```bash
make run-client
```
