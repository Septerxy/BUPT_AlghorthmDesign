#include <iostream>
#include <ctime>

using namespace std;

int testData_1[10];
int testData_2[100];
int testData_3[1000];
int testData_4[10000];
int testData_5[100000];
int testData_6[1000000];
int testData_7[10000000];
int testData_8[100000000];
clock_t start;
clock_t ending;

void InitialTestData()
{
	for (int i = 0;i < 10;i++)
		testData_1[i] = rand() % 40 - 20;
	for (int i = 0;i < 100;i++)
		testData_2[i] = rand() % 40 - 20;
	for (int i = 0;i < 1000;i++)
		testData_3[i] = rand() % 40 - 20;
	for (int i = 0;i < 10000;i++)
		testData_4[i] = rand() % 40 - 20;
	for (int i = 0;i < 100000;i++)
		testData_5[i] = rand() % 40 - 20;
	for (int i = 0;i < 1000000;i++)
		testData_6[i] = rand() % 40 - 20;
	for (int i = 0;i < 10000000;i++)
		testData_7[i] = rand() % 40 - 20;
	for (int i = 0;i < 100000000;i++)
		testData_8[i] = rand() % 40 - 20;
}

int MaxSubsequenceSum_1(const int A[], int N)
{
	int ThisSum, MaxSum, i, j, k;
	/* 1*/ MaxSum = 0; /* initialize the maximum sum */
	/* 2*/ for (i = 0; i < N; i++) /* start from A[ i ] */
		/* 3*/ for (j = i; j < N; j++) { /* end at A[ j ] */
			/* 4*/ ThisSum = 0;
			/* 5*/ for (k = i; k <= j; k++)
				/* 6*/ ThisSum += A[k]; /* sum from A[ i ] to A[ j ] */
			/* 7*/ if (ThisSum > MaxSum)
				/* 8*/ MaxSum = ThisSum; /* update max sum */
		} /* end for-j and for-i */
	/* 9*/ return MaxSum;
}

int MaxSubsequenceSum_2(const int A[], int N)
{
	int ThisSum, MaxSum, i, j;
	/* 1*/ MaxSum = 0; /* initialize the maximum sum */
	/* 2*/ for (i = 0; i < N; i++) { /* start from A[ i ] */
		/* 3*/ ThisSum = 0;
		/* 4*/ for (j = i; j < N; j++) { /* end at A[ j ] */
			/* 5*/ ThisSum += A[j]; /* sum from A[ i ] to A[ j ] */
			/* 6*/ if (ThisSum > MaxSum)
				/* 7*/ MaxSum = ThisSum; /* update max sum */
		} /* end for-j */
	} /* end for-i */
	/* 8*/ return MaxSum;
}

int BinarySearch(const int A[], int left, int right)
{
	if (left == right)
		return A[left];
	else
	{
		int center = (left + right) / 2;
		int LeftSum = BinarySearch(A, left, center);
		int RightSum = BinarySearch(A, center+1, right);
		int LeftOfTotalSum = -99999;
		int RightOfTotalSum = -99999;
		int TotalSum = 0;
		int TempLeftSum = 0;
		int TempRightSum = 0;
		for (int i = center;i >= left;i--)
		{
			TempLeftSum += A[i];
			if (TempLeftSum > LeftOfTotalSum)
				LeftOfTotalSum = TempLeftSum;
		}
		for (int i = center + 1;i <= right;i++)
		{
			TempRightSum += A[i];
			if (TempRightSum > RightOfTotalSum)
				RightOfTotalSum = TempRightSum;
		}
		TotalSum = LeftOfTotalSum + RightOfTotalSum;

		if ((RightSum > LeftSum) && (RightSum > TotalSum))
			return RightSum;
		else if (LeftSum > TotalSum)
			return LeftSum;
		else
			return TotalSum;
	}
}

int MaxSubsequenceSum_3(const int A[], int N)
{
	int MaxSum = 0;
	MaxSum = BinarySearch(A, 0, N - 1);
	return MaxSum;
}

int MaxSubsequenceSum_4(const int A[], int N)
{
	int ThisSum, MaxSum, j;
	/* 1*/ ThisSum = MaxSum = 0;
	/* 2*/ for (j = 0; j < N; j++) {
		/* 3*/ ThisSum += A[j];
		/* 4*/ if (ThisSum > MaxSum)
			/* 5*/ MaxSum = ThisSum;
		/* 6*/ else if (ThisSum < 0)
			/* 7*/ ThisSum = 0;
	} /* end for-j */
	/* 8*/ return MaxSum;
}

