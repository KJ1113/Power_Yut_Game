#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define BUFSIZE 1024
#define _CRT_SECURE_NO_WARNINGS



#include <stdio.h>
#include <winsock2.h>
#include <string>
#include <iostream>
using namespace std;

class TCP_Network {

private:
	bool server_mode;
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKET hServSock;
	SOCKET hClientSock;
	SOCKET* tmpSocket; // client or server 에 따라 가르키는 SOKET이 다름

	SOCKADDR_IN servAddr;
	SOCKADDR clientAddr;
	void linkSoketPoint();

public:
	void serverModeOn();
	void clientModeOn();
	void disConnect();
	void send_message(int next_team, int yut_num, int mal_idx);
	string recv_message();
};