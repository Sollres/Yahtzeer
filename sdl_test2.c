#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL_image.h>

int main(int argc, char** argv)
{
    /*
    // Initialisation simple 
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Ã‰chec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }

    {
        // CrÃ©ation de la fenÃªtre 
        SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("YahtZeer",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  1444,
                                                                  1080,
                                                                  SDL_WINDOW_SHOWN);

        if( pWindow )
        {
            SDL_Delay(3000); // Attendre trois secondes, que l'utilisateur voie la fenÃªtre 

            SDL_DestroyWindow(pWindow);
        }
        else
        {
            fprintf(stderr,"Erreur de crÃ©ation de la fenÃªtre: %s\n",SDL_GetError());
        }
    }
    

    SDL_Quit();

    return 0;*/
    int quit = 0;
    SDL_Event event;
 
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG);
 
    SDL_Surface *window = SDL_CreateWindow("YahtZeer",
                                            SDL_WINDOWPOS_UNDEFINED, 
                                            SDL_WINDOWPOS_UNDEFINED, 
                                            980, 650, 0);
 
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface * image = NULL;
    SDL_Surface * image2 = NULL;
    //SDL_Surface * henni = NULL;
    
    SDL_Rect pos;
    pos.x=100;
    pos.y=250;

    SDL_RWops *fond=SDL_RWFromFile("./IMAGE/background.png", "rb");
    SDL_RWops *titre=SDL_RWFromFile("./IMAGE/titre.png", "rb");

    image=IMG_LoadPNG_RW(fond);
    image2= IMG_LoadPNG_RW(titre);

    //SDL_BlitSurface(fond, NULL, window, NULL);
    SDL_BlitSurface(image2, NULL, window, &pos);

    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_Texture * texture2 = SDL_CreateTextureFromSurface(renderer, image2);

 
    while (!quit)
    {
        SDL_WaitEvent(&event);
 
        switch (event.type)
        {
            case SDL_QUIT:
                quit = 1;
                break;
        }
 
        //SDL_Rect dstrect = { 5, 5, 320, 240 };
        //SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderCopy(renderer, texture2, NULL, NULL);

        SDL_RenderPresent(renderer);
    }
 
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
 
    IMG_Quit();
    SDL_Quit();
 
    return 0;

}