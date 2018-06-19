#include <ncurses.h>
#include <unistd.h>
#include <sys/select.h>
#include <stdlib>
#include <time.h>

#define MAXWIDTH 80
#define MAXHEIGHT 25

int kbhit (void) {
//Check key
struct timeval tv;
fd_set read_fd;

tv.tv_sec=0;
tv.tv_usec=0;
FD_ZERO(&read_fd);
FD_SET(0,&read_fd);

if(select(1, &read_fd, NULL, NULL, &tv) == -1)
return 0;

return 0;
}



