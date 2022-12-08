#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

int check_left(vector<int> tree_row, int index){
  int score = 0;
  for (int i = index-1; i >= 0;--i){
    if (tree_row[i]<tree_row[index]){
      score += 1;
    }else{
      score+=1;
      return score;
    }
  }
  return score;
}

int check_right(vector<int> tree_row, int index){
  int score = 0;
  for (int i = index+1;i<tree_row.size();++i){
    if (tree_row[i]<tree_row[index]){
          score += 1;
        }else{
          score+=1;
          return score;
      }
  }
  return score;
}
int check_up(vector<vector<int>> trees,int row, int column){
  int score = 0;
  for(int i = row-1;i>=0;--i){
    if(trees[i][column]<trees[row][column]){
      score+= 1;
    }else{
      score+=1;
      return score;
    }
  }
  return score;
}
int check_down(vector<vector<int>> trees,int row, int column){
  int score = 0;
  for(int i = row+1;i<trees.size();i++){
    if(trees[i][column]<trees[row][column]){
      score += 1;
    }else{
      score+=1;
      return score;
    }
  }
  return score;
}
//No need to check first and last row since all are visible
int main(){
  string content;
  ifstream layout("input8.txt");
  int max = 0;
  int height = 0;
  int temp_score;
  vector<vector<int>> grid;
  while(getline(layout,content)){
    height+=1;
    vector<int> rows;
    for (int i = 0; i<content.length(); ++i){
      rows.push_back(content[i]-'0');
    }
    grid.push_back(rows);
  }
  //cout<<check_left(grid[1],2)*check_right(grid[1],2)*check_up(grid,1,2)*check_down(grid,1,2)<<endl;
  int j = 0;

  while (j<grid.size()){
    for (int i = 1; i<grid[j].size(); ++i){
      temp_score = check_left(grid[j],i)*check_right(grid[j],i)*check_up(grid,j,i)*check_down(grid,j,i);
      if (temp_score>max){
        max = temp_score;
      }else{
        temp_score = 0;
      }
    }
    j+=1;
  }
  cout<<max<<endl;
}