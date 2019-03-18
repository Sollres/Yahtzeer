#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL_image.h>


int main(int argc, char** argv)
{	
	SDL_Event event;
    /* Initialisation*/
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }
    
    int quit, fullscreen = 0;
    
        /* Création de la fenêtre */
        SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("YATHZEER",SDL_WINDOWPOS_UNDEFINED,
                                              SDL_WINDOWPOS_UNDEFINED,
                                              980,
                                              500,
                                              SDL_WINDOW_SHOWN);

    SDL_Surface* pSprite = SDL_LoadBMP("./IMAGE/background.bmp");

	if ( pSprite )
	{
	    SDL_Rect dest = { 980/2 - pSprite->w/2, 500/2 - pSprite->h/2, 0, 0};
	    SDL_BlitSurface(pSprite,NULL,SDL_GetWindowSurface(pWindow),&dest); // Copie du sprite
	    
	    SDL_UpdateWindowSurface(pWindow); // Mise à jour de la fenêtre pour prendre en compte la copie du sprite
	    SDL_Delay(3000); /* Attendre trois secondes, que l'utilisateur voit la fenêtre */
	    
	    SDL_FreeSurface(pSprite); // Libération de la ressource occupée par le sprite
	}
	else
	{
	    fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
	}



        /*garde la fenetre ouverte jusu'à appuyer sur la croix*/
        if( pWindow )
		{
			int running = 1; 
			while(running) {  
				while(SDL_PollEvent(&event)) { 
					switch(event.type) { 
						case SDL_QUIT: running = 0; 
						break; 
					}
				}
			}
		}			
        else
        {
            fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
        }

    SDL_Quit();


    return 0;
}