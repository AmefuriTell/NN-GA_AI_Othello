#include "Board.h"

int main()
{
	Board a;
	a.turn = 1;
	a.CheckBoard();
	a.PrintBoard();
	//for (int i = 1; i <= a.WCP[0]; i++)printf("%d ", a.WCP[i]);
	//printf("\n");

	while (true)
	{
		if (a.turn == 1)
		{
			printf("黒の番です。\n");
		}
		else
		{
			printf("白の版です。\n");
		}
		a.PutPiece();
		a.turn *= -1;
		for (int i = 0; i < 2; i++)
		{
			a.CheckBoard();
			a.PrintBoard();
			//for (int i = 1; i <= a.WCP[0]; i++)printf("%d ", a.WCP[i]);
			//printf("\n");
			if(a.WCP[0] != 0)break;
			a.turn *= -1;
		}
	}
}