#include <bits/stdc++.h>
using namespace std;

int main() {
  string content;
  vector<string> path;
  ifstream files("input7.txt");
  long total = 0;
  map<string,int> file_memos;
  long needed_space = 0;
  long freed_space = 0;
  while(getline(files,content)){
    stringstream action(content);
    string choice; action>>choice;
    if (choice == "$"){
      string action2; action>>action2;
      if (action2 == "cd"){
        string file_name;action>>file_name;
        if (file_name == ".."){
          path.pop_back();
        }else{
          path.push_back(file_name);
        }
      }
    }else if (choice != "dir"){
      string location = "";
      for (string i: path){
        location+=i;
        file_memos[location] += stol(choice);
      }
    }
  }
  needed_space = 30000000-(70000000 - file_memos["/"]);
  for(auto [k,v]: file_memos){
    if (freed_space == 0){
      freed_space = v;
    }else if (v>needed_space && v<freed_space){
      freed_space = v;
    }
  }
  cout<<freed_space<<endl;
  
}