#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main(){
  vector<string> gameData = {};
  ifstream gameMoves("input2.txt");
  string moves;
  int points = 0;
  
  while(getline(gameMoves,moves)){
    gameData.push_back(moves);
  }
  
  for(int i = 0; i<gameData.size(); ++i){
    char opp = gameData[i][0];
    char player = gameData[i][2];
    if (player == 'X'){
      if (opp == 'A'){
        points+=3;
      }else if(opp == 'B'){
        points+=1;
      }else if(opp == 'C'){
        points+=2;
      }
    }else if (player == 'Y'){
      points+=3;
      if (opp == 'A'){
        points+=1;
      }else if(opp == 'B'){
        points+=2;
      }else{
        points+=3;
      }
    }else if (player == 'Z'){
      points+=6;
      if (opp == 'A'){
        points+=2;
      }else if (opp == 'B'){
        points+=3;
      }else{
        points+=1;
      }
    }
  }
  cout<<points<<endl;
}