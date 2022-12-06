#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// lowercase --> ASCII - 96
// Uppercase --> ASCII - 38
int main() {
  vector<string> elves = {};
  vector <char> common = {};
  ifstream data("input3.txt");
  string content;
  string e1;
  string e2;
  string e3;
  int i = 0;
  int j = 1;
  int k = 2;
  int value = 0;
  while(getline(data,content)){
    elves.push_back(content);
  }
  while(k<elves.size()){
    e1 = elves[i];
    e2 = elves[j];
    e3 = elves[k];
    for (int i = 0; i<e1.size(); ++i){
      for(int j = 0; j<e2.size(); ++j){
        for(int k = 0; k<e3.size(); ++k){
          if (e1[i]==e2[j] && e1[i]==e3[k]){
            common.push_back(e1[i]);
          }
        }
      }
    }
    if(isupper(common[0])){
      value+=int(common[0]) - 38;
      common = {};
    }else{
      value+=int(common[0]) - 96;
      common = {};
    }
    i+=3;
    j+=3;
    k+=3;
  }
  cout<<value<<endl;
}