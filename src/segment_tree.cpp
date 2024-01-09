#include <cmath>
constexpr const int maxn = 1e5, treeLast = maxn * 4, treeSize = treeLast + 1;

// Segment tree internals
int tree[treeSize];

void updateID(int id, int left, int right, int idx, int value) {
  if (idx < left || idx > right)
    return;

  if (left == right) {
    tree[id] = value;
    return;
  }

  int mid = (left + right) / 2, leftID = id << 1, rightID = leftID + 1;

  updateID(leftID, left, mid, idx, value);
  updateID(rightID, mid + 1, right, idx, value);

  // Main
  tree[id] = std::max(tree[leftID], tree[rightID]);
}

int queryID(int id, int left, int right, int rangeStart, int rangeEnd) {
  if (rangeEnd < left || rangeStart > right)
    return -INFINITY;

  if (rangeStart <= left && rangeEnd >= right)
    return tree[id];

  int mid = (left + right) / 2;

  return std::max(queryID(id << 1, left, mid, rangeStart, rangeEnd),
                  queryID((id << 1) + 1, mid + 1, right, rangeStart, rangeEnd));
}

// Methods to use
void update(int idx, int value) { updateID(1, 1, treeLast, idx, value); }
int get() { return queryID(1, 1, treeLast, 1, treeLast); }
