#ifndef __NET_H
#define __NET_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <signal.h>

enum {
    P_TCP,
    P_UDP,
};

#define serv(port, o...) \
    ({ int backlog = 10, max_buf = 65507,\
        proto = P_TCP, exit = 1; o;\
    serv_(port, backlog, max_buf, proto, exit); })

#define con(host, port, o...) \
    ({ int max_buf = 65507, proto = P_TCP,\
        exit = 1; o;\
    con_(host, port, max_buf, proto, exit); })

int serv_(int port, int backlog, int max_buf, int proto,
    int exit);
int con_(char* host, int port, int max_buf, int proto,
    int exit);
int end(int socket);

#endif