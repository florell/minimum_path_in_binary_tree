#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data): data(data), left(nullptr), right(nullptr) {}
};

pair<pair<vector<int>, int>, pair<vector<int>, int>> get_max_path(Node* root)
{
    if (!root)
    {
        return {{{}, 0},{{}, 0}};
    }

    pair<pair<vector<int>, int>, pair<vector<int>, int>> left(get_max_path(root->left)), right(get_max_path(root->right)), ans;

    if (left.second.second > right.second.second || (left.second.second == right.second.second && left.second.first.size() <= right.second.first.size()))
    {
        if (left.second.second < 0)
        {
            ans.second = {{root->data}, root->data};
        }
        else
        {
            ans.second = left.second;
            ans.second.first.emplace_back(root->data);
            ans.second.second += root->data;
        }
    }
    else
    {
        if (right.second.second < 0)
        {
            ans.second = {{root->data}, root->data};
        }
        else
        {
            ans.second = right.second;
            ans.second.first.emplace_back(root->data);
            ans.second.second += root->data;
        }
    }
    if (ans.second.second <= 0)
    {
        ans.second = {{}, 0};
    }

    for (int & i : left.second.first)
    {
        ans.first.first.emplace_back(i);
        ans.first.second += i;
    }

    ans.first.first.emplace_back(root->data);
    ans.first.second += root->data;

    for (int & i : right.second.first)
    {
        ans.first.first.emplace_back(i);
        ans.first.second += i;
    }

    if (left.first.second > 0 && (ans.first.second < left.first.second || (ans.first.second == left.first.second && ans.first.first.size() < left.first.first.size())))
    {
        ans.first = left.first;
    }

    if (right.first.second > 0 && (ans.first.second < right.first.second || (ans.first.second == right.first.second && ans.first.first.size() < right.first.first.size())))
    {
        ans.first = right.first;
    }

    if (ans.first.second < root->data)
    {
        ans.first = {{root->data}, root->data};
    }

    return ans;
}

class BinaryTree {
public:
    Node *root;

    BinaryTree() {
        root = nullptr;
    }

    void insert(int data) {
        Node *node = new Node(data);
        if (root == nullptr) {
            root = node;
        } else {
            Node *current = root;
            Node *parent;
            while (true) {
                parent = current;
                if (data < current->data) {
                    current = current->left;
                    if (current == nullptr) {
                        parent->left = node;
                        break;
                    }
                } else {
                    current = current->right;
                    if (current == nullptr) {
                        parent->right = node;
                        break;
                    }
                }
            }
        }
    }

    void printTree(Node *node, bool isRight = false, const std::string& indent = "", bool isFirst = true) {
        if (node == nullptr) {
            return;
        }

        printTree(node->right, true, indent + (isRight ? "     " : "│    "), false);

        std::cout << (isFirst ? "" : indent);
        if (isRight) {
            std::cout << "┌───";
        } else {
            std::cout << "└───";
        }
        std::cout << node->data << std::endl;

        printTree(node->left, false, indent + (isRight ? "│    " : "     "), false);
    }
};


