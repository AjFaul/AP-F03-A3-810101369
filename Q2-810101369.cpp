#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>




using namespace std; 
 
int diff_char_int = 48;


void handle_input(int &num, string &main_expr){
    string line;
    int num_line=1;
    while (getline(cin,line)){
        if(num_line==1)
            num=stoi(line);
        main_expr=line;
    }
}

int calc(int left_num,int right_num,char op){
    if(op=='+')
        return left_num+right_num;
    if(op=='-')
        return left_num-right_num;
    if(op=='*')
        return left_num*right_num;
    return 0;
}

void convert_str2vec(string expr,int indx_leave,vector<string>& new_expr){
    int calculate_num=calc(int(expr[indx_leave-1])-diff_char_int,int(expr[indx_leave+1])-diff_char_int,char(expr[indx_leave]));
    string expr2=expr.substr(0,indx_leave-1);
    new_expr.push_back(expr2);

    expr2=to_string(calculate_num);
    new_expr.push_back(expr2);

    expr2=expr.substr(indx_leave+2);
    new_expr.push_back(expr2);
}


string vector_to_string(const vector<string> & v, const string & delimiter =" "){
    ostringstream oss;
    copy(v.begin() , v.end() , ostreamiterator<string> (oss , delimiter.c_str()));
    return oss.str();
}








bool is_sign(char a){
    if(a=='-'|| a=='+' || a=='*')
        return true;
    return false;
}






int main(){
    int num;
    string main_expr;
    handle_input(num,main_expr);
    vector<string> new_expr;
    convert_str2vec(main_expr,3,new_expr);
    for (int i=0;i<new_expr.size();i++) 
        cout<<new_expr[i]<<endl;
    cout<<endl<<new_expr.size();
    



}