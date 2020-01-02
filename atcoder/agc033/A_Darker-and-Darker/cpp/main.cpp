#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

// ref : https://atcoder.jp/contests/agc033/submissions/9281971

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
	// https://qiita.com/blackcurrant/items/312ea2471900132fbd6a
	std::cin.tie(0);
	std::ios_base::sync_with_stdio(false);

	// 1 <= H,W <= 1000
	int in_h, in_w;
	std::cin >> in_h >> in_w;

	// 2-dim array (allocate memory space)
	// store input
	std::vector<std::string> in_squre(in_h);
	std::vector<std::vector<int>> palette_counter(in_h, std::vector<int>(in_w));

	std::queue<std::pair<int, int>> q;

	for (int row_i=0; row_i < in_h; row_i++)
	{
		std::cin >> in_squre.at(/* pos= */row_i);
		for (int col_i=0; col_i < in_w; col_i++)
		{
			if(in_squre[row_i][col_i] == '#')
			{
				palette_counter.at(row_i).at(col_i) = 0;
				q.push(std::make_pair(col_i, row_i));
			}
			else
			{
				// palette_counter.at(row_i).at(col_i) = -1;
				palette_counter[row_i][col_i] = -1;
			}
		}
	}

	while(!q.empty())
	{
		std::pair<int, int> p = q.front();
		q.pop();
		for (int i=0; i < 4; i++)
		{
			int nx = p.first + dx[i],
			    ny = p.second + dy[i];
			if (!(0 <= nx && nx < in_w && 0 <= ny && ny < in_h)) continue;
			if (palette_counter[ny][nx] != -1) continue;

			palette_counter[ny][nx] = palette_counter[p.second][p.first] + 1;
			q.push(std::make_pair(nx, ny));
		}
	}

	int rsl = 0;
	for (int row_i = 0; row_i < in_h; row_i++)
	{
		for (int col_i = 0; col_i < in_w; col_i++)
		{
			rsl = std::max(rsl, palette_counter[row_i][col_i]);
		}
	}

	std::cout << rsl << std::endl;

	return 0;
}