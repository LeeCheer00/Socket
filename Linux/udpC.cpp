#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define BUF_SIZE 100
int main(){
        //创建套接字
        int sock = socket(PF_INET, SOCK_DGRAM, 0);

        //将套接字和IP、端口绑定
        struct sockaddr_in serv_addr;
        memset(&serv_addr, 0, sizeof(serv_addr));// 每个字节都用0 填充
        serv_addr.sin_family = PF_INET; // 使用IPv4地址
        serv_addr.sin_addr.s_addr =inet_addr("127.0.0.1");// 具体的IP地址 // TODO 特别注意，ip地址写成127.0.1 导致第二次使用程序出现错误
        serv_addr.sin_port =htons(1234);//自动获取IP地址
        

        
        //接收客户端的请求
        sockaddr  fromAddr;
        socklen_t nSize =sizeof(fromAddr);
        //修改迭代方式
        while(1){
                char buffer[BUF_SIZE]={0};//缓冲区
                printf("Input a string:");
                scanf("%[^\n]",buffer); 
                sendto(sock,buffer,strlen(buffer),0,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
                int strLen = recvfrom(sock,buffer,BUF_SIZE,0,&fromAddr,&nSize);
                buffer[strLen]=0;
                printf("Message from server:%s\n",buffer);
        }
        //关闭套接字 
        close(sock);


        return 0;


}
