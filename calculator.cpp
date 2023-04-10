#include <bits/stdc++.h>
using namespace std;

vector<pair<char, int>> p_int; //整数変数格納配列
vector<pair<char, vector<int>>> p_vec;//配列変数格納配列


//<int式>の計算を行う関数
int int_calculate(){
  char v; //整数or変数
  int i_v;
  char o_s; //演算子
  int x ;
  cin >> v;
  if (isdigit(v)){ //文字か数値か判定
    i_v = int(v - '0'); //文字を数値に変換
    x = i_v;
  }
  else{
    for (pair<char, int> p : p_int){
      if (p.first == v){
        x = p.second; //変数の計算
      }
    }

  }
  while(1){
    cin >> o_s; //演算子読み込み
    if (o_s == '+'){ //加
      cin >> v;
      if (isdigit(v)){ //文字か数値か判定
        i_v = int(v - '0'); //文字を数値に変換
        x += i_v;
      }
      else{
        for (pair<char, int> p : p_int){
          if (p.first == v){
            x += p.second; //変数の計算
          }
        }
      }   
    }
    if (o_s == '-'){ //減算
      cin >> v;
      if(isdigit(v)){
        i_v = int(v - '0');
        x -= i_v;
      }
      else{
        for (pair<char, int> p : p_int){
          if (p.first == v){
            x -= p.second; //変数の計算
          }
        }
      }
    }
    if (o_s == ';'){
      return x;
    }
  }
} 

//配列を読み込む関数
vector<int> vec_read(){
  vector<int> vec;
  while(1){
    char vec_v;//vec値　整数or変数
    int v;
    cin >> vec_v;
    if (isdigit(vec_v)){//整数判定
      v = int(vec_v - '0');
    }
    else{//変数判定
      for (auto p : p_int){//整数変数格納配列
        if(p.first == vec_v){//変数照合
          v = p.second;
        }
      }
    }
    vec.push_back(v);
    char corb;//コンマ括弧判定
    cin >> corb;
    if (corb == ']'){
      return vec;
    }
  
  }
}
//配列変数代入関数
vector<int> assign(){
  char v_b;//変数か括弧か
  vector<int> vec;
  cin >> v_b;//変数か括弧の判定
  if (v_b == '['){
    vec = vec_read();
  }
  else{
    for (auto p : p_vec){
      if(p.first == v_b){
        vec = p.second;
      }
    }
  }
  return vec;
}

//配列計算関数
vector<int> vec_calculate(){
  char o_s;//演算子かセミコロンか
  vector<int> vec;
  vector<int> s_vec;//計算用の予備配列
  vec = assign();
  while(1){
    cin >> o_s;
    if (o_s == '+'){
      s_vec = assign();
      for (int i = 0; i < vec.size(); i++){
        vec.at(i) += s_vec.at(i);
      }
    }
    if (o_s == '-'){
      s_vec = assign();
      for (int i = 0; i < vec.size(); i++){
        vec.at(i) -= s_vec.at(i);
      }
    }
    if (o_s == ';'){
      return vec;
    }
  }
}


int main(){ 
  int N; 
  cin >> N; //行数入力
  for (int i = 0; i < N; i++){ //行数回実行
    string format; //　形式読み込み
    cin >> format;
    if (format == "int"){ //int <変数名> = <int式> ;	
      char key; //変数名
      char eq;
      cin >> key >> eq; //読み込み
      int n;
      n = int_calculate(); //整数計算を行う関数の呼び出し
      p_int.push_back(make_pair(key, n));

    }
    if (format == "print_int"){
      int i_v;
      i_v = int_calculate();
      cout << i_v << endl; 
    }
    if (format == "vec"){
      char key;//変数名
      char eq;//等号演算子
      char borv;//括弧か変数か
      cin >> key >> eq;
      vector<int> vec;//配列変数に格納する配列
      vec = vec_calculate();
      p_vec.push_back(make_pair(key, vec));
    }
    if (format == "print_vec"){
      vector<int> vec;//出力する配列
      vec = vec_calculate();
      cout << '[' << ' ';
      for (int i = 0; i < vec.size(); i++){
          cout << vec.at(i) << ' ';
      }
      cout << ']' << endl;
    }
  } 
}
