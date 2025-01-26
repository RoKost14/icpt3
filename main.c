#include <stdio.h>
#include <stdbool.h>


char *board[6][7];

void initializeBoard() {
    for (int row = 0; row < 6; row++) {
        for (int col = 0; col < 7; col++) {
            board[row][col] = NULL;
        }
    }
}

int movePlayer1() {
    int column;

    printf("Kies kolom voor speler: * ");
    scanf("%d", &column);

    return column;
}

int movePlayer2() {
    int column;

    printf("Kies kolom voor speler: ^ ");
    scanf("%d", &column);

    return column;
}

void addMoveToBoard(char playerChar, int column) {
    char *playerSymbol = playerChar == '*' ? "*" : "^";

    for (int row = 5; row >= 0; row--) {
        if (board[row][column] == NULL) {
            board[row][column] = playerSymbol;
            break;
        }
    }
}

void displayBoard() {
    printf("0 1 2 3 4 5 6 \n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == NULL) {
                printf("0 ");
            } else {
                printf("%s ", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("0 1 2 3 4 5 6 \n");
}

void checkForWin(char symbol) {
    // Check voor horizontal win
    for (int row = 0; row < 6; row++) {
        for (int col = 0; col < 4; col++) {
            if (board[row][col] != NULL && *board[row][col] == symbol &&
                board[row][col + 1] != NULL && *board[row][col + 1] == symbol &&
                board[row][col + 2] != NULL && *board[row][col + 2] == symbol &&
                board[row][col + 3] != NULL && *board[row][col + 3] == symbol) {
                // Verwijder de rij die gewonnen heeft
                for (int i = 0; i < 4; i++) {
                    board[row][col + i] = NULL;
                }
                // Laat de bovenliggende stenen naar beneden vallen
                for (int i = col; i < col + 4; i++) {
                    for (int j = row; j > 0; j--) {
                        board[j][i] = board[j - 1][i];
                        board[j - 1][i] = NULL;
                    }
                }
                return;
            }
        }
    }

    // Check voor verticale win
    for (int col = 0; col < 7; col++) {
        for (int row = 0; row < 3; row++) {
            if (board[row][col] != NULL && *board[row][col] == symbol &&
                board[row + 1][col] != NULL && *board[row + 1][col] == symbol &&
                board[row + 2][col] != NULL && *board[row + 2][col] == symbol &&
                board[row + 3][col] != NULL && *board[row + 3][col] == symbol) {
                for (int i = 0; i < 4; i++) {
                    board[row + i][col] = NULL;
                }

                return;
            }
        }
    }
}


int main() {
    do {
        displayBoard();
        addMoveToBoard('*', movePlayer1());
        checkForWin('*');

        displayBoard();
        addMoveToBoard('^', movePlayer2());
        checkForWin('^');
    } while (1);
}
