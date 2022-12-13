#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> generateParentheses(int n);
void addingpar(vector<string>& v, string str, int n, int m);

vector<string> generateParentheses(int n) {
    vector<string> res;
    addingpar(res, "", n, 0);
    return res;
}

void addingpar(vector<string>& v, string str, int n, int m) {
    if (n == 0 && m == 0) {
        v.push_back(str);
        return;
    }
    if (m > 0) { addingpar(v, str + ")", n, m - 1); }
    if (n > 0) { addingpar(v, str + "(", n - 1, m + 1); }
}

int main() {
    vector<string> res = generateParentheses(2);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}