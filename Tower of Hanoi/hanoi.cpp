//Libraries
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
 
//Screen dimensions
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
 
//SDL initialization
bool init();
 
//SDL shutdown
void close();
 
//The window to render to
SDL_Window* gWindow = NULL;
 
//The window renderer
SDL_Renderer* gRenderer = NULL;
 
 
bool init()
{
	//Initialization flag
	bool success = true;
 
		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
 
			}
		}
 
 
	return success;
}
 
void close()
{
 
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
 
	//Quit SDL
	IMG_Quit();
	SDL_Quit();
}
 
 
 
//Disc data will be stored in form of a class
class disc
{
private:
	int size;
	int color_r, color_g, color_b;
 
public:
	disc(int newSize, int r, int g, int b) {
	size = newSize;
	color_r = r;
	color_g = g;
	color_b = b;
	}
 
	int getSize() {
	return size;
	}
 
	int getColor_r() {
	return color_r;
	}
 
	int getColor_g() {
	return color_g;
	}
 
	int getColor_b() {
	return color_b;
	}
};

//Constructing discs 1-5 and empty disc 0
disc disc0(0,0x00,0x00,0x00);
disc disc1(1,0xFF,0x00,0x00);
disc disc2(2,0x00,0xFF,0x00);
disc disc3(3,0x00,0x00,0xFF);
disc disc4(4,0xFF,0x00,0xFF);
disc disc5(5,0x00,0xFF,0xFF);
 
//Constructing towers in form of arrays
disc tower1[5] = {disc1, disc2, disc3, disc4, disc5};
disc tower2[5] = {disc0, disc0, disc0, disc0, disc0};
disc tower3[5] = {disc0, disc0, disc0, disc0, disc0};

//Pointer to read current disc data from
disc *temporary = NULL;
 
//Variables to be used later
int originDiscPosition;
int targetDiscPosition;
int origintower;
bool wasTowerChosenFlag = false;
 
