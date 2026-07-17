import numpy as np

# Program: Find all pairs in an array whose sum equals the target value.
# Algorithm: Brute Force
# Time Complexity: O(n²)
# Space Complexity: O(1)

def pair_finding(arr, target):

    n = len(arr)
    pair_found = False

    for i in range(n):
        for j in range(i + 1, n):

            if arr[i] + arr[j] == target:
                print(f"Pair found: ({arr[i]}, {arr[j]})")
                pair_found = True

    if not pair_found:
        print("Pair not found.")


arr = np.array([1, 2, 3, 4, 5, 7])

pair_finding(arr, 7)
