#include <iostream>
#include <sudoku_solver.pb.h>
#include "socket.h"

const int MAX_INBOUND_CONNECTIONS = 10;
const int PORT = 9999;
const int BUFFER_SIZE = 100;

int main(int argc, char* argv[])
{
    Socket socket(MAX_INBOUND_CONNECTIONS);
    socket.Bind(PORT);
    socket.Listen();
    socket.Connect();

    char message[BUFFER_SIZE];
    socket.Read(message, BUFFER_SIZE);
    std::cout << "The message was " << message << std::endl;

    const std::string response = "Good talking to you\n";
    socket.Send(response);
}

