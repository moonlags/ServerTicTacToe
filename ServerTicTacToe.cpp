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
}