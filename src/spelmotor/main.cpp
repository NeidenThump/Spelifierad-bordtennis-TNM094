// This script uses sdl, make sure you have sdl2 installed to use the script; https://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/msvc2019/index.php
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include "websocket/websocketClient.h"

// Global variables:
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_Surface* surface = nullptr;
SDL_Texture* textrue = nullptr;
SDL_Texture* textrue_hit = nullptr;

//int count = 1; 

const int NUM_PARTICLES = 500;




struct Particle {
	int x, y; // Position
	int vx, vy; // Velocity
	int lifetime; // Lifetime of the particle
};

std::vector<Particle> createExplosionParticles(int x, int y) {
	std::vector<Particle> particles;
	for (int i = 0; i < NUM_PARTICLES; ++i) {
		Particle p;
		p.x = x;
		p.y = y;
		p.vx = (rand() % 20 - 10)/2; 
		p.vy = (rand() % 20 - 10)/2;
		p.lifetime = rand() % 5 + 5; // Random lifetime in range [30, 60] frames
		particles.push_back(p);
	}
	return particles;
}


void renderExplosion(SDL_Renderer* renderer, int x, int y) {
	std::vector<Particle> particles = createExplosionParticles(x, y);
	//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 

	// Main loop for rendering particles
	for (int frame = 0; frame < 30; ++frame) { // Assuming the explosion lasts for 60 frames
		//SDL_RenderClear(renderer);
		for (Particle& p : particles) {
			// Update particle position
			p.x += p.vx;
			p.y += p.vy;
			p.lifetime--;

			// Render particle
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, p.lifetime * 255 / 60); // Fade out particle
			SDL_RenderDrawPoint(renderer, p.x, p.y);
			//SDL_Rect rect = { p.x, p.y, 5, 5 }; // Particle size
			//SDL_RenderFillRect(renderer, &rect);
		}
		SDL_RenderPresent(renderer);
		SDL_Delay(10); // Delay to control frame rate
	}
}










