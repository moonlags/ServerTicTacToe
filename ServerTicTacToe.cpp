#include <iostream>
#include <vector>
#include "Game.h"
#include <WS2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{
	cout << "Starting server..." << endl;
	vector<Game> games;

	WSADATA wsDATA;
	WORD ver = MAKEWORD(2, 2);

	int wsOk = WSAStartup(ver, &wsDATA);
	if(wsOk!=0)
	{
		cerr << "winsock!" << endl;
		return;
	}

	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if(listening==INVALID_SOCKET)
	{
		cerr << "socket!" << endl;
		return;
	}

	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(8888);// host to network short
	hint.sin_addr.S_un.S_addr = INADDR_ANY;

	bind(listening, (sockaddr*)&hint, sizeof(hint));

	listen(listening, SOMAXCONN);
	sockaddr_in client;
	int clientSize = sizeof(client);
	SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);
	
	char host[NI_MAXHOST];
	char service[NI_MAXSERV];

	ZeroMemory(host, NI_MAXHOST);
	ZeroMemory(service, NI_MAXSERV);

	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
		cout << host << " connected on port " << service << endl;
	}
	else {
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		cout << host << " connected on port " << ntohs(client.sin_port) << endl;
	}

	closesocket(listening);
	char buf[4096];
	while (true) {
		ZeroMemory(buf, 4096);
		int bytesReceived = recv(clientSocket, buf, 4096, 0);
		if (bytesReceived == SOCKET_ERROR) {
			cout << "Receive error!" << endl;
			break;
		}
		if (bytesReceived == 0) {
			cout << "client disconnected" << endl;
			break;
		}

		send(clientSocket, buf, bytesReceived + 1, 0);
	}

	closesocket(clientSocket);
	WSACleanup();
}