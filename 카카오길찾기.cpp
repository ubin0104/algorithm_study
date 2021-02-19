#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

class TreeNode {
public :
	int x;
	int y;
	int value;

	TreeNode* left;
	TreeNode* right;

	TreeNode(int x, int y, int value) {
		this->x = x;
		this->y = y;
		this->value = value;
		this->left = NULL;
		this->right = NULL;
	}
	~TreeNode() {
		delete this;
	}

};
// 노드 추가
void add(TreeNode* node, TreeNode* newNode) {
	if (node->x < newNode->x) {
		if (node->right == NULL) {
			node->right = newNode;
		}
		else {
			add(node->right, newNode);
		}
	}
	else if (node->x > newNode->x) {
		if (node->left == NULL) {
			node->left = newNode;
		}
		else {
			add(node->left, newNode);
		}
	}
	// 같은 경우는 애초에 트리로 만들지 않는다.
	return;

}

//전위 순회
void preorder(TreeNode* node, vector<int>& lst) {
	if (node == NULL) return;
	lst.push_back(node->value);
	preorder(node->left, lst);
	preorder(node->right, lst);
}

//후위 순회
void postorder(TreeNode* node, vector<int>& lst) {
	if (node == NULL) return;
	postorder(node->left, lst);
	postorder(node->right, lst);
	lst.push_back(node->value);
}

//sort 비교함수
bool cmp(TreeNode* a, TreeNode* b) {
	return a->y > b->y;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer(2);
	vector<TreeNode*> l(nodeinfo.size());

	for (int i = 0; i < nodeinfo.size(); i++) {
		l[i] = new TreeNode(nodeinfo[i][0], nodeinfo[i][1],i+1);
		
	}
	sort(l.begin(), l.end(), cmp);

	for (int i = 1; i < l.size(); i++) {
		add(l[0], l[i]);
	}

	preorder(l[0], answer[0]);
	postorder(l[0], answer[1]);
	return answer;
}
