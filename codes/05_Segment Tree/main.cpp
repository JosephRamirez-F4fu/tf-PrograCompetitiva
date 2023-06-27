#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class STree {
    int* t, n, size;
    int ope(int A, int B) {
        return A + B;
    }
public:
    STree(int n) {
        this->size = n;
        this->n = pow(2, ceil(log2(this->size)) + 1);
        t = new int[this->n];
        for (int i = 0; i < this->n; i++)
            t[i] = 0;
        for (int i = 0; i < this->size; i++)
            update(i, 1);
    }
    ~STree() {
        delete[] t;
    }
    void _update(int inode, int l, int r, int i, int value) {
        if (l < r) {
            int p = (l + r) / 2;
            if (i > p){
                _update(inode<<1|1, p+1, r, i, value);
            }
            else {
                _update(inode<<1, l, p, i, value);
            }
            t[inode] = ope(t[inode<<1], t[inode<<1|1]);
        }
        else {
            t[inode] = value;
        }
    }
    void update(int i, int value) {
        _update(1, 0, size - 1, i, value);
    }
    int _find(int inode, int i, int l, int r) {
        int p;
        while (l < r) {
            p = (l + r) / 2;
            inode <<= 1;
            if (i < t[inode]) {
                r = p;
            }
            else {
                i -= t[inode];
                inode = inode|1;
                l = p + 1;
            }
        }
        return l;
    }
    int find(int i) {
        return _find(1, i, 0, size - 1);
    }
};
bool fcmp(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0])
        return a[1] > b[1];
    else
        return a[0] < b[0];
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int index, n = people.size();
        sort(people.begin(), people.end(), fcmp);
        vector<std::vector<int>> result(n, std::vector<int>{0,0});
        STree sgTree(n);
        for (int i = 0; i < n ; i++) {
            index = sgTree.find(people[i][1]);//+1
            sgTree.update(index, 0);
            result[index][0] = people[i][0];
            result[index][1] = people[i][1];
        }
        return result;
    }
};
