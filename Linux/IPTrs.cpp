#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>


int main() {
        //创建套接字
        int sock = socket(AF_INET, SOCK_STREAM, 0);


        //向服务器（特定的IP和端口）发送请求
        struct sockaddr_in serv_addr;
        memset(&serv_addr, 0, sizeof(serv_addr)); // 每个字节都用0填充
        serv_addr.sin_family = AF_INET; //使用IPv4
        serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");//具体的IP的地址
        serv_addr.sin_port = htons(1234);//端口
        connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));


        struct in_addr{
                in_addr_t s_addr;   //32位的ip地址

        };

        unsigned long ip = inet_addr("127.0.0.1");
        printf("%ld\n",ip);


        //关闭套接字 
        close(sock);

        return 0;
}
