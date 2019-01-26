#include<cstdio>
#include<iostream>
#include<vector>
 
using namespace std;
 
int n, a, b;
string instr1, instr2;
vector<vector<int> > blocks;
 
// returns the column and row of an element a
pair<int, int> column(int a) {
    for(int i = 0; i < blocks.size(); i++)
        for(int j = 0; j < blocks[i].size(); j++)
            if(a == blocks[i][j]) return make_pair(i, j);
    return make_pair(0, 0);
}
 
// returns the element at (i, j) to it's initial position
void return_to_initial(int i, int j) {
    blocks[blocks[i][j]].push_back(blocks[i][j]);
    blocks[i].erase(blocks[i].begin() + j);
}
 
void move_onto(pair<int, int> c, pair<int, int> d) {
    while(d.second + 1 != blocks[d.first].size()) {
        return_to_initial(d.first, d.second + 1);
    }
    while(c.second + 1 != blocks[c.first].size()) {
        return_to_initial(c.first, c.second + 1);
    }
    blocks[c.first].erase(blocks[c.first].begin() + c.second);
    blocks[d.first].push_back(a);
}
 
void move_over(pair<int, int> c, pair<int, int> d) {
    while(c.second + 1 != blocks[c.first].size()) {
        return_to_initial(c.first, c.second + 1);
    }
    blocks[c.first].erase(blocks[c.first].begin() + c.second);
    blocks[d.first].push_back(a);
}
 
void pile_onto(pair<int, int> c, pair<int, int> d) {
    while(d.second + 1 != blocks[d.first].size()) {
        return_to_initial(d.first, d.second + 1);
    }
    while(c.second != blocks[c.first].size()) {
        blocks[d.first].push_back(blocks[c.first][c.second]);
        blocks[c.first].erase(blocks[c.first].begin() + c.second);
    }
}
 
void pile_over(pair<int, int> c, pair<int, int> d) {
    while(c.second != blocks[c.first].size()) {
        blocks[d.first].push_back(blocks[c.first][c.second]);
        blocks[c.first].erase(blocks[c.first].begin() + c.second);
    }
}
 
int main() {
    scanf("%d\n", &n);
    blocks.resize(n);
    for(int i = 0; i < n; i++)
        blocks[i].push_back(i);
    for(;;) {
        cin >> instr1;
        if(instr1 == "quit") break;
        cin >> a >> instr2 >> b;
 
        // if it's an illegal instruction keep going
        if(a == b) continue;
        pair<int, int> c = column(a);
        pair<int, int> d = column(b);
        if(c.first == d.first) continue;
 
        if(instr1 == "move" && instr2 == "onto")
            move_onto(c, d);
        if(instr1 == "move" && instr2 == "over")
            move_over(c, d);
        if(instr1 == "pile" && instr2 == "onto")
            pile_onto(c, d);
        if(instr1 == "pile" && instr2 == "over")
            pile_over(c, d);
    }
 
    for(int i = 0; i < blocks.size(); i++) {
        printf("%d:", i);
        for(int j = 0; j < blocks[i].size(); j++) {
            printf(" %d", blocks[i][j]);
        }
        printf("\n");
    }
}