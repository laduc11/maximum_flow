#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <sstream>

#define MAX_FILE 10

using namespace std;

int fordFulkerson(int **graph, int s, int t);
void setV(int v);
void create_data();
void create_solution();