//
// Created by hunordbcz on 22.11.2020.
//

#include "LIIDS.h"

void LIIDS::runTest() {
    vector<int> sizes;
    for (auto const &imap: scoreBySize) {
        sizes.push_back(imap.first);
    }

    this->execute(sizes);
}

void randomArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        array[i] = rand() % size;
}

void LIIDS::runCode(int N) {
    int arr[N];
    randomArray(arr, N);
    RDTSC_START();
    int dp[N + 1];

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        dp[i] = 1;
    }

    // Traverse the given array
    for (int i = 1; i <= N; i++) {

        // If the index is divisible by
        // the previous index
        for (int j = i + i; j <= N; j += i) {

            // if increasing
            // subsequence identified
            if (arr[j] > arr[i]) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }

        // Longest length is stored
        ans = max(ans, dp[i]);
    }
    RDTSC_STOP();
}

LIIDS::LIIDS() : Algorithm("Length of longest increasing index dividing subsequence") {
    for (int size : {1, 10, 100, 1000, 1000, 10000, 100000}) {
        scoreBySize.emplace(size, -1);
    }
}
