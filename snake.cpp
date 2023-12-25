#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> startGameBoard(int ROWS, int COLS); // init board 

void drawBoard(vector<vector<char>>);

class Head{
private: 
    int headXPos;
    int headYPos;
    char headDirection; // u, d, l, r

public:
    void move(){
        if (headDirection == 'u'){
            headYPos -= 1;
        }
        else if (headDirection == 'd'){
            headYPos += 1;
        }
        else if (headDirection == 'l'){
            headXPos -= 1;
        }
        else if (headDirection == 'r'){
            headXPos += 1; 
        }
    }

    Head(int xPos, int yPos, char dir); // constructor

    bool checkCollideWall(){
        return false;
    }

    int getHeadXPos(){
        return headXPos;
    }

    int getHeadYPos(){
        return headYPos;
    }

    void setHeadDirection(char dir){
        if (dir == 'u' || dir == 'd' || dir == 'l' || dir == 'r'){
            headDirection = dir;
        }
    }

    char getHeadDirection(){
        return headDirection;
    }
};

Head::Head(int xPos, int yPos, char dir){
    headXPos = xPos;
    headYPos = yPos; 
    headDirection = dir;
}

int main(){
    const int ROWS = 7;
    const int COLS = 7; 
    int numIterations = 0;
    vector<vector<char>> board = startGameBoard(ROWS, COLS);

        
    // init head
    Head head((ROWS/2), (COLS/2), 'l');

    bool running = true;
    while (running){

        char input;
        cin >> input;
        cout << endl;
        
        switch(input){
            case 'x':
                running = false;
                break;
            case 'u':
                head.setHeadDirection('u');
                break;
            case 'd':
                head.setHeadDirection('d');
                break;
            case 'l':
                head.setHeadDirection('l');
                break;
            case 'r':
                head.setHeadDirection('r');
                break;
        }

        head.move();
        board[head.getHeadYPos()][head.getHeadXPos()] = 'o';

        
        drawBoard(board);

        numIterations++;
        cout << "Number of iterations: " << numIterations << " | Direction: " << head.getHeadDirection() << " | Input: ";
        

        board[head.getHeadYPos()][head.getHeadXPos()] = 'x';
        

    
    }



}

vector<vector<char>> startGameBoard(const int ROWS, const int COLS){ // init board 

    vector<vector<char>> board(ROWS, vector<char>(COLS, 'x'));

    return board;
}

void drawBoard(vector<vector<char>> board){ // display board
    
    for (vector<char> row : board){
        for (char element : row){
            cout << element << " ";
        }
        cout << '\n';
    }

}