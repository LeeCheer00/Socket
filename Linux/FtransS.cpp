#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define BUF_SIZE 100


int main(){
        //检查文件是否存在
        const char *filename = "/home/leecheer/Capela.pdf"; //文件名
        FILE *fp=fopen(filename,"rb");//以二进值方式打开文件
        if(fp==NULL){
                printf("Cannot open file,press any key to exit!\n");
                system("pause");
                exit(0);
        }
        //创建套接字
        int serv_sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
        //将套接字和IP、端口绑定
        struct sockaddr_in serv_addr;
        memset(&serv_addr,0,sizeof(serv_addr));//每个字节都用0填充
        serv_addr.sin_family=AF_INET;//使用IPv4
        serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");//具体的IP地址
        serv_addr.sin_port=htons(1234);//端口
        bind(serv_sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr));//让套接字与特定的IP地址和端口对应起来，这样客户端才能连接到该套接字


        //进入监听状态，等待用户发起请求
        listen(serv_sock, 20);

        //接收客户端的请求
        struct sockaddr_in clnt_addr;
        socklen_t clnt_addr_size =sizeof(clnt_addr);
        char buffer[BUF_SIZE]={0};//缓冲区


        int clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_addr,&clnt_addr_size);//建立连接定义sock
        int nCount;
        while((nCount=fread(buffer,1,BUF_SIZE,fp))>0){
            write(clnt_sock,buffer,nCount);
        }
        shutdown(clnt_sock,SHUT_WR);//文件读取完毕，断开输出流，向客户端发送FIN包
        //接收客户端发来的数据
        read(clnt_sock,buffer,BUF_SIZE);


        close(clnt_sock);
        close(serv_sock);
        return 0;

        
}
