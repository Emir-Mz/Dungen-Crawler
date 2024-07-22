#include<stdio.h>

void printa(int row, int col, char area[5][9]){

    for(int i = 0; i <= row; i++){
        for(int j = 0; j <= col; j++){
            printf("%c", area[i][j]);
        }
        printf("\n");
    }
}

void moveit(int row, int col, char input, int plxy[2], char area[5][9]){

    int temp[2];
    temp[0] = plxy[0];
    temp[1] = plxy[1];

    switch (input)
    {
    case 'w':
        if(area[plxy[0]-1][plxy[1]] == '.'){
            plxy[0] -= 1;
            area[temp[0]][temp[1]] = '.';
            area[plxy[0]][plxy[1]] = '@';
        }
        break;

    case 'a':
            if(area[plxy[0]][plxy[1]-1] == '.'){
            plxy[1] -= 1;
            area[temp[0]][temp[1]] = '.';
            area[plxy[0]][plxy[1]] = '@';
        }

        break;
    case 's':
            if(area[plxy[0]+1][plxy[1]] == '.'){
            plxy[0] += 1;
            area[temp[0]][temp[1]] = '.';
            area[plxy[0]][plxy[1]] = '@';
        }

        break;
    case 'd':
            if(area[plxy[0]][plxy[1]+1] == '.'){
            plxy[1] += 1;
            area[temp[0]][temp[1]] = '.';
            area[plxy[0]][plxy[1]] = '@';
        }

        break;
    default:
        break;
    }



}

int main(){

    char player = '@';

    int plxy[2] = {2, 4};
    int ext = 1;
    char input;
	
	char area[5][9] = {
                        {'#','#','#','#','#','#','#','#','#'},
                        {'#','.','.','.','.','.','.','.','#'},
                        {'#','.','.','.','.','.','.','.','#'},
                        {'#','.','.','.','.','.','.','.','#'},
                        {'#','#','#','#','#','#','#','#','#'}
                      };
    int row = (sizeof(area)/sizeof(area[0]))-1;
    int col = (sizeof(area[0])/sizeof(area[0][0]))-1;

    printf("%d", row);
    printf("%d", col);

    printa(row, col, area);
    printf("\n\n\n\n");

    

    area[plxy[0]][plxy[1]] = player;

    printa(row, col, area);

	while(ext == 1){
        printf("\n\n\n\n");
        printa(row, col, area);
        scanf(" %c", &input);
        switch (input)
        {
        case 'w':
            moveit(row, col, input, plxy,area);
            break;
        case 'a':
            moveit(row, col, input, plxy,area);
            break;
        case 's':
            moveit(row, col, input, plxy,area);
            break;
        case 'd':
            moveit(row, col, input, plxy,area);
            break;
        
        default:
            break;
        }
    }
	return 0;
}