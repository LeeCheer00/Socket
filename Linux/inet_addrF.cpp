#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define BUF_SIZE 100


int main(){
        const char *addr1="1.2.3.4";
        const char *addr2="1.2.3.256";


        unsigned long conv_addr=inet_addr(addr1);
        if(conv_addr==INADDR_NONE){
                puts("Error occured!");
        }else{
                printf("Network orded integer addr: %#lx\n",conv_addr);
        }

        conv_addr=inet_addr(addr2);
        if(conv_addr==INADDR_NONE){
                puts("Error occured!");
        }else{
                printf("Network oreded integer addr:%#lx\n",conv_addr);
        }

        return 0;
}
