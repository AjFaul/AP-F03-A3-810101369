#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int calc(int left, int right, char op)
{
  if (op == '+')
    return left + right;
  if (op == '-')
    return left - right;
  if (op == '*')
    return left * right;
  return 0;
}

void separate_num(string line, vector<int> &num)
{
  for (int i = 0; i < line.size(); i++)
  {
    if (line[i] >= '1' && line[i] <= '9')
      num.push_back(int(line[i]) - 48);
  }
  return;
}

void separate_op(string line, vector<char> &op)
{
  for (int i = 0; i < line.size(); i++)
  {
    if (line[i] == '-' || line[i] == '+' || line[i] == '*')
      op.push_back(line[i]);
  }
  return;
}

vector<char> update_op(int i, vector<char> op)
{
  vector<char> new_op;
  for (int j = 0; j < op.size(); j++)
  {
    if (i == j)
      continue;
    else
      new_op.push_back(op[j]);
  }
  return new_op;
}

vector<int> update_num(int i, vector<int> num,int new_calc)
{
  int left_num = i;
  int right_num = i+1;
  vector<int> new_num;
  for (int j = 0; j < num.size(); j++)
  {
    if((i)==(j))
      new_num.push_back(new_calc);
    if(j==left_num || j==right_num)
      continue;
    else
      new_num.push_back(num[j]);
  }
  return new_num;
}


void solve(vector<int> num, vector<char> op , vector<int> &save_num){
  int new_calc;
  vector <int> new_num;
  vector <char> new_op;
  for(int i=0 ; i < op.size() ; i++){
    new_calc=calc(num[i],num[i+1],op[i]);
    new_num=update_num(i,num,new_calc);
    new_op=update_op(i,op);
    if(new_num.size()==1)
      save_num.push_back(new_num[0]);
    solve(new_num,new_op,save_num);
  }
  return;
}


void control_main(vector<int> num , vector<char> op){
  string line;
  int line_num=0;
  while (getline(cin,line))
  {
    line_num++;
    if(line_num==1)
      continue;
    separate_num(line, num);
    separate_op(line,op);
    vector <int> save_num;
    solve(num,op,save_num);
    sort(save_num.begin() , save_num.end());
    auto it=unique(save_num.begin() , save_num.end());
    save_num.erase(it,save_num.end());
    cout<<save_num.size();
    
  }
}




int main()
{
  vector<int> num;
  vector<char> op;
  control_main(num,op);
  return 0;
}
