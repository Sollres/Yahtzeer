#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL_image.h>


SDL_Texture *tex_text(char * font, int size, char *s, SDL_Color color, SDL_Renderer *renderer){

    TTF_Font *policeTitre = NULL;

    if((policeTitre = TTF_OpenFont(font, size)) == NULL){

        fprintf(stderr, "Erreur chargement font\n");
        exit(EXIT_FAILURE);
    }
    SDL_Surface *texte = TTF_RenderUTF8_Blended(policeTitre, s, color);

    if(!texte){

        fprintf(stderr,"Erreur à la création du texte : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_Texture *texte_tex = SDL_CreateTextureFromSurface(renderer, texte);

    if(!texte_tex){

        fprintf(stderr, " Erreur à la création du rendu du texte : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
 
    SDL_FreeSurface(texte);
    TTF_CloseFont(policeTitre);
    return texte_tex;
}   


SDL_Texture *tex_img_png(char * s, SDL_Renderer * renderer){

    SDL_RWops *rwop=SDL_RWFromFile(s, "rb");

        SDL_Surface *image=IMG_LoadPNG_RW(rwop);

        if(!image){

            printf("IMG_LoadPNG_RW : %s\n", IMG_GetError());
        }

        SDL_Texture *bouton = SDL_CreateTextureFromSurface(renderer, image);
        
        if(!bouton){

            fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }

        SDL_FreeSurface(image);

    return bouton;
}

int main(void){

      int x,y;
      int i, j;

    TTF_Init();
    SDL_Window *pWindow = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Rect imgBGRect, txtDestRect;
   
    
    /*couleur noir*/
    SDL_Color noir = {0,0,0,0};



    /*Création de la fenêtre */

    pWindow = SDL_CreateWindow("YATHZEE",SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                1080,
                                650,
                                SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);

    if(!pWindow){
        fprintf(stderr, "Erreur à la création de la fenetre : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        fprintf(stderr, "Erreur à la création du renderer\n");
        exit(EXIT_FAILURE);
    }

    SDL_Texture *titre = tex_text("./Police_ttf/police.ttf",80,"Yathzee",noir,renderer);


    SDL_QueryTexture(titre, NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));
    txtDestRect.x = 1080/2-txtDestRect.w/2;
    txtDestRect.y = 20;

    SDL_Texture *background = tex_img_png("./IMAGE/table_jeu.png", renderer);
    
    if( pWindow )
    {
        int running = 1; 
        while(running) { 
            
            SDL_Event e;
            SDL_GetMouseState(&x,&y);
            
         
            
            while(SDL_PollEvent(&e)) { 
                switch(e.type) { 
                    case SDL_QUIT: running = 0; 
                    break;
                    case SDL_WINDOWEVENT:

                    /*le fond*/
                        
                        imgBGRect.x = 0;
                        imgBGRect.y = 0;
                        imgBGRect.w = 1080;
                        imgBGRect.h = 650;
                        //SDL_QueryTexture(background, NULL, NULL, &(imgBGRect.w), &(imgBGRect.h));
                        SDL_RenderCopy(renderer, background, NULL, &imgBGRect); 

                        /* Ajout du texte en noir */
                        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

                        SDL_RenderCopy(renderer, titre, NULL, &txtDestRect);
                    
                        SDL_RenderPresent(renderer);
                    break;
                }
            } 
        }           
    }
    else {
        fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
    }
     //Destruction de la fenetre
    if(pWindow != NULL) SDL_DestroyWindow(pWindow);

    /*TTF_CloseFont(police);  Doit être avant TTF_Quit() */
    TTF_Quit();
    SDL_Quit();

    return 0;
}                
