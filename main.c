#define SDL_MAIN_HANDLED

#include "SDL2/SDL.h" 
#include <stdio.h>
#include <stdbool.h>
//#define main SDL_main

int main(int argv, char** args)
{
  printf("Init SDL 2.0 \n");
  //SDL_Init(SDL_INIT_VIDEO);
  //SDL_Init( SDL_INIT_EVERYTHING ); //Start SDL
  bool keep_window_open = true;

  if(SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("Failed to initialize the SDL2 library\n");
    return -1;
  }

  SDL_Window  *window;
  //The surface contained by the window
  SDL_Surface* screenSurface = NULL;
  
  window = SDL_CreateWindow("SDL2 Window", 100, 100, 640, 480, 0); 
  if(window==NULL)
  {   
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
  }

  SDL_Surface *window_surface = SDL_GetWindowSurface(window);
  if(!window_surface)
  {
    printf("Failed to get the surface from the window\n");
    printf("SDL2 Error: ", SDL_GetError(), "\n");
    return -1;
  }

  // The window is open: could enter program loop here (see SDL_PollEvent())
  
  printf("init window...");
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
      //Get window surface
      screenSurface = SDL_GetWindowSurface( window );

      //Fill the surface white
      SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

      SDL_UpdateWindowSurface(window);
    }
  }

  SDL_DestroyWindow(window); 
  // Clean up
  SDL_Quit();
  return 0;
}