#include <bits/stdc++.h>
using namespace std;
// https://onlinejudge.u-aizu.ac.jp/problems/0109
// 木構造にして解く例

int expr(string& s, int& i);
int term(string& s, int& i);
int factor(string& s, int& i);
int number(string& s, int& i);

struct node{
	string ch; 
	vector<int> to;
};
vector<node>nodes;
int expr(string& s, int& i) {
  int ret = term(s, i);
  while(s[i] == '+' || s[i] == '-') {
    int bef = ret;
    string op; op = s[i];
    i++;
    ret = nodes.size();
    nodes.push_back({op,{}});
    int aft = term(s, i);

    nodes[ret].to.push_back(bef);
    nodes[bef].to.push_back(ret);
    nodes[ret].to.push_back(aft);
    nodes[aft].to.push_back(ret);

  }
  return ret;
}

int term(string& s, int& i) {
  int ret = factor(s, i);
  while(s[i] == '*' || s[i] == '/') {
    int bef = ret;
    string op; op = s[i];
    i++;
    ret = nodes.size();
    nodes.push_back({op,{}});
    int aft = factor(s, i);

    nodes[ret].to.push_back(bef);
    nodes[bef].to.push_back(ret);
    nodes[ret].to.push_back(aft);
    nodes[aft].to.push_back(ret);
    
  }
  return ret;
}

int factor(string& s, int& i) {
  if (isdigit(s[i])) return number(s, i);

  // ここで構文が正しければ s[i] == '(' となる
  i++; // '('を読み飛ばす
  int ret = expr(s, i);
  i++; // ')'を読み飛ばす
  return ret;
}

int number(string& s, int& i) {
  int n = s[i++] - '0';
  while(isdigit(s[i])) n = n*10 + s[i++] - '0';
  int ret = nodes.size();
  nodes.push_back({to_string(n),{}});
  return ret;
}

int dfs(int v,vector<int> found){//木上で計算
  found[v] = 1;
  if(isdigit(nodes[v].ch[0])){
    return stoi(nodes[v].ch);
  }
  bool fst = true;
  int ret = 0;
  for(auto &p:nodes[v].to)if(!found[p]){
    int val = dfs(p,found);
     if(fst){
      ret = val;
      fst = false;
    }else{
      if(nodes[v].ch == "+"){
        ret += val;
      }else if(nodes[v].ch == "-"){
        ret -= val;
      }else if(nodes[v].ch == "*"){
        ret *= val;
      }else if(nodes[v].ch == "/"){
        ret /=val;
      }
    }
  }

  return ret;
}


int main() {
  int n;cin >> n;
  while(n--){
    nodes.clear();
    string s;
    cin >> s;
    int i = 0;
    int root = expr(s,i);
    vector<int>found(nodes.size());
    cout << dfs(root,found) << endl;
    
  }
  return 0;
}

