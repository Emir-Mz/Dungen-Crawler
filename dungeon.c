#include<stdio.h>

void printa(int row, int col, char area[row+1][col+1]){

    for(int i = 0; i <= row; i++){
        for(int j = 0; j <= col; j++){
            switch (area[i][j])
            {
            case '#':
                printf("\x1b[33m%c\x1b[0m", area[i][j]);
                printf(" ");//yellow
                break;
            case '.':
                printf("\x1b[30m%c\x1b[0m", area[i][j]);
                printf(" ");//black
                break;
            case '@':
                printf("\x1b[36m%c\x1b[0m", area[i][j]);
                printf(" ");//cyan
                break;
            case '=':
                printf("%c", area[i][j]);
                printf(" ");//nothing
                break;
            default:
                break;
            }
        }
        printf("\n");
    }
}

void areacopy(int row, int col, char areain[9][14], char areaout[9][14]){

    for(int i = 0; i <= row; i++){
        for (int j = 0; j <= col; j++)
        {
            areaout[i][j] = areain[i][j];
        }
        
    }
}

void areahandel(){

}

//WOW i was able to cut this down soooo muck nw i just need to make a area handeler func
void moveit(int row, int col, char input,int inptx, int inpty, int plxy[2], char curarea[row+1][col+1], char area1[row+1][col+1], char area2[row+1][col+1], int areachec){
//ABSOLUTE MOUNTAIN OF ARGUMENTS HELP!!!
    int temp[2];
    temp[0] = plxy[0];
    temp[1] = plxy[1];

    switch (curarea[plxy[0]+inptx][plxy[1]+inpty])
    {
    case '.':
        plxy[0] += inptx;
        plxy[1] += inpty;
        curarea[temp[0]][temp[1]] = '.';
        curarea[plxy[0]][plxy[1]] = '@';
        break;
    case '=':
        switch (areachec)
        {
        case 1:
            
            break;
        
        default:
            break;
        }
    default:
        break;
    }
    /*switch (areachec)
            {
            case 1:
                areachec = 1;
                areacopy(row, col, area1, curarea);
                plxy[0] = temp[0];
                plxy[1] = 12;
                curarea[plxy[0]][plxy[1]] = '@';
                break;
    switch (areachec)
            {
            case 1:
                areachec = 2;
                areacopy(row, col, area2, curarea);
                plxy[0] = temp[0];
                plxy[1] = 1;
                curarea[plxy[0]][plxy[1]] = '@';
                break;
    */
}

int main(){

    int plxy[2] = {2, 4};
    int ext = 1;
    char input;
    int areachec = 1;

    char curarea[9][14];

	char area1[9][14] = {
                        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                        {'#','.','.','.','.','.','.','.','.','.','.','.','.','#'},
                        {'#','.','.','.','.','.','.','.','.','.','.','.','.','='},
                        {'#','.','.','.','.','.','.','.','.','.','.','.','.','='},
                        {'#','.','.','.','.','.','.','.','.','.','.','.','.','#'},
                        {'#','.','.','#','.','.','.','.','.','.','.','.','.','#'},
                        {'#','.','.','#','.','.','.','.','.','.','.','.','.','#'},
                        {'#','.','.','#','.','.','.','.','.','.','.','.','.','#'},
                        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
                      };

    char area2[9][14] = {
                        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                        {'#','.','.','#','.','.','.','.','.','.','.','.','.','#'},
                        {'=','.','.','#','.','.','.','.','.','.','.','.','.','#'},
                        {'=','.','.','#','.','.','.','.','.','.','.','.','.','#'},
                        {'#','.','.','#','#','.','.','.','.','.','.','.','.','#'},
                        {'#','.','.','.','.','.','.','.','.','.','.','.','.','#'},
                        {'#','.','.','.','.','.','.','.','.','.','.','.','.','#'},
                        {'#','.','.','.','.','.','.','.','.','.','.','.','.','#'},
                        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
                      };
    //will move this to another file to not waste space
    
    int rowa = (sizeof(area1)/sizeof(area1[0]))-1;
    int cola = (sizeof(area1[0])/sizeof(area1[0][0]))-1;
    
    areacopy(rowa, cola, area1, curarea);

    int row = (sizeof(curarea)/sizeof(curarea[0]))-1;
    int col = (sizeof(curarea[0])/sizeof(curarea[0][0]))-1;

    printf("%d", row);
    printf("%d", col);

    printa(row, col, area1);
    printf("\n\n\n\n");

    

    curarea[plxy[0]][plxy[1]] = '@';

    printa(row, col, area1);

	while(ext == 1){
        printf("\n\n\n\n\n\n\n\n");
        printa(row, col, curarea);
        printf("x%d y%d\n", plxy[0], plxy[1]); 
        scanf(" %c", &input);
        switch (input)
        {
        case 'w'://this is a mess of arguments
            moveit(row, col, input, -1, 0, plxy, curarea, area1, area2, areachec);
            break;
        case 'a':
            moveit(row, col, input, 0, -1, plxy, curarea, area1, area2, areachec);
            break;
        case 's':
            moveit(row, col, input, 1, 0, plxy, curarea, area1, area2, areachec);
            break;
        case 'd':
            moveit(row, col, input, 0, 1, plxy, curarea, area1, area2, areachec);
            break;
        case 'b':
            ext = 0;
            break;
        
        default:
            break;
        }
    }
	return 0;
}