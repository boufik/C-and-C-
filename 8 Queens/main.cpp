#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Helpful functions
void displayStars(int n){
    for(int i=0; i<n; i++){
        cout << "*";
    }
    cout << endl;
}

void displayVector(vector <int> v){
    for(unsigned int i=0; i<v.size(); i++){
        cout << v[i] << endl;
    }
    cout << endl;
}

bool checkRowsOrColumns(vector <int> v){
    bool flag = true;
    for(unsigned int i=0; i<v.size()-1; i++){
        for(unsigned int j=i+1; j<v.size(); j++){
            if(v[i] == v[j]){
                flag = false;
                break;
            }
        }
    }
    return flag;                                            // If flag == true, no problem, but if flag == false, that means that there are i,j: v[i] = v[j], something we don't want for the solution
}

bool checkDiagoniaDexia(vector <int> vx, vector <int> vy){
    bool flag = true;
    for(unsigned int i=0; i<vx.size(); i++){
        for(unsigned int j=0; j<vy.size(); j++){
            if (i == j){                                    // If i == j, we are comparing the same thing (example: when i=j=4, we are comparing the 5th pair with the 5th pair)
                continue;
            }
            else{
                if(vx[i] - vy[i] == vx[j] - vy[j]){
                    flag = false;
                    break;
                }
            }
        }
    }
    return flag;
}

bool checkDiagoniaAristera(vector <int> vx, vector <int> vy){
    bool flag = true;
    for(unsigned int i=0; i<vx.size(); i++){
        for(unsigned int j=0; j<vy.size(); j++){
            if(i == j){
                continue;
            }

            else{
                if(vx[i] + vy[i] == vx[j] + vy[j]){
                    flag = false;
                    break;
                }
            }
        }
    }
    return flag;
}

int main()
{
    // 1. Intro
    displayStars(100);
    cout << "This is the 8 Queens Problem!" << endl;
    cout << "You have to give me 8 positions of the 8 queens to tell you if you have found a solution." << endl;
    cout << "Each position on the chess can be described with 2 numbers\nExample: If you want position 'e7' you have to write 5 and then 7\n\n";

    // 2. Create 2 vectors
    vector <int> vx = vector <int> ();
    vector <int> vy = vector <int> ();
    for(int i=0; i<8; i++){
        cout << "Position " << i+1 << ": ";
        int x,y;
        cin >> x;
        vx.push_back(x);
        cout << "            ";
        cin >> y;
        vy.push_back(y);
        cout << endl;
    }

    // 3. Display the tableau
    char tableau[vx.size()][vy.size()];                                         // vx.size = vy.size = 8
    for(int i=0; i<vx.size(); i++){
        for(int j=0; j<vy.size(); j++){
            tableau[i][j] = '-';
        }
    }

    for(int i=0; i<8; i++){
        tableau[vx[i]-1][vy[i]-1] = 'Q';
    }

    for(int i=0; i<vx.size(); i++){
        for(int j=0; j<vy.size(); j++){
            cout << tableau[i][j] << " ";
        }
        cout << endl;
    }

    // 4. Check if this combination of positions is solution
    if(checkRowsOrColumns(vx) == true && checkRowsOrColumns(vy) == true && checkDiagoniaDexia(vx, vy) == true &&checkDiagoniaAristera(vx, vy) == true){
        cout << "Congratulations. This combination of chess choices is solution!\n\n";
    }
    else{
        cout << "Unlucky! This is not a solution of this problem\n\n";
    }

    return 0;
}
