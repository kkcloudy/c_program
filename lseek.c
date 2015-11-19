#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJK";

int main(void)
{
	int fd,size;
	if((fd = creat("file.hole",S_IRUSR|S_IWUSR)) < 0){
		perror("creat");
		return -1;
	}

	size = sizeof(buf1) - 1;
	if(write(fd,buf1,size) != size){
		perror("write");
		return -1;
	}
	if(lseek(fd,16384,SEEK_SET) == -1){
		perror("lseek error");
		return -1;
	}
	size = sizeof(buf2) -1;
	if(write(fd,buf2,size) !=size){
		perror("error");
		return -1;
	}
	return 0;
}


