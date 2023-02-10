#include <iostream>
using namespace std;

// empty space elements on the board
char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
char token = 'x';
bool draw = false;
string p1 ="";
string p2 ="";

void display_board(){

//Renders Game Board LAYOUT
cout<<"  |      |   \n";
cout<<"  |      |   \n";
cout<<" "<< space[0][0] << "   |  " << space[0][1] << "   | " << space[0][2] << " \n";
cout<<" ____|______|____\n";
cout<<"     |      |   \n";
cout<<" " << space[1][0] << "   |  " << space[1][1] << "   | " << space[1][2] << "  \n";
cout<<" ____|______|___\n";
cout<<"     |      |   \n";
cout<<" " << space[2][0] << "   |  " << space[2][1] << "   | " << space[2][2] << "   \n";
cout<<"     |      |   \n";
}

void player_turn()
{
  int digit;

  if (token == 'x'){
    cout<<p1<<"Please enter";
    cin>>digit;
  }

  if (token == 'o'){
    cout<<p2<<"Please enter";
    cin>>digit;
  }

  if (digit == 1){
    row = 0;
    column = 0;
  }

  if (digit == 2){
    row = 0;
    column = 1;
  }

  if (digit == 3)
  {
    row = 0;
    column = 2;
  }
  if (digit == 4)
  {
    row = 1;
    column = 0;
  }
  if (digit == 5)
  {
    row = 1;
    column = 1;
  }
  if (digit == 6)
  {
    row = 1;
    column = 2;
  }
  if (digit == 7)
  {
    row = 2;
    column = 0;
  }
  if (digit == 8)
  {
    row = 2;
    column = 1;
  }
  if (digit == 9)
  {
    row = 2;
    column = 2;
  }
  else if(digit<1 || digit>9)
  {
    cout<<"Invalid !!"<<endl;
  }
  // here we are checking for any used space.
  if (token == 'x' && space[row][column] != 'x' && space[row][column] != 'o')
  {
    space[row][column] = 'x';
    token = 'o';
  }
  else if (token == 'o' && space[row][column] != 'x' && space[row][column] != 'o')
  {
    space[row][column] = 'o';
    token = 'x';
  }
  else
  {
    cout << "There is no empty space" << endl;
    player_turn();
  }
  display_board();
}

bool game(){
  for (int i = 0; i < 3; i++){
    if (space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i]){
      return true;
    }
  }
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0]){
        return true;
    }
      for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
          if (space[i][j] != 'x' && space[i][j] != 'o'){
            return false;
          }
        }

        //Checking the if game already draw
        draw = true;
        return false;
      }
}


int main()
{
  cout << "Enter the name of First player : \n";
  getline(cin, p1);
  cout << "Enter the name of Second player : \n";
  getline(cin, p2);
  cout << p1 << "is player1 so they will play first \n";
  cout << p2 << "is player2 so they will play second \n";

  while (!game())
  {
    display_board();
    player_turn();
    game();
  }

  if (token == 'x' && draw == false)
  {
    cout << p2 << "Wins!!" << endl;
  }
  else if (token == 'o' && draw == false)
  {
    cout << p1 << "Wins!!" << endl;
  }
  else
  {
    cout << "It's a draw" << endl;
  }
}
  
  
  
  
  
  
  
  
  

  
  
  
  
  
    
 
  
  

