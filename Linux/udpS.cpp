#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define BUF_SIZE 100
int main(){
        int sock =socket(AF_INET,SOCK_DGRAM, 0);

        struct sockaddr_in serv_addr;
        memset(&serv_addr,0,sizeof(serv_addr));//每个字节都用0填充
        serv_addr.sin_family=PF_INET;//使用IPv4地址
        serv_addr.sin_addr.s_addr=inet_addr(INADDR_ANY);//具体的IP地址
        serv_addr.sin_port=htons(1234);//端口
        bind(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr));


        //接收客户端请求
        struct sockaddr clnt_addr;//客户端地址信息
        socklen_t clnt_addr_size = sizeof(clnt_addr);
        char buffer[BUF_SIZE];


        while(1){
                int strLen=recvfrom(sock,buffer,BUF_SIZE,0,&clnt_addr,&clnt_addr_size);
                sendto(sock,buffer,strLen,0,&clnt_addr,clnt_addr_size);
        }
        close(sock);
        return 0;
}
