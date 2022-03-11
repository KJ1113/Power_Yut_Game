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
	bool mode;
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKET hServSock;
	SOCKET hClientSock;
	SOCKADDR_IN servAddr;
	SOCKADDR clientAddr;

	
public:


	void serverMode();
	void clientMode();
	void send_message(int next_team, int yut_num, int mal_idx);
	string recv_message();

};