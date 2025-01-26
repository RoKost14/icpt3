#include <stdio.h>

char board[6][7];

void display(){
for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 7; j++) {
        printf("%s ", board[i][j]);
    }
}
}
