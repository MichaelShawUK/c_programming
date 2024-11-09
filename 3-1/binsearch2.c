int binsearch(int x, int v[], int n);

int main() {
  int array[3] = {1, 3, 4};
  binsearch(2, array, 3);
}

int binsearch(int x, int v[], int n) {
  int low, mid, high;

  low = 0;
  high = n - 1;
  mid = (low + high) / 2;

  while (low <= high && v[mid] != x) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }
  if (v[mid] == x)
    return mid;
  else
    return -1;
}