int main()
{
	int result = 0;
	double time = 0.0;

	InitialTestData();

	cout << "**************************************************************************" << endl;
	cout << "��������Ϊ10ʱ��" << endl;
	start = clock();
	result = MaxSubsequenceSum_1(testData_1, 10);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨һ��ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;

	start = clock();
	result = MaxSubsequenceSum_2(testData_1, 10);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨����ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;

	start = clock();
	result = MaxSubsequenceSum_3(testData_1, 10);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨����ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;

	start = clock();
	result = MaxSubsequenceSum_4(testData_1, 10);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨����ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;
	cout << "**************************************************************************" << endl;
	cout << endl;

	cout << "**************************************************************************" << endl;
	cout << "��������Ϊ100ʱ��" << endl;
	start = clock();
	result = MaxSubsequenceSum_1(testData_2, 100);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨һ��ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;

	start = clock();
	result = MaxSubsequenceSum_2(testData_2, 100);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨����ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;

	start = clock();
	result = MaxSubsequenceSum_3(testData_2, 100);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨����ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;

	start = clock();
	result = MaxSubsequenceSum_4(testData_2, 100);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨����ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;
	cout << "**************************************************************************" << endl;
	cout << endl;

	cout << "**************************************************************************" << endl;
	cout << "��������Ϊ1000ʱ��" << endl;
	start = clock();
	result = MaxSubsequenceSum_1(testData_3, 1000);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨һ��ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;

	start = clock();
	result = MaxSubsequenceSum_2(testData_3, 1000);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨����ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;

	start = clock();
	result = MaxSubsequenceSum_3(testData_3, 1000);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨����ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;

	start = clock();
	result = MaxSubsequenceSum_4(testData_3, 1000);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨����ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;
	cout << "**************************************************************************" << endl;
	cout << endl;

	cout << "**************************************************************************" << endl;
	cout << "��������Ϊ10000ʱ��" << endl;
	start = clock();
	result = MaxSubsequenceSum_1(testData_4, 10000);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨һ��ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;

	start = clock();
	result = MaxSubsequenceSum_2(testData_4, 10000);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨����ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;

	start = clock();
	result = MaxSubsequenceSum_3(testData_4, 10000);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨����ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;

	start = clock();
	result = MaxSubsequenceSum_4(testData_4, 10000);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨����ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;
	cout << "**************************************************************************" << endl;
	cout << endl;

	cout << "**************************************************************************" << endl;
	cout << "��������Ϊ100000ʱ��" << endl;
	start = clock();
	result = MaxSubsequenceSum_1(testData_5, 100000);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨һ��ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;

	start = clock();
	result = MaxSubsequenceSum_2(testData_5, 100000);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨����ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;

	start = clock();
	result = MaxSubsequenceSum_3(testData_5, 100000);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨����ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;

	start = clock();
	result = MaxSubsequenceSum_4(testData_5, 100000);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨����ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;
	cout << "**************************************************************************" << endl;
	cout << endl;

	cout << "**************************************************************************" << endl;
	cout << "��������Ϊ1000000ʱ��" << endl;
	start = clock();
	result = MaxSubsequenceSum_1(testData_6, 1000000);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨һ��ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;

	start = clock();
	result = MaxSubsequenceSum_2(testData_6, 1000000);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨����ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;

	start = clock();
	result = MaxSubsequenceSum_3(testData_6, 1000000);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨����ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;

	start = clock();
	result = MaxSubsequenceSum_4(testData_6, 1000000);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨����ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;
	cout << "**************************************************************************" << endl;
	cout << endl;

	cout << "**************************************************************************" << endl;
	cout << "��������Ϊ10000000ʱ��" << endl;
	start = clock();
	result = MaxSubsequenceSum_1(testData_7, 10000000);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨һ��ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;

	start = clock();
	result = MaxSubsequenceSum_2(testData_7, 10000000);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨����ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;

	start = clock();
	result = MaxSubsequenceSum_3(testData_7, 10000000);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨����ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;

	start = clock();
	result = MaxSubsequenceSum_4(testData_7, 10000000);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨����ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;
	cout << "**************************************************************************" << endl;
	cout << endl;

	cout << "**************************************************************************" << endl;
	cout << "��������Ϊ100000000ʱ��" << endl;
	start = clock();
	result = MaxSubsequenceSum_1(testData_8, 100000000);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨һ��ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;

	start = clock();
	result = MaxSubsequenceSum_2(testData_8, 100000000);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨����ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;

	start = clock();
	result = MaxSubsequenceSum_3(testData_8, 100000000);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨����ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;

	start = clock();
	result = MaxSubsequenceSum_4(testData_8, 100000000);
	ending = clock();
	time = (double)(ending - start) / CLOCKS_PER_SEC;
	cout << "�����㷨����ʱ��" << time * 1000 << "ms��������Ϊ��" << result << endl;
	cout << endl;
	cout << "**************************************************************************" << endl;
	cout << endl;

	system("pause");
	return 0;
}



/*
**************************************************************************
��������Ϊ10ʱ��
�����㷨һ��ʱ��0ms��������Ϊ��36

�����㷨����ʱ��0ms��������Ϊ��36

�����㷨����ʱ��0ms��������Ϊ��36

�����㷨����ʱ��0ms��������Ϊ��36

**************************************************************************

**************************************************************************
��������Ϊ100ʱ��
�����㷨һ��ʱ��2ms��������Ϊ��109

�����㷨����ʱ��0ms��������Ϊ��109

�����㷨����ʱ��0ms��������Ϊ��109

�����㷨����ʱ��0ms��������Ϊ��109

**************************************************************************

**************************************************************************
��������Ϊ1000ʱ��
�����㷨һ��ʱ��1443ms��������Ϊ��320

�����㷨����ʱ��4ms��������Ϊ��320

�����㷨����ʱ��1ms��������Ϊ��320

�����㷨����ʱ��0ms��������Ϊ��320

**************************************************************************

**************************************************************************
��������Ϊ10000ʱ��
�����㷨һ��ʱ��953894ms��������Ϊ��508

�����㷨����ʱ��258ms��������Ϊ��508

�����㷨����ʱ��3ms��������Ϊ��508

�����㷨����ʱ��0ms��������Ϊ��508

**************************************************************************

�밴���������. . .
*/