#include <poll.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

int main(int argc, char *argv[])
{
    char buf[4096];
    while(1) {
        struct pollfd fds;
        int ret;
        fds.fd = 0; /* this is STDIN */
        fds.events = POLLIN;
        ret = poll(&fds, 1, 0);
        if(ret == 1) {
            if (0==fgets(buf,4090,stdin) ) {
                std::cout<<"Program terminated"<<std::endl;
                
                return 8;
            }
            else{
                std::string payload = std::string(buf);
                std::cout<<"payload:"<<payload<<std::endl;
            }
        }

    }
        
  return 0;
}
