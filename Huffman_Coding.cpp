#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// A Huffman Tree node
struct MinHeapNode {
    char data;  // Character (or '\0' for internal nodes)
    int freq;   // Frequency of the character
    MinHeapNode *left, *right; // Left and right children

    MinHeapNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// Comparison object for min heap
struct Compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        return l->freq > r->freq;
    }
};

// Preorder traversal to print Huffman codes only
void printCodes(MinHeapNode* root, string str) {
    if (!root) return;

    // If it's a leaf node, print the Huffman code
    if (!root->left && !root->right)
        cout << str << " ";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// Function to build the Huffman tree and generate codes
void HuffmanCodes(const vector<char>& data, const vector<int>& freq) {
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, Compare> minHeap;

    // Insert all characters into the min-heap
    for (size_t i = 0; i < data.size(); ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    // Build the Huffman Tree
    while (minHeap.size() > 1) {
        MinHeapNode* left = minHeap.top(); minHeap.pop();
        MinHeapNode* right = minHeap.top(); minHeap.pop();

        MinHeapNode* top = new MinHeapNode('\0', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // Print Huffman codes in preorder
    printCodes(minHeap.top(), "");
    cout << endl; // Print newline at the end
}

int main() {
    string S = "abcdef";
    vector<int> freq = {5, 9, 12, 13, 16, 45};
    vector<char> data(S.begin(), S.end());

    // Build Huffman Tree and print codes
    HuffmanCodes(data, freq);

    return 0;
}
