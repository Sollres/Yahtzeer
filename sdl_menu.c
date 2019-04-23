#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL_image.h>



int SDL_menu(void){

      int x,y;
      int i, j;

    TTF_Init();
    SDL_Window *pWindow = NULL;
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

    SDL_Texture *titre = tex_text("./Police_ttf/police.ttf",100,"Yathzee",noir,renderer);
    SDL_Texture *menu[3];
    menu[0] = tex_text("./Police_ttf/police.ttf", 50, "JOUEUR VS IA", noir, renderer);
    menu[1] = tex_text("./Police_ttf/police.ttf", 50, "JOUEUR VS JOUEUR", noir, renderer);
    menu[2] = tex_text("./Police_ttf/police.ttf", 50, "QuitZeR", noir, renderer);

    
    /*position du titre*/

    SDL_QueryTexture(titre, NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));
    txtDestRect.x = 1080/2-txtDestRect.w/2;
    txtDestRect.y = 20;
    
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
    SDL_Texture *bouton = tex_img_png("./IMAGE/bouton1.png", renderer);

    /*Image du bouton quand on passe dessus*/
    SDL_Texture *bouton_dessus = tex_img_png("./IMAGE/bouton2.png", renderer);

    SDL_Texture *temp;
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
                    case SDL_MOUSEBUTTONDOWN:
                        
                    // on a cliqué en (x,y)
            for(i = 0; i<3; i++){
                if(x>txtMenuRect[i].x&&x<txtMenuRect[i].x+txtMenuRect[i].w && y>txtMenuRect[i].y&&y<txtMenuRect[i].y+txtMenuRect[i].h){
                    fprintf(stderr, "on a cliqué sur le bouton %d\n", i+1);
                    if(i==2) running=0;
                }
            }   
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

                        /*Position du premier bouton*/
                        
                        imgBtnRect.x = 440;
                        imgBtnRect.y = 150;
                        SDL_QueryTexture(bouton_dessus, NULL, NULL, &(imgBtnRect.w), &(imgBtnRect.h));
                        
                        for(j=0;j<3;j++){

                            

                                temp = bouton_dessus;
                                if(e.type == SDL_MOUSEBUTTONDOWN){
                                    SDL_DestroyWindow(pWindow);
                                    
                                    return 0;
                                }
                        
                            else{
                                temp = bouton;
                            }
                            
                            SDL_RenderCopy(renderer, temp, NULL, &imgBtnRect);
                            SDL_RenderCopy(renderer, menu[i], NULL, &(txtMenuRect[i]));
                            imgBtnRect.y += 90;
                        
                        }
                        
                                
                        /* On fait le rendu ! */
                        SDL_RenderPresent(renderer);
                        break;

                } 
            } 
        }
    } else {
        fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
    }

    //Destruction de la fenetre
    if(pWindow != NULL) SDL_DestroyWindow(pWindow);
    
    /*TTF_CloseFont(police);  Doit être avant TTF_Quit() */
    TTF_Quit();
    SDL_Quit();
    return 0;
}
