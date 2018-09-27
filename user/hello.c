#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"

char buf[4028];
int stdout = 1;
int main(int argc, char** argv)
{
	int fd;
        int i;

        printf(stdout, "small file test\n");
        fd = open("small", O_CREATE|O_RDWR);
        if(fd >= 0){
		printf(stdout, "creat small succeeded; ok\n");
	} else {
		printf(stdout, "error: creat small failed!\n");
		exit();
	}
	for(i = 0; i < 100; i++){
		if(write(fd, "aaaaaaaaaa", 10) != 10){
        		printf(stdout, "error: write aa %d new file failed\n", i);
        		exit();
		}
        	if(write(fd, "bbbbbbbbbb", 10) != 10){
        		printf(stdout, "error: write bb %d new file failed\n", i);
        		exit();
    		}
 	}
	printf(stdout, "writes ok\n");
 	close(fd);
  	fd = open("small", O_RDONLY);
  	if(fd >= 0){
		printf(stdout, "open small succeeded ok\n");
  	} else {
    		printf(stdout, "error: open small failed!\n");
    		exit();
  	}
  	i = read(fd, buf, 2000);
  	if(i == 2000){
    		printf(stdout, "read succeeded ok\n");
  	} else {
   	printf(stdout, "read failed\n");
    	exit();
  	}
           
	printf(1, "getreadcount(): %d\n", getreadcount());
	
	exit();
}
