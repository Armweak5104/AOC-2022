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
      points+=1;
      if (opp == 'A'){
        points+=3;
      }else if(opp == 'C'){
        points+=6;
      }
    }else if (player == 'Y'){
      points+=2;
      if(opp == 'A'){
        points+=6;
      }else if(opp == 'B'){
        points+=3;
      }
    }else if (player == 'Z'){
      points+=3;
      if (opp == 'B'){
        points+=6;
      }else if(opp == 'C'){
        points+=3;
      }
    }
  }
  cout<<points<<endl;
}