// function for rendering a rectangle with textrue
void RenderRectangle_target(int recx, int recy, int recw, int rech, int alpha) {
	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	//SDL_RenderClear(renderer);
	// create rectangle
	SDL_Rect Rectangle = { recx,recy, recw,rech };
	// set color 
	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	//render 
	//SDL_RenderFillRect(renderer, &Rectangle);

	// Alpha blend: 
	SDL_SetTextureBlendMode(textrue, SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(textrue, alpha);

	SDL_RenderCopy(renderer, textrue, NULL, &Rectangle);
	
	//std::cout << " rec rendered ";

}
void RenderRectangle_hit(int recx, int recy, int recw, int rech, int alpha) {
	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_Rect Rectangle = { recx,recy, recw,rech };
	// Alpha blend: 
	SDL_SetTextureBlendMode(textrue_hit, SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(textrue_hit, alpha);

	SDL_RenderCopy(renderer, textrue_hit, NULL, &Rectangle);
}


int Topleft_x(int x, int width) {
	return x - width;
}
int Topleft_y(int y, int hight) {
	return y - hight; 
}
void renderWaterdrop(int x, int y) {
	for (int frame = 0; frame < 30; ++frame) {
		RenderRectangle_hit(Topleft_x(x, (20+frame)/2), Topleft_y(y,(20+frame)/2), 20 + frame, 20 + frame, 255 - 6*frame);
		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
}


int createRandomCoordninate(int a) {
	std::random_device rd; 
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(100, a);
	return dist(gen); 
}

bool checkedHit(int x, int y, int d, double hitx, double hity) {
	double distance = floor(sqrt(pow(x - hitx, 2) + pow(y - hity,2)));
	//std::cout << distance << "\n";
	if (distance <= d + 15) {
		return true;
	}
	else {
		return false; 
	}
}

double scoreCalc(int hits) {
	return((100 / hits) * 100 );
}






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

	if (TTF_Init() != 0) {
		std::cerr << "TTF_Init Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	
	TTF_Font* font = TTF_OpenFont("../Spelifierad-bordtennis-TNM094/bilder/OpenSans_Condensed-Bold.ttf", 24);

		

	// display windiow on second screen
	// if you don't have 2 screens, you have to remove this code and uncomment the other window creation code
	int numDisplays = SDL_GetNumVideoDisplays();
	SDL_Rect secondDisplayBounds;
	SDL_GetDisplayBounds(1, &secondDisplayBounds);

	SDL_Window* window = SDL_CreateWindow("Window on Second Screen",
		secondDisplayBounds.x , // Adjust the x-coordinate as needed
		secondDisplayBounds.y + 20, // Adjust the y-coordinate as needed
		secondDisplayBounds.w, // Width
		secondDisplayBounds.h, // Height
		SDL_WINDOW_SHOWN);


	// If rendering is enabled, proceed with creating window and renderer
	if (renderEnabled) {
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			std::cout << "SDL initialization error: " << SDL_GetError() << std::endl;
			return 1; // Exit the program with an error code
		}
		else {
			std::cout << "SDL initialization successful." << std::endl;
		}

		//window = SDL_CreateWindow("C++ SDL2 Window", 10, 10, window_width, window_hight, SDL_WINDOW_SHOWN);
		if (!window) {
			std::cout << "Window creation error: " << SDL_GetError() << std::endl;
			SDL_Quit(); // Clean up SDL before exiting
			return 1; // Exit the program with an error code
		}
		else {
			std::cout << "Window creation successful." << std::endl;
		}
		

		// Add a short delay to allow the window to become visible
		SDL_Delay(100); // Delay for 100 milliseconds

		// Handle window events to wait until the window is shown
		bool windowShown = false;
		while (!windowShown) {
			SDL_Event e;
			while (SDL_PollEvent(&e)) {
				if (e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_SHOWN) {
					windowShown = true;
				}
			}
			SDL_Delay(10); // Delay to prevent high CPU usage
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (!renderer) {
			std::cout << "Renderer creation error: " << SDL_GetError() << std::endl;
			SDL_DestroyWindow(window); // Clean up window before exiting
			SDL_Quit(); // Clean up SDL before exiting
			return 1; // Exit the program with an error code
		}
		else {
			std::cout << "Renderer creation successful." << std::endl;
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);


		
		if (!font) {
			std::cerr << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
			TTF_Quit();
			SDL_Quit();
			return 1;
		}



	// Create texture
	// taxture uses an bitmap image, change the path to make sure that the image can be loaded. 
	const char* image_path = "../Spelifierad-bordtennis-TNM094/bilder/target_utan_linjer.bmp";
	//const char* image_path = "../Spelifierad-bordtennis-TNM094/bilder/target_utan_linjer.bmp";
	surface = SDL_LoadBMP(image_path); 
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0xFF,0xFF, 0xFF));
	textrue = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	const char* image_path_hit = "../Spelifierad-bordtennis-TNM094/bilder/circle.bmp";
	surface = SDL_LoadBMP(image_path_hit);
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	textrue_hit = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	
	bool gameIsRunning = true; 
	int count = 1;

	// add a function to get coordinates

	int x = createRandomCoordninate(secondDisplayBounds.w - 200); // x- coordinate 
	int y = createRandomCoordninate(secondDisplayBounds.h - 200); // y coordinate 
	int width = 100;
	int hight = 100; 
	int hits = 1;
	int score = 0;
	int hx;
	int hy;
	std::string scoreText = "Score: " + std::to_string(score);

	
	//Websocket
	std::cout << "Starting client..." << std::endl;
	WebSocketClient client("localhost", "30000");

	while (!client.connect()) {
		std::cout << "Could not connect, retrying..." << std::endl;
	}
	std::cout << "Connected to MATLAB successfully!" << std::endl;

	// Game loop: 
	while (gameIsRunning and client.isConnected()) {
		try {
				auto coordinates = readCoordinates(client.read());
				hx = coordinates.first; 
				hy = coordinates.second;
			std::cout << "X coordinate: " << hx << ", Y coordinate: " << hy << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		SDL_Event e;
		//hx = createRandomCoordninate(x + 4); // x- coordinate 
		//hy = createRandomCoordninate(y + 4); // y coordinate 


		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				gameIsRunning = false;
			}
		}  


		SDL_Color color = { 0,0,0 }; 
		SDL_Surface* textSurface = TTF_RenderText_Solid(font, scoreText.c_str(), color); 
		if (!textSurface) {
			std::cerr << "TTF_RenderText_Solid Error: " << TTF_GetError() << std::endl;
			break;
		}

		SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
		if (!textTexture) {
			std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
			SDL_FreeSurface(textSurface);
			break;
		}

		int textWidth = 2* textSurface->w;
		int textHeight = 2* textSurface->h;
		int posX = 10;
		int posY = 10;
		SDL_Rect destRect = { posX, posY, textWidth, textHeight };

		
		scoreText = "Score: " + std::to_string(score);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, textTexture, NULL, &destRect);
		//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		RenderRectangle_target(Topleft_x(x, width/2), Topleft_y(y, hight/2), width, hight, 255);
		//renderExplosion(renderer, hx, hy);
		renderWaterdrop(hx,hy); 
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		if (checkedHit(x, y, width, hx, hy) == true) {
			std::cout << "true";
			x = createRandomCoordninate(secondDisplayBounds.w-100); // x- coordinate 
			y = createRandomCoordninate(secondDisplayBounds.h-100); // y coordinate 
			score = score + scoreCalc(hits);
			std::cout << hits << "\n";
			std::cout << score << "\n";
			hits = 1; 

		}
		else {
			hits++;
		}

		if (hits >= 150) {


			std::string gameOver = "GAME OVER \n  Score: " + std::to_string(score);

			SDL_Surface* GOSurface = TTF_RenderText_Solid(font, gameOver.c_str(), color);
			if (!GOSurface) {
				std::cerr << "TTF_RenderText_Solid Error: " << TTF_GetError() << std::endl;
				break;
			}

			SDL_Texture* GOTexture = SDL_CreateTextureFromSurface(renderer, GOSurface);
			if (!GOTexture) {
				std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
				SDL_FreeSurface(textSurface);
				break;
			}

			int pX = (secondDisplayBounds.w/2 - 2*GOSurface->w) ;
			int pY = secondDisplayBounds.h/4;
			SDL_Rect dRect = { pX, pY, secondDisplayBounds.w/2,  secondDisplayBounds.h/2 };


			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, GOTexture, NULL, &dRect);
			SDL_RenderPresent(renderer);


			SDL_DestroyTexture(textTexture);
			SDL_FreeSurface(textSurface);
			SDL_DestroyTexture(GOTexture);
			SDL_FreeSurface(GOSurface);

			SDL_Delay(5000);
			gameIsRunning = false; 

		}
		
		SDL_RenderPresent(renderer);
		SDL_DestroyTexture(textTexture);
		SDL_FreeSurface(textSurface);

		SDL_RenderClear(renderer);
		SDL_Delay(500);
	}
	client.close();
	}
	TTF_CloseFont(font);
	SDL_DestroyTexture(textrue);
	SDL_DestroyTexture(textrue_hit);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();

	return 0;
	
}
