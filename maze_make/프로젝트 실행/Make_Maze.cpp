#include"stdafx.h"
#include"Make_Maze.h"

FILE* fp;

//maze_list
char maze[maze_skaleton][maze_skaleton];

void init_maze()
{
	int updoor = rand() % (maze_skaleton - 1);
	int downdoor = rand() % (maze_skaleton - 1);

	if (updoor % 2 == 0)
	{
		updoor += 1;
	}

	if (downdoor % 2 == 0)
	{
		downdoor += 1;
	}

	for (int i = 0; i < maze_skaleton; ++i)
	{
		for (int j = 0; j < maze_skaleton; ++j)
		{
			switch (i % 2)
			{
			case 0:
				switch (j % 2)
				{
				case 0:
					maze[i][j] = '+';
					break;
				case 1:
					if (i == 0 && j == updoor)
					{
						maze[i][updoor] = ' ';
					}
					else if (i == maze_skaleton - 1 && j == downdoor)
					{
						maze[i][downdoor] = ' ';
					}
					else
					{
						maze[i][j] = '-';
					}
					break;
				}
				break;
			case 1:
				switch (j % 2)
				{
				case 0:
					maze[i][j] = '!';
					break;
				case 1:
					maze[i][j] = '&';
					break;
				}
				break;
			}
		}
	}


}


