#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

int main(){
	char *addr1="1.2.3.4";
	char *addr2="1.2.3.256";
	

	unsigned long conv_addr=inet_addr(addr1);
	if(conv_addr==INADDR_NONE){
		puts("Error occured!");	
	}else{
		printf("Network oreded integer addr: %#lx\n",conv_addr);
	}
	conv_addr=inet_addr(addr2);
	if(conv_addr==INADDR_NONE){
		puts("Error occured!");
	}else{
		printf("Network orded integer addr: %#lx\n",conv_addr);
	}
	system("pause");
	return 0;



}