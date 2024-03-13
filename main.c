#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "menu.h"

int main(int argc, char** argv) {
    SDL_Surface *ecran = NULL;
    menu themenu;
    background back;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Echec d'initialisation de SDL : %s\n", SDL_GetError());
        return 1;
    } else {
        printf("Bonjour le monde, SDL est initialisé avec succès.\n");
    }

    ecran = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (ecran == NULL) {
        fprintf(stderr, "Echec de creation de la fenetre : %s.\n", SDL_GetError());
        return 1;
    }
  initialiser_menu(&themenu);
  afficher_menu(&themenu,ecran);
  liberer_menu(&themenu,&back);

    SDL_Quit();
  

    return 0;
}

