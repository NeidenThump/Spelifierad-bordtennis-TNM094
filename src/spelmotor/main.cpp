// This script uses sdl, make sure you have sdl2 installed to use the script; https://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/msvc2019/index.php
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <iostream>
#include <random>

// Global variables:
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_Surface* surface = nullptr;
SDL_Texture* textrue = nullptr;
SDL_Texture* textrue_hit = nullptr;
int count = 1; 
int hx; 
int hy;
int window_width = 1000;
int window_hight = floor(window_width * 1.37 / 1.525);


// function for rendering a rectangle with textrue
void RenderRectangle_target(int recx, int recy, int recw, int rech, int alpha) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	//SDL_RenderClear(renderer);
	// create rectangle
	SDL_Rect Rectangle = { recx,recy, recw,rech };
	// set color 
	//SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
	//render 
	//SDL_RenderFillRect(renderer, &Rectangle);

	// Alpha blend: 
	SDL_SetTextureBlendMode(textrue, SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(textrue, alpha);

	SDL_RenderCopy(renderer, textrue, NULL, &Rectangle);
	
	std::cout << " rec rendered ";

}
void RenderRectangle_hit(int recx, int recy, int recw, int rech, int alpha) {
	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_Rect Rectangle = { recx,recy, recw,rech };
	// Alpha blend: 
	SDL_SetTextureBlendMode(textrue, SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(textrue, alpha);

	SDL_RenderCopy(renderer, textrue_hit, NULL, &Rectangle);

	std::cout << " rec rendered ";
}

int Topleft_x(int x, int width) {
	return x - width;
}
int Topleft_y(int y, int hight) {
	return y - hight; 
}

//int drawLine(int side) {
//	if (side == 0) {
//		for (int i = 0; i <= 400; ++i) {
//			SDL_RenderClear(renderer); 
//			SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
//			//SDL_RenderDrawLine(renderer, 40, 0, 40, 2 * i );
//			SDL_Rect rec = { 40,0,40, 2 * i };
//			SDL_RenderFillRect(renderer, &rec);
//			SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
//			SDL_Delay(10);
//			SDL_RenderPresent(renderer);
//		}
//		return 1;
//	}
//	else {
//		for (int i = 0; i <= 400; ++i) {
//			SDL_RenderClear(renderer);
//			SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
//			SDL_Rect rec = { 560,0,40, 2 * i };
//			SDL_RenderFillRect(renderer, &rec);
//			//SDL_RenderDrawLine(renderer, 600, 0,600 , 2 * i);
//			SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
//			SDL_Delay(10);
//			SDL_RenderPresent(renderer);
//		}
//		return 0; 
//	}
//}

int createRandomCoordninate(int a) {
	std::random_device rd; 
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, a);
	return dist(gen); 
}

bool checkedHit(int x, int y, int d, double hitx, double hity) {
	double distance = floor(sqrt(pow(x - hitx, 2) + pow(y - hity,2)));
	std::cout << distance << "\n";
	if (distance <= d + 30) {
		return true;
	}
	else {
		return false; 
	}
}

int score(int hits) {
	return(100 * (0.1 * hits));
}

//void waterdropeffect(double hx, double hy, double w, int c ) {
//	int count = c; 
//	RenderRectangle(Topleft_x(hx, w) - floor(count / 2), Topleft_y(hy, w) - floor(count / 2), 30, 30, 255 - (count * 2));
//
//}






int main(int argc, char* args[]){
	// Check if the command-line argument to start rendering is provided
	bool renderEnabled = false;
	for (int i = 1; i < argc; ++i) {
		if (strcmp(args[i], "--render") == 0) {
			renderEnabled = true;
			break;
		}
	}
	
	// create window data type
	

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL error" << SDL_GetError();
	}
	else {
		std::cout << "SDL window is ready to go!\n";
	}

	// If rendering is enabled, proceed with creating window and renderer
	if (renderEnabled) {
	window = SDL_CreateWindow("C++ SDL2 Window", 10, 10, window_width ,window_hight, SDL_WINDOW_SHOWN);
	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	// Create texture
	// taxture uses an bitmap image, change the path to make sure that the image can be loaded. 
	const char* image_path = "../bilder/target_red_green_yellow.bmp";
	surface = SDL_LoadBMP(image_path); 
	//SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0xFF,0xFF, 0xFF));
	textrue = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	const char* image_path_hit = "../bilder/circle.bmp";
	surface = SDL_LoadBMP(image_path_hit);
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	textrue_hit = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);


	bool gameIsRunning = true; 
	int count = 1;

	// add a function to get coordinates

	int x = createRandomCoordninate(window_width); // x- coordinate 
	int y = createRandomCoordninate(window_hight); // y coordinate 
	int width = 100;
	int hight = 150; 



	// Game loop: 
	while (gameIsRunning) {
		SDL_Event e;
		
		if (count == 1) {
			 hx = createRandomCoordninate(x + 4); // x- coordinate 
			 hy = createRandomCoordninate(y + 4); // y coordinate 
		}

		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				gameIsRunning = false;
			}
		}
			// render a "circle"  ( vattendroppe)  

			RenderRectangle_hit(Topleft_x(hx,width) - floor(count / 2), Topleft_y(hy,hight) - floor(count / 2), 30, 30, 255 - (count * 2));
			//waterdropeffect(hx, hy, width, count);
			/*++count; 
			if (count == 125) {
				count = 1; 
			}*/
			SDL_Delay(10); 

			RenderRectangle_target(Topleft_x(x, width), Topleft_y(y, hight) , width , hight , 255 );

		if (checkedHit(x, y, width, hx, hy) == true) {
			std::cout << "true";
			x = createRandomCoordninate(window_width); // x- coordinate 
			y = createRandomCoordninate(window_hight); // y coordinate 

		}
		else {

		}
		
		std::cout << hx << ", " << hy << "\n";
		std::cout << x << "," << y << "\n";
		

		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);
		SDL_Delay(1000);
	}
	}

	SDL_DestroyTexture(textrue);
	SDL_DestroyTexture(textrue_hit);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
	
}
