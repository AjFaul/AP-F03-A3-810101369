#include <iostream>
#include <cmath>
#include <map>
#include <vector>
using namespace std;
int SIZE_PAGE = 8;
int IS_EMPTY =-1;
int OUT_OF_PAGE = SIZE_PAGE + 1;

typedef map<int , vector<int> > place;


bool threat(int r1,int c1,int r2,int c2){
    return (r1==r2|| c1==c2 || abs(r1-r2) == abs(c1-c2));
}

void handle_line(string line,place &obstacles,int row){
    if(line.size()==0)
        return;
    
    if(line[line.size()-1] == '*'){
        obstacles[row].push_back(line.size());
        line.pop_back();
        return handle_line(line,obstacles,row);
    }
    line.pop_back();
    return handle_line(line, obstacles,row);
}

void handle_input(place &obstacles)
{
    string line;
    int row=1;
    while (getline(cin, line)){
        handle_line(line,obstacles,row);
        row++;
    }
}

bool safe_to_put_at(int row, int col , place &obstacles, place &queens){
    for ( int i=0; i<obstacles[row].size();i++){
        if(obstacles[row][i] ==col)
            return false;
    }
    
    for (int row1=1;row1<=8;row1++){
        if(queens[row1].empty())
            continue;
        if(threat(row,col,row1,queens[row1][0]))
            return false;
    }
    return true;
}

void solve(int row,int& solutions_count,place & obstacles,place &queens){
    if(row==OUT_OF_PAGE){
        solutions_count++;
        return;
    }
    for(int col=1;col<=8;col++){
        if(safe_to_put_at(row,col,obstacles,queens)){
            queens[row].push_back(col);
            solve(row+1,solutions_count,obstacles,queens);
            queens[row].pop_back();
        }
    }
}




int main()
{
    place obstacles;
    handle_input(obstacles);
    place queens;
    int sol_count=0;
    solve(1,sol_count,obstacles,queens);
    cout<<sol_count;
    return 0;
}