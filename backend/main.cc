#include <iostream>
#include <sudoku_solver.pb.h>
#include <sys/socket.h> // For socket functions
#include <netinet/in.h> // For sockaddr_in
#include <cstdlib> // For exit() and EXIT_FAILURE
#include <iostream> // For cout
#include <unistd.h> // For read

const int MAX_INBOUND_CONNECTIONS = 10;
const int PORT = 9999;
const int BUFFER_SIZE = 100;

int main(int argc, char* argv[])
{
    // Create a socket
    int sockFd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockFd == -1)
    {
        std::cout << "Failed to create socket. ErrNo: " << errno << std::endl;
        exit(EXIT_FAILURE);
    }

    // Listen to port on current address
    sockaddr_in sockAddr;
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_addr.s_addr = INADDR_ANY;
    sockAddr.sin_port = htons(PORT); // htons converts a number from host-order to network-byte order

    if (bind(sockFd, (struct sockaddr*)&sockAddr, sizeof(sockAddr)) < 0)
    {
        std::cout << "Failed to bind to port 9999. ErrNo: " << errno << std::endl;
        exit(EXIT_FAILURE);
    }

    // Start listening. Limit the number of inbound connections
    if (listen(sockFd, MAX_INBOUND_CONNECTIONS) < 0)
    {
        std::cout << "Failed to listen on socket. ErrNo: " << errno << std::endl;
        exit(EXIT_FAILURE);
    }

    // Grab a connection from the queue
    int addrLen = sizeof(sockAddr);
    int connection = accept(sockFd, (struct sockaddr*)&sockAddr, (socklen_t*)&addrLen);
    if (connection < 0)
    {
        std::cout << "Failed to grab connection. ErrNo: " << errno << std::endl;
        exit(EXIT_FAILURE);
    }

    // Read from the connection
    char buffer[BUFFER_SIZE];
    int bytesRead = read(connection, buffer, BUFFER_SIZE);
    std::cout << "The message was: " << buffer << std::endl;

    // Send a message to the connection
    std::string response = "Good talking to you\n";
    send(connection, response.c_str(), response.size(), 0);

    // Close the connection
    close(connection);
    close(sockFd);
}

