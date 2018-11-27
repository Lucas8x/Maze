#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int x,y, fim=0, selected=0, cursor=1;
int cX, cY, oldX, oldY;

void gotoxy(int x, int y){
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

char selectMap[20][50] ={
"#################################################",
"#                                               #",
"#                                               #",
"#                                               #",
"#                                               #",
"#                                               #",
"#                                               #",
"#                                               #",
"#                                               #",
"#                                               #",
"#                                               #",
"#                                               #",
"#                                               #",
"#                                               #",
"#                                               #",
"#                                               #",
"#                                               #",
"#                                               #",
"#                                               #",
"#################################################"};

//20 linhas(y) 50 colunas(x)
char mapaA[20][50] ={
"#################################################",
"#   #####          # #    ##                    #",
"#   #   #   ##     # #    ##    ###        #### #",
"#   #####   ##            ##    ###        #  # #",
"#           ##     ###    ##               #### #",
"#   ####            ###   ####     #####        #",
"#    ##       ###  ###    ####     #####        #",
"#   #  #      ###   ###                         #",
"#    ##            ###     #    ##    ##        #",
"#      ##  ##       ###      #       ###      ###",
"####   # ## #      ###     #      ##          ###",
"####   ##  ##       ###      #     ##         ###",
"#              ##  ###     #       ####         #",
"#   #########       ##      #         ##        #",
"#   #       #                   ##    ##        #",
"#   #       #                     #    ####   ###",
"#   #       #  ##    # # # # #         #  #   * #",
"#   #########       # # # # # #  ##    ####   ###",
"#              ##                ##     ##      #",
"#################################################"};

char mapaB[20][50] ={
"#################################################",
"#                                               #",
"#                          #                    #",
"#     #           #                      #      #",
"#  *                 #                          #",
"#                              #  #             #",
"#                                       #       #",
"#                                               #",
"#  #            #           #       #           #",
"#                                               #",
"#                #                              #",
"#            #                      #           #",
"#                                               #",
"#          #            #   #                   #",
"#     #                                         #",
"#                                               #",
"#                    #               #          #",
"#                                             * #",
"#      #                                        #",
"#################################################"};

char mapaC[19][50]={
"#################################################",
"#   #         #     #     #       #             #",
"### # ### ##### # # # ### ### ##### ####### ### #",
"#   #   #   #   # #   # #     #   # #     # #   #",
"# ##### ### # ### ##### # ##### # # ##### # #####",
"# #   # # # #   #   #   # #     # #     # #     #",
"# # # # # # # ##### # ### # ##### ##### # ##### #",
"#   #   # #   #     #     #     #   #   #     # #",
"# ####### ##### ##### ######### ### # ##### # # #",
"#     #   #   # #   # # #   #     # # #     # # #",
"##### # # # ### ### # # # # # ##### # # ##### ###",
"# #   # # #   #   #     # #   #     #   #     # #",
"# # ### # ### ### ##### # ##### ### ##### ##### #",
"# # #   #   #   #     # #   # #   #     # #     #",
"# # ### ### # # ##### # ### # ### ##### # # ### #",
"#   #   #   # # #   # #   # #   #     # # # # # #",
"# ### ### ### # # # # ##### # # ##### ### # # # #",
"#     #       #   # #         #     #       #   #",
"#########################*#######################"};

void printMapSelect(){
  for(y=0;y<20;y++) { //linha(y)
    for(x=0;x<50;x++) { //coluna(x)
      printf("%c",selectMap[y][x]);
    }
    printf("\n");
  }
  gotoxy(19,5); printf("M A Z E");
  gotoxy(19,10); printf("World 1");
  gotoxy(19,11); printf("World 2");
  gotoxy(19,12); printf("World 3");
}

void mapSelector(){
  if(GetAsyncKeyState(VK_UP)){
    if(cursor > 1 && cursor <= 3) cursor--; }
  if(GetAsyncKeyState(VK_DOWN)){
    if(cursor >= 1 && cursor < 3) cursor++; }

  gotoxy(16,10); printf("  "); gotoxy(27,10); printf("  ");
  gotoxy(16,11); printf("  "); gotoxy(27,11); printf("  ");
  gotoxy(16,12); printf("  "); gotoxy(27,12); printf("  ");

  //gotoxy(2,2); printf("Cursor: %d ", cursor);

  switch(cursor){
    case 1: gotoxy(16,10); printf(">>"); gotoxy(27,10); printf("<<"); break;
    case 2: gotoxy(16,11); printf(">>"); gotoxy(27,11); printf("<<"); break;
    case 3: gotoxy(16,12); printf(">>"); gotoxy(27,12); printf("<<"); break;
  }
  gotoxy(0,0);
  if(GetAsyncKeyState(VK_RETURN)){selected = 1;}
}

void printMap(){
  switch(cursor){
    case 1: {
      cX=2, cY=2, oldX=1, oldY=1;
      for(y=0;y<20;y++) { //linha(y)
        for(x=0;x<50;x++) { //coluna(x)
          printf("%c",mapaA[y][x]);
        }
        printf("\n");
      }
    } break;
    case 2: {
      cX=2, cY=2, oldX=1, oldY=1;
      for(y=0;y<20;y++) { //linha(y)
        for(x=0;x<50;x++) { //coluna(x)
          printf("%c",mapaB[y][x]);
        }
        printf("\n");
      }
    } break;
    case 3: {
      cX=25, cY=1, oldX=1, oldY=1;
      for(y=0;y<19;y++) { //linha(y)
        for(x=0;x<50;x++) { //coluna(x)
          printf("%c",mapaC[y][x]);
        }
        printf("\n");
      }
    } break;
  }
}

void controles(){
  if(GetAsyncKeyState(VK_ESCAPE)){
    system("CLS");
    selected = 0;
    //cursor = 1;
    main();
  }

  gotoxy(cX, cY);
  switch(cursor){
    case 1: {
      if(GetAsyncKeyState(VK_RIGHT)){
        if(mapaA[cY][cX+1] != '#'){ oldX = cX; oldY = cY; cX++; }
      }
      else if(GetAsyncKeyState(VK_LEFT)){
        if(mapaA[cY][cX-1] != '#'){ oldX = cX; oldY = cY; cX--; }
      }
      else if(GetAsyncKeyState(VK_UP)){
        if(mapaA[cY-1][cX] != '#'){ oldY = cY; oldX = cX; cY--; }
      }
      else if(GetAsyncKeyState(VK_DOWN)){
        if(mapaA[cY+1][cX] != '#'){ oldY = cY; oldX = cX; cY++; }
      }
    } break;
    case 2: {
      if(GetAsyncKeyState(VK_RIGHT)){
        if(mapaB[cY][cX+1] != '#'){ oldX = cX; oldY = cY; cX++; }
      }
      else if(GetAsyncKeyState(VK_LEFT)){
        if(mapaB[cY][cX-1] != '#'){ oldX = cX; oldY = cY; cX--; }
      }
      else if(GetAsyncKeyState(VK_UP)){
        if(mapaB[cY-1][cX] != '#'){ oldY = cY; oldX = cX; cY--; }
      }
      else if(GetAsyncKeyState(VK_DOWN)){
        if(mapaB[cY+1][cX] != '#'){ oldY = cY; oldX = cX; cY++; }
      }
    } break;

    case 3: {
      if(GetAsyncKeyState(VK_RIGHT)){
        if(mapaC[cY][cX+1] != '#'){ oldX = cX; oldY = cY; cX++; }
      }
      else if(GetAsyncKeyState(VK_LEFT)){
        if(mapaC[cY][cX-1] != '#'){ oldX = cX; oldY = cY; cX--; }
      }
      else if(GetAsyncKeyState(VK_UP)){
        if(mapaC[cY-1][cX] != '#'){ oldY = cY; oldX = cX; cY--; }
      }
      else if(GetAsyncKeyState(VK_DOWN)){
        if(mapaC[cY+1][cX] != '#'){ oldY = cY; oldX = cX; cY++; }
      }
    } break;
  }

  /*Chega se esta no final*/
  switch(cursor){
    case 1: if(mapaA[cY][cX] == '*') fim = 1; break;
    case 2: if(mapaB[cY][cX] == '*') fim = 1; break;
    case 3: if(mapaC[cY][cX] == '*') fim = 1; break;
  }

  change_pos();
}

void change_pos(){
  switch(cursor){
    case 1: {
      mapaA[cY][cX] = '@';
      mapaA[oldY][oldX] = ' ';
    } break;

    case 2: {
      mapaB[cY][cX] = '@';
      mapaB[oldY][oldX] = ' ';
    } break;

    case 3: {
      mapaC[cY][cX] = '@';
      mapaC[oldY][oldX] = ' ';
    } break;

  }
  update_map();
}

void update_map(){
  gotoxy(oldX, oldY);
  switch(cursor){
    case 1: printf("%c", mapaA[oldY][oldX]); break;
    case 2: printf("%c", mapaB[oldY][oldX]); break;
    case 3: printf("%c", mapaC[oldY][oldX]); break;
  }
  gotoxy(cX, cY);
  switch(cursor){
    case 1: printf("%c", mapaA[cY][cX]); break;
    case 2: printf("%c", mapaB[cY][cX]); break;
    case 3: printf("%c", mapaC[cY][cX]); break;
  }
  screenPos();
}

void screenPos(){
    gotoxy(0, 21); printf("Pos X: %d  Pos Y: %d  \nold X: %d  old Y: %d  \n", cX, cY, oldX, oldY);
}

void printPlayAgain(){
  switch(cursor){
    case 1: if(mapaA[cY][cX] = '*') break;
    case 2: if(mapaB[cY][cX] = '*') break;
    case 3: if(mapaC[cY][cX] = '*') break;
  }
  cursor = 1;
  for(y=0;y<20;y++) { //linha(y)
    for(x=0;x<50;x++) { //coluna(x)
      printf("%c",selectMap[y][x]);
    }
    printf("\n");
  }
  gotoxy(19,5); printf("M A Z E");
  gotoxy(10,7); printf("Parabéns você chegou ao final");
  gotoxy(16,8); printf("Jogar Novamente?");
  gotoxy(21,10); printf("Sim");
  gotoxy(21,11); printf("Não");
}

void playAgain(){
  gotoxy(0,0);
  if(GetAsyncKeyState(VK_UP)){
    if(cursor > 1 && cursor <= 2) cursor--; }
  if(GetAsyncKeyState(VK_DOWN)){
    if(cursor >= 1 && cursor < 2) cursor++; }

  gotoxy(18,10); printf("  "); gotoxy(25,10); printf("  ");
  gotoxy(18,11); printf("  "); gotoxy(25,11); printf("  ");

  //gotoxy(2,2); printf("Cursor: %d ", cursor);

  switch(cursor){
    case 1: gotoxy(18,10); printf(">>"); gotoxy(25,10); printf("<<"); break;
    case 2: gotoxy(18,11); printf(">>"); gotoxy(25,11); printf("<<"); break;
  }
  gotoxy(0,0);
  if(GetAsyncKeyState(VK_RETURN)){
    switch(cursor){
      case 1: { selected = 0; fim = 0; main(); } break;
      case 2: { selected = 0; } break;
    }
  }
}

int main(void) {
  setlocale(LC_ALL, "Portuguese");

  //Seletor de Mapas
  printMapSelect();
  do {
    mapSelector();
    Sleep(55);
  } while (selected != 1);

  system("CLS");

  //O Jogo
  printMap();
  gotoxy(0, 24); printf("Pressione ESC para voltar a seleção\n\n");
  do {
    controles();
    Sleep(55);
  } while(fim != 1);

  system("CLS");

  //Try Again
  printPlayAgain();
  do {
    playAgain();
    Sleep(55);
  } while (selected != 0);

  return 0;
}
