#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL_image.h>


int menu_SDL(void){

    int x,y;
    int i, j;

    SDL_wINDOW *pwindow = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Rect txtDestRect, txtMenuRect[3], imgBtnRect, imgBGRect;
    
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

    SDL_Texture *titre = tex_text("./Police_ttf/police.ttf",100,"YathzeeR",noir,renderer);
    SDL_Texture *menu[3];
    menu[0] = tex_text("./Police_ttf/police.ttf", 50, "JOUEUR VS IA", noir, renderer);
    menu[1] = tex_text("./Police_ttf/police.ttf", 50, "JOUEUR VS JOUEUR", noir, renderer);
    menu[2] = tex_text("./Police_ttf/police.ttf", 50, "QuitZeR", noir, renderer);

    
    /*position du titre*/

    txtDestRect.x = 400;
    txtDestRect.y = 20;
    SDL_QueryTexture(titre, NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));

    /*le menu*/

    for(i = 0; i<3; i++){

        if(i == 2 ){

            txtMenuRect[i].x = 480;
        }

        else{

            txtMenuRect[i].x = 500;
        }

        txtMenuRect[i].y = 165 + 90 * i;

        SDL_QueryTexture(menu[i], NULL, NULL, &(txtMenuRect[i].w), &(txtMenuRect[i].h));
    }

    /*Image de fond : background*/
    SDL_Texture *background = tex_img_png("./IMAGE/background.png", renderer);

    /*Image pour les bouton*/
    SDL_Texture *bouton = tex_img_png("./IMAGE/bouton.png", renderer);

    /*Image du bouton quand on passe dessus*/
    SDL_Texture *bouton_dessus = tex_img_png("./IMAGE/bouton_dessus", renderer);

    SDL_Texture *temp;
    if( pWindow )
    {
        int running = 1; 
        while(running) { 
            
            SDL_Event e;
            SDL_GetMouseState(&x,&y);
            
            if(x<700 && x>385 && y<526 && y>130){
                    goto aff_Menu;

            } 
            
            while(SDL_PollEvent(&e)) { 
                switch(e.type) { 
                    case SDL_QUIT: running = 0; 
                    break;
                    case SDL_MOUSEBUTTONDOWN;
                        if(x>1000 && x<1000+82 && y>570 && y<570+80) 
                    case SDL_WINDOWEVENT:

                    aff_Menu :
                        /* Le fond de la fenêtre sera blanc 
                        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                        SDL_RenderClear(renderer);*/

                        /*le fond*/
                        
                        imgBGRect.x = 0;
                        imgBGRect.y = 0; 
                        SDL_QueryTexture(background, NULL, NULL, &(imgBGRect.w), &(imgBGRect.h));
                        SDL_RenderCopy(renderer, background, NULL, &imgBGRect);        
                        
                         /* Ajout du texte en noir */
                        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

                        SDL_RenderCopy(renderer, titre, NULL, &txtDestRect);

                        /*Position du premier bouton*/
                        
                        imgBtnRect.x = 440;
                        imgBtnRect.y = 150;
                        SDL_QueryTexture(bouton_dessus, NULL, NULL, &(imgBtnRect.w), &(imgBtnRect.h));
                        for(j=0;j<3;j++){

                            if(x<620 && x>440 && y<imgBtnRect.y+77 && imgBtnRect.y<y){

                                temp = bouton_dessus;
                                if(e.type == SDL_MOUSEBUTTONDOWN){
                                    SDL_DestroyWindow(pWindow);
                                    //lancer_jeu(j);
                                    return 0;
                                }
                            }
                            else{
                                
                            }
                        }





                        /* Ajout de la seconde image à une certaine position */
                        imgDestRect.x = 10;
                        imgDestRect.y = 50;
                        SDL_QueryTexture(image_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
                        SDL_RenderCopy(renderer, image_tex, NULL, &imgDestRect);
                                
                        /* Ajout de la seconde image à une autre position */
                        imgDestRect.x = 250;
                         SDL_RenderCopy(renderer, image_tex, NULL, &imgDestRect);
                                
                        /* On fait le rendu ! */
                        SDL_RenderPresent(renderer);
                                
                            break;
                        }
                    break;
                } 
            } 
        }
    } else {
        fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
    }

    //Destruction de la fenetre
    SDL_DestroyWindow(pWindow);

    TTF_CloseFont(police); /* Doit être avant TTF_Quit() */
    TTF_Quit();
    SDL_Quit();
}