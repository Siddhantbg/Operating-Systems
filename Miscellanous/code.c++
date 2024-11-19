#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

class MemoryManager {
    int maxPageTableSize, frameSize, memoryCapacity;
    vector<int> secondaryStorage;
    unordered_map<int, int> pageDirectory;
    list<int> recentlyUsedPages;
    unordered_map<int, list<int>::iterator> pageLookup;
    vector<int> mainMemory;

public:
    MemoryManager(int maxTableSize, int frameBytes, int totalMemory, const vector<int>& storage)
        : maxPageTableSize(maxTableSize), frameSize(frameBytes), memoryCapacity(totalMemory), secondaryStorage(storage) {
        mainMemory.resize(memoryCapacity / frameSize, -1);
    }

    void loadPage(int virtualAddress) {
        int targetPage = virtualAddress / frameSize;
        if (pageDirectory.find(targetPage) == pageDirectory.end()) {
            cout << "Page fault for page: " << targetPage << endl;
            processPageFault(targetPage);
        } else {
            cout << "Page " << targetPage << " found in frame: " << pageDirectory[targetPage] << endl;
            refreshLRU(targetPage);
        }
    }

    void processPageFault(int page) {
        int freeFrame = findFreeMemoryFrame();
        if (freeFrame == -1) {
            freeFrame = performPageReplacement();
        }

        pageDirectory[page] = freeFrame;
        mainMemory[freeFrame] = secondaryStorage[page];
        cout << "Page " << page << " loaded into frame " << freeFrame << endl;
        refreshLRU(page);
    }

    int findFreeMemoryFrame() {
        for (int i = 0; i < mainMemory.size(); i++) {
            if (mainMemory[i] == -1) return i;
        }
        return -1;
    }

    int performPageReplacement() {
        int leastUsedPage = recentlyUsedPages.back();
        recentlyUsedPages.pop_back();
        int replacedFrame = pageDirectory[leastUsedPage];
        pageDirectory.erase(leastUsedPage);
        cout << "Page " << leastUsedPage << " removed from frame " << replacedFrame << endl;
        return replacedFrame;
    }

    void refreshLRU(int page) {
        if (pageLookup.find(page) != pageLookup.end()) {
            recentlyUsedPages.erase(pageLookup[page]);
        }
        recentlyUsedPages.push_front(page);
        pageLookup[page] = recentlyUsedPages.begin();
    }
};

int main() {
    int tableLimit, frameBytes, memorySize;
    cout << "Enter page table capacity: ";
    cin >> tableLimit;
    cout << "Enter size of each page frame: ";
    cin >> frameBytes;
    cout << "Enter total memory size: ";
    cin >> memorySize;

    int secondaryStorageSize;
    cout << "Enter size of secondary storage (backing store): ";
    cin >> secondaryStorageSize;
    vector<int> secondaryStorage(secondaryStorageSize);
    cout << "Enter data for each page in the secondary storage: ";
    for (int i = 0; i < secondaryStorageSize; i++) {
        cin >> secondaryStorage[i];
    }

    MemoryManager memSystem(tableLimit, frameBytes, memorySize, secondaryStorage);

    int addressCount;
    cout << "Enter number of virtual addresses to access: ";
    cin >> addressCount;
    cout << "Enter the virtual addresses: ";
    for (int i = 0; i < addressCount; i++) {
        int address;
        cin >> address;
        memSystem.loadPage(address);
    }

    return 0;
}
