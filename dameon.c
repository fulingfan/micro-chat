/** 
 * describe: createing a daemon
 * date: 2013/06/16
 * author: zhangyun
 **/
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include"tlpi_hdr.h"
#include"dameon.h"

int becomeDaemon(int flags)
{
    int maxfd, fd;
    /* Returns 0 on success, -1 on error */
    switch (fork()) { /* Become background process */
	case -1: return -1; 
	/* Child falls through... */
	case 0: break; 
	default: exit( 0); /* while parent terminates */

    } 
    if (setsid() == -1) /* Become leader of new session */
	return -1; 
    switch (fork()) { /* Ensure we are not session leader */
	case -1: return -1; 
	case 0: break; 
	default: exit( 0 ); 
    } 
//   if (!(flags & BD_NO_UMASK0)) /* Clear file mode creation mask */
//	 umask(0); 
 //    if (!(flags & BD_NO_CHDIR)) /* Change to root directory */
//	 chdir("/"); 
//     if (!(flags & BD_NO_CLOSE_FILES)) { /* Close all open files */
//	 maxfd = sysconf(_SC_OPEN_MAX);
//	 if (maxfd == -1)	/* Limit is indeterminate... */
//	     maxfd = BD_MAX_CLOSE;	/* so take a guess */
//	 for (fd = 0; fd < maxfd; fd++)
//	     close(fd);
//     }
//     if (!(flags & BD_NO_REOPEN_STD_FDS)) {
//	 /* Reopen standard fd's to /dev/null */
//	 close(STDIN_FILENO);
//	 fd = open("/dev/null", O_RDWR);
//	 /* 'fd' should be 0 */
//	 if (fd != STDIN_FILENO)
//	     return -1;
//	 if (dup2(STDIN_FILENO, STDOUT_FILENO) != STDOUT_FILENO)
//	     return -1;
//	 if (dup2(STDIN_FILENO, STDERR_FILENO) != STDERR_FILENO)
//	     return -1;
//     }
     return 0;
}
