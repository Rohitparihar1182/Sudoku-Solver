#include<bits/stdc++.h>
using namespace std;

#define vc vector<char>
#define pii pair<int,int>
#define vpi vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define mii map<int,int>
#define si set<int>

void solve(int R,int C,vector<vc> &a,map<pii,si> &m,map<int,si> &row,map<int,si> &col){
    if(R==9){
        rep(i,0,9){
            rep(j,0,9){
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
        return ;
    }
    if(C==9){
        solve(R+1,0,a,m,row,col);
        return ;
    }
    if(a[R][C]!='.'){
        solve(R,C+1,a,m,row,col);
        return ;
    }
    rep(i,1,10){
        if(!m[{R/3,C/3}].count(i) and !row[R].count(i) and !col[C].count(i)){
            m[{R/3,C/3}].insert(i);
            row[R].insert(i);
            col[C].insert(i);
            a[R][C]=i+'0';
            solve(R,C+1,a,m,row,col);
            m[{R/3,C/3}].erase(i);
            row[R].erase(i);
            col[C].erase(i);
            a[R][C]='.';
        }
    }
}

void definer(vector<vc> &a){
    map<pii,si> m;
    map<int,si> row;
    map<int,si> col;
    rep(i,0,9){
        rep(j,0,9){
            if(a[i][j]!='.'){
                m[{i/3,j/3}].insert(a[i][j]-'0');
                row[i].insert(a[i][j]-'0');
                col[j].insert(a[i][j]-'0');
            }
        }
    }
    solve(0,0,a,m,row,col);
}

int main(){
    vector<vector<char>> sudoku = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},

    };
    definer(sudoku);
    return 0;
}