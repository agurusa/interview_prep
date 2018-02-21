// #include <array>

class TreeNode{
public:
	TreeNode(int d){data = d;}
	TreeNode *left = NULL;
	TreeNode *right = NULL;
	int data;
	friend std::ostream& operator <<(std::ostream& os, const TreeNode *tn){
		os << tn->data;
		return os;
	}
	friend std::ostream& operator <<(std::ostream& os, const TreeNode &tn){
		os << tn.data;
		return os;
	}
};
class Tree{
public:
	Tree(){};
	TreeNode *root = NULL;
	void Insert(TreeNode *tn){
		if(root == NULL){
			root = tn;
		}
		else{
			std::vector<TreeNode*> nodes = {};
			TreeNode*next = root;
			while(next!= NULL){
				TreeNode *l = next->left;
				TreeNode *r = next->right;
				if(l == NULL){
					next->left = tn;
					return;
				}
				else if (r == NULL){
					next->right = tn;
					return;
				}
				else{
					nodes.push_back(l);
					nodes.push_back(r);
					next = nodes[0];
					nodes.erase(nodes.begin());
				}
			}
		}
	}
	friend bool operator == (const Tree lhs, const Tree rhs){
		return false;
	}
	friend std::ostream& operator <<(std::ostream& os, const Tree& tree){
		TreeNode *next;
		std::vector<TreeNode*> nodes = {};
		std::vector<TreeNode*> next_level = {};
		nodes.push_back(tree.root);
		next = nodes[0];
		while(next!= NULL){
			next_level.push_back(next->left);
			next_level.push_back(next->right);
			os<< next << " ";
			nodes.erase(nodes.begin());
			if(nodes.empty()){
				os << "::";
				nodes = next_level;
				next_level.clear();
			}
			next = nodes[0];
		}
		return os;
	}
};
Tree* minimal_tree(std::vector<int> input){
	Tree *tree = new Tree();
	return tree;
}