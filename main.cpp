#include <iostream>
#include <random>
#include "bt.h"

int main() {
    BinaryTree tree;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(-10000, 10000);
    for (int i = 0; i < 9; i++) {
        tree.insert( dist(rng));
    }
    tree.printTree(tree.root);
    cout << '\n';

    pair<pair<vector<int>, int>, pair<vector<int>, int>> res = get_max_path(tree.root);
    for (int i = 0; i < res.first.first.size(); ++i)
    {
        cout << res.first.first[i] << " ";
    }
    cout << '\n';


    return 0;

}
