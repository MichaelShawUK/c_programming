int binsearch(int x, int v[], int n);

int main() {
  int array[3] = {1, 2, 3};
  binsearch(0, array, 3);
}

int binsearch(int x, int v[], int n) {
  /* if (x < v[0] || x > v[n - 1]) */
  /*   return -1; */
  int low, mid, high;

  low = 0;
  high = n - 1;

  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}
