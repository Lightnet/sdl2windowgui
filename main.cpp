#define SDL_MAIN_HANDLED

#include "SDL2/SDL.h" 
#include <stdio.h>
#include <iostream>
//#define main SDL_main

int main(int argv, char** args)
{
  args = args;
  argv = argv;

  std::cout << "Init SDL 2.0 \n";
  //SDL_Init(SDL_INIT_VIDEO);
  //SDL_Init( SDL_INIT_EVERYTHING ); //Start SDL
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cout << "Failed to initialize the SDL2 library\n";
    return -1;
  }

  SDL_Window  *window;
  
  window = SDL_CreateWindow("SDL2 Window", 100, 100, 640, 480, 0); 
  if(window==NULL)
  {   
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
  }

  SDL_Surface *window_surface = SDL_GetWindowSurface(window);
  if(!window_surface)
  {
    std::cout << "Failed to get the surface from the window\n";
    std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
    return -1;
  }

  // The window is open: could enter program loop here (see SDL_PollEvent())
  bool keep_window_open = true;
  while(keep_window_open)
  {
    SDL_Event e;
    while(SDL_PollEvent(&e) > 0)
    {
      switch(e.type)
      {
        case SDL_QUIT:
          keep_window_open = false;
          break;
      }
      SDL_UpdateWindowSurface(window);
    }
  }

  SDL_DestroyWindow(window); 
  // Clean up
  SDL_Quit();
  return 0;
}