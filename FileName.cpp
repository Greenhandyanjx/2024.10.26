#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<numeric>
#include<sstream>
#include<unordered_map>
using namespace std;
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    void deleteNode(ListNode* node) {
        while (node->next) {
            node->val = node->next->val;
            node = node->next;
        }
        node = NULL;
    }
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string s1;
        while (head) {
            s1 += head->val - '0';
            head = head->next;
        }
        string s2 ( s1);
        reverse(s1.begin(), s1.end());
        return s1.compare(s2) == 0;
    }
};
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int>hash{ {0,0} };
        vector<int>res;
        int n = nums.size();
        for (auto& i : nums) {
            hash[i]++;
        }
        for (auto& i : hash) {
            if (i.second > n / 3) {
                res.push_back(i.first);
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>res;
        for (int i = 0; i < nums.size(); i++) {
            int start = nums[i];
            while (i < nums.size()-1 && nums[i + 1] == nums[i]+1) {
                i++;
            }
            int end = nums[i];
            if (start != end) {
                res.push_back(to_string(start) + "->" + to_string(end));
            }
            else res.push_back(to_string(start));
        }
        return res;
    }
};
class Solution {
public:
    int calculate(string s) {
        stack<char>sign;
        stack<int>num;
        int res = 0;
        for (auto& i : s) {
            if (i == ' ')continue;
            if (i == '-' || i == '+' || i == '*' || i == '/')
            {
                sign.push(i);
                i = ' ';
            }
        }
        stringstream ss(s);
        string str;
        while (getline(ss, str, ' ')) {
            num.push(stoi(str));
        }
        while (num.size() > 1) {
            char ch = sign.top();
            sign.pop();
            if (ch == '+') {
                int a = num.top(); num.pop();
                res += a;
            }
            else if (ch == '-') {
                int a = num.top(); num.pop();
                res -= a;
            }
            else if (ch == '*') {
                int a = num.top(); num.pop();
                int b = num.top(); num.pop();
                num.push(a * b);
            }
            else if (ch == '/') {
                int a = num.top(); num.pop();
                int b = num.top(); num.pop();
                num.push(b/a);
            }
        }
        res += num.top();
        num.pop();
        return res;
    }
};
// 构造树
TreeNode* buildTestTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->right->left = new TreeNode(8);
    return root;
}
TreeNode* findParent(TreeNode* root, int X) {
    if (!root || (!root->left && !root->right)) return nullptr;

    if ((root->left && root->left->value == X) ||
        (root->right && root->right->value == X)) {
        std::cout << "Parent of " << X << " is: " << root->value << std::endl;
        return root;
    }

    TreeNode* leftResult = findParent(root->left, X);
    if (leftResult) return leftResult;
    return findParent(root->right, X);
}

int main() {
    TreeNode* root = buildTestTree();
    TreeNode* res = findParent(root, 3);
    return 0;
}