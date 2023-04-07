#include <iostream>

using namespace std;

#define N 5

int main_graph[N][N] = {
	{0,4,5,0,0},
	{0,0,0,0,0},
	{0,0,0,0,10},
	{0,0,0,0,0},
	{0,0,0,0,0},
};


bool check(int index) {
	bool check_node = false;
	for (int i = 0; i < N; i++)
	{
		if (index == (N - 1)) {
			check_node = true;
		}
		else
		{
			if (main_graph[index][i] != 0) {
				check_node = check(i);
			}
		}
	}
	return check_node;
}

int minDistance(int graph[]) {
	int min_index = 0;
	int min = 1000;
	for (int i = 0; i < N; i++)
	{
		if (graph[i] != 0) {
			if (graph[i] < min && check(i)) {
				min_index = i;
				min = graph[i];
			}
		}
	}

	return min_index;
}


void dijkstra(int graph[N][N]) {

	int min = 0;
	int total = 0;
	int last = 0;
	for (int i = 0; i < N; i++)
	{
		cout << min + 1;
		last = min;
		min = minDistance(graph[min]);
		if (min == 0) {
			break;
		}
		total += graph[last][min];
	}
	cout << "\nTotal Cost: " << total;
}


int main() {
	dijkstra(main_graph);
}

