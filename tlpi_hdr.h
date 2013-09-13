#ifndef TLPI_HDR_H
#define TLPI_HDR_H  	 /* prevent accidental double inclusion*/

#include<sys/types.h>   /* thpe definitions used by many paograms*/
#include<stdio.h> 		/* standard I/O functions */
#include<stdlib.h> 		/* prototypes of commonly used library functions plus EXIT_SUCCESS and EXIT_FAILURE constants */

#include"get_num.h"		/* declares our function for handing numerix arguments( getInt() , getLong() )*/
#include"error_functions.h"  /* declars our error-handling functions*/

typedef enum { FALSE , TRUE } Boolean;

#define min( m , n )  ( ( m ) < ( n ) ? ( m ) : ( n ))
#define max( m , n )  ( ( m ) > ( n ) ? ( m ) : ( n )) 

#endif




 

