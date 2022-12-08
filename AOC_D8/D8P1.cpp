#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

bool check_left(vector<int> tree_row, int index){
  bool visible = true;
  for (int i = 0; i < index;++i){
    if (tree_row[i]>=tree_row[index]){
      visible = false;
    }
  }
  return visible;
}

bool check_right(vector<int> tree_row, int index){
  bool visible = true;
  for (int i = index+1;i<tree_row.size();++i){
    if (tree_row[i]>=tree_row[index]){
      visible = false;
    }
  }
  return visible;
}

bool check_up(vector<vector<int>> trees,int row, int column){
  bool visible = true;
  for(int i = 0;i<row;i++){
    if(trees[i][column]>=trees[row][column]){
      visible = false;
    }
  }
  return visible;
}
bool check_down(vector<vector<int>> trees,int row, int column){
  bool visible = true;
  for(int i = row+1;i<trees.size();i++){
    if(trees[i][column]>=trees[row][column]){
      visible = false;
    }
  }
  return visible;
}
//No need to check first and last row since all are visible
int main(){
  string content;
  ifstream layout("input8.txt");
  int total = 0;
  int height = 0;
  vector<vector<int>> grid;
  while(getline(layout,content)){
    height+=1;
    vector<int> rows;
    for (int i = 0; i<content.length(); ++i){
      rows.push_back(content[i]-'0');
    }
    grid.push_back(rows);
  }
  int width = grid[0].size();
  total+=width*2+(height-2)*2;
  //cout<<total<<endl;
  int j = 1;
  while (j<grid.size()-1){
    for (int i = 1; i<grid[j].size()-1; ++i){
      if (check_left(grid[j],i)||check_right(grid[j],i)||check_up(grid,j,i)||check_down(grid,j,i)){
        //cout<<grid[j][i]<<"Row="<<j+1<<"index="<<i<<endl;
        total+=1;
      }
    }
    j+=1;
  }
  cout<<total<<endl;
}