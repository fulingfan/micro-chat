#ifndef MANIPULATE_DB_H
#define MANIPULATE_DB_H

#define SERVER "localhost"
#define USERNAME "root"
#define PASSWORD "123456"
#define DATABASE "db_chat"

#include<mysql/mysql.h>
extern int mysql_connect( char* server , char* user , char* password , char* database );
extern int _mysql_query(  char* sql );
extern void mysql_fetch_result( );
extern void _mysql_close( );

MYSQL *conn;
#endif /*MANIPULATE_DB_H*/
