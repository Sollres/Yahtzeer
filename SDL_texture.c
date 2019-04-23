#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL_image.h>

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

