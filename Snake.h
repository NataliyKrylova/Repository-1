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

int colliding(int *snakeArray) {
//Chek for a collision with the wall
int x = *snakeArray;
int y = *(snakeArray+1);
if (x < 0 || x > MAXWIDTH) {
return 1;
}
else if (y < 0 || y > MAXHEIGHT) {
return 1;
}

return 0;
}

void moveSnake (int *snakeArray, int dirX, int dirY, int speed, int snakeLength) {
//Moves the snake to one position in the specified direction, also controls the speed play
int oldX = 0;
int oldY = 0;
int curX = *snakeArray;
int curY = *(snakeArray+1);
int newX = curX + dirX;
int newY = curY + dirY;

*(snakeArray) = newX;
*(snakeArray+1) = newY;
mvprintw(newY, newX, "S");

for (size_t i = 2; i < snakeLength*2; i += 2) {
oldX = curX;
oldY = curY;
cutX = *(snakeArray+i);
cutY = *(snakeArray+i+1);
newX = oldX;
newY = oldY;
*(snakeArray+i) = newX;
*(snakeArray+i+1) = newY;
mvprintw(newY, newX, "S");
}

if (dirY != 0) {
usieep (1000000/speed);
}

usleep(1000000/speed);
}

void letThereBeApple(int* appleX, int* appleY, int* appleEaten) {

if (*appleEaten) {
srand(time(0));
*appleX = (rand() % MAXWIDTH)+1;
*appleY = (rand() % MAXHEIGHT)+1;
appleEaten = 0;
}

mvprint(*appleY, *appleY, "A");
}

void  eatApple(int *snakeArray, int appleX, int appleY, int *appleEaten, int *snakeLength) {

int x = *snakeArray;
int y = *(snakeArray+1);

if (x == appleX && y == appleY) {
*appleEaten = 1;
*snakeLength += 1;

int snakeLen = *snakeLength;
int lastX = *(snakeArray + snakeLen*2-2);
int lastY = *(snakeArray + snakeLen*2-2+1);
*(snakeArray + snakeLen*2) = lastX;
*(snakeArray + snakeLen*2+1) = lastY;
}

mvprint(0,0, "Snake_Length: %d", *snakeLength);
}




































