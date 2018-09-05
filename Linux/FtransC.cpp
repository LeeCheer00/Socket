#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>


#define BUF_SIZE 100

int main(){
        //先输入文件名
        char filename[100]={0};//文件名
        printf("Input filename to save:");
        scanf("%s",filename);
        FILE *fp=fopen(filename,"wb");//以二进值方式打开（创建）文件
        if(fp==NULL){
                printf("Cannot open file, press any key to exit!\n");
                system("pause");
                exit(0);
        }

        //绑定服务器
        struct sockaddr_in serv_addr;
        memset(&serv_addr, 0, sizeof(serv_addr));//0来填充
        serv_addr.sin_family = AF_INET;//使用IPv4
        serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");//具体的IP地址
        serv_addr.sin_port=htons(1234);//端口


        char buffer[BUF_SIZE]={0};




        int sock=socket(AF_INET,SOCK_STREAM,0);//创建套接字
        connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
        //开始向外传输（写）文件
        int nCount;
        while((nCount=read(sock,buffer,BUF_SIZE))>0){
                fwrite(buffer,nCount,1,fp);
        }
        puts("File transfer success!");
        close(sock);
        return 0;
        


}
