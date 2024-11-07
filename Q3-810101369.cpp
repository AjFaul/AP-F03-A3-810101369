#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
char DELMITIER=' ';



typedef vector<int> num_of_sweet_in_each;




vector<int> split(string line){
    istringstream ss(line);
    string token;
    vector<int> input_section;
    while (getline(ss,token,DELMITIER))
        input_section.push_back(stoi(token));
    return input_section;
}

void handle_input(num_of_sweet_in_each &faculty,int &number_of_faculties){
    string line;
    int num_line=1;
    while (getline(cin,line))
    {
        if(num_line==1){
            number_of_faculties= split(line) [0];
            num_line++;
            continue;
        }
        faculty=split(line);
    } 
}

int min(int num1, int num2){
    return (num1<num2 ? num1:num2 );
}

int abs_diff(int num1 , int num2){
    return ((num1-num2 <0)? num2-num1:num1-num2 );
}

int solve(num_of_sweet_in_each faculty , int number,int  num_of_uni){
    if (number==2)
        return abs_diff (faculty[num_of_uni-1] , faculty[num_of_uni-2]);
    if (number==3)
        return abs_diff (faculty[num_of_uni-3] , faculty[num_of_uni-1]);
    int diff1=abs_diff(faculty[num_of_uni-number], faculty[num_of_uni-(number-1)]);
    int diff2=abs_diff(faculty[num_of_uni-number], faculty[num_of_uni-(number-2)]);
    return min(diff1+solve(faculty,number-1,num_of_uni) , diff2+solve(faculty,number-2,num_of_uni));
}



int main(){
    vector <int> faculty;
    int number_of_faculties;
    handle_input(faculty,number_of_faculties);
    int number=number_of_faculties;
    cout<<solve(faculty,number,number_of_faculties);
    
}