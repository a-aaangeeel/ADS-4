// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value) {
	int iResult=0;
	for (int i = 0; i < len; ++i) {
		for (int j = i + 1; j < len; ++j) {
			if (arr[i] + arr[j] == value) {
				iResult++;
			}
		}
	}
	return iResult;
}

int countPairs2(int* arr, int len, int value) {
	int iResult = 0;
	int left = 0;
	int right = len - 1;
	while (left < right) {
		if (arr[left] + arr[right] == value) {
			iResult++;
		}
		right--;
		if (right <= left) {
			left++;
			right = len - 1;
		}
	}
	return iResult;
}




int search(int* arr, int size, int value) {
	int low = 0;
	int high = size - 1;
	int iResult = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == value) {
			iResult++;
			int i = mid - 1;
			while (i >= 0 && arr[i] == value) {
				iResult++;
				i--;
			}
			i = mid + 1;
			while (i < size && arr[i] == value) {
				iResult++;
				i++;
			}
			break;
		}
		else if (arr[mid] < value) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return iResult;
}

int countPairs3(int* arr, int len, int value) {
	int iResult =0, i = 0;
	while (arr[i] <= (value / 2) - 1) {
		int iPer = value - arr[i];
		iResult += search(arr, len, iPer);
		i++;
	}
	int mid = search(arr, len, value / 2);
	iResult += mid * (mid - 1) / 2;
	return iResult;
}

