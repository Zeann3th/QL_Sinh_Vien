#include "sinhvien.h"
#include <cstring>

int partition(SinhVien *arr[], int low, int high) {
  SinhVien *pivot = arr[high];
  int i = low - 1;
  SinhVien *tmp;

  for (int j = low; j < high; j++) {
    if (strcmp(arr[j]->firstName, pivot->firstName) < 0) {
      i++;
      tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
    }
  }
  // Swap the pivot to its correct position
  tmp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = tmp;

  return i + 1;
}

void quicksort(SinhVien *arr[], int low, int high) {
  if (low < high) {
    int pivotIndex = partition(arr, low, high);
    quicksort(arr, low, pivotIndex - 1);
    quicksort(arr, pivotIndex + 1, high);
  }
}

void naivesort(SinhVien *arr[], int count) {
  SinhVien *sv;
  for (int i = 0; i < count; i++) {
    int cmpFirstName = strcmp((arr[i]->firstName), arr[i + 1]->firstName);
    if (cmpFirstName > 0) {
      sv = arr[i];
      arr[i] = arr[i + 1];
      arr[i + 1] = sv;
    } else if (cmpFirstName == 0) {
      int cmpLastName = strcmp(arr[i]->lastName, arr[i + 1]->lastName);
      if (cmpLastName > 0) {
        sv = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = sv;
      }
    }
  }
}
