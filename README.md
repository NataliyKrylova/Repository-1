#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

int N=30, M=20;
int size=16;
int w = size*N;
int h = size*M;

int main()
{
	RenderWindow window(VideoMode(w, h), "Snake Game!");
	
	Texture t1,t2;
	t1.loadFromFile("Images/white.png");
	t2.loadFromFile("Images/red.png");
	
	Sprite sprite1(t1);
	Sprite sprite2(t2);
	
	while (window.isOpen())
	{
		if (e.type == Event::Closed)
			window.close();
	}
	
	///////// draw ////////
	
	
return 0;
}
