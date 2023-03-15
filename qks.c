#include <stdio.h>
/* one of the simpliest version of quick sort */

/* qksort: sort v[left]...v[right] into increasing order */
void qksort(int v[], int left, int right) {
  int i, last;
  void swap(int v[], int i, int j);

  if (left >= right)
    // do nothing if array contains less than two elements
    return;

  swap(v, left, (left + right) / 2); /* move partition elem to v[left] */
  last = left;
  for (i = left + 1; i <= right; i++) {
    if (v[i] < v[left])
      swap(v, ++last, i);
  }
  swap(v, left, last); /* restore partition elem */
  qksort(v, left, last - 1);
  qksort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j) {
  int temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

/*
 * 5 2 1 3 4
 * 1 2 5 3 4
 * ^
 *   2 5 3 4
 *   3 5 2 4
 *   ^
 *   3 2 5 4
 *     ^
 *   2 3 5 4
 *       5 4
 *       4 5
 */

int main() {
  int arr[] = { 5, 2, 1, 3, 4 };
  qksort(arr, 0, 4);
  for (int i = 0; i < 5; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
