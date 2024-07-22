#include<stdio.h>

void printa(int row, int col, char area[row+1][col+1]){

    for(int i = 0; i <= row; i++){
        for(int j = 0; j <= col; j++){
            switch (area[i][j])
            {
            case '#':
                printf("\x1b[33m%c\x1b[0m", area[i][j]);
                printf(" ");
                break;
            case '.':
                printf("\x1b[30m%c\x1b[0m", area[i][j]);
                printf(" ");
                break;
            case '@':
                printf("\x1b[36m%c\x1b[0m", area[i][j]);
                printf(" ");
                break;
            case '=':
                printf("%c", area[i][j]);
                printf(" ");
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




void moveit(int row, int col, char input, int plxy[2], char curarea[row+1][col+1], char area1[row+1][col+1], char area2[row+1][col+1], int areachec){

    int temp[2];
    temp[0] = plxy[0];
    temp[1] = plxy[1];

    switch (input)
    {
    case 'w':
        switch (curarea[plxy[0]-1][plxy[1]])
        {
        case '.':
            plxy[0] -= 1;
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

        break;

    case 'a':
        switch (curarea[plxy[0]][plxy[1]-1])
        {
        case '.':
            plxy[1] -= 1;
            curarea[temp[0]][temp[1]] = '.';
            curarea[plxy[0]][plxy[1]] = '@';
            break;
        case '=':
            switch (areachec)
            {
            case 1:
                areachec = 1;
                areacopy(row, col, area1, curarea);
                plxy[0] = temp[0];
                plxy[1] = 12;
                curarea[plxy[0]][plxy[1]] = '@';
                break;
            
            default:
                break;
            }
        default:
            break;
        }
        break;
    case 's':

        switch (curarea[plxy[0]+1][plxy[1]])
        {
        case '.':
            plxy[0] += 1;
            curarea[temp[0]][temp[1]] = '.';
            curarea[plxy[0]][plxy[1]] = '@';
            break;
        case '=':

        }

        break;
    case 'd':

        switch (curarea[plxy[0]][plxy[1]+1])
        {
        case '.':
            plxy[1] += 1;
            curarea[temp[0]][temp[1]] = '.';
            curarea[plxy[0]][plxy[1]] = '@';
            break;
        case '=':
            switch (areachec)
            {
            case 1:
                areachec = 2;
                areacopy(row, col, area2, curarea);
                plxy[0] = temp[0];
                plxy[1] = 1;
                curarea[plxy[0]][plxy[1]] = '@';
                break;
            
            default:
                break;
            }
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
        case 'w':
            moveit(row, col, input, plxy, curarea, area1, area2, areachec);
            break;
        case 'a':
            moveit(row, col, input, plxy, curarea, area1, area2, areachec);
            break;
        case 's':
            moveit(row, col, input, plxy, curarea, area1, area2, areachec);
            break;
        case 'd':
            moveit(row, col, input, plxy, curarea, area1, area2, areachec);
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