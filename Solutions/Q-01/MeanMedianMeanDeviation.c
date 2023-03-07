// Contributed by - Anuj Das ( GC University, Silchar - @ Department of Computer Science )

// 1. Write a C program to calculate the Mean, Median and Mean Deviation of a simple distribution.

#include<stdio.h>
#include<math.h>

// Function to sort the array using Bubble Sort Algorithm
void sortArray(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to calculate the mean
float findMean(int arr[], int n) {
    int i;
    float sum = 0;
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

// Function to calculate the median
float findMedian(int arr[], int n) {
    sortArray(arr, n);
    if(n % 2 == 0) {
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    } else {
        return arr[n/2];
    }
}

// Function to calculate the mean deviation
float findMeanDeviation(int arr[], int n) {
    int i;
    float mean = findMean(arr, n);
    float sum = 0;
    for (i = 0; i < n; i++) {
        sum += fabs(arr[i] - mean);
    }
    return sum / n;
}


void main() {
    int size;
    printf("Enter the size of the Array: ");
    scanf("%d", &size);

    int arr[size], i;
    printf("Enter %d Elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate and print the mean
    float mean = findMean(arr, size);
    printf("Mean:  %.2f\n", mean);

    // Calculate and print the median
    float median = findMedian(arr, size);
    printf("Median:  %.2f\n", median);

    // Calculate and print the mean deviation
    float mean_deviation = findMeanDeviation(arr, size);
    printf("Mean Deviation:  %.2f\n", mean_deviation);
}
