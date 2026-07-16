import numpy as np

# Function to sort an array using the Selection Sort algorithm
def selection_sort(arr):
    # Get the number of elements in the array
    n = len(arr)

    # Traverse through each element except the last one
    for i in range(n - 1):

        # Assume the current element is the smallest
        min_index = i

        # Find the index of the smallest element in the remaining unsorted array
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j

        # Swap the smallest element with the current element
        arr[min_index], arr[i] = arr[i], arr[min_index]

    # Return the sorted array
    return arr

# Input array
arr = np.array([11, 5, 2, 0, 3, 4])

# Display the sorted array
print(selection_sort(arr))
