#include "tictac.h"

// ====================== PUBLIC FUNCTIONS ===================

// Constructor the tictac game
Tictac::Tictac()
{    
    // initialize the board with all empty chars
    initialBoard();

    // initialize two players
    _player1.initialPlayer('X', "player1");
    _player2.initialPlayer('O', "player2");
    _nextplayer = &_player1;
    _otherplayer = &_player2;

    // initialize the result
    _result = "Game is playing.";
}

// the main function to run the whole game
void Tictac::run()
{
    bool ends = false;
    // if the game is not ended by user, it will run forever
    while(!ends){
        // start the game
        do{
            displayBoard();
        }while(playerStep());

        displayBoard();

        // check the game result
        if(checkTie()){
            _result = "The game is tied!";
        }
        else{
            _result = _nextplayer->getName() + string(" wins!");
        }
        // output the game result
        cout<<endl<<"Game ends: "<<_result<<endl;

        // ask users whether play again
        char reset;
        cout<<endl<<"Do you want to play again? (Y/N)   ";
        cin>>reset;
        bool inputValid = false;

        // if the input is not valid, ask for input again
        while (!inputValid){
            // if play again, restart the game
            if(reset == _resetGame){
                initialBoard();
                _nextplayer = &_player1;
                _otherplayer = &_player2;
                _result = "Game is playing.";
                inputValid = true;
            }
            // if ends, set the signal and ends the loop
            else if(reset == _endGame){
                ends = true;
                inputValid = true;
            }
            // if the input is not valid, ask for input again
            else{
                cout<<endl<<"Input invalid. Try Again." <<endl;
                cout<<"Do you want to play again? (Y/N)   ";
                cin>>reset;
                inputValid = false;
            }
        }
    }
}

// display all the chars on the boards
void Tictac::displayBoard()
{
    cout<<"============================="<<endl;
    for(int i = 0;i < _size; i++){
        for(int j = 0;j < _size; j++){
            cout<<_board[i][j]<< " ";
        }
        cout<<endl;
    }
}

// ====================== PRIVATE FUNCTIONS ===================

// initialize the board with _initChar variable
void Tictac::initialBoard()
{
    for(int i = 0;i < _size; i++){
        for(int j = 0;j < _size; j++){
            _board[i][j] = _initChar;
        }
    }
}

// check whether the given row and col is valid on the board
bool Tictac::checkValid(int row, int col)
{
    return (row >= 0) and (row < _size) and (col >= 0) and (col < _size);
}

// check whether the given row and col is still available
bool Tictac::checkAvailable(int row, int col)
{
    return _board[row][col] == _initChar;
}

// change the given position on the board to the given symbol
void Tictac::writeOntoBoard(int row, int col, char symbol)
{
    _board[row][col] = symbol;
}

// switch the players turn
void Tictac::switchPlayerTurn()
{
    player* temp = _nextplayer;
    _nextplayer = _otherplayer;
    _otherplayer = temp;
}

// the main function for user's move
bool Tictac::playerStep()
{
    // initialize all the variables
    int row, col;
    char slash;
    bool writeSucceed = false;

    // get the first input information from users
    cout<<_nextplayer->getName()<<" : Which spot do you want to take?    ";
    cin>>slash>>row>>slash>>col>>slash;
    cout<<"("<<row<<","<<col<<")"<<endl;

    // use a while loop to check whether the input is valid or not
    while(!writeSucceed){
        // if the input row and col is valid, write the symbol
        if(checkValid(row, col) and checkAvailable(row,col)){
            cout<<"It is able to put here!"<<endl;
            writeOntoBoard(row, col, _nextplayer->getSymbol());
            writeSucceed = true;
        }
        // if the inputs are not valid, ask for input again
        else{
            cout<<"This spot is not good! Try again!"<<endl;
            cout<<_nextplayer->getName()<<" : Which spot do you want to take?    ";
            cin>>slash>>row>>slash>>col>>slash;
            cout<<"("<<row<<","<<col<<")"<<endl;
        }
    }

    // check whether game ties or someone wins
    if(checkWin() or checkTie()){
        cout<<"found the game ends!"<<endl;
        return false;
    }

    // switch the players turn
    switchPlayerTurn();
    return true;
}

// check whether someone wins the game
bool Tictac::checkWin()
{
    return checkRowWin() or checkColumnWin() or checkDiagnolWin();
}

// check whether there is winner on each row
bool Tictac::checkRowWin()
{
    char firstChar = _initChar;
    bool rowSame = true;
    for(int i = 0;i < _size; i++){
        firstChar = _board[i][0];
        rowSame = true;
        for(int j = 1;j < _size; j++){
            if(_board[i][j] != firstChar){
                rowSame = false;
            }
        }
        if(rowSame and (firstChar != _initChar)){
            return true;
        }
    }
    return false;
}

// check whether there is winner on each column
bool Tictac::checkColumnWin()
{
    char firstChar = _initChar;
    bool columnSame = true;
    for(int j = 0;j < _size; j++){
        firstChar = _board[0][j];
        columnSame = true;
        for(int i = 1;i < _size; i++){
            if(_board[i][j] != firstChar){
                columnSame = false;
            }
        }
        if(columnSame and (firstChar != _initChar)){
            return true;
        }
    }
    return false;
}

// check whether there is winner on the diagnoal line
bool Tictac::checkDiagnolWin()
{
    char firstChar = _board[0][0];
    for(int i = 1; i < _size; i++){
        if(_board[i][i] != firstChar){
            return false;
        }
    }
    if(firstChar != _initChar){
        return true;
    }
    return false;
}

// check whether the game ties
bool Tictac::checkTie()
{
    if(!checkWin()){
        for(int i = 0;i < _size; i++){
            for(int j = 0;j < _size; j++){
                if(_board[i][j] == _initChar){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}
