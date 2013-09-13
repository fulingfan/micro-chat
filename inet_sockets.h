#ifndef INET_SOCKETS_H
#define INET_SOCKETS_H

#include<sys/socket.h>
#include<netdb.h>

int inetConnect( const char *host , const char *service , int type );
int inetListen( const char *service , int backlog , socklen_t *addrlen );
int inetBind( const char *service , int type , socklen_t addrlen , 
		char * addrstr , int addrstrlen );
#define IS_ADD_STR_LEN 4096

#endif
