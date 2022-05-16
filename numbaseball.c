#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)


int numBaseball(int* a, int num, int mode) {
	int N[5] = { 0, };
	int i = mode - 1;
	int S = 0, B = 0;
	while (num > 0) {
		N[i] = num % 10;
		num /= 10;
		i--;
	}

	for (int s = 0; s < mode; s++) {
		for (int j = 0; j < mode; j++) {
			if (N[s] == a[j]) {
				if (s == j) 
					S++;
				else 
					B++;
			}
		}
	}

	if (S == mode) 
		printf("정답!\n");
	else 
		printf("%dS %dB\n", S, B);
	return S;
}

int main() {
	int mode,idx = 0;
	int num,menu;
	printf("숫자 개수를 입력하세요(3,4,5 중 하나!) : ");
	scanf("%d", &mode); // 3,4,5중에 하나 고르기

	
	int A[5] = { 0, };
	srand(time(NULL));
	
	while (idx < mode) {
		int chk = 0;
		int a = rand() % 8 + 1;
		for (int i = 0; i < idx; i++) {
			if (A[i] == a) 
				chk++;
		}
		if (chk == 0) {
			A[idx] = a;
			idx++;
		}
		else continue;
	}

	while (1) {
		printf("메뉴 (입력 : 1 , 포기 : 2, 종료 : 3) : ");
		scanf("%d", &menu);

		switch (menu) {
		case 1:
			printf("숫자 : ");
			scanf("%d", &num);
			int k = numBaseball(A, num, mode);
			if (k == mode)
				return 0;
			break;
		case 2:
			printf("정답은 ");
			for (int i = 0; i < mode; i++) {
				printf("%d", A[i]);
			}
			printf(" 입니다!");
			return 0;
		case 3:
			return 0;
		}
	}
	
}