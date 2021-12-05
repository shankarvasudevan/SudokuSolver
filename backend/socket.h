#pragma once

#include <string>
#include <netinet/in.h> // For sockaddr_in

class Socket
{
public:
    Socket(int maxInboundConnections);
    ~Socket();

    void Bind(int port);
    void Listen();
    void Connect();
    int Read(char buffer[], int bufferSize);
    void Send(const std::string& msg);

private:
    int mMaxInboundConnections;
    int mSockFd;
    sockaddr_in mSockAddress;
    int mConnection;
};