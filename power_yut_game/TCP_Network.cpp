#include "TCP_Network.h"

void TCP_Network::serverMode(){
	mode = true;
	int clientLen;

	// ���� ���
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	printf("���� ���� ");


	//���� ����
	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	printf("socket() ���� ");

	//���ε�
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(5555);

	bind(hServSock, (SOCKADDR*)&servAddr, sizeof(servAddr));
	printf("bind ���� ");

	// listen : �����ڸ� ���
	listen(hServSock, 5);
	printf("listen ���� ");

	// accept �����ڸ� �ޱ�
	clientLen = sizeof(clientAddr);
	hClientSock = accept(hServSock, (SOCKADDR*)&clientAddr, &clientLen);

	printf("Ŭ���̾�Ʈ ���� ����");

}

void TCP_Network::clientMode(){
	mode = false;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	hSocket = socket(PF_INET, SOCK_STREAM, 0);

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servAddr.sin_port = htons(5555);

	connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr));

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

	SOCKET *tmpSocket;
	if (mode) {
		tmpSocket = &hClientSock;
	}
	else {
		tmpSocket = &hSocket;
	}
	send(*tmpSocket, send_message, strlen(send_message), 0); // ù��° ��� ����
}

string TCP_Network::recv_message(){
	char message[BUFSIZE] = "";
	int strLen = 0;
	SOCKET *tmpSocket;
	if (mode) {
		tmpSocket = &hClientSock;
	}
	else {
		tmpSocket = &hSocket;
	}

	while ((strLen = recv(*tmpSocket, message, BUFSIZE, 0)) != 0) {
		string res = "";
		for (int i = 0; i < strlen(message) ;i++) {
			res += message[i];
		}

		cout << res << endl;
		Sleep(2000);

		return res;
	}
}