//Gets position of the top disc object in tower array
int getPositionOfTopDisc(disc arr[])
{
	for (int k = 0; k < sizeof(arr); k++)
	{
		disc *temp = &arr[k];
		if(temp->getSize() != 0) {
			return k;}
	}
	return 5;
 
}
 
 
int main( int argc, char* args[] )
{
	//Initialize SDL
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Main loop flag
		bool quit = false;
 
		//Event handler
		SDL_Event e;
 
		while( !quit )
		{
			//Handle events
			while( SDL_PollEvent( &e ) != 0 )
			{
				//Quit request
				if( e.type == SDL_QUIT )
				{
					quit = true;
				}
				//Key is pressed
				else if( e.type == SDL_KEYDOWN )
				{
					//If tower of disc origin was not chosen, proceeds to tower choice
					//If it was chosen, proceeds to choice of tower to move disc to 
					if(wasTowerChosenFlag == false)
					{
						switch( e.key.keysym.sym )
						{
							//Disc is taken from tower 1
							case SDLK_1:
							originDiscPosition = getPositionOfTopDisc(tower1);
							origintower = 1;
							temporary = &tower1[originDiscPosition];
							wasTowerChosenFlag = true;
							break;
 
							//Disc is taken from tower 2
							case SDLK_2:
							originDiscPosition = getPositionOfTopDisc(tower2);
							origintower = 2;
							temporary = &tower2[originDiscPosition];
							wasTowerChosenFlag = true;
							break;
 
							//Disc is taken from tower 3
							case SDLK_3:
							originDiscPosition = getPositionOfTopDisc(tower3);
							origintower = 3;								
							temporary = &tower3[originDiscPosition];
							wasTowerChosenFlag = true;
							break;
						}
					} else if (temporary->getSize() > 0) {
 
						//Selects tower to move disc to
						switch( e.key.keysym.sym )
						{	
							//Tower 1 is chosen
							case SDLK_1:
							targetDiscPosition = getPositionOfTopDisc(tower1) - 1;
							switch(origintower) {
								case 1:
								break;
								case 2:
								tower1[targetDiscPosition] = tower2[originDiscPosition];
								tower2[originDiscPosition] = disc0;
								break;
								case 3:
								tower1[targetDiscPosition] = tower3[originDiscPosition];
								tower3[originDiscPosition] = disc0;
								break;
							}
							wasTowerChosenFlag = false;
							break;
 
							//Tower 2 is chosen
							case SDLK_2:
							targetDiscPosition = getPositionOfTopDisc(tower2) - 1;
							switch(origintower) {
								case 1:
								tower2[targetDiscPosition] = tower1[originDiscPosition];
								tower1[originDiscPosition] = disc0;
								break;
								case 2:
								break;
								case 3:
								tower2[targetDiscPosition] = tower3[originDiscPosition];
								tower3[originDiscPosition] = disc0;
								break;
							}
							wasTowerChosenFlag = false;
							break;
 
							//Tower 3 is chosen
							case SDLK_3:
							targetDiscPosition = getPositionOfTopDisc(tower3) - 1;
							switch(origintower) {
								case 1:
								tower3[targetDiscPosition] = tower1[originDiscPosition];
								tower1[originDiscPosition] = disc0;
								break;
								case 2:
								tower3[targetDiscPosition] = tower2[originDiscPosition];
								tower2[originDiscPosition] = disc0;
								break;
								case 3:
								break;
							}
							wasTowerChosenFlag = false;
							break;
						}
					} else {
					wasTowerChosenFlag = false;
					}
 
				}
			}
			//Reset screen and render background
			SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0x00, 0xFF );
			SDL_RenderClear( gRenderer );
 
			//Render Towers
			SDL_Rect tower1_fig = { SCREEN_WIDTH / 5 - 10, SCREEN_HEIGHT / 5 * 2, 20, SCREEN_HEIGHT / 5 * 3 };
			SDL_Rect tower2_fig = { SCREEN_WIDTH / 2 - 10, SCREEN_HEIGHT / 5 * 2, 20, SCREEN_HEIGHT / 5 * 3 };
			SDL_Rect tower3_fig = { SCREEN_WIDTH / 5 * 4 - 10, SCREEN_HEIGHT / 5 * 2, 20, SCREEN_HEIGHT / 5 * 3 };
			SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0xFF, 0xFF );		
			SDL_RenderFillRect( gRenderer, &tower1_fig );
			SDL_RenderFillRect( gRenderer, &tower2_fig );
			SDL_RenderFillRect( gRenderer, &tower3_fig );
 
 
			//Render discs on first tower
			for(int i = 0; i < 5; i++) {
				disc *temp = &tower1[i];
 
				if (temp->getSize() != 0) {
					SDL_Rect discs = { SCREEN_WIDTH / 5 - (30 + 10 * temp->getSize()), SCREEN_HEIGHT / 2 + SCREEN_HEIGHT / 10 * (i % 5), 60 + 20 * temp->getSize(), SCREEN_HEIGHT / 10 };
					SDL_SetRenderDrawColor( gRenderer, temp->getColor_r(), temp->getColor_g(), temp->getColor_b(), 0xFF );		
					SDL_RenderFillRect( gRenderer, &discs );
				}
			}
 
			//Render discs on second tower
			for(int i = 0; i < 5; i++) {
				disc *temp = &tower2[i];
 
				if (temp->getSize() != 0) {
					SDL_Rect discs = { SCREEN_WIDTH / 2 - (30 + 10 * temp->getSize()), SCREEN_HEIGHT / 2 + SCREEN_HEIGHT / 10 * (i % 5), 60 + 20 * temp->getSize(), SCREEN_HEIGHT / 10 };
					SDL_SetRenderDrawColor( gRenderer, temp->getColor_r(), temp->getColor_g(), temp->getColor_b(), 0xFF );		
					SDL_RenderFillRect( gRenderer, &discs );
				}
			}
 
			//Render discs on third tower				
			for(int i = 0; i < 5; i++) {
				disc *temp = &tower3[i];
 
				if (temp->getSize() != 0) {
					SDL_Rect discs = { SCREEN_WIDTH / 5 * 4 - (30 + 10 * temp->getSize()), SCREEN_HEIGHT / 2 + SCREEN_HEIGHT / 10 * (i % 5), 60 + 20 * temp->getSize(), SCREEN_HEIGHT / 10 };
					SDL_SetRenderDrawColor( gRenderer, temp->getColor_r(), temp->getColor_g(), temp->getColor_b(), 0xFF );		
					SDL_RenderFillRect( gRenderer, &discs );
				}
			}
 
			//Update screen
			SDL_RenderPresent( gRenderer );
		}
 
	}
 
	close();
 
	return 0;
}
