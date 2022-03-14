#include "TCP_Network.h"

void TCP_Network::linkSoketPoint(){
	if (server_mode) tmpSocket = &hClientSock;
	else tmpSocket = &hSocket;
}

void TCP_Network::setIP(string input){
	memset(IP,0,sizeof(IP));
	for (int i = 0; i < input.size() ;i++) {
		IP[i] = input[i];
	}
}

void TCP_Network::serverModeOn(){
	server_mode = true;

	// 윈속 사용
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	//소켓 생성
	hServSock = socket(PF_INET, SOCK_STREAM, 0);

	//바인딩
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(5555);
	bind(hServSock, (SOCKADDR*)&servAddr, sizeof(servAddr));

	// listen : 접속자를 대기
	listen(hServSock, 5);

	// accept 접속자를 받기
	int clientLen = sizeof(clientAddr);
	hClientSock = accept(hServSock, (SOCKADDR*)&clientAddr, &clientLen);
}

void TCP_Network::clientModeOn(){
	server_mode = false;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	hSocket = socket(PF_INET, SOCK_STREAM, 0);

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(IP);
	servAddr.sin_port = htons(5555);

	connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr));
}

void TCP_Network::disConnect(){

	closesocket(*tmpSocket);
	WSACleanup();
}

void TCP_Network::send_message(int next_team, int yut_num , int mal_idx){
	char send_message[BUFSIZE] = "";

	if(next_team == 0) strcat(send_message, "0");
	else strcat(send_message, "1");

	if (yut_num == 0) strcat(send_message, "0");
	else if (yut_num == 1) strcat(send_message, "1");
	else if (yut_num == 2) strcat(send_message, "2");
	else if (yut_num == 3) strcat(send_message, "3");
	else strcat(send_message, "4");

	if (mal_idx == 0) strcat(send_message, "0");
	else if (mal_idx == 1) strcat(send_message, "1");
	else strcat(send_message, "2");

	linkSoketPoint();
	send(*tmpSocket, send_message, strlen(send_message), 0); // 결과 메세지 전송
}

void TCP_Network::recv_message(){
	int strLen = 0;
	char message[BUFSIZE] = "";

	linkSoketPoint();
	while (true) {
		if ((strLen = recv(*tmpSocket, message, BUFSIZE, 0)) != 0) {
			recvMessage = "";
			for (int i = 0; i < strlen(message); i++) {
				recvMessage += message[i];
			}
		}
	}
}

int TCP_Network::getNextTeamMessage() {
	return recvMessage[0]-'0';
}
int TCP_Network::getYutNumMessage(){
	return recvMessage[1]-'0';
}
int TCP_Network::getMalIdxMessage(){
	return recvMessage[2]-'0';
}


