#include "socket.h"

#include <string>
#include <sys/socket.h> // For socket functions
#include <cstdlib> // For exit() and EXIT_FAILURE
#include <iostream> // For cout
#include <unistd.h> // For read

Socket::Socket(int maxInboundConnections) : mMaxInboundConnections(maxInboundConnections)
{
    mSockFd = socket(AF_INET, SOCK_STREAM, 0);
    if (mSockFd == -1)
    {
        throw std::runtime_error("Failed to create socket. [ErrNo: " + std::to_string(errno) + "]");
    }
}

Socket::~Socket()
{
    close(mConnection);
    close(mSockFd);
}

void Socket::Bind(int port)
{
    mSockAddress.sin_family = AF_INET;
    mSockAddress.sin_addr.s_addr = INADDR_ANY;
    mSockAddress.sin_port = htons(port); // Converts from host to network byte order

    if(bind(mSockFd, (struct sockaddr*)&mSockAddress, sizeof(mSockAddress)) < 0)
    {
        throw std::runtime_error("Failed to bind to port. [Port: " + std::to_string(port) + ", ErrNo" + std::to_string(errno) + "]");
    }
}

void Socket::Listen()
{
    if (listen(mSockFd, mMaxInboundConnections) < 0)
    {
        throw std::runtime_error("Failed to listen on socket. [ErrNo: " + std::to_string(errno) + "]");
    }
}

void Socket::Connect()
{
    int addrLen = sizeof(mSockAddress);
    mConnection = accept(mSockFd, (struct sockaddr*)&mSockAddress, (socklen_t*)&addrLen);
    if (mConnection < 0)
    {
        throw std::runtime_error("Failed to grab connection. [ErrNo: " + std::to_string(errno) + "]");
    }
}

int Socket::Read(char buffer[], int bufferSize)
{
    return read(mConnection, buffer, bufferSize);
}

void Socket::Send(const std::string& msg)
{
    send(mConnection, msg.c_str(), msg.size(), 0);
}