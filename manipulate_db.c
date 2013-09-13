/**
 * some functions for manipulating database in this file;
 * date: 2013/6/15
 * author: zhangyun
 * */
#include<stdio.h>
#include<stdlib.h>
#include"mysql/mysql.h"
#include"manipulate_db.h"


//connect to database
int mysql_connect( char* server , char* user , char* password , char* database ){
    conn = mysql_init( NULL );
    if( !mysql_real_connect( conn , SERVER , USERNAME , PASSWORD , DATABASE , 0 , NULL , 0)){
    	fprintf( stderr , "%s\n" , mysql_error(conn));
	return 1;
    }
    return 0;
}

//send sql query
int _mysql_query( char *sql ){
    if( mysql_query( conn , sql)){
 //   	fprintf( stderr , "%s\n" , mysql_error(conn));
	return 1;
    }
    return 0;
}

//fecth all content  of table
void  mysql_fetch_result( int column ){
    int i;
    MYSQL_RES *res;
    MYSQL_ROW row;
    res = mysql_store_result( conn );
    while( (row = mysql_fetch_row(res)) != NULL){
	for( i = 0 ; i < mysql_num_fields(res); i++ ){
	    printf("%s\t" , row[i]);
	}
	printf("\n");
    }
    mysql_free_result( res );
    return ;
}

//close database
void _mysql_close( ){
    mysql_close( conn );
}

