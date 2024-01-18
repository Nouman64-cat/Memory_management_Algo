#include <iostream>
using namespace std;

// Function to allocate memory to blocks as per Next fit algorithm
void nextFit(int blockSize[], int m, int processSize[], int n) {
    // Stores block id of the block allocated to a process
    int allocation[n], j = 0;

    // Initially no block is assigned to any process
    fill_n(allocation, n, -1);

    // Start from the beginning for the first process
    for (int i = 0; i < n; i++) {
        // Find a block for current process
        while (j < m) {
            if (blockSize[j] >= processSize[i]) {
                // Allocate block j to process i
                allocation[i] = j;

                // Reduce available memory in this block
                blockSize[j] -= processSize[i];

                // Break out of loop after allocation
                break;
            }

            // Move to the next block
            j = (j + 1) % m;

            // If we have traversed all blocks, stop trying for current process
            if (j == 0) break;
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

// Driver code
int main() {
    int blockSize[] = {100, 500, 200, 300, 600}; // Block sizes
    int processSize[] = {212, 417, 112, 426}; // Process sizes
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    nextFit(blockSize, m, processSize, n);

    return 0;
}
