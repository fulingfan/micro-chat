/**
 * describe :
 * date: 2013/06/16
 * author: zhangyun
 **/
#include<stdio.h>
#include<stdlib.h>
#include"manipulate_db.h"

void main(){
    mysql_connect(SERVER , USERNAME ,PASSWORD, DATABASE);
    _mysql_query("select * from user_info;");
    mysql_fetch_result( 5 );
    _mysql_close();
}

