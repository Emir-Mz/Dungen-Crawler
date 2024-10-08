#include<stdio.h>
#include<stdlib.h>
#include"getchar.h"
#include"arealib.h"
#include"health.h"
#include<unistd.h>

void save_screen() {
    system("tput smcup"); 
}

void restore_screen() {
    system("tput rmcup"); 
}

char getCharWithoutEnter();

void printa(int row, int col, char area[5][5][10][16], int curent[2]){

    for(int i = 0; i <= 9; i++){
        printf("\r");
        printf("\t");
        for(int j = 0; j <= 15; j++){
            switch (area[curent[0]][curent[1]][i][j])
            {
            case '#':
                printf("\x1b[33m%c \x1b[0m", area[curent[0]][curent[1]][i][j]);//yellow
                break;
            case '.':
                printf("\x1b[30m%c \x1b[0m", area[curent[0]][curent[1]][i][j]);//black
                break;
            case '@':
                printf("\x1b[36m%c \x1b[0m", area[curent[0]][curent[1]][i][j]);//cyan
                break;
            case '=':
                printf("%c ", area[curent[0]][curent[1]][i][j]);//nothing
                break;
            case '^':
                printf("\x1b[31m%c \x1b[0m", area[curent[0]][curent[1]][i][j]);
                break;
            case '1':
                printf("\x1b[35m# \x1b[0m");
                break;
            default:
                break;
            }
        }
        if (i < 9)
        {
            printf("\n");
        }
    }
    printf("\n\n\n");
    for (int i = 0; i < 12; i++)
    {
        printf("\033[F");
    }
    

}



void moveit(int inptx, int inpty, int areainptx, int areainpty, int bar, int plxy[2], char area[5][5][10][16], int curent[2]){

    int temp[2];
    temp[0] = plxy[0];
    temp[1] = plxy[1];

    switch (area[curent[0]][curent[1]][plxy[0]+inptx][plxy[1]+inpty])
    {
    case '.':
        plxy[0] += inptx;
        plxy[1] += inpty;
        area[curent[0]][curent[1]][temp[0]][temp[1]] = '.';
        area[curent[0]][curent[1]][plxy[0]][plxy[1]] = '@';
        break;

    case '=':
        
        area[curent[0]][curent[1]][temp[0]][temp[1]] = '.';
        plxy[0] += areainptx;
        plxy[1] += areainpty;
        curent[0] += inptx;
        curent[1] += inpty;
        area[curent[0]][curent[1]][temp[0]][temp[1]] = '.';
        area[curent[0]][curent[1]][plxy[0]][plxy[1]] = '@';
        break;

    case '1':
        
        switch (area[curent[0]][curent[1]][plxy[0]+inptx*2][plxy[1]+inpty*2]){

            case '.':
        
            plxy[0] += inptx;
            plxy[1] += inpty;
            area[curent[0]][curent[1]][temp[0]][temp[1]] = '.';
            area[curent[0]][curent[1]][plxy[0]][plxy[1]] = '@';
            area[curent[0]][curent[1]][plxy[0]+inptx][plxy[1]+inpty] = '1';
            break;
        }
        break;

    default:
        break;
    }

}

int main(){

    int plxy[2] = {2, 4};
    int ext = 1;
    char input;
    int areachec = 1;

    int bar = 4;
    int max = 10;

    char area[5][5][10][16];
    arealib(area);

    int curent[2] = {0, 0};
  
    int row = (sizeof(area)/sizeof(area[0]))-1;
    int col = (sizeof(area[0])/sizeof(area[0][0]))-1;
    
    area[curent[0]][curent[1]][plxy[0]][plxy[1]] = '@';
    save_screen();

	while(ext == 1){
        printa(row, col, area, curent);
        //health(bar, max);
        //printf("\nx%d y%d\n", plxy[0], plxy[1]); 
        input = getCharWithoutEnter();
        switch (input)
        {
        case 'w'://this is a mess of arguments
            moveit(-1, 0, 7, 0, bar, plxy, area, curent);
            break;
        case 'a':
            moveit(0, -1, 0, 13, bar, plxy, area, curent);
            break;
        case 's':
            moveit(1, 0, -7, 0, bar, plxy, area, curent);
            break;
        case 'd':
            moveit(0, 1, 0, -13, bar, plxy, area, curent);
            break;
        case 'b':
            ext = 0;
            restore_screen(0);
            break;
        
        default:
            break;
        }
    }
	return 0;
}