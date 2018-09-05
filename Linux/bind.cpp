//创建套接字
int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);


//创建sockaddr_in 结构体变量
struct sockaddr_in serv_addr
memset(&serv_addr,0,sizeof(serv_addr));//每个字节都用0填充
serv_addr.sin_family = AF_INET;//使用IPv4地址
serv_addr.sin_addr.s_addr =inet_addr("127.0.0.1");//具体的IP地址
serv_addr.sin_port = htons(1234); //端口

//将套接字和IP、端口绑定
bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));


struct sockaddr_in {
        sa_family_t     sin_family;     //地质族(Address Family)， 也就是地址类型
        uinit16_t       sin_port;       //16位的端口号
        struct in_addr  sin_addr;       //32位IP地址
        char            sin_zero[8];    //不使用，一般用0来填充
};
