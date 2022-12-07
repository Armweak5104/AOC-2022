#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main(){
  //Wasnt sure how to get the data so I hard coded it
  vector<vector<char>> organization = {{'R','N','P','G'},{'T','J','B','L','C','S','V','H'},{'T','D','B','M','N','L'},{'R','V','P','S','B'},{'G','C','Q','S','W','M','V','H'},{'W','Q','S','C','D','B','J'},{'F','Q','L'},{'W','M','H','T','D','L','F','V'},{'L','P','B','V','M','J','F'}};
  string content;
  ifstream crane("input5.txt");
  int vol;
  int start;
  int dest;
  string msg = "";
  while(getline(crane,content)){
    if (content[0]=='m'){
      vol = stoi(content.substr(content.find('e')+1,content.find('f')-content.find('e')-1));
      start = stoi(content.substr(content.find('f')+5,content.find('t')-content.find('f')-5));
      dest = stoi(content.substr(content.length()-1));
      dest -=1;
      start-=1;
      int x = organization[start].size()-1;
      for (int i = x; i>x-vol; --i){
          organization[dest].push_back(organization[start][i]); 
      }
      for(int i = x; i>x-vol; --i){
          organization[start].pop_back();
      }
    }
  }
  for (int i = 0; i< organization.size(); i++){
   msg+=organization[i][organization[i].size()-1];
  }
  cout<<msg<<endl;
}
