#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
    class BITree {
        int* BIT, n;
    public:
        BITree(int n) {
            this->n = n + 1;
            BIT = new int[this->n];
            for (int i = 1; i < this->n; i++)
                BIT[i] = 0;
        }
        ~BITree() {
            delete[] BIT;
        }
        void update(int i, int value) {
            while (i < n) {
                BIT[i] += value;
                i += i & -i;
            }
        }
        int query(size_t i) {
            int sum = 0;
            while (i > 0) {
                sum += BIT[i];
                i -= i & -i;
            }
            return sum;
        }
    };
    void transfA(vector<int>& A) {
        int n = A.size();
        pair<int, int> temp[n];
        for(int i = 0; i < n; i++) {
            temp[i].first = A[i];
            temp[i].second = i;
        }
        sort(temp, temp + n);
        for(int i = 0; i < n; i++)
            A[temp[i].second] = i + 1;
    }
    int combinaciones(vector<int>& A) {
        int n = A.size();
        BITree greater(n), lower(n);
        int combinations[n], sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            combinations[i] = lower.query(A[i] - 1);
            lower.update(A[i], 1);
        }
        for(int i = 0; i < n; i++) {
            combinations[i] *= i - greater.query(A[i] - 1);
            greater.update(A[i], 1);
            sum += combinations[i];
        }
        return sum;
    }
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<int> asc(n);
        BITree greater(n), lower(n);
        transfA(rating);
        for (int i = 0; i < n; i++)
            asc[i] = n + 1 - rating[i];
        return combinaciones(rating) + combinaciones(asc);
    }
};
