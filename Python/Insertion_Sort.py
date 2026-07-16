import numpy as np

# Function to perform insertion sort
def insertionSort(arr):

    # Start from the second element (index 1)
    # because the first element is considered already sorted
    for i in range(1, len(arr)):

        # Store the current element that needs to be inserted
        key = arr[i]

        # Compare key with elements before it
        j = i - 1

        # Move elements greater than key one position ahead
        while (j >= 0 and key < arr[j]):

            # Shift the larger element to the right
            arr[j + 1] = arr[j]

            # Move to the previous element
            j -= 1

        # Place key in its correct sorted position
        arr[j + 1] = key

    # Return the sorted array
    return arr


# Create an array using NumPy
arr = np.array([6, 5, 2, 8])

# Call insertion sort function and print the sorted array
print(insertionSort(arr))
