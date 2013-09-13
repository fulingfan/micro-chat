#include<stdio.h>
#include<time.h>
#include<string.h>
#include"userinfo.h"

/* create list*/
userinfo inital( userinfo pre){

	if(( pre = create() ) != NULL ){
		pre->userid = 0;
		memset(pre->username , '\0' , USERNAME_L);
		memset(pre->password , '\0' , PASSWORD_L);
		memset(pre->gender , '\0' , 4);
		memset(pre->onlinetime , '\0' , 20);
		pre->age = 0;
		pre->next = NULL;
	}
	else
		return NULL;

	return pre;
}

userinfo create(  ){

	userinfo p;

	p = ( userinfo )malloc( sizeof( struct node ));
	if( !p ){
		printf("out of space\n");
		return NULL;
	}
	else
		return p;
}

userinfo insert( int userid , char* username , char* password , char *gender , 
	int age , userinfo init ){
	
	long ltime;
	userinfo p = NULL;
	p = inital( p );
	if( !p )
		return NULL;
	p->userid = userid;
	strcpy(p->username , username);
	strcpy(p->password , password);
	time( &ltime );
	//getting a  current time ( functions from time.h )
	strcpy( pre->onlinetime , asctime( gmtime(&ltime)));
	strcpy(p->gender , gender);
	p->age = age;
	if( init ){
		init->next = p;	
		init =p;
	}
	
	return p;
}

void print( userinfo p ){

	while( p ){
	    	printf("\tuserid\t\tusername\t\tpassword\t\tgender\t\tage\t\tonlinetime\n");
		printf( " %10d" , p->userid);
		printf( " %10s" , p->username);
		printf( " %10s" , p->password);
		printf( " %10s" , p->gender);
		printf( " %10d" , p->age);
		printf( " %10s" , p->onlinetime);
		printf("\n");
		p = p->next ;
	}
	printf("\n");

	return;
}






