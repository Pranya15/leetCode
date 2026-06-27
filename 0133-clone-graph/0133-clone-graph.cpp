/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {

        if(node == NULL) {
            return NULL;
        }

        // Already cloned
        if(mp.find(node) != mp.end()) {
            return mp[node];
        }

        // Create clone node
        Node* cloneNode = new Node(node->val);

        // Store mapping
        mp[node] = cloneNode;

        // Clone neighbors
        for(Node* neighbor : node->neighbors) {

            cloneNode->neighbors.push_back(
                cloneGraph(neighbor)
            );
        }

        return cloneNode;
    }
};