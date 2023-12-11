#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    if(argc!=3){
        printf("usage: %s source-file dest-file\n", argv[0]);
        return 0;
    }

    int fd_src, fd_dest;

    fd_src = open(argv[1], O_RDONLY);
    fd_dest = open(argv[2], O_WRONLY, 0644);

    if(fd_src == -1 || fd_dest == -1){
        perror("ERROR : CANNOT OPEN FILE");
        return 0;
    }
    else{    
        while(1){
            char buf[256];
            if(read(fd_src, buf, 1) == 0){
                break;
            }
            else{
                write(fd_dest, buf, 1);
            }
        }
    }

    return 0;
}