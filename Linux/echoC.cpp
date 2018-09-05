#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 100
int main() {
        //向服务器（特定的IP和端口）发送请求
        struct sockaddr_in serv_addr;
        memset(&serv_addr, 0, sizeof(serv_addr)); // 每个字节都用0填充
        serv_addr.sin_family = AF_INET; //使用IPv4
        serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");//具体的IP的地址
        serv_addr.sin_port = htons(1234);//端口

        char bufSend[BUF_SIZE]= {0};
        char bufRecv[BUF_SIZE]= {0};

        int sock = socket(AF_INET, SOCK_STREAM, 0);//创建套接字
        connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
        //获取用户输入的字符串并发送给服务器
        printf("Input a string: ");
        scanf("%s",bufSend);
        size_t nbytes=strlen(bufSend);
        //向服务器传输数据
        write(sock,bufSend,nbytes);//write 函数的写法
        //读取服务器回传的数据
        read(sock,bufRecv,nbytes);//read 函数写法
        //输出接收到的数据
        printf("Message from server: %s\n",bufRecv);


        //关闭套接字 
        close(sock);
        return 0;
}
