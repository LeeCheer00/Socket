#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib") //���� ws2_32.dll


#define BUF_SIZE 100

int main() {
	//��ʼ��DLL
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2,2), &wsaData);

	//�����׽���
	SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	//	���������������
	sockaddr_in sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));//ÿ���ֽڶ���0���
	sockAddr.sin_family = PF_INET;
	sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	sockAddr.sin_port = htons(1234);
	connect(sock,(SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
	//��ȡ�û�������ַ��������͸�������
	char bufSend[BUF_SIZE] = {0};
	printf("Input a string: ");
	gets(bufSend);
	send(sock,bufSend, strlen(bufSend),0);
	//���շ��������ص�����
	char bufRecv[BUF_SIZE] = {0};
	recv(sock, bufRecv, BUF_SIZE, 0);
	//������յ�������
	printf("Message from server: %s\n", bufRecv);
	//�ر��׽���
	closesocket(sock);
	//��ֹʹ��DLL
	WSACleanup();

	system("pause");
	return 0;

}