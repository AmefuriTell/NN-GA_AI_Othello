#include "Board.h"

Board::Board()
{
    ClearBoard();
    turn = 1;
    WCP[0] = 0;
}
void Board::ClearBoard()//Board������
{
    for (int i = 0; i < 10; i++)for (int j = 0; j < 10; j++)board[i][j] = 0;
    board[4][4] = 1; board[4][5] = -1; board[5][4] = -1; board[5][5] = 1;

    for (int i = 0; i < 10; i++)
    {
        board[i][0] = 10; board[i][9] = 10; board[0][i] = 10; board[9][i] = 10;
    }
}
void Board::PrintBoard()//�Ֆʕ`��
{
    printf(" ");
    for (int i = 1; i < 9; i++)
    {
        printf("%d", i);
    }
    printf("\n");
    for (int i = 1; i < 9; i++)
    {
        printf("%d", i);
        for (int j = 1; j < 9; j++)
        {
            switch (board[i][j])
            {
            case 1:
                printf("B");
                break;
            case -1:
                printf("W");
                break;
            case 0:
                printf("-");
                break;
            default:
                printf("C");
                break;
            }
        }
        printf("\n");
    }
}
void Board::CheckBoard()//�ǂ��ɒu���邩���`�F�b�N����
{
    int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    for (int x = 1; x < 9; x++)
    {
        for (int y = 1; y < 9; y++)
        {

            if (board[x][y] == 0)
            {
                for (int i = 0; i < 8; i++)
                {
                    IPDWT[x + y * 10][i] = 0;
                }
                bool flag = false;
                for (int i = 0; i < 8; i++)
                {
                    if (board[x + dx[i]][y + dy[i]] == -turn)
                    {
                        for (int j = 1; j < 100; j++)
                        {
                            if (board[x + dx[i] * j][y + dy[i] * j] == turn)
                            {
                                flag = true;
                                IPDWT[x + y * 10][i] = j;
                                board[x][y] = 2;

                                break;
                            }
                            else if (board[x + dx[i] * j][y + dy[i] * j] != -turn)
                            {
                                break;
                            }
                        }
                    }
                }
                if (flag)
                {
                    WCP[WCP[0] + 1] = x * 10 + y;
                    WCP[0]++;
                }
            }
        }
    }
    return;
}
void Board::PutPiece(int putx, int puty)//�u����Ƃ���ɂ���putx puty����͂��Ȃ����Ɏg���B
{
    int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

    for (int i = 0; i < 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            if (board[putx + dx[i] * j][puty + dy[i] * j] == turn)
            {
                for (int k = 0; k < j + 1; k++)
                {
                    board[putx + k * dx[i]][puty + k * dy[i]] = turn;
                }
                break;
            }
            else if (board[putx + dx[i] * j][puty + dy[i] * j] != -turn)
            {
                break;
            }
        }

    }

    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j < 9; j++)
        {
            if (board[i][j] == 2)board[i][j] = 0;
        }
    }
    return;
}
void Board::PutPiece()//�u����Ƃ������͂���o�[�W����
{
    int putx, puty;
    int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

    while (true)
    {
        printf("�ォ�牽�s�ځH\n");
        scanf("%d", &putx);
        printf("�����牽��ځH\n");
        scanf("%d", &puty);

        if (board[putx][puty] == 2)
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 1; j <= 8; j++)
                {
                    if (board[putx + dx[i] * j][puty + dy[i] * j] == turn)
                    {
                        for (int k = 0; k < j + 1; k++)
                        {
                            board[putx + k * dx[i]][puty + k * dy[i]] = turn;
                        }
                        break;
                    }
                    else if (board[putx + dx[i] * j][puty + dy[i] * j] != -turn)
                    {
                        break;
                    }
                }

            }

            for (int i = 1; i < 9; i++)
            {
                for (int j = 1; j < 9; j++)
                {
                    if (board[i][j] == 2)board[i][j] = 0;
                }
            }

            WCP[0] = 0;
            return;
        }
        printf("You Can Not Put A Piece There.\n");
    }
}

