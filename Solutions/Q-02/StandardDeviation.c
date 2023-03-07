// Contributed by - Anuj Das ( GC University, Silchar - @ Department of Computer Science )

//  2. Write a C program to compute the Standard Deviation.


#include<stdio.h>
#include<math.h>

float findMean(int arr[], int size) {
    int i;
    float sum = 0;
    // Sum all elements of the array
    for (i = 0; i < size; i++) {
        sum += arr[i];
    }
    // Divide the sum by the size of the array to get the mean
    return sum / size;
}

float findStandardDeviation(int arr[], int size, float mean) {
	int i;
    float sum = 0;

    // Calculate the sum of the squares of the differences between each element of the array and the mean
    for (i = 0; i < size; i++) {
        sum += pow(arr[i] - mean, 2);
    }

    // Divide the sum by the size of the array, and take the square root to get the standard deviation
    return sqrt(sum / size);
}

void main() {
    int size, i;
    printf("Enter the size of the Array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d Elements: \n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Mean: %.2f\n", findMean(arr, size));
    printf("Standard Deviation: %.2f\n", findStandardDeviation(arr, size, findMean(arr, size)));
}



