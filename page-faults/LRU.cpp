// Calculate amount of page faults that occur during the LRU algorithm

#include <bits/stdc++.h>

using namespace std;

int getPageFaults(int pageCount, int maxSize, int pages[]) {

  int faults = 0, i;
  // Store elements in memory of size (maxSize)
  vector < int > pageStore;

  for (i = 0; i <= pageCount - 1; i++) {

    // Check if element is memory or not
    auto result = find(pageStore.begin(), pageStore.end(), pages[i]);
    // If element is present or not
    if (result == pageStore.end()) {

      // If memory is already full
      if (pageStore.size() == maxSize) {
        pageStore.erase(pageStore.begin());
      }
      // Add the most recent page element into the memory & add 1 to fault amount
      pageStore.push_back(pages[i]);
      faults++;
    } else {
      // If element exists, remove it, and then add it to the end
      pageStore.erase(result);
      pageStore.push_back(pages[i]);
    }
  }
  return faults;
}

int main() {

  int pages[] = {
    5,
    0,
    2,
    4,
    0,
    1,
    0,
    5,
    4,
    1,
    0,
    1,
    4,
    2,
    4,
    0,
    2,
    5,
    0,
    2
  };
  int pageCount = 20, maxSize = 3;

  cout << "Page Faults = " << getPageFaults(pageCount, maxSize, pages);
  return 0;
}
