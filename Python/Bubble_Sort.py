import numpy as np

# Function to sort an array using the Bubble Sort algorithm
def bubbleSort(arr):
    """
    Sorts an array in ascending order using the Bubble Sort algorithm.

    Parameters:
        arr (numpy.ndarray): Array to be sorted.

    Returns:
        numpy.ndarray: Sorted array.
    """

    # Get the number of elements in the array
    n = len(arr)

    # Traverse through all elements of the array
    for i in range(n):

        # Flag to check if any swapping occurs in the current pass
        swapped = False

        # Compare adjacent elements in the unsorted part of the array
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:

                # Swap the elements if they are in the wrong order
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

                # Mark that a swap has occurred
                swapped = True

        # If no swaps occurred, the array is already sorted
        if swapped == False:
            break

    # Return the sorted array
    return arr

# Input array
arr1 = np.array([5, 6, 1, 2])

# Call the Bubble Sort function
arr = bubbleSort(arr1)

# Display the sorted array
print(arr)
