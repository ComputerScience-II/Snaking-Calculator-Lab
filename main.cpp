#include <iostream>
#include <vector>
using namespace std;

int currentOp(int total, int a, char op ) {

    if (op == '+') return total + a;

    if (op == '-') return total - a;

    if (op == '*') return total * a;

    return total;

}


int calc(const vector<string>& totalGrid, int r, int c, char op, int total) {

    if(r < 0 || r >= totalGrid.size() || c >= totalGrid[r].size()) return total;

    char currentChar = totalGrid[r][c];

    if(isdigit(currentChar)) {

        total = currentOp(total, currentChar - '0', op);
    }

    else if(currentChar == '+' || currentChar == '-' || currentChar == '*') {

        op = currentChar;

    }

    else if(currentChar == '^') {

        total = calc(totalGrid, r - 1, c, op, total);
    }

    else if(currentChar == 'v') {

        total = calc(totalGrid, r + 1, c, op, total);
    }
    
    return calc(totalGrid, r, c + 1, op, total);
}


int initialCalc(const vector<string>& totalGrid) {

    return calc(totalGrid, 0, 0, '+', 0);

}


int main() {

    vector<string> totalGrid = {
        "1+v2*3",
        " ^ 4+1",
        "5-2*2"
    };

    cout << initialCalc(totalGrid) << endl;

    return 0;

}