void make_maze()
{
	bool check = false;
	int first_holl_w = rand() % (maze_skaleton - 1);
	if (first_holl_w % 2 == 0)
		first_holl_w += 1;

	int first_holl_h = rand() % (maze_skaleton - 1);
	if (first_holl_h % 2 == 0)
		first_holl_h += 1;

	maze[first_holl_h][first_holl_w] = ' ';


	int Count_Block = 0; // 이것을 통해 체크한다.
						 //방향을 정하자. 
						 //1 = 위
						 //2 = 아래
						 //3 = 왼쪽
						 //4 = 오른쪽

	while (1)
	{
		switch (rand() % 4 + 1)
		{
		case 1:
			if (maze[first_holl_h - 2][first_holl_w] == ' ')
			{
				check = true;
				break;
			}
			first_holl_h -= 2;
			if (first_holl_h < 1 || first_holl_h > maze_skaleton - 2)
			{
				check = true;
				break;
			}
			maze[first_holl_h][first_holl_w] = ' ';
			maze[first_holl_h + 1][first_holl_w] = ' ';
			break;
		case 2:
			if (maze[first_holl_h + 2][first_holl_w] == ' ')
			{
				check = true;
				break;
			}
			first_holl_h += 2;
			if (first_holl_h < 1 || first_holl_h > maze_skaleton - 2)
			{
				check = true;
				break;
			}
			maze[first_holl_h][first_holl_w] = ' ';
			maze[first_holl_h - 1][first_holl_w] = ' ';
			break;
		case 3:
			if (maze[first_holl_h][first_holl_w - 2] == ' ')
			{
				check = true;
				break;
			}

			first_holl_w -= 2;
			if (first_holl_w < 1 || first_holl_w > maze_skaleton - 2)
			{
				check = true;
				break;
			}
			maze[first_holl_h][first_holl_w] = ' ';
			maze[first_holl_h][first_holl_w + 1] = ' ';
			break;
		case 4:
			if (maze[first_holl_h][first_holl_w + 2] == ' ')
			{
				check = true;
				break;
			}

			first_holl_w += 2;
			if (first_holl_w < 1 || first_holl_w > maze_skaleton - 2)
			{
				check = true;
				break;
			}
			maze[first_holl_h][first_holl_w] = ' ';
			maze[first_holl_h][first_holl_w - 1] = ' ';
			break;
		}

		if (check)
		{
			break;
		}

		if (maze[first_holl_h - 2][first_holl_w] == ' ' && maze[first_holl_h + 2][first_holl_w] == ' '
			&&maze[first_holl_h][first_holl_w - 2] == ' ' && maze[first_holl_h][first_holl_w + 2] == ' ')
		{
			break;
		}
	}


	while (1)
	{
		Count_Block = 0;
		check = false;

		for (int i = 1; i < maze_skaleton - 1; i += 2)
		{
			for (int j = 1; j < maze_skaleton - 1; j += 2)
			{
				if (maze[i][j] != ' ')
				{
					if (j > 1 && maze[i][j - 2] == ' ' && maze[i][j])
					{
						maze[i][j] = ' ';
						maze[i][j - 1] = ' ';
						first_holl_w = j;
						first_holl_h = i;
						check = true;
						break;
					}
					else if (j < maze_skaleton - 3 && maze[i][j + 2] == ' ')
					{
						maze[i][j] = ' ';
						maze[i][j + 1] = ' ';
						first_holl_w = j;
						first_holl_h = i;
						check = true;
						break;
					}
					else if (i > 1 && maze[i - 2][j] == ' ')
					{
						maze[i][j] = ' ';
						maze[i - 1][j] = ' ';
						first_holl_w = j;
						first_holl_h = i;
						check = true;
						break;
					}
					else if (i < maze_skaleton - 3 && maze[i + 2][j] == ' ')
					{
						maze[i][j] = ' ';
						maze[i + 1][j] = ' ';
						first_holl_w = j;
						first_holl_h = i;
						check = true;
						break;
					}
				}

			}
			if (check)
			{
				break;
			}
		}

		check = false;

		while (1)
		{
			switch (rand() % 4 + 1)
			{
			case 1:
				if (maze[first_holl_h - 2][first_holl_w] == ' ')
				{
					check = true;
					break;
				}

				if (first_holl_h - 2< 1 || first_holl_h - 2 > maze_skaleton - 2)
				{
					check = true;
					break;
				}
				first_holl_h -= 2;
				maze[first_holl_h][first_holl_w] = ' ';
				maze[first_holl_h + 1][first_holl_w] = ' ';
				break;
			case 2:
				if (maze[first_holl_h + 2][first_holl_w] == ' ')
				{
					check = true;
					break;
				}

				if (first_holl_h + 2 < 1 || first_holl_h + 2 > maze_skaleton - 2)
				{
					check = true;
					break;
				}
				first_holl_h += 2;
				maze[first_holl_h][first_holl_w] = ' ';
				maze[first_holl_h - 1][first_holl_w] = ' ';
				break;
			case 3:
				if (maze[first_holl_h][first_holl_w - 2] == ' ')
				{
					check = true;
					break;
				}


				if (first_holl_w - 2< 1 || first_holl_w - 2> maze_skaleton - 2)
				{
					check = true;
					break;
				}
				first_holl_w -= 2;
				maze[first_holl_h][first_holl_w] = ' ';
				maze[first_holl_h][first_holl_w + 1] = ' ';
				break;
			case 4:
				if (maze[first_holl_h][first_holl_w + 2] == ' ')
				{
					check = true;
					break;
				}


				if (first_holl_w + 2 < 1 || first_holl_w + 2 > maze_skaleton - 2)
				{
					check = true;
					break;
				}
				first_holl_w += 2;
				maze[first_holl_h][first_holl_w] = ' ';
				maze[first_holl_h][first_holl_w - 1] = ' ';
				break;
			}

			if (check)
			{
				break;
			}

			if (maze[first_holl_h - 2][first_holl_w] == ' ' && maze[first_holl_h + 2][first_holl_w] == ' '
				&&maze[first_holl_h][first_holl_w - 2] == ' ' && maze[first_holl_h][first_holl_w + 2] == ' ')
			{
				break;
			}
		}

		for (int i = 1; i < maze_skaleton; i += 2)
		{
			for (int j = 1; j < maze_skaleton; j += 2)
			{
				if (maze[i][j] == '&')
				{
					Count_Block++;
				}
			}
		}

		printf("빈 공간 : %d\n", Count_Block);

		if (Count_Block == 0)
		{
			break;
		}


	}
	

	fp = fopen("maze.txt", "wt");
	for (int i = 0; i < maze_skaleton; ++i)
	{
		for (int j = 0; j < maze_skaleton; ++j)
		{

			fprintf(fp, "%c", maze[i][j]);
		}
		fprintf(fp, "\n");
	}
	

	fclose(fp);
}