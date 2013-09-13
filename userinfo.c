/**
 * describe: some  mutipulation for function of user
 * date: 2013/06/18
 * author: zhangyun
 **/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include"userinfo.h"
#include"manipulate_db.h"

void userinfo_init( ){
    mysql_fetch_result( 7 );
    _mysql_close();
    userinfo_list = inital( userinfo_list );

}

void user userlogin( int sockfd ){
    char sql[100]="select * from user_info where username='";
    char username[USERNAME_L];
    char password[PASSWORD_L]; 
    int menu;
    MYSQL_RES *res;
    MYSQL_ROW row;
    userinfo *p;
    p  = inital( p  );
    userinfo_list = p;
    memset(username , '\0' ,USERNAME_L);
    memset(password , '\0' ,PASSWORD_L);
    mysql_connect(SERVER , USERNAME ,PASSWORD, DATABASE);
    while(1){
	printf("\n\n\n\t\t\t\twelcome login~\n");
	printf("       \t\t\t\t1.sign in\n");
	printf("       \t\t\t\t2.sign up\n");
	printf("\n\n\n\nchose:");
	scanf("%d" , &menu);
	setbuf( stdin , 0);
	switch( menu ){
	    case 1: 
		printf("*******sign in****");
		printf("username:\t");
		scanf("%s",username);
		printf("\n");
		printf("password:\t");
		scanf("%s",password);
		printf("\n");
		strcat(sql , username );
		strcat(sql, "'and password='");
		strcat(sql, password);
		stract(sql. "';");
		if(_mysql_query( sql) == 1 ){
		    fprintf(stderr , "username or password error!\n" );
		    break;
		}else{
		    res = mysql_store_result( conn );
		    row = mysql_fetch_row( res ); 
		    //storage online user into list
		    p  = insert( atoi(row[0]) , row[1] , row[2] , row[3], atoi(row[4]) , p );
		}
		break;
	    case 2:
		//sign up procedure
	}
    }
}

