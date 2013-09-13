#ifndef USERINFO_H
#define USERINFO_H

#define USERNAME_L	50
#define PASSWORD_L	10
#define USERMESG_L	256

//define a structure data type to storage userinfo of online
typedef struct user_info{
    int userid;
    char username[USERNAME_L];
    char password[PASSWORD_L];
    char gender[4];
    int age;
    char *onlinetime[20];
    userinfo *next;
}userinfo;

//define a structure data type to storage message content
typedef struct mesg{
    int userid;
    char usermesg[USERMESG_L];
    int fd;
    mesg *next;
}mesg;

/*
//to storage user (online user)
typedef struct user_status{
    int userid;
    onlineuser *next;
}onlineuser;*/

//declare global variable
userinfo *userinfo_list;

extern userinfo create( );
extern userinfo insert( int userid , char* username , char* password , char *gender , int age , userinfo init );
extern void print( userinfo p );
extern void userinfo_init();
extern void userlogin( int sockfd );

#endif/*USERINFO_H*/
