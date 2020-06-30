// 2번째 배팅시 사용하는 족보검사 함수 (카드 6장)
int Bpedigree_check(int R[], int S[], int& ptr1, int& ptr2)
{
	arrsort(R, S, 6);

	int ptr1, ptr2;

	int pedigree = High_card;

	// pair!
	if ((R[0] == R[1]) || (R[1] == R[2]) || (R[2] == R[3]) || (R[3] == R[4]) || (R[4] == R[5]))
	{

		// one_pair
		if ((R[0] == R[1]) && (R[1] != R[2] != R[3] != R[4] != R[5]))
		{
			pedigree = One_pair;
			ptr1 = R[1];
			ptr2 = S[1];
		}
		else if ((R[1] == R[2]) && (R[0] != R[2] != R[3] != R[4] != R[5]))
		{
			pedigree = One_pair;
			ptr1 = R[2];
			ptr2 = S[2];
		}
		else if ((R[2] == R[3]) && (R[0] != R[1] != R[3] != R[4] != R[5]))
		{
			pedigree = One_pair;
			ptr1 = R[3];
			ptr2 = S[3];
		}
		else if ((R[3] == R[4]) && (R[0] != R[1] != R[2] != R[4] != R[5]))
		{
			pedigree = One_pair;
			ptr1 = R[4];
			ptr2 = S[4];
		}
		else if ((R[4] == R[5]) && (R[0] != R[1] != R[2] != R[3] != R[5]))
		{
			pedigree = One_pair;
			ptr1 = R[5];
			ptr2 = S[5];
		}

		// two_pair
		else if ((R[0] == R[1]) && (R[2] == R[3]) && (R[1] != R[3] != R[4] != R[5]))
		{
			pedigree = Two_pair;
			ptr1 = R[3];
			ptr2 = S[3];
		}
		else if ((R[0] == R[1]) && (R[3] == R[4]) && (R[1] != R[2] != R[4] != R[5]))
		{
			pedigree = Two_pair;
			ptr1 = R[4];
			ptr2 = S[4];
		}
		else if ((R[0] == R[1]) && (R[4] == R[5]) && (R[1] != R[2] != R[3] != R[5]))
		{
			pedigree = Two_pair;
			ptr1 = R[5];
			ptr2 = S[5];
		}
		else if ((R[1] == R[2]) && (R[3] == R[4]) && (R[0] != R[2] != R[4] != R[5]))
		{
			pedigree = Two_pair;
			ptr1 = R[4];
			ptr2 = S[4];
		}
		else if ((R[1] == R[2]) && (R[4] == R[5]) && (R[0] != R[2] != R[3] != R[5]))
		{
			pedigree = Two_pair;
			ptr1 = R[5];
			ptr2 = S[5];
		}
		else if ((R[2] == R[3]) && (R[4] == R[5]) && (R[0] != R[1] != R[3] != R[5]))
		{
			pedigree = Two_pair;
			ptr1 = R[5];
			ptr2 = S[5];
		}
	}

	// triple
	if ((R[0] == R[1] == R[2]) || (R[1] == R[2] == R[3]) || (R[2] == R[3] == R[4]) || (R[3] == R[4] == R[5]))
	{
		if ((R[0] == R[1] == R[2]) && (R[2] != R[3] != R[4] != R[5]))
		{
			pedigree = Triple;
			ptr1 = R[2];
			ptr2 = S[2];
		}
		else if ((R[1] == R[2] == R[3]) && (R[0] != R[3] != R[4] != R[5]))
		{
			pedigree = Triple;
			ptr1 = R[3];
			ptr2 = S[3];
		}
		else if ((R[2] == R[3] == R[4]) && (R[0] != R[1] != R[4] != R[5]))
		{
			pedigree = Triple;
			ptr1 = R[4];
			ptr2 = S[4];
		}
		else if ((R[3] == R[4] == R[5]) && (R[0] != R[1] != R[2] != R[5]))
		{
			pedigree = Triple;
			ptr1 = R[5];
			ptr2 = S[5];
		}
		//full house
		else if ((R[0] == R[1] == R[2]) && (R[3] == R[4]) && (R[2] != R[4] != R[5]))
		{
			pedigree = Full_house;
			ptr1 = R[2];
			ptr2 = S[2];
		}
		else if ((R[0] == R[1] == R[2]) && (R[4] == R[5]) && (R[2] != R[3] != R[5]))
		{
			pedigree = Full_house;
			ptr1 = R[2];
			ptr2 = S[2];
		}
		else if ((R[1] == R[2] == R[3]) && (R[4] == R[5]) && (R[0] != R[3] != R[5]))
		{
			pedigree = Full_house;
			ptr1 = R[3];
			ptr2 = S[3];
		}
	}
	// four card
	if ((R[0] == R[1] == R[2] == R[3]) || (R[1] == R[2] == R[3] == R[4]) || (R[2] == R[3] == R[4] == R[5]))
	{
		if (R[0] == R[1] == R[2] == R[3])
		{
			pedigree = Four_card;
			ptr1 = R[3];
			ptr2 = S[3];
		}
		else if (R[1] == R[2] == R[3] == R[4])
		{
			pedigree = Four_card;
			ptr1 = R[4];
			ptr2 = S[4];
		}
		else if (R[2] == R[3] == R[4] == R[5])
		{
			pedigree = Four_card;
			ptr1 = R[5];
			ptr2 = S[5];
		}
	}

	//straight
	if (((R[1] == R[0] + 1) && (R[2] == R[1] + 1) && (R[3] == R[2] + 1) && (R[4] == R[3] + 1)) || ((R[2] == R[1] + 1) && (R[3] == R[2] + 1) && (R[4] == R[3] + 1) && (R[5] == R[4] + 1)))
	{
		if ((R[1] == R[0] + 1) && (R[2] == R[1] + 1) && (R[3] == R[2] + 1) && (R[4] == R[3] + 1))
		{
			pedigree = Straight;
			ptr1 = R[4];
			ptr2 = S[4];
		}
		if ((R[2] == R[1] + 1) && (R[3] == R[2] + 1) && (R[4] == R[3] + 1) && (R[5] == R[4] + 1))
		{
			pedigree = Straight;
			ptr1 = R[5];
			ptr2 = S[5];
		}
	}

	//flush
	if ((S[0] == S[1] == S[2] == S[3] == S[4]) || (S[1] == S[2] == S[3] == S[4] == S[5]))
	{
		if (S[0] == S[1] == S[2] == S[3] == S[4])
		{
			pedigree = Flush;
			ptr1 = R[4];
			ptr2 = S[4];
		}
		if (S[1] == S[2] == S[3] == S[4] == S[5])
		{
			pedigree = Flush;
			ptr1 = R[5];
			ptr2 = S[5];
		}
	}

	// straight flush
	if (((R[1] == R[0] + 1) && (R[2] == R[1] + 1) && (R[3] == R[2] + 1) && (R[4] == R[3] + 1)) && (S[0] == S[1] == S[2] == S[3] == S[4]))
	{
		pedigree = Straight_flush;
		ptr1 = R[4];
		ptr2 = S[4];
	}
	if (((R[2] == R[1] + 1) && (R[3] == R[2] + 1) && (R[4] == R[3] + 1) && (R[5] == R[4] + 1)) && (S[1] == S[2] == S[3] == S[4] == S[5]))
	{
		pedigree = Straight_flush;
		ptr1 = R[5];
		ptr2 = S[5];
	}
	return pedigree;
}
